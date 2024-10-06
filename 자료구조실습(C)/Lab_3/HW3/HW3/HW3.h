#ifndef HW3_H
#define HW3_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct { //���׽� ����ü
	float coef; //���
	int exp; //����
} poly;

poly* extend(poly* p, int* size) {
	*size += 10;
	return (poly*)realloc(p, (*size) * sizeof(poly)); //�������� �迭�뷮����
}

void printPoly(poly* pl, int index) { //���׽� ���
	printf("    coef    exp\n");
	for (int i = 0; i < index; i++) printf("    %4.2f%6d\n", pl[i].coef, pl[i].exp);
	printf("\n");
}

int COMPARE(int a, int b) { //�� �Լ�
	if (a < b) return -1;
	else if (a == b) return 0;
	else return 1;
}

int polyGenerator(poly* p, int* size) { //HW3.1
	int i = 0;
	int psize = *size; //�ϴ� ���������� �ű�
	do {
		printf("���� �Է��Ͻÿ�(coef exp)(exp�� -1�̸� ��ǥ��) : ");
		scanf("%f %d", &p[i].coef, &p[i].exp);
		if (i - 1 == psize) p = extend(p, &psize); //�ٸ��Լ��� ���·� �����Ͽ� ���������͸� �����ʱ� ����
	} while (p[i++].exp >= 0);
	*size = psize; //�ٽ� �μ��� �ű�
	return --i; //���׽��� �迭 ���̸� ��ȯ
}

poly* padd(poly* A, poly* B, int endA, int endB, int* Dlen) {
	int startA = 0, startB = 0, startD = 0;
	int sizeD = 10; //�ʱ������ 10
	poly* D = (poly*)malloc(sizeD * sizeof(poly));

	while (startA <= endA && startB <= endB) {
		if (startD == sizeD) D = extend(D, &sizeD);
		switch (COMPARE(A[startA].exp, B[startB].exp)) {
		case -1: { //a<b
			D[startD].coef = B[startB].coef;
			D[startD++].exp = B[startB++].exp;
			break;
		}
		case 0: { //a=b
			if (A[startA].coef + B[startB].coef) { //0�� �ƴϸ�
				D[startD].coef = A[startA].coef + B[startB].coef;
				D[startD++].exp = A[startA].exp;
			}
			startA++, startB++;
			break;
		}
		case 1: { //a>b
			D[startD].coef = A[startA].coef;
			D[startD++].exp = A[startA++].exp; //���� ������ �̿��Ͽ� ��ġ ����
			break;
		}
		}
	}
	// A�� B�� ���� �� ó��, �̹� ������ ���� �ϳ��� �� ������Ƿ�
	while (startA <= endA) {
		if (startD == sizeD) D = extend(D, &sizeD);
		D[startD].coef = A[startA].coef;
		D[startD].exp = A[startA].exp;
		(startD)++;
		startA++;
	}

	while (startB <= endB) {
		if (startD == sizeD) D = extend(D, &sizeD);
		D[startD].coef = B[startB].coef;
		D[startD].exp = B[startB].exp;
		startD++;
		startB++;
	}
	*Dlen = startD; //startD�� ����Ű�� ��ġ��ŭ ���׽��� ���̰� �������Ƿ�
	return D;
}

poly* single_mul(poly Ai, poly* B, int Blen) { //HW3.3
	poly* C = (poly*)malloc(Blen * sizeof(poly));
	for (int i = 0; i < Blen; i++) {
		C[i].coef = Ai.coef * B[i].coef; //����� ���ϰ�
		C[i].exp = Ai.exp + B[i].exp; //������ ���Ѵ�
	}
	return C;
}

poly* pmul(poly* A, poly* B, int Alen, int Blen, int* Dlen) {
	int sizeD = 10; // �ʱ� ������
	poly* D = (poly*)malloc(sizeD * sizeof(poly)); // ���� ��� ���׽�
	*Dlen = 0; // ���׽� ���� �ʱ�ȭ

	for (int i = 0; i < Alen; i++) {
		poly* Ci = single_mul(A[i], B, Blen); // A[i]�� B�� ��
		printf("single_mul - C%d(x)\n", i + 1);
		printPoly(Ci, Blen); //Ci�� Blen��ŭ�� ���׽� ���̸� ���´�.
		int tempDlen = 0;
		poly* tempD = padd(D, Ci, *Dlen - 1, Blen - 1, &tempDlen); // D�� Ci�� ����
		free(D); // ������ D �޸� ����
		D = tempD; // �Ű��ֱ�
		*Dlen = tempDlen; // ���׽� ���� ������Ʈ
		free(Ci); // Ci �޸� ����
	}
	return D;
}

#endif