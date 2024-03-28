#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next; 
};

struct LinkedList
{
	Node* head;
	Node* tail;
};

Node* CreateNode(int init_data)
{
	Node* node = new Node;
	node->data = init_data;
	node->next = NULL;      // node v?a t?o chua thêm vào danh sách nên chua liên k?t v?i ph?n t? nào c? nên ph?n liên k?t gán b?ng NULL
	return node;
}

void CreateList(LinkedList& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void AddHead(LinkedList& l, Node* node)
{
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		node->next = l.head;
		l.head = node;
	}
}

void AddTail(LinkedList& l, Node* node)
{
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		l.tail->next = node;
		l.tail = node;
	}
}

void InsertAfterQ(LinkedList& l, Node* p, Node* q)
{
	if (q != NULL)
	{
		p->next = q->next;
		q->next = p;
		if (l.tail == q)
			l.tail = p;
	}
	else
		AddHead(l, p);
}

int RemoveHead(LinkedList& l, int& x)
{
	if (l.head != NULL)
	{
		Node* node = l.head;
		x = node->data;      // Luu giá tr? c?a node head l?i
		l.head = node->next;
		delete node;         // H?y node head di
		if (l.head == NULL)
			l.tail = NULL;
		return 1;
	}
	return 0;
}

void PrintList(LinkedList l)
{
	if (l.head != NULL)
	{
		Node* node = l.head;
		while (node != NULL)
		{
			cout << node->data << ' ';
			node = node->next; // Chuy?n sang node ti?p theo
		}
	}
}

int RemoveAfterQ(LinkedList& l, Node* q, int& x)
{
	if (q != NULL)
	{
		Node* p = q->next;
		if (p != NULL)
		{
			if (l.tail == p)
				l.tail = q;
			q->next = p->next;
			x = p->data;
			delete p;
			return 1;
		}
		return 0;
	}
	return 0;
}

Node* GetNode(LinkedList& l, int index)
{
	Node* node = l.head;
	int i = 0;
	while (node != NULL && i != index)
	{
		node = node->next;
		i++;
	}
	if (i == index && node != NULL)
		return node;
	return NULL;
}

Node* Search(LinkedList l, int x)
{
	Node* node = l.head;
	while (node != NULL && node->data != x)
		node = node->next;
	if (node != NULL)
		return node;
	return NULL;
}

int Length(LinkedList l)
{
	int count = 0;
	Node* node = l.head;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}

main(){
	LinkedList list;
	CreateList(list); // Gán head và tail b?ng NULL
}
