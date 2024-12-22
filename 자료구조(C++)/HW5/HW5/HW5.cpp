#include <stdio.h>
#include <iostream> //c++ 동적할당 이용
#include <time.h> //CLOCK_PER_SEC의 값을 변경하지 못하여 소수점은 셋째자리까지만 표시하였음
using namespace std;


//모든 정렬 코드는 자료구조실습 12번 코드 인용하였음
//무작위로 생성되어있는 배열을 정렬(즉 최악의 상황은 아님)
void SWAP(int* ls1, int* ls2) {
    int temp = *ls1;
    *ls1 = *ls2;
    *ls2 = temp;
}

double slec(int arr[], int size) {
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
    double clk = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%.3lf    ", clk);

    delete[] copy;

    return clk;
}

double inst(int arr[], int size) {
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
    double clk = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%.3lf    ", clk);

    delete[] copy;

    return clk;
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

double start_Quik(int arr[], int size) {
    int* copy = new int[size];
    for (int i = 0; i < size; i++) copy[i] = arr[i];

    clock_t start = clock();
    quik(copy, 0, size - 1); //본 퀵정렬 진입(순환함수 사용에 따라 시간측정을 위해서)
    clock_t end = clock();
    double clk = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%.3lf    ", clk);

    delete[] copy;

    return clk;
}

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int temp[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

double start_Merge(int arr[], int size) {
    int* copy = new int[size];
    int* temp = new int[size];
    for (int i = 0; i < size; i++) copy[i] = arr[i];

    clock_t start = clock();
    mergeSort(copy, temp, 0, size - 1);
    clock_t end = clock();
    double clk = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%.3lf    ", clk);

    delete[] copy;
    delete[] temp;

    return clk;
}

void heapify(int arr[], int n, int i) {
    int parent = i; //힙의 성질을 이용한 변수들
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[parent]) parent = left;
    if (right < n && arr[right] > arr[parent]) parent = right;

    if (parent != i) {
        SWAP(&arr[i], &arr[parent]);
        heapify(arr, n, parent);
    }
}

void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    for (int i = size - 1; i > 0; i--) {
        SWAP(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

double start_Heap(int arr[], int size) {
    int* copy = new int[size];
    for (int i = 0; i < size; i++) copy[i] = arr[i];

    clock_t start = clock();
    heapSort(copy, size);
    clock_t end = clock();
    double clk = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%.3lf    ", clk);

    delete[] copy;

    return clk;
}

int main() {
    srand(time(NULL)); //중복되지 않는 난수 설정
    int size;
    int num;
    
    cout << "배열의 원소 수를 입력(size > 0) : ";
    cin >> size;
    cout << "작업을 반복 할 횟수 입력(0 <= num <= 20) : ";
    cin >> num;
        
    if (size < 0 || num < 0 || num > 20) return -1;

    cout << endl << size << "개의 데이터를 " << num << "번 정렬 시행" << endl;
    cout << "선택     삽입     퀵       합병     힙" << endl;

    double sumS = 0; double sumI = 0; double sumQ = 0; double sumM = 0; double sumH = 0;
    for (int k = 0; k < num; k++) {
        int* arr = new int[size]; //동적할당
        for (int i = 0; i < size; i++) arr[i] = ((rand() * RAND_MAX) + rand()) % 100000000;
        sumS += slec(arr, size); //선택정렬 진입
        sumI += inst(arr, size); //삽입정렬 진입
        sumQ += start_Quik(arr, size); //사전 퀵정렬 진입
        sumM += start_Merge(arr, size); //사전 합병정렬 진입
        sumH += start_Heap(arr, size); //사전 힙정렬 진입
        cout << endl;
        delete[] arr; //동적할당 해제
    }

    cout << endl << num << "번 시행에 대한 각 정렬의 평균시간" << endl;
    cout << "선택     삽입     퀵       합병     힙" << endl;
    cout << sumS / num << "   " << sumI / num << "   " << sumQ / num << "   " << sumM / num << "   " << sumH / num << endl;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = i + 1; //오름차순
    cout << "\n오름차순에서의 정렬" << endl;
    cout << "선택     삽입     퀵       합병     힙" << endl;
    slec(arr, size);
    inst(arr, size);
    start_Quik(arr, size);
    start_Merge(arr, size);
    start_Heap(arr, size);
    delete[] arr; //동적할당 해제

    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = size - i;
    cout << "\n\n내림차순에서의 정렬" << endl;
    cout << "선택     삽입     퀵       합병     힙" << endl;
    slec(arr, size);
    inst(arr, size);
    start_Quik(arr, size);
    start_Merge(arr, size);
    start_Heap(arr, size);
    delete[] arr; //동적할당 해제
}