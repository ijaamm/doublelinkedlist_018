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

bool doublelinkedlist::search(int rollNo, node** previous, node** current) {
	*previous = *current = START;
	while (*current != NULL && rollNo != (*current)->noMhs) {
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}

bool doublelinkedlist::deletenode(int rollNo) {
	node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;
	if (previous != NULL)
		previous->next = current->next;
	else
		START = current->next;
	delete current;
	return true;
}

bool doublelinkedlist::listempty() {
	return (START == NULL);

}
void doublelinkedlist::ascending() {
	if (listempty())
		cout << "\nlist empty" << endl;
	else {
		cout << "\nrecord in ascending order of roll number are: " << endl;
		node* currentnode = START;
		while (currentnode != NULL) {
			cout << currentnode->noMhs << " " << currentnode->name << endl;
			currentnode = currentnode->next;
		}
	}
}

void doublelinkedlist::descending() {
	if (listempty())
		cout << "\nlist is empty" << endl;
	else {
		cout << "\nrecord in descending order of roll number are" << endl;
		node* currentnode = START;
		while (currentnode->next != NULL)
			currentnode = currentnode->next;

		while (currentnode != NULL) {
			cout << currentnode->noMhs << " " << endl;
			currentnode = currentnode->prev;
		}
	}
}

void doublelinkedlist::hapus() {
	if (listempty()) {
		cout << "\nlist is empty" << endl;
	}
	cout << "\nenter the roll number of the student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (doublelinkedlist::deletenode(rollNo) == false)
		cout << "record not found" << endl;
	else
		cout << "record with roll number" << rollNo << "deleted" << endl;
}