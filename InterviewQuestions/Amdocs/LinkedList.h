
template<typename T>
class Node 
{
public:
	Node<T> (T& data):
	data(data),next(nullptr){}

	T data;
	Node<T> * next;
};

template<typename T>
class List{
public:
	List(){ head = nullptr; }
	
	//straight forward
	bool find(T * data);
	void insert(Node<T> * node);
	void deleteNode(T * data);
	void print();

	//better solution 1.extra variable 2.deleted is at the head
	//pointer which points to the pointer which points to current
	void deleteNodeBetter(T * data);
	void insertBetter(Node<T> * node);

private:
	Node<T>* head;

};




template<typename T>
void List<T>::print()
{
	Node<T> * temp = head;
	while (temp != nullptr)
	{
		cout << temp.data << endl;
		temp = temp->next;
	}
}


template<typename T>
void List<T>::insert(Node<T> * node)
{
	if (head == nullptr || head->data >= node->data)
	{
		node->next = head;
		head = node;
	}
	else
	{
		/* Locate the node before the point of insertion */
		//i look at the next data so it should not be nulll
		Node<T> * current = head;
		while (current->next != nullptr && current->next->data < node->data)
		{
			current = current->next;
		}
		node->next = current->next;
		current->next = node;
	}
}

template<typename T>
bool List<T>::find(T * data)
{
	bool found = false;
	Node<T> * current = head;
	for (Node<T> * current = head; current != nullptr; current = current->next)
	{
		if (*data == current->data)
		{
			found = true;
			break;
		}
	}
	return found;
}


template<typename T>
void List<T>::deleteNode(T * data)
{
	if (head == nullptr)
		return;

	if (*data == head->data)
	{
		head = head->next;
		return;
	}
	
	//we try to find the node 
	for (Node<T> * prev = head,* current = head->next;current != nullptr ; current = current->next)
	{
		if (current->data == *data)
		{
			prev->next = current->next;
			break;
		}

		prev = current;
	}
}



template<typename T>
void List<T>::deleteNodeBetter(T * data)
{
	for (Node<T> ** lpp = &head; *lpp != nullptr; lpp = &(*lpp)->next)
	{
		if ((*lpp)->data == *data)
		{
			*lpp = (*lpp)->next;
			break;
		}
	}
}




template<typename T>
void List<T>::insertBetter(Node<T> * node)
{
	for (Node<T> ** lpp = &head; *lpp != nullptr; lpp = &(*lpp)->next)
	{
		Node<T> * lp = *lpp;
		if (node->data <= lp->data)
		{
			node->next = lp;
			*lpp = node;
			break;
		}
	}
}
