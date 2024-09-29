#include <stdio.h>
#include <iostream> //c++ 동적할당 이용
#include <time.h>
using namespace std;
//HW12-2 최악의 상황에서의 정렬 (오름차순 및 내림차순)

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

void quik(int arr[], int left, int right) { //12-1 코드에서 조금 수정
    if (left < right) {
        // 피벗을 첫 번째, 중간, 마지막 중 중간값으로 설정
        int mid = (left + right) / 2;
        if (arr[left] > arr[mid]) SWAP(&arr[left], &arr[mid]);
        if (arr[left] > arr[right]) SWAP(&arr[left], &arr[right]);
        if (arr[mid] > arr[right]) SWAP(&arr[mid], &arr[right]);

        int pivot = arr[mid];  // 중간값을 피벗으로 설정
        SWAP(&arr[mid], &arr[left]);  // 중간값을 맨 앞과 교체

        int i = left, j = right;
        while (i < j) {
            while (i <= right && arr[i] <= pivot) i++;  // 피벗보다 큰 값 찾기
            while (j >= left && arr[j] > pivot) j--;    // 피벗보다 작은 값 찾기
            if (i < j) SWAP(&arr[i], &arr[j]);
        }

        SWAP(&arr[left], &arr[j]);  // 피벗을 정확한 위치로 이동

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
    int size;
    int flag; //오름차순 내림차순 선택

    while (true) {
        cout << "배열의 원소 수를 입력하세요(0이하의 정수일경우 종료) : ";
        cin >> size;
        if (size < 1) break;

        int* arr = new int[size]; //동적할당

        cout << "1.오름차순 / 2.내림차순 : ";
        cin >> flag;

        //오름차순
        if (flag == 1) for (int i = 0; i < size; i++) arr[i] = i + 1;
        //내림차순
        else if (flag == 2) for (int i = 0; i < size; i++) arr[i] = size - i;
        else {
            cout << "잘못된 입력입니다. 처음부터 다시 시도하세요" << endl;
            delete[] arr; //동적할당 해제
            continue;
        }

        slec(arr, size); //선택정렬 진입
        inst(arr, size); //삽입정렬 진입
        start_Quik(arr, size); //사전 퀵정렬 진입
        delete[] arr; //동적할당 해제
    }
}