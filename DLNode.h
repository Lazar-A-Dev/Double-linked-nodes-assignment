#pragma once
#include<iostream>
#include"Node.h"
using namespace std;
class DLNode
{
protected:
	Node* head, * tail;

public:
	DLNode();
	~DLNode();

	bool IsEmpty();
	void PrintAll();
	Node* FindNode(int el);
	Node* GetHead();
	Node* GetNext(Node* ptr);
	int GetHeadEl();
	int GetNextEl(int el);
	bool IsInList(int el);
	void DeleteEl(int el);
	void AddToHead(int el);
	void AddToTail(int el);
	int DeleteFromHead();
	int DeleteFromTail();
};

