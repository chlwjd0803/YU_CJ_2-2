#define _CRT_SECURE_NO_WARNINGS
#define FALSE 0
#define TRUE 1
#define MAX_VERTICES 100
#include <iostream>

using namespace std;

short int visited[MAX_VERTICES]; //short int나 bool이나 같은 기능을 하기 위함
int parent[MAX_VERTICES]; //부모노드를 저장하는 곳, 신장트리 출력을 위해 선언

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
	printf("%4d", v);
	for (w = graph[v]; w; w = w->link) {
		if (!visited[w->data]) {
			parent[w->data] = v;
			dfs(w->data);
		}
	}
}

void bfs(int v) {
	Node* w;
	int queue[MAX_VERTICES];
	int front = -1;
	int rear = -1;

	printf("%4d", v);
	visited[v] = TRUE;
	queue[++rear] = v;
	while (front != rear) {
		v = queue[++front];
		for (w = graph[v]; w; w = w->link) {
			if (!visited[w->data]) {
				printf("%4d", w->data);
				queue[++rear] = w->data;
				visited[w->data] = TRUE;
				parent[w->data] = v;
			}
		}
	}
}

void printSpanningTree(int nodeNum) {
	for (int i = 0; i < nodeNum; ++i){ 
		if (parent[i] != -1){
			printf("(%d, %d) ", parent[i], i); 
		} 
	} 
	printf("\n");
}


int main() {

	//사전작업
	
	
	printf("HW10.1 인접 리스트 형태의 무방향성 그래프 생성\n");
	printf("노드 개수 : ");
	int nodeNum;
	scanf("%d", &nodeNum);

	graph = new Node*[nodeNum];
	for (int i = 0; i < nodeNum; i++) graph[i] = NULL; //일단 NULL로 모두 초기화
	for (int i = 0; i < MAX_VERTICES; i++) parent[i] = -1; //처음에 0이 읽히지 않게 제대로 초기화, HW10.3 전용

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

	printf("\ndegree가 가장 큰 노드와 그 값 : ");
	printf("노드 %d, degree %d\n", max_idx, max);
	printf("노드 %d와 연결된 노드들 : ", max_idx);
	printList(max_idx, graph[max_idx]);

	printf("\nHW10.2/10.3 탐색알고리즘과 신장트리\n");
	
	printf("깊이 우선 탐색 DFS\n");
	for (int i = 0; i < nodeNum; i+=2) {
		printf("\n시작노드 %d : ", i);
		dfs(i);
		printf("\nDFS 신장 트리 : ");
		printSpanningTree(nodeNum);
		for (int j = 0; j < MAX_VERTICES; j++) {
			visited[j] = FALSE; //방문기록 삭제
			parent[j] = -1; //부모노드 초기화
		}
	}
	printf("\n너비 우선 탐색 BFS\n");
	for (int i = 1; i < nodeNum; i += 2) {
		printf("\n시작노드 %d : ", i);
		bfs(i);
		printf("\nBFS 신장 트리 : ");
		printSpanningTree(nodeNum);
		for (int j = 0; j < MAX_VERTICES; j++) {
			visited[j] = FALSE; //방문기록 삭제
			parent[j] = -1; //부모노드 초기화
		}
	}

	//메모리 정리과정, 필수는 아님
	for (int i = 0; i < nodeNum; i++) {
		Node* temp = graph[i];
		while (temp) {
			Node* del = temp; 
			temp = temp->link; 
			delete del; 
		} 
	} 
	delete[] graph;

	return 0;
}