#include <iostream>

using namespace std;

class Circular_Queue {
private:
	int head; //rear와 같은기능을 함
	int tail; //front와 같은기능을 함, 변수 이름만 바뀌었음
	int* cqueue;
	int size; //원형 큐 들어간 원소의 개수
	int max_q_size; //원형 큐의 최대 이용 가능 용량

public:
	Circular_Queue(int n) { //생성자와 함께 초기화
		head = 0;
		tail = 0; //head와 tail의 실제값은 용량을 초과하여 계속 증가할것
		cqueue = new int[n];
		size = 0; //몇칸만큼 원소를 넣었는지 기록
		max_q_size = n; //실제 용량
	}

	~Circular_Queue() { //소멸자를 통해 메모리 해제
		delete[] cqueue;
	}

	void printQueue() { //%연산자 활용하여 원형 큐 형태 구현
		if (head != tail) {
			printf("index    item\n");
			for (int i = tail + 1; i <= head; i++) printf("  %d       %d\n", i % max_q_size, cqueue[i % max_q_size]);
		}
	}

	bool empty() {
		if (head == tail) return true;
		else return false;
	}

	bool full() {
		if (size == max_q_size) return true;
		else return false;
	}

	void enqueue(int item) { //%연산자 활용하여 원형 큐 형태 구현
		cqueue[(++head)%max_q_size] = item;
		size++;
	}

	int dequeue() { //%연산자 활용하여 원형 큐 형태 구현
		size--;
		return cqueue[(++tail)%max_q_size];
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

	return 0;
}


