#include <iostream>

using namespace std;

// 배열의 용량을 n-1이 아닌 n으로 전체 사용할 수 있게 개선한 코드
// size 멤버변수로 empty와 full 조건문 구분
// head와 tail이 무한히 증가하는 경우에 따라 적절히 두 변수를 줄여주는 함수 구현

class Circular_Queue {
private:
	int head; //rear와 같은기능을 함
	int tail; //front와 같은기능을 함, 변수 이름만 바뀌었음
	int* cqueue;
	int size; //원형 큐 들어간 원소의 개수
	int capacity; //원형 큐의 최대 이용 가능 용량

public:
	Circular_Queue(int n) { //생성자와 함께 초기화
		head = -1; // 기존 교본과 다르게 -1로 시작해도 문제없음
		tail = -1;
		cqueue = new int[n];
		size = 0; //몇칸만큼 원소를 넣었는지 기록
		capacity = n; //실제 용량
	}

	~Circular_Queue() { //소멸자를 통해 메모리 해제
		delete[] cqueue;
	}

	void printQueue() { //%연산자 활용하여 원형 큐 형태 구현
		if (head != tail) {
			printf("index    item\n");
			for (int i = tail + 1; i <= head; i++)
				printf("  %d       %d\n", i%capacity, cqueue[i%capacity]);
		}
	}

	bool empty() {
		if (head == tail) return true; //위치비교
		else return false;
	}

	bool full() {
		if (size == capacity) return true; //용량비교
		else return false;
	}

	void enqueue(int item) { //%연산자 활용하여 원형 큐 형태 구현
		cqueue[(++head) % capacity] = item;
		size++;
	}

	int dequeue() { //%연산자 활용하여 원형 큐 형태 구현
		size--;
		return cqueue[(++tail) % capacity];
	}

	void maintain_int_range() { //head와 tail이 무한히 증가할 수 있으므로 적절한 시기에 수를 낮춤
		int range = 100;
		if (tail > range) //어짜피 head는 tail보다 크다
			tail %= range, head %= range;
	}
};


int main() {
	Circular_Queue cq(10);
	int menu = 0;
	int item = 0;
	bool flag = true;
	while (flag) {
		cq.maintain_int_range(); //매번 정수 크기 확인
		
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
}