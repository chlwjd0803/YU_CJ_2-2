#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //랜덤정수 생성을 위한 헤더
#include <time.h>


//1-3에서 역순배열지정으로 수정한 소스파일, 10만과 5만을 소스코드에 대입해서 실행
//문제의 조건에서 역순으로 정렬된 배열을 활용하여 둘의 성능을 counter값을 비교하므로 랜덤함수 사용하지않음


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
    int arr[50000]; //100000과 50000을 대입해서 프로그램 실행
    int size = 50000; //이하 같음
    int data;

    printf("정렬중...\n");
    for (int i = 0; i < size; i++) arr[i] = size - i; //최악의 상황(배열이 아예 역순일때)을 만들어주기 위한 반복문
    sort(arr, size); //선택정렬 함수 진입

    while (true) {
        printf("검색할 데이터를 입력하세요(1~%d)(0이하값 종료) : ", size);
        scanf("%d", &data);
        if (data <= 0) break;

        int count = binsearch(arr, data, size);
        printf("count = %d\n\n", count);
    }

    return 0;
}