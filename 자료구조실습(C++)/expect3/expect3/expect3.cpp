#include <iostream>

using namespace std;

class Poly {
public:
	float coef;
	int exp;
};

Poly* extend(Poly* p, int* size) { //연장

	int newSize = *size + 10;
	Poly* temp = new Poly[newSize]; //옮길 객체배열 생성

	for (int i = 0; i < *size; i++) {
		temp[i].coef = p[i].coef;
		temp[i].exp = p[i].exp;
	}

	delete[] p;

	*size = newSize;
	return temp;
}

void printPoly(Poly* p, int index) { //다항식 출력
	printf("    coef    exp\n");
	for (int i = 0; i < index; i++) printf("    %4.2f%6d\n", p[i].coef, p[i].exp);
	printf("\n");
}

int COMPARE(int a, int b) { //비교 함수
	if (a < b) return -1;
	else if (a == b) return 0;
	else return 1;
}

int polyGenerator(Poly* p, int* size) { //HW3.1
	int i = 0;
	int psize = *size; //일단 지역변수로 옮김
	do {
		printf("항을 입력하시오(coef exp)(exp가 -1이면 끝표시) : ");
		cin >> p[i].coef >> p[i].exp;
		if (i - 1 == psize) p = extend(p, &psize); //다른함수와 형태를 통일하여 이중포인터를 쓰지않기 위함
	} while (p[i++].exp >= 0);
	*size = psize; //다시 인수로 옮김
	return --i; //다항식의 배열 길이를 반환
}

Poly* pAdd(Poly* A, Poly* B, int* Dlen) {
	int startA = 0, startB = 0, startD = 0;
	int sizeD = 10; //초기사이즈 10
	Poly* D = new Poly[sizeD];

	while ((A[startA].exp != -1) || (B[startB].exp != -1)){ //둘다 -1이면 탈출
		if (startD == sizeD) D = extend(D, &sizeD); //사이즈가 꽉차면 증가
		switch (COMPARE(A[startA].exp, B[startB].exp)) {
		case -1: { //a<b
			D[startD].coef = B[startB].coef;
			D[startD++].exp = B[startB++].exp;
			break;
		}
		case 0: { //a=b
			if (A[startA].coef + B[startB].coef) { //0이 아니면
				D[startD].coef = A[startA].coef + B[startB].coef;
				D[startD++].exp = A[startA].exp; //연산을 완료 후 후위증가
			}
			startA++, startB++; //둘다 연산을 끝냈으니 증가함
			break;
		}
		case 1: { //a>b
			D[startD].coef = A[startA].coef;
			D[startD++].exp = A[startA++].exp; //후위 연산자 이용하여 위치 증가
			break;
		}
		}
	}

	*Dlen = startD;
	return D;
}

Poly* single_Mul(Poly Ai, Poly* B, int bLen) {
	Poly* temp = new Poly[bLen+1]; //마지막에 다항식의 끝을 알려주는 -1를 넣기 위함
	for (int i = 0; i < bLen; i++) {
		temp[i].coef = Ai.coef * B[i].coef; //계수는 곱하고
		temp[i].exp = Ai.exp + B[i].exp; //차수는 더한다
	}
	temp[bLen].exp = -1; //-1로 지정..
	return temp;
}

Poly* pMul(Poly* A, Poly* B, int aLen, int bLen, int* mulLen) {
	int sizeD = 10;
	Poly* D = new Poly[sizeD];
	*mulLen = 0;

	for (int i = 0; A[i].exp != -1; i++) {
		Poly* Ci = single_Mul(A[i], B, bLen);
		printf("single_mul - C%d(x)\n", i + 1);
		printPoly(Ci, bLen+1);

		int tempLen = 0;
		Poly* temp = pAdd(D, Ci, &tempLen);
		delete[] D;
		D = temp;
		*mulLen = tempLen;
		delete[] Ci;
	}
	return D;
}

int main() {
	int Asz = 10;
	int Bsz = 10;
	
	Poly* A = new Poly[Asz];
	Poly* B = new Poly[Bsz]; //둘다 초기 크기를 할당
	Poly* Add; //선언만, 얘를 덧셈결과용
	Poly* Mul; //얘를 곱셈결과용
	Poly* Del; //얘를 뺄셈결과용
	Poly* Div; //얘를 나눗셈결과용

	printf("==========3.1 다항식 생성==========\n");
	printf("주의 : 지수는 내림차순으로 입력하여야 합니다.\n");

	printf("A(x)에 대한\n");
	int Alen = polyGenerator(A, &Asz); //A에 대한 다항식 생성, A의 다항식 마지막 index 반환(Alen)

	printf("\nA(x) =\n");
	printPoly(A, Alen); //다항식 출력

	printf("B(x)에 대한\n");
	int Blen = polyGenerator(B, &Bsz); //B에 대한 다항식 생성, B의 다항식 마지막 index 반환(Blen)

	printf("\nB(x) =\n");
	printPoly(B, Blen);

	int addLen = 0; //다항식의 길이
	printf("\n==========3.2 다항식 덧셈==========\n");
	printf("다항식 덧셈 결과 : D(x) = \n");
	Add = pAdd(A, B, &addLen); //Dlen은 참조형으로 나중에 값이 변경됨
	printPoly(Add, addLen);

	printf("\n==========3.3 다항식 곱셈==========\n");
	int mulLen = 0; //D의 길이를 동기화하기 위함
	Mul = pMul(A, B, Alen, Blen, &mulLen); //새로 초기화
	printf("다항식 곱셈 결과 : D(x) = \n");
	printPoly(Mul, mulLen);

}