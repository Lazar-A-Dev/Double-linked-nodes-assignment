#include "DLNode.h"
DLNode::DLNode() {
	head = tail = NULL;
}

DLNode::~DLNode() {
	while (!IsEmpty())
		int rmp = DeleteFromHead();
}

bool DLNode::IsEmpty() {
	return head == NULL;
}

void DLNode::PrintAll() {
	Node* tmp = head;
	while (tmp != NULL) {
		tmp->Print();
		tmp = tmp->next;
	}
	cout << endl;
}

Node* DLNode::FindNode(int el) {
	Node* tmp = head;
	if (tmp == NULL)
		throw "Niz je prazan !";

	while (tmp != NULL && tmp->info != el) {
		tmp = tmp->next;
	}
	return tmp;
}

Node* DLNode::GetHead() {
	return head;
}

Node* DLNode::GetNext(Node* ptr) {
	return ptr->next;
}

int DLNode::GetHeadEl() {
	return head->info;
}

int DLNode::GetNextEl(int el) {
	Node* tmp = FindNode(el);
	return tmp->next->info;
}

bool DLNode::IsInList(int el) {
	if (FindNode(el))
		return true;
	return false;
}

void DLNode::DeleteEl(int el) {
	if (!IsEmpty())
		if (head == tail && head->IsEqual(el)) {
			Node* tmp = head;
			delete tmp;
			head = tail = NULL;
		}
		else if (el == head->info) {
			Node* tmp = head;
			head = head->next;
			head->prev = NULL;
			delete tmp;
		}
		else {
			Node* tmp = head->next;
			while (tmp != NULL && !tmp->IsEqual(el)) {
				tmp = tmp->next;
			}
			if (tmp != NULL) {
				tmp->prev->next = tmp->next;
				if (tmp->next)
					tmp->next->prev = tmp->prev;
				if (tmp == tail)
					tail = tmp->prev;
				delete tmp;
			}
		}
}

void DLNode::AddToHead(int el) {
	if (!IsEmpty()) {
		head = new Node(el, NULL, head);
		head->next->prev = head;
	}
	else
		head = tail = new Node(el);
}

void DLNode::AddToTail(int el) {
	if (!IsEmpty()) {
		tail = new Node(el, tail, NULL);
		tail->prev->next = tail;
	}
	else
		head = tail = new Node(el);
}

int DLNode::DeleteFromHead() {
	if (IsEmpty())
		throw "Niz je prazan !";
	int el = head->info;
	Node* tmp = head;
	if (head == tail)
		head = tail = NULL;
	else {
		head = head->next;
		head->prev = NULL;
	}
	delete tmp;
	return el;
}

int DLNode::DeleteFromTail() {
	if (IsEmpty())
		throw "Niz je prazan !";
	int el = tail->info;
	Node* del = tail;
	if (head == tail)
		head = tail = NULL;
	else {
		Node* tmp = head;
		while (tmp->next != tail)
			tmp = tmp->next;
		tail = tmp;
		tail->next = NULL;
	}
	delete del;
	return el;
}