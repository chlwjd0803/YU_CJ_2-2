#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void prtLst(int** arr, int n) {
	printf("\t");
	for (int i = 0; i < n; i++) printf("[%d]\t", i);
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("[%d] ", i);
		for (int j = 0; j < n; j++) {
			printf("%8d", arr[i][j]);
		}
		printf("\n");
	}
}

int choose(int distance[], int n, bool found[]) {
	int min, minpos;

	min = INT_MAX; //일단 정수형 최대값으로 초기화
	minpos = -1; //일단 -1로 초기화
	for (int i = 0; i < n; i++) if (distance[i] < min && !found[i]) {
		//거리가 최소값보다 작고 찾은 경로가 아니라면
		min = distance[i]; //최소값을 최신화
		minpos = i; //최소값의 인덱스를 최신화
	}
	return minpos;
}

void srtPath(int v, int** arr, int n, int** dst) {
	int* distance = new int[n];
	bool* found = new bool[n];

	int u, w;
	for (int i = 0; i < n; i++) {
		found[i] = false; //먼저 찾았다는 표시를 false로 초기화
		distance[i] = arr[v][i]; //거리를 일단 다 옮김
	}
	found[v] = true; //같은 노드는 이미 찾은 것이므로
	distance[v] = 0; //같은 노드는 거리가 없으므로

	for (int i = 0; i < n - 2; i++) {
		u = choose(distance, n, found); //찾는 함수 이용
		found[u] = true; //길을 찾았으므로 true

		//비교를 하여 바로가는 거리보다 경유한 거리가 작은경우에
		//거리를 변경하여 저장한다.
		for (w = 0; w < n; w++) if (!found[w]) if (distance[u] + arr[u][w] < distance[w])
			distance[w] = distance[u] + arr[u][w]; 
	}

	for (int i = 0; i < n; i++) { //경로 배열에 바로 저장해주는 작업
		dst[v][i] = distance[i];
	}

	delete[] distance; //메모리 해제
	delete[] found;
}



int main() {
	/* //예시의 첫번째 입력을 한번에 받고 싶다면 아래 정보를 이용
	int strc[12][3] =
	{ {0,1,50},
		{0,2,45},
		{0,3,10},
		{1,2,10},
		{1,3,15},
		{2,4,30},
		{3,0,20},
		{3,4,15},
		{4,1,20},
		{4,2,35},
		{5,4,3},
		{-1,-1,-1}
	};
	*/

	printf("11.1 인접 행렬 형태의 방향성 그래프 생성\n");
	int n;
	printf("노드 수(n) : ");
	scanf("%d", &n);

	int** ajl = new int* [n];
	

	for (int i = 0; i < n; i++) ajl[i] = new int[n]; //동적 할당을 통한 2차원 배열을 생성함
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (i == j) ajl[i][j] = 0; //같은경우는 거리가 0이므로
		else ajl[i][j] = 99999; //일단 무한대로 초기화, 무한대 표현은 99999
	}

	int u, v, d;
	
	//직접입력
	while (true) {
		printf("엣지 정보(from to weight) : ");
		scanf("%d %d %d", &u, &v, &d);
		if (u == -1 || v == -1 || d == -1) break;
		ajl[u][v] = d;
	}
	
	/* //만들어 둔 엣지정보 배열을 이용한 입력
	printf("실험용으로 엣지정보를 읽어옵니다.\n");
	for (int i = 0; i < 11; i++) {
		u = strc[i][0];
		v = strc[i][1];
		d = strc[i][2];
		ajl[u][v] = d;
	}
	*/

	printf("\n\n인접 행렬을 이용한 그래프의 구성 : \n");
	prtLst(ajl, n);

	//11.2 11.3을 위해 최단경로를 모두 저장해놓음
	int** allSrt = new int* [n];
	for (int i = 0; i < n; i++) allSrt[i] = new int[n]; //동적 할당을 통한 2차원 배열을 생성함
	for (int i = 0; i < n; i++) {
		srtPath(i, ajl, n, allSrt);
	}


	printf("\n\n11.2 최단경로 (단일 출발점)");
	while (true) {
		printf("\n시작 노드(v) : ");
		scanf("%d", &v);
		if (v == -1) break;
		for (int i = 0; i < n; i++) printf(" %d", allSrt[v][i]);
		
	}


	printf("\n\n11.3 최단경로 (모든경로)\n");
	printf("All Path Distance :\n");
	prtLst(allSrt, n);

	return 0;
}