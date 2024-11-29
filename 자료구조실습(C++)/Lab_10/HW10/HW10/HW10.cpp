#define _CRT_SECURE_NO_WARNINGS
#define FALSE 0
#define TRUE 1
#define MAX_VERTICES 100
#include <iostream>

using namespace std;

short int visited[MAX_VERTICES];


class Node {
public:
	int data;
	Node* link;

	Node(int data = 0) {
		this->data = data;
		link = NULL;
	}
};
Node** graph;

void insert(Node*& front, int val) {
	Node* temp = new Node(val);

	if (front) {
		temp->link = front;
	}
	front = temp;

}

int printList(int index, Node* temp) {
	int count = 0;
	printf("[%d] : ", index);
	for (temp; temp != NULL; temp = temp->link) {
		printf("%d -> ", temp->data);
		count++;
	}
	printf("end\n");
	return count;
}

void dfs(int v) {
	Node* w;
	visited[v] = TRUE;
	printf("%5d", v);
	for (w = graph[v]; w; w = w->link) {
		if (!visited[w->data]) dfs(w->data);
	}
}


int main() {
	
	printf("HW10.1 인접 리스트 형태의 무방향성 그래프 생성\n");
	printf("노드 개수 : ");
	int nodeNum;
	scanf("%d", &nodeNum);

	graph = new Node*[nodeNum];
	for (int i = 0; i < nodeNum; i++) {
		graph[i] = NULL; //일단 NULL로 모두 초기화
	}

	int vi, vj;
	while (true) {
		printf("엣지 정보(vi,vj) : ");
		scanf("%d %d", &vi, &vj);
		if (vi == -1 || vj == -1) break;
		insert(graph[vi], vj);
		insert(graph[vj], vi); //방향성이 없으므로 양쪽 다 이어줌
	}

	printf("인접 리스트를 이용하여 구성한 그래프\n");
	//리스트 출력부분
	int max = 0;
	int count;
	int max_idx;
	for (int i = 0; i < nodeNum; i++) {
		count = printList(i, graph[i]);
		if (count > max) {
			max = count;
			max_idx = i;
		}
	}

	printf("degree가 가장 큰 노드와 그 값 : ");
	printf("노드 %d, degree %d\n", max_idx, max);
	printf("노드 %d와 연결된 노드들 : ", max_idx);
	printList(max_idx, graph[max_idx]); //수정하셈

	printf("HW10.2 탐색알고리즘\n");
	//v는 시작노드
	for (int i = 0; i < nodeNum; i++) {
		printf("시작노드 %d : ", i);
		dfs(i);
		printf("\n");
	}




	return 0;
}