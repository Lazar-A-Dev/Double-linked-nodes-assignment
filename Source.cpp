#include<iostream>
#include"DLNode.h"
#include"Node.h"
using namespace std;
void main() {

	DLNode dl;
	dl.AddToHead(5);
	dl.AddToHead(6);
	dl.AddToHead(2);
	dl.AddToHead(8);
	dl.AddToHead(9);
	dl.AddToHead(3);

	dl.PrintAll();

	cout << "Num. 9: " << dl.IsInList(9) << endl;
	dl.DeleteEl(9);

	dl.PrintAll();

	cout << "Num. 9: " << dl.IsInList(9) << endl;

	dl.AddToTail(88);
	dl.PrintAll();

	dl.DeleteFromTail();
	dl.PrintAll();

	system("pause");
}