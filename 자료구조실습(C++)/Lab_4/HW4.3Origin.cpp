#include <iostream>

using namespace std;

// 자료구조이론 교본에있는 내용과 유사하게 구현
// ->엔큐 할 수 있는 원소의 수는 용량-1

class Circular_Queue {
private:
	int head; //rear와 같은기능을 함
	int tail; //front와 같은기능을 함, 변수 이름만 바뀌었음
	int* cqueue;
	int capacity; // 실제 용량
	int max_q_size; //원형 큐의 최대 이용 가능 용량

public:
	Circular_Queue(int n) { //생성자와 함께 초기화
		head = 0;
		tail = 0;
		cqueue = new int[n];
		capacity = n; // 실제용량
		max_q_size = n-1; // 원형큐는 한칸 비워둬야 하므로
	}

	~Circular_Queue() { //소멸자를 통해 메모리 해제
		delete[] cqueue;
	}

	void printQueue() {
		if (!empty()) {
			cout << "index    item" << endl;
			for (int i = (tail+1)%capacity; i != (head+1)%capacity; i = (i+1)%capacity) //전체 %연산
				printf("  %d       %d\n", i, cqueue[i]);
		}
	}

	bool empty() { // 디큐하기 전에 실행됨
		if (head == tail) return true; // 엔큐와 디큐한 횟수가 같아지면 empty임
		else return false;
	}

	bool full() { // 엔큐하기 전에 실행됨
		int nexthead = (head + 1) % capacity; // nexthead로 변경 후의 값을 미리 비교하기 위함
		if (nexthead == tail) return true; // 즉 큐 할당 사이즈보다 1 작으면 가득찬것. 
		else return false;
	}

	void enqueue(int item) { //%연산자 활용하여 원형 큐 형태 구현
		head = (head + 1) % capacity;
		cqueue[head] = item;
	}

	int dequeue() { //%연산자 활용하여 원형 큐 형태 구현
		tail = (tail + 1) % capacity;
		return cqueue[tail];
	}
};


int main() {
	Circular_Queue cq(10);
	int menu = 0;
	int item = 0;
	bool flag = true;
	while (flag) {
		cout << "원형 큐 메뉴 : 1.엔큐 / 2.디큐 : ";
		cin >> menu;

		switch (menu) {
		case 1:
			if (cq.full()) cout << "Circular Queue is full!!" << endl;

			else {
				cout << "enqueue item : ";
				cin >> item;
				cq.enqueue(item);
				cq.printQueue();
			}
			break;

		case 2:
			if (cq.empty()) cout << "Circular is empty!!" << endl;
			else {
				cout << "dequeue item : " << cq.dequeue() << endl;
				cq.printQueue();
			}
			break;
		default:
			flag = false;
			break;
		}
	}
	cout << "종료합니다." << endl;
}
