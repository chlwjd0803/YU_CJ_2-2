﻿#include "ListMerge.h"
#include <iostream>

using namespace std;

int main() {
	ListMerge A;
	ListMerge B;

	int item; //입력용

	cout << "리스트 A의 원소를 연속으로 입력하세요(-1 입력시 종료) : ";
	while (true) {
		cin >> item;
		if (item == -1) break;
		A.insert(item);
	}

	cout << "리스트 B의 데이터를 연속으로 입력하세요(-1 입력시 종료) : ";
	while (true) {
		cin >> item;
		if (item == -1) break;
		B.insert(item);
	}



	cout << "프로그램을 종료합니다" << endl;
}