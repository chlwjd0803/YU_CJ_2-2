#include <iostream>

using namespace std;

// n개의 용량을 모두 사용할 수 있게 개선한 코드
// 변수 size가 추가되어 empty와 full을 구분하게함

class Circular_Queue {
private:
	int head; //rear와 같은기능을 함
	int tail; //front와 같은기능을 함, 변수 이름만 바뀌었음
	int* cqueue;
	int size; //원형 큐 들어간 원소의 개수
	int capacity; //원형 큐의 최대 이용 가능 용량 = 실제용량

public:
	Circular_Queue(int n) { //생성자와 함께 초기화
		head = 0;
		tail = 0;
		cqueue = new int[n];
		size = 0; //몇칸만큼 원소를 넣었는지 기록
		capacity = n; //실제 용량
	}

	~Circular_Queue() { //소멸자를 통해 메모리 해제
		delete[] cqueue;
	}

	void printQueue() {
		if (!empty()) {
			cout << "index    item" << endl;
			for (int i = (tail + 1) % capacity; i != (head + 1) % capacity; i = (i + 1) % capacity) //전체 %연산
				printf("  %d       %d\n", i, cqueue[i]);
		}
	}

	bool empty() {
		if (head == tail) return true;
		else return false;
	}

	bool full() {
		if (size == capacity) return true;
		else return false;
	}

	void enqueue(int item) { //%연산자 활용하여 원형 큐 형태 구현
		head = (head + 1) % capacity;
		cqueue[head] = item;
		size++;
	}

	int dequeue() { //%연산자 활용하여 원형 큐 형태 구현
		size--;
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
			if (cq.empty()) cout << "Circular Queue is empty!!" << endl;
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

	return 0;
}


