#include <stdio.h>
#include <iostream> //C++ 동적할당 사용을 위한 헤더
#include <time.h> //시간측정을 위한 헤더

//역순배열을 통한 최악의상황에서 시간을 측정하므로 랜덤함수는 이용하지않음

void sort(int list[], int n) { //선택정렬 함수
    for (int i = 0; i < n - 1; i++) for (int j = i + 1; j < n; j++) {
        if (list[i] > list[j]) {
            int temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }
}

void rev_srt(int list[], int n) {
    for (int i = 0; i < n - 1; i++) for (int j = i + 1; j < n; j++) {
        if (list[i] > list[j]) {
            int temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }
}

int main() {
    int size_arr[37] = { 100,200,300,400,500,600,700,800,900,1000,2000,3000,4000,5000,6000,7000,8000,9000,
                        10000,20000,30000,40000,50000,60000,70000,80000,90000,100000,200000,300000,400000,500000,600000,
                        700000, 800000, 900000, 1000000 }; //문제 1-2 주어진 자료의 크기들
    int size = 0; //비교해야할 크기들 종류의 개수
    while (size != 37) {

        int n = size_arr[size]; //n으로 간략화
        int* arr = new int[n]; //c++식 동적할당

        for (int i = 0; i < n; i++) arr[i] = n - i; //최악의 상황(배열이 아예 역순일때)을 만들어주기 위한 반복문

        clock_t start = clock();
        sort(arr, n); //선택정렬 함수 진입
        clock_t end = clock();
        printf("자료가 %d개일때 소요시간 %lf\n", n, (double)(end - start) / CLOCKS_PER_SEC);

        delete[] arr; //할당해제
        size++;
    }
    return 0;
}