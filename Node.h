#pragma once
#include<iostream>
using namespace std;
class Node {
public:
	int info;
	Node* prev, * next;

	Node() {
		info = 0;
		prev = next = NULL;
	}

	Node(int i) {
		info = i;
		prev = next = NULL;
	}

	Node(int i, Node* p, Node* n) {
		info = i;
		prev = p;
		next = n;
	}

	~Node() {}

	bool IsEqual(int i) {
		return info == i;
	}

	void Print() {
		cout << "[" << info << "] ";
	}

	int ReturnInfo() {
		return info;
	}

};
