#include "List.h"
#include <iostream>

using namespace std;

int main() {
	List A;
	List B;

	int item; //입력용

	cout << "리스트 A의 원소를 연속으로 입력하세요(-1 입력시 종료) : ";
	while (true) {
		cin >> item;
		if (item == -1) break;
		A.insert(item);
	}
	A.printList();

	cout << "리스트 B의 데이터를 연속으로 입력하세요(-1 입력시 종료) : ";
	while (true) {
		cin >> item;
		if (item == -1) break;
		B.insert(item);
	}
	B.printList();

	cout << "두 리스트를 합친 후" << endl;
	A.merge(&B);
	A.printList();

	cout << "프로그램을 종료합니다" << endl;
}