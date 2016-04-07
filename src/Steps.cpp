/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22
	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include<malloc.h>
#include "stdafx.h"
struct node{

	struct node* left;
	int data;
	struct node* right;
};
void Recurr(struct node* root, int *count);
int get_steps(int s)
{
	if (s == 0) return 0;
	int count = 0;
	struct node* root = NULL;
	root = (struct node*)malloc(sizeof(struct node));
	root->data = s;
	Recurr(root, &count);
	return count;
}
void Recurr(struct node* root, int *count){


	if (root->data >= 1){

		struct node* newnode = NULL;
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->left = NULL;
		newnode->right = NULL;
		root->left = newnode;
		newnode->data = root->data - 1;
		if (newnode->data == 0) {
			*count = *count + 1;
		}
		Recurr(root->left, count);

		if (root->data >= 2){
			struct node* newnode = NULL;
			newnode = (struct node*)malloc(sizeof(struct node));
			newnode->left = NULL;
			newnode->right = NULL;
			newnode->data = root->data - 2;
			if (newnode->data == 0) {
				*count = *count + 1;
			}
			root->right = newnode;
			Recurr(root->right, count);
		}
		else{
			root->right = NULL;
		}
	}
	else{
		root->left = NULL;
	}
}
