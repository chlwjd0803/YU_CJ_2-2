#include <iostream>

using namespace std;

class Queue {
private:
	int head; //rear와 같은기능을 함
	int tail; //front와 같은기능을 함, 변수 이름만 바뀌었음
	int* queue;
	int size; //용량

public:
	Queue(int n) { //생성자와 함께 초기화
		head = -1;
		tail = -1;
		queue = new int[n];
		size = n;
	}

	~Queue() { //소멸자를 통해 메모리 해제
		delete[] queue;
	}

	void printQueue() {
		if (head != tail) {
			cout << "index    item" << endl;
			for (int i = tail + 1; i <= head; i++) cout << "  " << i << "        " << queue[i] << endl;
		}
	}

	bool empty() {
		if (head == tail) return true;
		else return false;
	}

	void extend() { //용량이 차면 2배로 늘려주는 함수
		if (head + 1 == size) {
			size *= 2;
			int* temp = new int[size];
			for (int i = tail + 1; i <= head; i++) temp[i] = queue[i];
			delete[] queue; //기존 메모리 해제
			queue = temp;
		}
	}

	void enqueue(int item) {queue[++head] = item;}

	int dequeue() {return queue[++tail];}
};


int main() {
	Queue q(10);
	int menu = 0;
	int item = 0;
	bool flag = true;
	while (flag) {
		cout << "큐 메뉴 : 1.엔큐  /  2.디큐  : ";
		cin >> menu;

		switch (menu) {
		case 1:
			q.extend(); //용량이 찼다면 증가할 것이고 아니면 의미없는 함수
			cout << "enqueue item : ";
			cin >> item;
			q.enqueue(item);
			q.printQueue();
			break;

		case 2:
			if (q.empty()) cout << "Queue is empty!!" << endl;
			else {
				cout << "dequeue item : " << q.dequeue() << endl;
				q.printQueue();
			}
			break;
		default:
			flag = false;
			break;
		}
	}
	cout << "종료합니다." << endl;
	
	return 0;
}