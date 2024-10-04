#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //C언어식 동적할당

typedef struct {
	float coef; //계수
	int exp; //차수
} poly;

void extend(poly *pl, int *size) { //참조에 의한 전달로 받기
	size += 10;
	pl = (poly*)realloc(pl, *size * sizeof(poly));
}

void printPoly(poly *pl, int index) {
	printf("    coef    exp\n");
	for (int i = 0; i < index; i++) printf("%4f%5d\n", pl[i].coef, pl[i].exp);
	printf("\n");
}

int COMPARE(int a, int b) {
	if (a < b) return -1;
	else if (a == b) return 0;
	else return 1;
}

void padd(poly* A, poly* B, poly* D, int endA, int endB, int* sizeD) {
	int startA = 0, startB = 0, startD = 0;//시작 인덱스는 0으로
	while (startA <= endA && startB <= endB) {
		if (startD == *sizeD) extend(D, sizeD); //D의 용량을 늘려줌
		switch (COMPARE(A[startA].exp, B[startB].exp)) {
			case -1: { //a<b
				D[startD].coef = B[startB].coef;
				D[startD++].exp = B[startB++].exp; //후위 연산자 이용하여 위치 증가
				break;
			}
			case 0: { //a=b
				if (A[startA].coef + B[startB].coef) { //계수가 0이 아닐때만
					D[startD].coef = A[startA].coef + B[startB++].coef; //계수의 합을 넣음
					D[startD++].exp = A[startA++].exp; //차수는 아무거나 넣어도됨, 후위연산자를 통해 모두의 위치 증가
				}
				break;
			}
			case 1: { //a>b
				D[startD].coef = A[startA].coef;
				D[startD++].exp = B[startA++].exp; //후위 연산자 이용하여 위치 증가
				break;
			}
		}
	}
}

int main() {
	poly* A, * B, * D;
	int Asz = 10, Bsz = 10, Dsz = 10; //배열의 초기 크기
	A = (poly*)malloc(Asz * sizeof(poly));
	B = (poly*)malloc(Bsz * sizeof(poly));
	D = (poly*)malloc(Dsz * sizeof(poly));
	
	printf("3.1다항식 생성\n");
	printf("주의 : 지수는 내림차순으로 입력하여야 합니다.\n");
	int Aindex = 0; //A의 인덱스 선언
	do{
		printf("A(x)의 항을 입력하시오(coef exp)(exp가 -1이면 끝표시) : ");
		scanf("%f %d", &A[Aindex].coef, &A[Aindex].exp);
		if (Aindex - 1 == Asz) extend(A, &Asz); //용량 초과임박시 배열증가
	} while (A[Aindex++].exp >= 0);
	Aindex--; //-1은 다항식의 끝으로 인식하므로 뺌

	printf("A(x) =\n");
	printPoly(A, Aindex);

	int Bindex = 0; //B의 인덱스 선언
	do {
		printf("B(x)의 항을 입력하시오(coef exp)(exp가 -1이면 끝표시) : ");
		scanf("%f %d", &B[Bindex].coef, &B[Bindex].exp);
		if (Bindex - 1 == Bsz) extend(B, &Bsz); //용량 초과임박시 배열증가

	} while (B[Bindex++].exp >= 0);
	Bindex--; //다항식의 끝을 제외

	padd(A, B, D, Aindex, Bindex, &Dsz); //D를 연산해줌
	printf("다항식 덧셈결과 D(x) =\n");
	printPoly(D, Dsz);

	free(A);
	free(B);
	free(D);

	return 0;
}