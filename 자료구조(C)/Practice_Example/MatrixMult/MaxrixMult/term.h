#pragma once //ifndef-endif의 알수없는 오류로 pragma once 사용

#define _CRT_SECURE_NO_WARNINGS //비주얼 스튜디오 2022 정책으로 scanf사용이 제한되어 선언
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COL 50
#define MAX_TERMS 101 //define정의 형태 알아놓기
#define COMPARE(x, y) ((x<y)? -1 : (x==y) ? 0 : 1) //compare 한줄로 만드는 형태


typedef struct term {
	int row;
	int col;
	int value;
} term;


typedef enum shape { SPARSE, MATRIX } printShape; //교수님 코드 인용

void printMatrix(term t[], printShape shape, const char* title){ //교수님 코드 인용
	int n = t[0].value;
	int i, len;

	const char* line = "---------------";
	char tLine[32];

	len = strlen(line);
	sprintf(tLine, "%s: %s", title, line);

	if (shape == SPARSE)
	{
		printf("%.*s\n", len, tLine);
		for (i = 0; i <= n; i++)
			printf("%2d | %d, %d, %d\n", i, t[i].row, t[i].col, t[i].value);
		printf("%s\n", line);
	}
	else if (shape == MATRIX)
	{
		int j, p = 1;
		printf("%s:\n", title);
		for (i = 0; i < t[0].row; i++)
		{
			for (j = 0; j < t[0].col; j++)
				if (t[p].row == i && t[p].col == j)
					printf("%4d", t[p++].value);
				else
					printf("%4d", 0);
			printf("\n");
		}
		printf("\n");
	}
}

void fast_transpose(term a[], term b[]) { //빠른전치에 대한 해설 추가
	//a를 b로 전치
	int row_terms[MAX_COL], starting_pos[MAX_COL];
	//rt = 해당 행이 몇번 출현한지, sp = rt에 따른 행별 시작지점

	int i, j, num_cols = a[0].col, num_terms = a[0].value;
	//num_cols : a의 열 개수(b에서 행으로 작용), num_terms : 0이 아닌 행렬원소의 개수

	b[0].row = num_cols; //a의 열이 b의 행이된다
	b[0].value = num_terms; //0이 아닌 행렬원소의 개수는 같으므로 그대로 대입

	if (num_terms > 0) { //0이 아닌 원소가 하나이상 존재한다면
		for (i = 0; i < num_cols; i++) row_terms[i] = 0; //rt를 0으로 초기화(나중에 찾아내면서 1씩 더할 예정이기에)

		for (i = 1; i <= num_terms; i++) row_terms[a[i].col]++; //a의 열의 값으로 rt의 index에 대해 1 증가
		//a는 1번째부터 정보가 담겨있으므로, rt의 인덱스 위치가 곧 그 열(b에선 행)이 출현한 횟수

		starting_pos[0] = 1; //전치할 b의 0번째 칸에는 행렬의 크기와 0이아닌 원소의 개수가 저장된다.

		for (i = 1; i < num_cols; i++) starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
		//현재위치는 이전위치값에서 이전 행의 출현 횟수만큼 더한값이다.

		for (i = 1; i < num_terms; i++) {
			j = starting_pos[a[i].col]++; //j에 현재위치 지점을 반환하고 sp[a[i]]는 후위연산을 통해 증가한다.
			b[j].row = a[i].col; //행렬은 서로 전치되었으므로 교차로 주면 된다.
			b[j].col = a[i].row;
			b[j].value = a[i].value;
			//a는 처음부터 조사하지만 b는 st를 통해 정해진 위치에서 기록하게된다.
		}
	}
}

void storesum(term d[], int* totald, int row, int column, int* sum){
	if (*sum) //sum이 0이아니면 = 더할것이 있다면
		if (*totald < MAX_TERMS) //초과조건 확인 (중요X)
		{
			d[++*totald].row = row; //d의 다음 인덱스로 이동하여 연산
			d[*totald].col = column;
			d[*totald].value = *sum;
			*sum = 0; //더해준 후 sum은 0으로 초기화, 포인터변수 이므로 호출자에도 값전달됨
		}
		else
		{ //그냥 오류메시지와 함수종료
			fprintf(stderr, "Numbers of terms in product exceeds %d\n", MAX_TERMS);
			return;
		}
}


void mMult(term a[], term b[], term d[]) {
	int i, j, column, totald = 0; //totald = d에 들어갈 희소행렬의 크기 = 0이 아닌 원소의 개수
	int rows_a = a[0].row, cols_a = a[0].col, totala = a[0].value; //totala = 0이 아닌 원소의 개수 = 희소행렬의 크기
	int cols_b = b[0].col, totalb = b[0].value;
	int row_begin = 1, row = a[1].row, sum = 0; //마찬가지로 인덱스가 1인 곳부터 행의시작, row도 a의 시작점에 맞춤
	term newB[MAX_TERMS]; //희소행렬의 최대크기 지정

	if (cols_a != b[0].row) { //둘이 곱할수있는지 확인 a의 열과 b의 행의 크기가 반드시 같아야함
		fprintf(stderr, "Incompatible matricses for MMult\n");
		exit(0); //강제종료
	}

	fast_transpose(b, newB); //newB로 b의 빠른전치 실행, 프로그램 상의 연산이 편하도록 전치하는것

	a[totala + 1].row = rows_a; //a의 행 마지막 다음 부분에다가 a의 초기 행 저장
	newB[totalb + 1].row = cols_b; //newB 행의 마지막 다음 부분에다가 B의 열 저장, 전치되었기 때문 

	newB[totalb + 1].col = -1; //newB 열의 마지막 다음 부분에다가 -1초기화, 이 부분은 추가설명이 필요함

	for (i = 1; i <= totala; sum = 0) //sum을 계속해서 0으로 초기화시켜주어 오류방지
	{
		column = newB[1].row; //열에 newB의 첫번째(0은 기본정보가 담기므로 1)행을 저장
		for (j = 1; j <= totalb + 1; )
		{
			if (a[i].row != row) //a의 현재 행과 다르다면
			{
				storesum(d, &totald, row, column, &sum);
				//저장할 d행렬, d의 크기(점차 증가할 예정), 행, 렬, 합(모았던 sum을 저장하고 0으로 초기화 한것을 반영하기 위해 포인터 사용)
				i = row_begin; // 시작위치 초기화
				for (; newB[j].row == column; j++); // newB의 행의값이랑 column의 값이 달라질때까지 j증가
				column = newB[j].row; //달라지면 column 최신화
			}
			else if (newB[j].row != column) //newB의 현재 행과 열의 값이 다르다면
			{
				storesum(d, &totald, row, column, &sum);
				i = row_begin; // 시작위치 초기화
				column = newB[j].row; //이미 newB의 행과 column의 값이 다르므로 바로 최신화
			}
			else switch (COMPARE(a[i].col, newB[j].col))
			{
			case -1: // a의 다음행으로 이동함 <
				i++;
				break;
			case 0:
				// 곱하여 sum에 더하여 저장
				sum += (a[i++].value * newB[j++].value);
				break;
			case 1: // b의 다음행으로 이동함 >
				j++;
			}
		}
		for (; a[i].row == row; i++);
		row_begin = i;
		row = a[i].row;
	}
	d[0].row = rows_a;
	d[0].col = cols_b;
	d[0].value = totald; //마지막에 d[0]에 행의개수 열의개수 원소의개수를 저장
}
