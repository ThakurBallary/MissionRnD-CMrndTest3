/*
Given a Binary Tree of N Nodes, which have unique values in the range of 
[0,N](Inclusive)  with one value(Node) missing in that sequence.
Return that missing value .

Example 1 : N=5 
   3
  / \
 4   1
    / \
   5   0
Missing Value is 2 ,Sequence is [0,1,2,3,4,5]

Example 2 : N=8
      2
     / \
    4   5
   / \ / \
  3  1 6  8
 /
0
Missing Value is 7 ,Sequence is [0,1,2,3,4,5,6,7,8]

Constaints : 
-10000<=N<=10000 [N will not be equal to 0]

Input :
Struct node Root Address
Output :
Return Missing Value .
Return -1 for NULL Inputs 

Note:
Dont Create an Extra Array/String ,or else your solution would receive 30% Cut in the Marks you got for this
question .

Difficulty : Easy
*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

void get_tree_sum(struct node *root, int *sum) {
	if (!root) {
		return;
	}
	*sum += root->data;
	get_tree_sum(root->left, sum);
	get_tree_sum(root->right, sum);
}

int get_input_sum(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}

int get_missing_value(struct node *root,int n){
	if (!root || n == 0) {
		return -1;
	}
	int treeSum = 0;
	get_tree_sum(root, &treeSum);

	int inputSum = 0;

	if (n > 0) {
		inputSum = get_input_sum(n);
	} 
	else if(n < 0) {
		n *= -1;
		inputSum = get_input_sum(n);
		inputSum *= -1;
	}
	int missingValue = inputSum - treeSum;
	return missingValue;
}