#include <stdio.h>
#include <stdlib.h> //랜덤함수를 위한 헤더

void sort(int list[], int n) { //선택정렬 함수
    for (int i = 0; i < n - 1; i++) for (int j = i + 1; j < n; j++) {
        if (list[i] > list[j]) {
            int temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }
}

int is_sorted(int list[], int n) {
    int flag = 1;
    for (int i = 0; i < n - 1; i++) if (list[i] > list[i + 1]) flag = 0;
    return flag;
}

/* 출력을 보고싶을때 주석해제
void print(int list[], int n){ //출력함수(임시)
    for(int i=0; i<20; i++){
        printf("%7d", list[i]);
        if(i==9) printf("\n");
    }
    printf("\n...........................\n");
    for(int i=n-20; i<n; i++){
        printf("%7d", list[i]);
        if(i==n-11) printf("\n");
    }
    printf("\n\n");
}
*/

int main() {
    int size = 100000;
    int arr[100000];

    printf("정렬 여부를 확인하겠습니다.(몇 초 소요됨)\n");
    for (int i = 0; i < size; i++) arr[i] = ((rand() * RAND_MAX) + rand()) % size + 1;
    sort(arr, size);
    int flag = is_sorted(arr, size);

    if (flag == 1) printf("정렬되어있음\n");
    else printf("정렬되어있지않음\n");

    return 0;
}