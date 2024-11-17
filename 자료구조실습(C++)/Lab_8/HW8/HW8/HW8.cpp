#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int data) {
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
};

//순회 알고리즘 구현
void inorder(node* ptr) {
	if (ptr) {
		inorder(ptr->left);
		printf("%d ", ptr->data);
		inorder(ptr->right);
	}
}

void preorder(node* ptr) {
	if (ptr) {
		printf("%d ", ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(node* ptr) {
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d ", ptr->data);
	}
}

void allOrder(node* ptr) {
	printf("Inorder 중위순회 : ");
	inorder(ptr);
	printf("\nPreorder 전위순회 : ");
	preorder(ptr);
	printf("\nPostorder 후위순회 : ");
	postorder(ptr);
	printf("\n");
}

node* copy(node* origin) {
	node* temp;
	if (origin) { //복사할 이진트리가 존재함
		temp = new node(0); //이때 0은 어짜피 의미없음
		temp->left = copy(origin->left);
		temp->right = copy(origin->right);
		temp->data = origin->data;
		return temp;
	}
	return nullptr;
}

node* swap(node* origin) {
	node* temp;
	if (origin) {
		temp = new node(0);
		temp->left = copy(origin->right);
		temp->right = copy(origin->left);
		temp->data = origin->data;
		return temp;
	}
	return nullptr;
}

int equals(node* X, node* Y) {
	return ((!X && !Y) || (X && Y && (X->data == Y->data) && equals(X->left, Y->left) && equals(X->right, Y->right)));
	//X와 Y가 null이 아닌지 || X Y 노드가 존재하고 데이터도 같아야함 && 왼쪽자식과 오른쪽자식이 같은지 재귀호출
	//틀리면 연산이 0이 되므로 false가 된다.
}

node* dynamicTreeGen() {
	printf("정수를 입력하세요 : ");
	int n;
	scanf("%d", &n);

	node* root = new node(1); //일단 루트는 1이므로
	node* temp;

	if (n == 0) root->data = 0;

	for (int i = 2; i <= n; i++) {
		temp = root; //항상 루트에서 시작할 수 있도록
		int rd = rand() % 2;

		while (true) {
			if (!rd) {
				if (!(temp->left)) {
					temp->left = new node(i);
					break;
				}
				else {
					rd = rand() % 2; //새로운 난수 생성
					temp = temp->left;
				}
			}
			else {
				if (!(temp->right)) {
					temp->right = new node(i);
					break;
				}
				else {
					rd = rand() % 2;
					temp = temp->right;
				}
			}
		}
	}
	return root;
}

int main() {
	srand(time(NULL)); //매번 다른 난수를 얻기 위함
	
	node* A;
	//이진트리 구현
	A = new node(5);
	A->left = new node(3);
	A->left->left = new node(1);
	A->left->right = new node(4);
	A->right = new node(8);

	printf("HW8.1 트리구성 및 트리순회 A\n");
	allOrder(A);

	printf("\n\nHW8.21 트리복사B\n");
	node* B = copy(A); //복사
	allOrder(B); //확인

	printf("\nHW8.22 동질성검사AB\n");
	if (equals(A, B)) printf("equals(A, B) : True\n");
	else printf("equals(A, B) : False\n");

	printf("\nHW8.23 좌우반전 swap C\n");
	node* C = swap(A); //좌우반전 복사
	allOrder(C);

	printf("\nHW8.3 랜덤트리 자동생성 및 순회 D\n");
	node* D = dynamicTreeGen();
	allOrder(D);

	delete A;
	delete B;
	delete C;
	delete D;

	return 0;
}