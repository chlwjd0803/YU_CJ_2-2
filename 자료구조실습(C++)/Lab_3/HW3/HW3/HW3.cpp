#define _CRT_SECURE_NO_WARNINGS
#include "HW3.h" //해당 헤더에 모두 포함되어있음

int main() {
	poly* A, * B, * D;
	int Asz = 10, Bsz = 10; //배열의 초기 크기
	A = (poly*)malloc(Asz * sizeof(poly));
	B = (poly*)malloc(Bsz * sizeof(poly));

	//HW3.1 시작
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
	//HW3.1 끝

	//HW3.2 시작
	int Dlen = 0; //다항식의 길이
	printf("\n==========3.2 다항식 덧셈==========\n");
	printf("다항식 덧셈 결과 : D(x) = \n");
	D = padd(A, B, Alen, Blen, &Dlen); //Dlen은 참조형으로 나중에 값이 변경됨
	printPoly(D, Dlen-1); //길이 조정
	//HW3.2 끝

	//HW3.3 시작
	printf("\n==========3.3 다항식 곱셈==========\n");
	Dlen = 0; //D의 길이를 동기화하기 위함
	D = pmul(A, B, Alen, Blen, &Dlen); //새로 초기화
	printf("다항식 곱셈 결과 : D(x) = \n");
	printPoly(D, Dlen);

	//HW3.3 끝

	free(A);
	free(B);
	free(D);
}