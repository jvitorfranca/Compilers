#ifndef SYNTAX_TREE_h_
#define SYNTAX_TREE_h_

#define TRUE 1
#define FALSE 0

typedef struct _syntaxtree_{
	struct _syntaxtree_ *left;
	struct _syntaxtree_ *right;
	int key;
} syntaxTree;

	#ifndef syntaxTree_c_

		syntaxTree *createNode(int data);
		void leftChild(syntaxTree *node, syntaxTree *newnode);
		void rightChild(syntaxTree *node, syntaxTree *newnode);

	#else

		extern syntaxTree *createNode(int data);
		extern void leftChild(syntaxTree *node, syntaxTree *newnode);
		extern void rightChild(syntaxTree *node, syntaxTree *newnode);

	#endif
#endif