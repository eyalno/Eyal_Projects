

Node * RecursiveReverse(Node * node);


List* recur_rlist(List* head)
{
	List* result;
	if (!(head && head->next))
		return head;

	result = recur_rlist(head->next);
	head->next->next = head;
	head->next = NULL;

	return result;

Node * IterativeReverse(Node * node);

Node * reverse(Node * ptr)
{
	Node * temp;
	Node * previous = NULL;
	while (ptr != NULL) {
		temp = ptr->next;
		ptr->next = previous;
		previous = ptr;
		ptr = temp;
	}
	return previous;
}


//  producer consumer
make_new(widget);             // create a new widget to put in the buffer
down(&empty);                 // decrement the empty semaphore
down(&mutex);                 // enter critical section
put_item(widget);             // put widget in buffer
up(&mutex);                   // leave critical section
up(&full);                    // increment the full semaphore

lock
	push 
unlock



lock
	pop
unlock


down(&full);                  // decrement the full semaphore
down(&mutex);                 // enter critical section
remove_item(widget);          // take a widget from the buffer
up(&mutex);                   // leave critical section
up(&empty);                   // increment the empty semaphore
consume_item(widget);         // consume the item



doWork()
{
	_____________

	throw

	return 

	return;
}


print begin end 
CTOR

// 3 thread 

max min 
2 / 99

int i = 0 

for (j = 0; j < 33; ++j)
{
	i = i + 1;
}


load fetch
inc 
store 
