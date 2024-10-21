#include <stdio.h>
#include <iostream> //c++ 동적할당 이용
#include <time.h>
using namespace std;

//무작위로 생성되어있는 배열을 정렬(즉 최악의 상황은 아님)
void SWAP(int* ls1, int* ls2) {
    int temp = *ls1;
    *ls1 = *ls2;
    *ls2 = temp;
}

void slec(int arr[], int size) {
    int* copy = new int[size];
    for (int i = 0; i < size; i++) copy[i] = arr[i];

    clock_t start = clock();
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i; // 현재 위치를 최솟값의 인덱스로 초기화
        for (int j = i + 1; j < size; j++) {
            if (copy[j] < copy[minIndex]) {
                minIndex = j; // 최솟값의 인덱스를 업데이트
            }
        }
        // 최솟값을 현재 위치와 교환
        if (minIndex != i) {
            int temp = copy[i];
            copy[i] = copy[minIndex];
            copy[minIndex] = temp;
        }
    }
    clock_t end = clock();
    printf("선택정렬 시간 : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    delete[] copy;
}

void inst(int arr[], int size) {
    int temp, i;
    int* copy = new int[size];
    for (int i = 0; i < size; i++) copy[i] = arr[i];

    clock_t start = clock();
    for (int j = 1; j < size; j++) {
        temp = copy[j];
        i = j;
        while (i > 0 && copy[i - 1] >= temp) {
            copy[i] = copy[i - 1];
            i--;
        }
        copy[i] = temp;
    }
    clock_t end = clock();
    printf("삽입정렬 시간 : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    delete[] copy;
}

void quik(int arr[], int left, int right) { //교본코드 인용
    int pivot, i, j;
    if (left < right) {
        i = left, j = right + 1;
        pivot = arr[left];

        do {
            do i++; while (arr[i] < pivot);
            do j--; while (arr[j] > pivot);
            if (i < j) SWAP(&arr[i], &arr[j]); //참조형(주소전달)
        } while (i < j);

        SWAP(&arr[left], &arr[j]);
        quik(arr, left, j - 1);
        quik(arr, j + 1, right);
    }
}

void start_Quik(int arr[], int size) {
    int* copy = new int[size];
    for (int i = 0; i < size; i++) copy[i] = arr[i];

    clock_t start = clock();
    quik(copy, 0, size - 1); //본 퀵정렬 진입(순환함수 사용에 따라 시간측정을 위해서)
    clock_t end = clock();
    printf("퀵정렬 시간 : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    delete[] copy;
}

int main() {
    srand(time(NULL)); //중복되지 않는 난수 설정
    int size;

    while (true) {
        cout << "배열의 원소 수를 입력하세요(0이하의 정수일경우 종료) : ";
        cin >> size;
        if (size < 1) break;

        int* arr = new int[size]; //동적할당

        //난수생성
        for (int i = 0; i < size; i++) arr[i] = (rand() / (0x7fff) * 1.0) * 100000000;
        slec(arr, size); //선택정렬 진입
        inst(arr, size); //삽입정렬 진입
        start_Quik(arr, size); //사전 퀵정렬 진입
        delete[] arr; //동적할당 해제
    }
}