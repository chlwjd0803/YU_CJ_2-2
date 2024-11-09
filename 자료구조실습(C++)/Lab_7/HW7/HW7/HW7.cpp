#include <iostream>

//환형연결리스트를 이용한 다항식 프로그램 7.1 7.2 7.3

using namespace std;

class List { //클래스 이름은 그냥 List로 이용
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
		List* A = this;//A의 시작지점으로 지정하는게 중요함
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
		List* ptr = D->first;
		for (ptr; ptr->link != nullptr; ptr = ptr->link);

		ptr->link = temp;
		temp->link = D->first;
		D->first = temp; //더미노드를 헤드로 지정

		return D;
	}

	List* single_Mul(List* X) { //X는 이미 첫 주소(헤드노드를 넘어간 주소)가 지정된 상태로 받음

		List* C = new List();

		for (; X->exp != -1; X = X->link) { 
			int mCoef = this->coef * X->coef;
			int sExp = this->exp + X->exp;
			C->insert(mCoef, sExp);
		}


		List* temp = new List(-1, -1); //더미노드를 붙이기 위해 생성
		List* ptr = C->first;
		for (ptr; ptr->link != nullptr; ptr = ptr->link); //마지막 노드까지 진행

		ptr->link = temp;
		temp->link = C->first;
		C->first = temp; //더미노드를 헤드로 만듦

		return C;
	}

	List* pMul(List* X) {
		List* D = nullptr;
		List* A = this; //A의 시작지점으로 지정하는게 중요함
		List* B = X->first->link; //더미노드는 지나치기

		int index = 0;

		for (; B->exp != -1; B = B->link) {
			List* Ci = B->single_Mul(A);

			printf("single_mul - C%d(x)\n", ++index);
			Ci->print();

			if (D == nullptr) {
				D = Ci; //최초로 더할땐 Ci를 그냥 복사하면됨
				Ci = nullptr;
			}

			else {
				D = D->first->link; //D의 연산이 시작되는 지점으로 항상 초기화해줌
				D = D->pAdd(Ci); //D에 더해주기
				delete Ci; //합 해주고 메모리 해제
			}
		}
		return D;
	}

	void print() {
		printf("    coef    exp\n");
		for (List* temp = first->link; temp != first; temp = temp->link) printf("    %4d%7d\n", temp->coef, temp->exp);
		printf("\n");
	}

};

List* avail; //전역변수

int main() {
	List* A = new List();
	List* B = new List();
	List* D; //계산 후 참조반환
	List* E; //계산 후 참조반환

	cout << "7.1 다항식 생성" << endl;
	cout << "다항식 A(x)" << endl;
	A->polyGen();
	cout << "다항식 A(x) :" << endl;
	A->print();
	cout << "다항식 B(x)" << endl;
	B->polyGen();
	cout << "다항식 B(x) :" << endl;
	B->print();

	A = A->first->link; //계산할 초기위치 지정해주기

	cout << "7.2 다항식 덧셈" << endl;
	D = A->pAdd(B); //포인터 방식으로 접근 필수
	cout << "다항식 덧셈 결과 : D(x)" << endl;
	D->print();

	cout << endl << "7.3 다항식 곱셈" << endl;
	E = A->pMul(B);
	cout << "다항식 곱셈 결과 : E(x)" << endl;
	E->print();

	delete A;
	delete B;
	delete D;
	delete E;

	return 0;
}