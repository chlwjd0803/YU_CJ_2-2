#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void prt_arr(int arr[], int size) { //배열정보 출력 함수
	for (int i = 0; i < size; i++) printf("%d / ", arr[i]);
	printf("\n");
}

int main() {
	int a[100]; //원소의 수는 100개
	int row_terms[101] = { 0, }; //0~100범위이므로 총 101개, 각 원소의 개수를 저장하는 배열
	int starting_pos[101] = { 0, }; //위와같이 총 101개, 시작위치를 저장하는 배열
	int sorted[100]; //원소의 수는 100개
	int size = 100; //a배열 기준

	for (int i = 0; i < size; i++) a[i] = rand() % size; //0~100 정수 랜덤할당(중복허용)
	
	for (int i = 0; i < size; i++) row_terms[a[i]]++; //원소의 개수를 세는 반복문

	int pos = 0;
	for (int i = 0; i < size+1; i++) { //starting_pos 위치 계산 반복문
		starting_pos[i] = pos; //먼저 위치지정하고
		pos += row_terms[i]; //위치를 row_terms만큼 증가
	}

	for (int i = 0; i < size; i++) sorted[starting_pos[a[i]]++] = a[i]; //a엫서 읽어온 수를 위치에 맞게 저장 후 후위연산자 이용하여 위치증가

	printf("a = \n"); prt_arr(a, size);
	printf("\nrow_terms = \n"); prt_arr(row_terms, size+1);
	printf("\nstarting_pos = \n"); prt_arr(starting_pos, size+1);
	printf("\nsorted = \n"); prt_arr(sorted, size);
}