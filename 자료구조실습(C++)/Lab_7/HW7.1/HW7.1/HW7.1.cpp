#include <iostream>

using namespace std;

class List {
public:
	int coef;
	int exp;
	List* link;

	List* first = nullptr; //첫 노드를 저장할 공간은 nullptr로 초기화, 객체마다 first가 다르기에 멤버변수로 선언

	List() { link = nullptr; }

	List(int coef, int exp) {
		this->coef = coef;
		this->exp = exp;
		link = nullptr;
	}

	void insert(int coef, int exp) {
		List* temp = new List(coef, exp);
		List* ptr;

		if (first == nullptr) first = temp;
		else {
			for (ptr = first; ptr->link != nullptr; ptr = ptr->link);
			ptr->link = temp;
			temp->link = nullptr;
		}
	}

	void polyGen() {
		while (true) {
			cout << "다항식을 입력하세요(coef exp) : ";
			cin >> coef >> exp;
			insert(coef, exp); //-1이어도 일단 기입함
			if (coef == -1 && exp == -1) {
				List* temp = first;
				for (; temp->link != nullptr; temp = temp->link);
				temp->link = first; //마지막에 환형처리
				first = temp; //-1 -1이 있는 더미노드를 헤드로 변경
				return;
			}
		}
	}

	int COMPARE(int x, int y) {
		if (x < y) return -1;
		else if (x == y) return 0;
		else return 1;
	}

	List* pAdd(List* X) {
		//A는 this가 됨
		List* D = new List();
		List* A = this->first->link; //A의 시작지점으로 지정하는게 중요함
		List* B = X->first->link; //더미노드를 넘기고 시작

		while ((A->exp != -1) || (B->exp != -1)) {

			switch (COMPARE(A->exp, B->exp)) {
			case -1: {
				D->insert(B->coef, B->exp);
				B = B->link; //D는 insert함수를 통해 다음노드로 이동되어 있음, B만 움직임
				break;
			}
			case 0: {
				if (A->coef + B->coef) 
					D->insert((A->coef + B->coef), A->exp);
				A = A->link;
				B = B->link;
				break;
			}
			case 1: {
				D->insert(A->coef, A->exp);
				A = A->link;
				break;
			}
			}
		}

		List* temp = new List(-1, -1);

		cout << D->exp << endl; //여기에 무슨 문제가 있는듯
		if (D->link == nullptr) cout << "널포인터닷" << endl;


		D->link = temp;

		temp->link = D->first;
		D->first = temp; //더미노드를 헤드로 지정

		cout << D->first->exp << endl;
		cout << D->first->link->exp << endl;

		return D;
	}

	List* single_Mul(List* A, List* X) {
		List* C = new List();
		
		List* B = X; //B만 계속 움직이고 A는 값만 이용하므로 X(B)는 복사
		for (; B != B->first; B = B->link) {
			int mCoef = A->coef * B->coef;
			int sExp = A->exp + B->exp;
			C->insert(mCoef, sExp);
		}
		List* temp = new List(-1, -1); //더미노드를 붙이기 위해 생성
		C->link = temp;
		temp->link = C->first;
		C->first = temp; //더미노드를 헤드로 만듦

		return C;
	}

	List* pMul(List* X) {
		List* D = new List();
		List* A = this->first->link; //A의 시작지점으로 지정하는게 중요함
		List* B = X->first->link; //더미노드는 지나치기

		int index = 0;

		for (; A != A->first; A = A->link) {
			List* Ci = single_Mul(A, B);

			printf("single_mul - C%d(x)\n", ++index);
			Ci->print();

			D = D->pAdd(Ci); //D에 더해주기

			delete Ci; //합 해주고 메모리 해제
		}

		return D;
	}

	void print() {
		printf("    coef    exp\n");
		for (List* temp = first->link; temp != first; temp = temp->link) printf("    %4d%7d\n", temp->coef, temp->exp);
		printf("\n");
	}

	
	void printList() { //환형이 제대로 이루어졌는지 확인용
		List* temp = first->link;
		while (temp != first) {
			cout << temp->coef << "," << temp->exp << " -> ";
			temp = temp->link; //다음 노드로 이동
		}
		cout << temp->coef << "," << temp->exp << endl; //헤드노드까지 출력해보는것
	}
	
};

List* avail; //전역변수

int main() {
	List* A = new List();
	List* B = new List();
	List* D; //계산 후 참조반환
	List* X; //계산 후 참조반환

	cout << "7.1 다항식 생성" << endl;
	cout << "다항식 A(x)" << endl;
	A->polyGen();
	cout << "다항식 A(x) :" << endl;
	A->print();
	cout << "다항식 B(x)" << endl;
	B->polyGen();
	cout << "다항식 B(x) :" << endl;
	B->print();


	cout << "7.2 다항식 덧셈" << endl;
	D = A->pAdd(B); //포인터 방식으로 접근 필수
	cout << "다항식 덧셈 결과 : D(x)" << endl;
	D->printList();
	D->print();

	cout << endl << "7.3 다항식 곱셈" << endl;
	D = A->pMul(B);


	return 0;
}