#include "List.h"
#include <iostream>

using namespace std;

int main() {
	List l;

	l.add(10);
	l.add(20);
	l.add(30);
	l.insert(50, 20); //50을 20뒤에 추가
	l.dlt(30);

	l.printList();
}