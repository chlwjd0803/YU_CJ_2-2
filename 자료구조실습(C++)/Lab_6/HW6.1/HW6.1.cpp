#include "List.h"
#include "ListBasic.h" //반드시 두 헤더파일이 필요함
#include <iostream>

using namespace std;

int main() {
	ListBasic lb;

	int slt; //선택메뉴
	int item; //입력용

	cout << "==리스트 기본연산==" << endl;
	cout << "0. 리스트 출력" << endl;
	cout << "1. 맨앞에 노드 추가" << endl;
	cout << "2. 맨뒤에 노드 추가" << endl;
	cout << "3. 맨앞에 노드 제거" << endl;
	cout << "4. 지정한 노드 제거" << endl;
	cout << "5. 노드 위치 검색" << endl;
	cout << "6. 노드 리스트 역순" << endl;
	cout << "-1. 프로그램 종료" << endl;

	while (true) {
		/*
		cout << "==리스트 기본연산==" << endl;
		cout << "0. 리스트 출력" << endl;
		cout << "1. 맨앞에 노드 추가" << endl;
		cout << "2. 맨뒤에 노드 추가" << endl;
		cout << "3. 맨앞에 노드 제거" << endl;
		cout << "4. 지정한 노드 제거" << endl;
		cout << "5. 노드 위치 검색" << endl;
		cout << "6. 노드 리스트 역순" << endl;
		cout << "-1. 프로그램 종료" << endl;
		*/
		cout << "메뉴 입력 : ";
		

		cin >> slt;
		if (slt == -1) break;

		switch (slt) {
		case 0: 
			lb.printList();
			break;
		case 1:
			cout << "입력 데이터 : ";
			cin >> item;
			lb.insert_front(item);
			break;
		case 2:
			cout << "입력 데이터 : ";
			cin >> item;
			lb.insert_last(item);
			break;
		case 3:
			item = lb.dlt_front();
			cout << "제거한 데이터 : " << item << endl;
			break;
		case 4:
			cout << "제거할 데이터를 입력하세요 : ";
			cin >> item;
			lb.dlt(item);
			break;
		case 5:
			cout << "검색할 노드 데이터를 입력하세요 : ";
			cin >> item;
			lb.search(item);
			break;
		case 6:
			lb.invert();
			break;
		default:
			cout << "입력값이 유효하지 않습니다" << endl;

		}
		cout << endl << endl;
	}

	cout << "프로그램을 종료합니다" << endl;
}