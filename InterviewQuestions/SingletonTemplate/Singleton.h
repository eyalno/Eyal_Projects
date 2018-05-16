
http://www.codeproject.com/Articles/4750/Singleton-Pattern-A-review-and-analysis-of-existin
//add auto pointer for destruction
class Lock {
	  public:
		    Lock() { /* placeholder code to create the lock */ }
		    ~Lock() { /* placeholder code to deallocate the lock */ }
		    static void AcquireLock() { /* placeholder to acquire the lock */ }
			static void ReleaseLock(){ /* placeholder to release the lock */ }
};

template<typename T>
class singleton
{
public:
	static T * getInstance()
	{
		if (instance == nullptr)
		{
			Lock::AcquireLock();

			if (instance == nullptr)
			{
				try
				{
					instance = new T;
				}
				catch (...)
				{
				}
			}
			Lock::ReleaseLock();
		}

		return instance;
	}

private:
	singleton<T>(){}
	static T * instance;
	
};


template<typename T>
T * singleton<T>::instance = nullptr;
