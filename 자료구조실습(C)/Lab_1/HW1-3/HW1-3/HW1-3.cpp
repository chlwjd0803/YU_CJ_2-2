#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //랜덤정수 생성을 위한 헤더
#include <time.h>

void sort(int list[], int n) { //선택정렬 함수
    for (int i = 0; i < n - 1; i++) for (int j = i + 1; j < n; j++) {
        if (list[i] > list[j]) {
            int temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }
}

int binsearch(int list[], int data, int size) {
    int left = 0;
    int right = size;
    int mid = size / 2;
    int count = 0;
    int flag = 0;

    while (left <= right) {
        if (data > mid) {
            left = mid + 1;
            mid = (left + right) / 2;
        }
        else if (data < mid) {
            right = mid - 1;
            mid = (left + right) / 2;
        }
        else {
            printf("찾았습니다.\n mid=%d, data=%d\n", mid, data);
            flag = 1;
        }
        count++;
        if (flag == 1) break; //찾을경우 반복문을 나가야하므로
    }
    if (flag == 0) printf("찾지 못하였습니다.");
    return count;
}


int main() {
    //srand(time(0)); //매번 다른 수가 나오게 하고 싶은경우 주석해제
    int arr[100000];
    int size = 100000;
    int data;

    printf("정렬중입니다..\n");
    for (int i = 0; i < size; i++) arr[i] = ((rand() * RAND_MAX) + rand()) % 100000 + 1;
    sort(arr, size); //선택정렬 함수 진입

    while (true) {
        printf("검색할 데이터를 입력하세요(1~100000)(0이하값종료) : ");
        scanf("%d", &data);
        if (data <= 0) break;

        int count = binsearch(arr, data, size);
        printf("count = %d\n\n", count);
    }

    return 0;
}