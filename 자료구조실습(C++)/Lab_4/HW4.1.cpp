#include <stdio.h>
#include <iostream>

using namespace std;

class Stack {
private:
	int* stack;
	int top;
	int size;

public:
	Stack(int n) {
		stack = new int[n];
		top = -1;
		size = n;
	}

	~Stack() { delete[] stack; } //메모리해제

	void push(int item) { stack[++top] = item; }

	int pop() { return stack[top--]; }

	void printStack() {
		if (top > -1) {
			cout << "index    item" << endl;
			for (int i = 0; i <= top; i++) cout << "  " << i << "        " << stack[i] << endl;
		}
	}

	void extend() {
		if (top + 1 == size) { //푸시 하기 전 용량검사
			size *= 2;
			int* temp = new int[size];
			for (int i = 0; i <= top; i++) temp[i] = stack[i];
			delete[] stack;; //기존 메모리 해제
			stack = temp;
		}
	}

	bool empty() {
		if (top == -1) return true;
		else return false;
	}
};


int main() {
	Stack s(10);
	int menu=0;
	int item=0;
	bool flag = true;
	while (flag) {
		cout << "스택 메뉴 : 1.푸시  /  2.팝  : ";
		cin >> menu;

		switch(menu){
		case 1:
			s.extend(); //연장이 필요하면 재할당, 아니면 의미없는 실행
			cout << "push item : ";
			cin >> item;
			s.push(item);
			s.printStack();
			break;
		case 2:
			if (s.empty()) {printf("Stack is empty!!\n");}
			else {
				printf("pop item : %d\n", s.pop());
				s.printStack();
			}
			break;
		default:
			flag = false;
			break;
		}
	}
	printf("종료합니다.");
	return 0;
}
