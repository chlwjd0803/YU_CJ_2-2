#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class element {
public:
	int key;
	double value;
};

class node { //트리를 이을 노드 클래스
public:
	element data;
	node* left;
	node* right;

	node(int key, double val) {
		this->data.key = key;
		this->data.value = val;
		left = nullptr;
		right = nullptr;
	}
};

void inorder(node* ptr) {
	if (ptr) {
		inorder(ptr->left);
		printf("(%d %lf)\n", ptr->data.key, ptr->data.value);
		inorder(ptr->right);
	}
}

int end;
int count = 0;

void npInorder(node* ptr) {
	if (ptr) {
		npInorder(ptr->left);
		::count++; //전역변수임을 컴파일러에게 알려줌
		if (::count < 3 || ::count >(::end - 3)) printf("(%d %lf)\n", ptr->data.key, ptr->data.value);
		if (::count == 3) printf("////생략/////\n");
		npInorder(ptr->right);
	}
}

element* search(node* tree, int key) {
	int count = 0;

	while (tree) {
		count++;
		if (key == tree->data.key) {
			printf("count : %d, ", count); //0이상이면 출력
			return &(tree->data);
		}
		if (key < tree->data.key) tree = tree->left;
		else tree = tree->right;
	}
	return NULL;
}

node* modified_search(node* root, int key) {
	node* tree = root;
	node* parent = NULL; //부모노드를 저장하기위해 선언

	while (tree) {
		if (key == tree->data.key) {
			return NULL;
		}
		parent = tree; //부모 노드를 저장해놓음
		if (key < tree->data.key) {
			tree = tree->left;
		}
		else {
			tree = tree->right;
		}
	}
	return parent; //못찾은 마지막 위치 반환
}

bool insert(node*& root, int key) { //참조전달(이중포인터와 같음)
	double value = 1.0 / key;

	node* ptr;
	node* temp = modified_search(root, key);

	if (!temp && root)
		return false; // 키가 이미 존재하면 삽입하지 않음

	if (temp || !root) {
		ptr = new node(key, value);

		if (root) {
			if (key < temp->data.key) temp->left = ptr;
			else temp->right = ptr;
		}
		else root = ptr;
	}
	return true;
}

int nodeCount(node* temp)  // 이진트리의 노드 개수
{
	if (!temp) return 0;
	return 1 + nodeCount(temp->left) + nodeCount(temp->right);
}

int leafCount(node* temp)
{
	if (!temp) return 0;
	if (!temp->left && !temp->right) return 1;
	return leafCount(temp->left) + leafCount(temp->right);
}

int height(node* temp) {
	int leftHeight, rightHeight;

	if (!temp) return 0;
	leftHeight = height(temp->left);
	rightHeight = height(temp->right);
	return 1 +
		(leftHeight > rightHeight ? leftHeight : rightHeight);
}



int main() {
	srand(time(NULL));
	node* root = NULL;
	int istk[12] = { 10, 6, 15, 8, 18, 12, 3, 14, 9, 20, 5, 2 };

	printf("HW9.1 12개의 (k,v)쌍을 생성하여 이진 탐색 트리 생성\n");

	for (int i = 0; i < 12; i++)
		insert(root, istk[i]);

	printf("Inorder 중위순회 : \n");
	inorder(root);
	printf("생성완료\n\n");


	printf("HW9.2 key값을 이용한 검색\n");

	int key;
	while (true) {
		printf("찾고자 하는 key를 입력 : ");
		scanf("%d", &key);
		if (key == -1) break;
		element* temp = search(root, key);
		if (!temp) printf("key : %d의 노드가 없습니다.\n", key);
		else printf("key : %d의 value : %lf\n", temp->key, temp->value);
	}


	printf("\nHW9.3 n개의 노드를 가진 이진트리 생성시간 및 노드 수, 높이, 단말(리프)노드 수\n");
	int n;
	while (true) {
		printf("n개의 노드를 가진 이진검색 트리 생성 : ");
		scanf("%d", &n);
		if (n == -1) break;
		root = NULL; //새로 만들면 다시 초기화해줘야함
		::end = n;
		::count = 0;

		clock_t start = clock();
		int rand1, rand2, combined;

		for (int i = 0; i < n; i++) {
			rand1 = rand();
			rand2 = rand();
			combined = (rand1 << 15) | rand2;
			key = (combined % (100000000 - 1 + 1)) + 1;
			//insert(root, key); //중복을 버리는용
			if (!insert(root, key)) i--; //중복제거용
		}

		clock_t end = clock();
		printf("생성된 트리 :\n");
		npInorder(root);

		printf("이진검색트리의 생성소요시간 : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
		printf("이진검색트리 노드 수 : %d\n", nodeCount(root));
		printf("이진검색트리 높이 : %d\n", height(root));
		printf("이진검색트리 리프노드 수 : %d\n\n", leafCount(root));
	}

	return 0;
}