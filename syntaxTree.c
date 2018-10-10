#include<stdlib.h>
#include<stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct _syntaxtree_{
	struct _syntaxtree_ *left;
	struct _syntaxtree_ *right;
	int key;
} syntaxTree;

syntaxTree *createNode(int data){
	syntaxTree *newnode = (syntaxTree*)malloc(sizeof(syntaxTree));

	if (syntaxTree != NULL){

		syntaxTree->left = NULL;
		syntaxTree->right = NULL;
		syntaxTree->key = data;

		return newnode;
	}

	return NULL;
}

void leftChild(syntaxTree *node, syntaxTree *newnode){
	if (node != NULL){
		if (newnode != NULL){
			node->left = newnode;
		}
	}
}

void rightChild(syntaxTree *node, syntaxTree *newnode){
	if (node != NULL){
		if (newnode != NULL){
			node->right = newnode;
		}
	}
}