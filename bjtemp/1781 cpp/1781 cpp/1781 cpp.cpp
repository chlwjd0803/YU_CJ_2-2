#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class HomeWork {
public:
	int ddline;

	int* noodles;
	int nsize;
	int top; //noodles를 스택처럼 이용하기 위해

	HomeWork() {
		noodles = new int[10]; //초기값은 그냥 10
		nsize = 10; //초기 크기
		top = -1;
	}

	void setDeadline(int n) {ddline = n;}

	void extend() {
		int* temp = new int[nsize*2];
		for (int i = 0; i < nsize; i++) temp[i] = noodles[i];
		delete[] noodles;
		noodles = temp; // 확장된 배열을 옮겨줌
		nsize *= 2; //사이즈를 2배로 증가 반영
	}

	void push(int item) {
		if (top + 1 == nsize) extend(); // 스택이 꽉 차면 확장
		noodles[++top] = item;

		// 선택 정렬 알고리즘을 사용하여 스택을 오름차순으로 정렬
		for (int i = 0; i < top; i++) {
			int minIndex = i;
			for (int j = i + 1; j <= top; j++) {
				if (noodles[j] < noodles[minIndex]) {
					minIndex = j;
				}
			}
			// swap
			int temp = noodles[i];
			noodles[i] = noodles[minIndex];
			noodles[minIndex] = temp;
		}
	}

	bool isEmpty() {
		if (top == -1) return true;
		else return false;
	}

	int pop() {
		if (top == -1) return -1;
		else return noodles[top--];
	}

};

int main(void) {
	HomeWork* hw;

	int hnum;
	scanf("%d", &hnum); //숙제의 개수를 입력받는다.

	hw = new HomeWork[hnum+1]; //일단 개수만큼 할당받음
	for (int i = 1; i <= hnum; i++) hw[i].setDeadline(i); //각 객체에 데드라인 설정, 데드라인은 1~숙제개수 까지 할당가능


	int dline;
	int cup;
	for (int i = 1; i <= hnum; i++) {
		scanf("%d %d", &dline, &cup);
		hw[dline].push(cup); //해당 데드라인에 해당하는 지점에 컵라면 개수 추가
	}

	int dcnt = 1;
	int sum = 0;
	while (dcnt <= hnum) {
		sum += hw[dcnt].pop();
		if (hw[dcnt].isEmpty()) {
			
		}
	}

	printf("%d", sum);
}