#include <cmath>
#include <functional>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <thread>

using namespace std;




/*
Included in the attached cpp file is an implementation of a concurrent queue.
The intention is to use this queue in a high performance trading system where one consumer will execute tasks submitted to the concurrent queue by multiple producers.
The assumption is that the consumer can handle events faster than that the producers can produce them,
otherwise behavior is undefined.Please answer the following questions as clear and concise as possible :
• What changes would you suggest in a code review ?
Would you check in your code like this ? Do you think the code is clean ?
• Do you see room for improving the performance without breaking thread safety ?
In the latest release of the software it was discovered that the queue has a bug :
a segmentation fault occurs while trying to execute one of the tasks in the queue.
An example case has been implemented in the main function of the file that can reproduce the problem
(at least on our systems, it could be dependent on how fast the tasks get executed and how the threads will be scheduled on other systems).
Please answer the following questions as clear and concise as possible :
• What steps would you take to find the bug ?

• If you can find the bug, what fix would you suggest ?
Write a proper test case to prove that the bug is solved(may be in pseudo code),
preferably in a deterministic matter ? •s
If you cannot find the bug,
how would you go about testing the thread safety of the class ?
Give an example of such a test(may be in pseudo code).
If you want to compile the problem please make sure to enable c++11 language features.
For example with clang : clang++ - std = c++11 ConcurrentQueue.cpp - o test
*/

//64  bits  we don't need 64 
template<typename T, uint64_t SIZE = 4096, uint64_t MAX_SPIN_ON_BUSY = 40000000>
class ConcurrentQueue {
private:
	//unsigned int
	//constexpr computation in compile time 
	//log one below  4096 = 12

	static  unsigned Log2(unsigned n, unsigned p = 0) {
		return (n <= 1) ? p : Log2(n / 2, p + 1);
	}

	// x? 
	// shift left . Unsigned long
	//in bit wise 12 digit  
	static  uint64_t closestExponentOf2(uint64_t x) {
		return (1UL << ((uint64_t)(Log2(SIZE - 1)) + 1));
	}

	// 11 first digits 
	static  uint64_t mRingModMask = closestExponentOf2(SIZE) - 1;
	static  uint64_t mSize = closestExponentOf2(SIZE);

	static const T mEmpty;

	T mMem[mSize];
	std::mutex mLock;
	uint64_t mReadPtr = 0;
	uint64_t mWritePtr = 0;

public:
	const T& pop() {
		if (!peek()) {
			return mEmpty;
		}

		std::lock_guard<std::mutex> lock(mLock);

		if (!peek()) {
			return mEmpty;
		}

		T& ret = mMem[mReadPtr & mRingModMask];

		mReadPtr++;
		return ret;
	}

	bool peek() const {
		return (mWritePtr != mReadPtr);
	}

	uint64_t getCount() const {
		return mWritePtr > mReadPtr ? mWritePtr - mReadPtr : mReadPtr - mWritePtr;
	}

	bool busyWaitForPush() {
		uint64_t start = 0;
		while (getCount() == mSize) {
			if (start++ > MAX_SPIN_ON_BUSY) {
				return false;
			}
		}
		return true;
	}

	void push(const T& pItem) {
		if (!busyWaitForPush()) {
			throw std::runtime_error("Concurrent queue full cannot write to it!");
		}

		std::lock_guard<std::mutex> lock(mLock);
		mMem[mWritePtr & mRingModMask] = pItem;
		mWritePtr++;
	}

	void push(T&& pItem) {
		if (!busyWaitForPush()) {
			throw std::runtime_error("Concurrent queue full cannot write to it!");
		}

		std::lock_guard<std::mutex> lock(mLock);
		mMem[mWritePtr & mRingModMask] = std::move(pItem);
		mWritePtr++;
	}
};

template<typename T, uint64_t SIZE, uint64_t MAX_SPIN_ON_BUSY>
const T ConcurrentQueue<T, SIZE, MAX_SPIN_ON_BUSY>::mEmpty = T{};

int main(int, char**) {
	


	
	//function
	using Functor = std::function < void() > ;


	//don't understand the template
	ConcurrentQueue<Functor*> queue;

	//call the thread lambada capture
	std::thread consumer([&] {
		while (true) {
			if (queue.peek()) {
				auto task = queue.pop();
				(*task)();
				delete task;
			}
		}
	});

	std::thread producer([&] {
		uint64_t counter = 0;
		while (true) {
			auto taskId = counter++;
			auto newTask = new Functor([=] {
				std::cout << "Running task " << taskId << std::endl << std::flush;
			});
			queue.push(newTask);
		}
	});

	consumer.join();
	producer.join();


	
	return 0;
}
