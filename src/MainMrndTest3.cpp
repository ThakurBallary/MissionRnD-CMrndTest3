#include <stdio.h>
#include "FunctionHeadersMrndTest3.h"
#include <stdlib.h>"
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct enode{
	char data[6];
	struct enode *left;
	struct enode *right;
};

struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};

void printArray(int *arr, int len){
	for (int i = 0; i < len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void printDLL(struct node_dll *root){
	while (root != NULL){
		printf("%d ", root->data);
		root = root->next;
	}
	printf("\n");
}

void printBST(struct node * root){
	if (root != NULL){
		printBST(root->left);
		printf("%d ", root->data);
		printBST(root->right);
	}
}
/*
struct node *newNode_spec(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * add_node_spec(struct node *root, int data){
	if (root == NULL) return newNode_spec(data);

	if (data < root->data)
		root->left = add_node_spec(root->left, data);
	else if (data > root->data)
		root->right = add_node_spec(root->right, data);

	return root;
}
struct node * make_bst_spec(int *arr, int len){
	struct node *root = NULL;
	for (int i = 0; i < len; i++){
		root = add_node_spec(root, arr[i]);
	}
	return root;
}

struct node_dll *newNode_DLL_spec(int key)
{
	struct node_dll *temp = (struct node_dll *)malloc(sizeof(struct node_dll));
	temp->data = key;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
struct node_dll * make_dll_spec(int *arr, int len){
	struct node_dll *root = newNode_DLL_spec(arr[0]);
	struct node_dll *temp = root;
	for (int i = 1; i < len; i++){
		struct node_dll *cur = newNode_DLL_spec(arr[i]);
		temp->next = cur;
		cur->prev = temp;
		temp = temp->next;
	}
	return root;
}
*/
struct node *newNode_spec(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node * constructBinaryTree_spec(int *arr, int len){
	struct node *root = NULL;
	struct node *nodes[2005];
	for (int i = 0; i < len; i++){
		nodes[i] = newNode_spec(arr[i]);
	}
	int mid = (len / 2);
	for (int i = 0; i < mid; i++){
		struct node *curnode = nodes[i];
		struct node *leftnode = nodes[(i * 2) + 1];
		struct node *rightnode = nodes[(i * 2) + 2];
		if (curnode->data != -999){
			if (leftnode->data != -999){
				curnode->left = leftnode;
			}
			if (rightnode->data != -999){
				curnode->right = rightnode;
			}
		}
	}
	root = nodes[0];
	return root;
}

int main(){

	//Test here
	/*
	int arr[5] = { 1, 2, 3, 4, 5 };
	int  len1 = 5;
	struct node_dll * head = make_dll_spec(arr, len1);
	printDLL(head);
	int bst_arr[5] = { 5, 3, 2, 1, 4 };
	int len2 = 5;
	struct node *root = make_bst_spec(bst_arr, len2);
	printBST(root);
	int result = is_identical(head, root);
	*/

	/*
	int arr[] = { -1, -2, -3, -5, 0, -999, -999 };
	int len = 5;
	struct node *root = constructBinaryTree_spec(arr, len);
	int missingValue = get_missing_value(root, -5);
	*/

	return 0;
}