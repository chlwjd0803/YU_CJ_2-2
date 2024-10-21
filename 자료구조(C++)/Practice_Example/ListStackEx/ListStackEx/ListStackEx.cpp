#include "ListStack.h"
#include <iostream>

using namespace std;

int main() {
	ListStack ls;

	ls.push(10);
	ls.push(20);
	ls.pop();
	ls.push(30);
	ls.printStack();

}