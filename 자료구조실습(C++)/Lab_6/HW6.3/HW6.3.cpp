#include "List.h"
#include "ListQueue.h"
#include <iostream>

using namespace std;

int main() {
	ListQueue lq;
	int item;
	int slt;

	cout << "====리스트로 구현한 큐====" << endl;
	cout << "1. enqueue" << endl;
	cout << "2. dequeue" << endl;
	cout << "-1. exit" << endl;
	

	while (true) {
		/*
		cout << "====리스트로 구현한 큐====" << endl;
		cout << "1. enqueue" << endl;
		cout << "2. dequeue" << endl;
		cout << "-1. exit" << endl;
		*/
		cout << "메뉴선택 : ";
		cin >> slt;

		if (slt == -1) break;

		switch (slt) {
		case 1:
			cout << "enqueue 할 데이터를 입력 : ";
			cin >> item;
			lq.enqueue(item);
			break;
		case 2:
			cout << "dequeue 한 데이터 : " << lq.dequeue() << endl;
			break;
		default:
			cout << "잘못 입력하셨습니다." << endl << endl;
			continue;
		}

		lq.printQueue();
		cout << endl;

	}

	cout << "종료합니다." << endl;
}