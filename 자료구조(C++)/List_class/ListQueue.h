#ifndef LISTQUEUE_H
#define LISTQUEUE_H
#include "List.h"
#include <iostream>

using namespace std;

class ListQueue : public List {
protected:
	List* front;
	List* rear;

public:
	
	ListQueue() {
		front = first; //얘는 그냥 first 쓰고..(어짜피 nullptr임)
		rear = nullptr; //얘는 nullptr을 주자
	}

	bool empty() {
		if (front == nullptr) { //front가 가리키는게 없으면 노드가 없음
			cout << "Queue is empty!! (return -1)" << endl;
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


	void enqueue(int item) {
		List* temp = new List(item); //data는 정해지고 link는 nullptr임
		//여기다가 풀 or 에러 구현할것

		temp->data = item;

		if (rear != nullptr)
			rear->link = temp; //노드가 하나이상 있으면 연결처리까지
		else
			front = temp; //노드가 처음 생성되면 front에도 노드를 저장해야함

		rear = temp; //rear 증가
	}

	int dequeue() {
		if (empty()) return -1;

		List* temp = front; //마지막에 지우기 위함

		int item = front->data;
		front = front->link; //front증가, 마지막 노드를 디큐하면 front는 nullptr가됨
		delete temp; //노드 삭제, 디큐
		return item; //원소 반환
	}

	void printQueue() {
		List* temp = front;

		cout << "printQueue" << endl;
		cout << "front -> ";
		if (temp == nullptr) cout << "nullptr ";
		else while(temp != nullptr){ //마지막엔 nullptr를 만나므로
			cout << temp->data << " ";
			temp = temp->link;
		}

		cout << "<- rear" << endl;
	}
};

#endif
