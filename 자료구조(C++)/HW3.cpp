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
	NodeP queue[SQ_SIZE];
	int depth[SQ_SIZE];
	int front = -1;
	int rear = -1;

	if (node == NULL) return 0;

	queue[++rear] = node;
	depth[rear] = 1;

	while (front < rear) {
		node = queue[++front];
		if (node != NULL) {
			if (node->left != NULL) {
				queue[++rear] = node->left;
				depth[rear] = depth[front] + 1;
			}
			if (node->right != NULL) {
				queue[++rear] = node->right;
				depth[rear] = depth[front] + 1;
			}
		}
		else break; //node에서 dequeue한 node가 NULL이면 큐가 빈 상태
	}
	return depth[rear];
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