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
	void hapus();
	void searchdata();
};

doublelinkedlist::doublelinkedlist() {
	START = NULL;
}

void doublelinkedlist::addnode() {
	int nim;
	string nm;
	cout << "\enter the roll number of the student: ";
	cin >> nim;
	cout << "\rnter the name of the student: ";
	cin.ignore();
	getline(cin, nm);
	node* newnode = new node();
	newnode->noMhs = nim;
	newnode->name = nm;

	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\n duplicate number no allowed" << endl;
			return;
		}
		newnode->next = START;
		if (START != NULL)
			START->prev = NULL;
		START = newnode;
		return;
	}

	node* current = START;
	while (current->next != NULL && nim > current->next->noMhs)
		current = current->next;

	if (current->next != NULL && nim > current->next->noMhs) {
		cout << "\ndublicate roll numbers not allowed" << endl;
		return;
	}
	
	newnode->next = current->next;
	newnode->prev = current;
	if (current->next != NULL)
		current->next->prev = newnode;
	current->next = newnode;
	
}