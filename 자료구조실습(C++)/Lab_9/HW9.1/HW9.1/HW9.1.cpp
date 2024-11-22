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

bool insert(node*& root) { //참조전달(이중포인터와 같음)
	int key = (rand() % 24) + 1; //1~24까지만
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


int main() {
	srand(time(NULL));
	node* root = NULL;

	printf("HW9.1 12개의 (k,v)쌍을 생성하여 이진 탐색 트리 생성\n");
	for (int i = 0; i < 12; i++) {
		if (!insert(root))
			i--; //다시 키를 뽑아야 하므로
	} 
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

	return 0;
}