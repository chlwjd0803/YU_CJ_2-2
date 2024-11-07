#define _CRT_SECURE_NO_WARNINGS
#include <iostream> //필요없으면 해제가능
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//22112155 최정

using namespace std;

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


poly* psub(poly* A, poly* B, int endA, int endB, int* Dlen) {
	int startA = 0, startB = 0, startD = 0;
	int sizeD = 10; //초기사이즈 10
	poly* D = (poly*)malloc(sizeD * sizeof(poly));

	while (startA <= endA && startB <= endB) {
		if (startD == sizeD) D = extend(D, &sizeD);
		switch (COMPARE(A[startA].exp, B[startB].exp)) {
		case -1: { //a<b
			D[startD].coef = -B[startB].coef; //계수만 음수로 만들어주면 된다
			D[startD++].exp = B[startB++].exp;
			break;
		}
		case 0: { //a=b
			if (A[startA].coef - B[startB].coef) { //0이 아니면
				D[startD].coef = A[startA].coef - B[startB].coef; //빼기연산 실행
				D[startD++].exp = A[startA].exp;
			}
			startA++, startB++;
			break;
		}
		case 1: { //a>b
			D[startD].coef = A[startA].coef; //A는 그냥 더하면 됨
			D[startD++].exp = A[startA++].exp; //후위 연산자 이용하여 위치 증가
			break;
		}
		}
	}
	// A와 B의 남은 항 처리, 이미 위에서 둘중 하나는 다 비웠으므로
	while (startA <= endA) {
		if (startD == sizeD) D = extend(D, &sizeD);
		D[startD].coef = A[startA].coef;
		D[startD].exp = A[startA].exp;
		(startD)++;
		startA++;
	}

	while (startB <= endB) {
		if (startD == sizeD) D = extend(D, &sizeD);
		D[startD].coef = -B[startB].coef; //역시 빼기로 구현
		D[startD].exp = B[startB].exp;
		startD++;
		startB++;
	}
	*Dlen = startD; //startD가 가르키는 위치만큼 다항식의 길이가 정해지므로
	return D;
}

double calc(poly* D, double x, int Dlen) {
	double res = 0.0;
	for (int i = 0; i < Dlen; i++) {
		res += (double)pow(x, D[i].exp) * D[i].coef;
		cout << "x = " << x << " exp = " << D[i].exp << " coef = " << D[i].coef << endl;
		cout << "res = " << res << endl;
	
	}
	return res;
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

	printf("B(x)에 대한\n");
	int Blen = polyGenerator(B, &Bsz); //B에 대한 다항식 생성, B의 다항식 마지막 index 반환(Blen)

	int Dlen = 0; //다항식의 길이
	printf("다항식 D : A-B\n");
	D = psub(A, B, Alen, Blen, &Dlen); //Dlen은 참조형으로 나중에 값이 변경됨
	printPoly(D, Dlen);

	double x;
	printf("\n\n다항식 D의 미지수(x) 값 입력하세요 : ");
	scanf("%lf", &x);
	printf("다항식 D 계산 결과 : %lf", calc(D, x, Dlen));

	free(A);
	free(B);
	free(D);
}