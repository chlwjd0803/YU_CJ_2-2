#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct { //다항식 구조체
	float coef; //계수
	int exp; //차수
} poly;

poly* extend(poly* p, int* size) {
	*size += 10;
	return (poly*)realloc(p, (*size) * sizeof(poly)); //가득차면 배열용량증가
}

void printPoly(poly* pl, int index) { //다항식 출력
	printf("    coef    exp\n");
	for (int i = 0; i < index; i++) printf("    %4.2f%6d\n", pl[i].coef, pl[i].exp);
	printf("\n");
}

int COMPARE(int a, int b) { //비교 함수
	if (a < b) return -1;
	else if (a == b) return 0;
	else return 1;
}

int polyGenerator(poly* p, int* size) { //HW3.1
	int i = 0;
	int psize = *size; //일단 지역변수로 옮김
	do {
		printf("항을 입력하시오(coef exp)(exp가 -1이면 끝표시) : ");
		scanf("%f %d", &p[i].coef, &p[i].exp);
		if (i - 1 == psize) p = extend(p, &psize); //다른함수와 형태롤 통일하여 이중포인터를 쓰지않기 위함
	} while (p[i++].exp >= 0);
	*size = psize; //다시 인수로 옮김
	return --i; //다항식의 배열 길이를 반환
}

poly* padd(poly* A, poly* B, int* Dlen) {
	int startA = 0, startB = 0, startD = 0;
	int sizeD = 10; //초기사이즈 10
	poly* D = (poly*)malloc(sizeD * sizeof(poly));

	while ((A[startA].exp != -1) || (B[startB].exp != -1)) {
		if (startD == sizeD) D = extend(D, &sizeD);
		switch (COMPARE(A[startA].exp, B[startB].exp)) {
		case -1: { //a<b
			D[startD].coef = B[startB].coef;
			D[startD++].exp = B[startB++].exp;
			break;
		}
		case 0: { //a=b
			if (A[startA].coef + B[startB].coef) { //0이 아니면
				D[startD].coef = A[startA].coef + B[startB].coef;
				D[startD++].exp = A[startA].exp;
			}
			startA++, startB++;
			break;
		}
		case 1: { //a>b
			D[startD].coef = A[startA].coef;
			D[startD++].exp = A[startA++].exp; //후위 연산자 이용하여 위치 증가
			break;
		}
		}
	}
	// A와 B의 남은 항 처리, 이미 위에서 둘중 하나는 다 비웠으므로
	D[startD].exp = -1;
	*Dlen = startD + 1;  //startD가 가르키는 위치만큼 다항식의 길이가 정해지므로
	return D;
}

poly* pSub(poly* A, poly* B, int* Dlen) {
	int startA = 0, startB = 0, startD = 0;
	int sizeD = 10; //초기사이즈 10
	poly* D = (poly*)malloc(sizeD * sizeof(poly));

	while ((A[startA].exp != -1) || (B[startB].exp != -1)) {
		if (startD == sizeD) D = extend(D, &sizeD);
		switch (COMPARE(A[startA].exp, B[startB].exp)) {
		case -1: { //a<b
			D[startD].coef = -B[startB].coef;
			D[startD++].exp = B[startB++].exp;
			break;
		}
		case 0: { //a=b
			if (A[startA].coef - B[startB].coef) { //0이 아니면
				D[startD].coef = A[startA].coef - B[startB].coef;
				D[startD++].exp = A[startA].exp;
			}
			startA++, startB++;
			break;
		}
		case 1: { //a>b
			D[startD].coef = A[startA].coef;
			D[startD++].exp = A[startA++].exp; //후위 연산자 이용하여 위치 증가
			break;
		}
		}
	}

	*Dlen = startD; //startD가 가르키는 위치만큼 다항식의 길이가 정해지므로
	return D;
}

poly* single_mul(poly Ai, poly* B, int Blen) { //HW3.3
	poly* C = (poly*)malloc(Blen * sizeof(poly));
	for (int i = 0; i < Blen; i++) {
		C[i].coef = Ai.coef * B[i].coef; //계수는 곱하고
		C[i].exp = Ai.exp + B[i].exp; //차수는 더한다
	}
	return C;
}

poly* pmul(poly* A, poly* B, int Alen, int Blen, int* Dlen) {
	int sizeD = 10; // 초기 사이즈
	poly* D = (poly*)malloc(sizeD * sizeof(poly)); // 곱셈 결과 다항식
	*Dlen = 0; // 다항식 길이 초기화

	for (int i = 0; i < Alen; i++) {
		poly* Ci = single_mul(A[i], B, Blen); // A[i]와 B의 곱
		printf("single_mul - C%d(x)\n", i + 1);
		printPoly(Ci, Blen); //Ci는 Blen만큼의 다항식 길이를 갖는다.

		int tempDlen = 0;
		poly* tempD = padd(D, Ci, &tempDlen); // D와 Ci의 덧셈
		free(D); // 이전의 D 메모리 해제
		D = tempD; // 옮겨주기
		*Dlen = tempDlen; // 다항식 길이 업데이트
		free(Ci); // Ci 메모리 해제
	}
	return D;
}

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

	int Dlen = 0; //다항식의 길이
	
	printf("\n========== 다항식 덧셈 ==========\n");
	printf("다항식 덧셈 결과 : D(x) = \n");
	D = padd(A, B, &Dlen); //Dlen은 참조형으로 나중에 값이 변경됨
	printPoly(D, Dlen); //길이 조정
	
	/*
	printf("\n========== 다항식 뺄셈 ==========\n");
	printf("다항식 덧셈 결과 : D(x) = \n");
	D = pSub(A, B, Alen, Blen, &Dlen); //Dlen은 참조형으로 나중에 값이 변경됨
	printPoly(D, Dlen - 1); //길이 조정
	*/

	
	printf("\n========== 다항식 곱셈 ==========\n");
	Dlen = 0; //D의 길이를 동기화하기 위함
	D = pmul(A, B, Alen, Blen, &Dlen); //새로 초기화
	printf("다항식 곱셈 결과 : D(x) = \n");
	printPoly(D, Dlen);
	


	free(A);
	free(B);
	free(D);
}