#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

void SWAP(int *ls1, int *ls2) {
	int temp = *ls1;
	*ls1 = *ls2;
	*ls2 = temp;
}


void perm(int* list, int i, int n) {
	int j;
	if (i == n) {
		for (j = 0; j < n; j++) printf("%d", list[j]);
		printf(" ");
	}
	else {
		for (j = i; j < n; j++) {
			SWAP(&list[i], &list[j]);
			perm(list, i + 1, n);
			SWAP(&list[i], &list[j]); //원상복구
		}
	}
}

int main(void) {
	int n;
	cout << "양의 정수를 입력해주세요 : ";
	cin >> n;

	int* arr = new int[n]; //c++식 동적할당
	for (int i = 0; i < n; i++) arr[i] = i + 1; //1부터n사이의 숫자들을 넣는 작업

	clock_t start = clock();
	perm(arr, 0, n);
	clock_t end = clock();
	printf("\n실행시간 : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	delete[] arr; //동적할당해제

}