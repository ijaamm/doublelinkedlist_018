#include <iostream>
#include <string>
using namespace std;

class node {
public:
	int noMhs;
	string name;
	node* next;
	node* prev;
};

class doublelinkedlist {
private:
	node* START;
public:
	doublelinkedlist();
	void addnode();
	bool search(int rollNo, node** previous, node** current);
	bool deletenode(int rolNo);
	bool listempty();
	void ascending();
	void descending();
};