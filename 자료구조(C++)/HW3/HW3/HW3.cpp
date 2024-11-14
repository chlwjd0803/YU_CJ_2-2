#include <stdio.h>
#include <stdlib.h>
#define SQ_SIZE 100

typedef struct node* NodeP; //노드포인터로 정의한것
struct node {   	// 트리의 노드 구조
	char data;
	struct node* left, * right;
};

NodeP mkNode(char c)
{
	NodeP node = (NodeP)malloc(sizeof(node));
	node->data = c; node->left = node->right = NULL;
	return node;
}

int recNodeCount(NodeP node)  // 이진트리의 노드 개수
{
	if (!node) return 0;
	return 1 + recNodeCount(node->left) + recNodeCount(node->right);
}

int recLeafCount(NodeP node)
{
	if (!node) return 0;
	if (!node->left && !node->right) return 1;
	return recLeafCount(node->left) + recLeafCount(node->right);
}

int recHeight(NodeP node)
{
	int leftHeight, rightHeight;

	if (!node) return 0;
	leftHeight = recHeight(node->left);
	rightHeight = recHeight(node->right);
	return 1 +
		(leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Complete 3 functions below!!

int iterNodeCount(NodeP node)
{
	int count = 0;
	NodeP stack[SQ_SIZE];
	int top = -1;

	while (true) {
		for (; node != NULL; node = node->left, count++) stack[++top] = node;
		if (top == -1) break;
		node = stack[top--];
		node = node->right;
	}

	return count;
}


int iterLeafCount(NodeP node)
{
	int count = 0;
	NodeP stack[SQ_SIZE];
	int top = -1;

	while (true) {
		for (; node != NULL; node = node->left) stack[++top] = node;
		if (top == -1) break;
		node = stack[top--];
		if (node->left == NULL && node->right == NULL) count++; //둘다 없으면 leaf이므로 카운트
		node = node->right;
	}

	return count;
}

int iterHeight(NodeP node)
{
	int lev = 0;
	int layer = 0;
	NodeP stack[SQ_SIZE];
	int top = -1;

	if (node == NULL) return layer; //입력되지않았으면 높이가 0이므로

	while (true) {
		for (; node != NULL; node = node->left, lev++) {
			stack[++top] = node;
			//printf("%d ", top);
		}
		printf("%c %d, ", stack[top]->data, top);
		if (lev > layer) layer = lev; //최대높이 최신화
		if (node == NULL) lev--; //NULL이면 그 전으로 팝 하므로 층 미리 감소
		if (top == -1) break;
		node = stack[top--];
		node = node->right;
		
	}

	return layer + 1; //높이를 구해야하므로 +1
}

int main()
{
	NodeP	root, temp;
	
	// Binary tree structure
	//          A
	//        /   \  
	//       B     C	
	//      /     / \ 
	//     D     E   F
	//          / \
	// 	       G   H
	//            /	
	//           K	

	root = mkNode('A');
	root->left = mkNode('B');
	root->left->left = mkNode('D');
	root->right = mkNode('C');
	root->right->left = mkNode('E');
	root->right->left->left = mkNode('G');
	root->right->left->right = mkNode('H');
	root->right->left->right->left = mkNode('K');
	root->right->right = mkNode('F');
	

	// by Recursion
	printf("Number of nodes(Recursive): %d\n", recNodeCount(root));
	printf("Number of leaf nodes(Recursive): %d\n", recLeafCount(root));
	printf("Height of Tree(Recursive): %d\n\n", recHeight(root));

	// by non-Recursion
	printf("Number of nodes(non-Recursive): %d\n", iterNodeCount(root));
	printf("Number of leaf nodes(non-Recursive): %d\n", iterLeafCount(root));
	printf("Height of Tree(non-Recursive): %d\n", iterHeight(root));

	return 0;
}