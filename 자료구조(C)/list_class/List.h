#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

class List {
protected:
	List* first; // 처음 리스트는 비어 있음

public:
	int data;
	List* link;

	List(int n = 0) {
		data = n;
		link = nullptr;
		first = nullptr;
	}

	~List() { //메모리해제
		List* temp;
		while (first != nullptr) {
			temp = first;
			first = first->link;
			delete temp;
		}
	}
};



#endif