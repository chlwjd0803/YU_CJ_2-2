#ifndef LISTSTACK_H
#define LISTSTACK_H
#include "List.h"
#include <iostream>

using namespace std;

class ListStack : public List {
protected:
	List* top;
public:

	ListStack() {
		top = first; //top이 first 역할을 수행함, 처음엔 null
	}

	//소멸자는 슈퍼클래스에서 다 메모리해제 해줌

	bool empty() {
		if (top == nullptr) {
			cout << "Stack is empty!!!, return -1" << endl;
			return true;
		}
		else return false;
	}

	bool full_or_error(List* temp) {
		if (temp == nullptr) {
			cout << "Out of Memory(Stack is full, or Memory alloc failed." << endl;
			return true;
		}
		else return false;
	}

	void push(int item) {
		List* temp = new List(item); //data는 채워진 상황
		if (full_or_error(temp)) return;


		if (top != nullptr) //노드가 1개 이상일때는
			temp->link = top; //새 노드의 링크를 기존 탑에 연결
		//즉 노드가 없을땐 top이 바로 temp를 가르키면 됨
		top = temp; //top은 temp가 되어 top변경

		//cout << "push data : " << item << "   top->data : " << top->data << endl;
	}

	int pop() {
		if (empty()) return -1;

		List* temp;

		temp = top; //링크를 옮긴후 해당 노드의 메모리를 해제하기 위해
		int item = top->data;

		if (top->link == nullptr) {
			delete top;
			top = nullptr; //노드가 하나도 없으므로
		}
		else {
			top = top->link; //top감소
			delete temp; //삭제하려던 top 노드 메모리 해제
		}
		//cout << "pop  data : " << item << "   top->data : " << top->data << endl;

		return item; //삭제된 노드의 원소 팝
	}

	void printStack() {
		List* temp = top;

		//cout << "printStack" << endl;
		cout << "top ";
		if (temp == nullptr) cout << "-> nullptr" << endl;
		else while (temp != nullptr) {
			cout << " -> " << temp->data;
			temp = temp->link;
		}

		cout << endl;
	}
};


#endif