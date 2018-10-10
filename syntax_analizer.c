/*  Calculadore aritmética 
    Análise Léxica
    Disciplina Compiladores
*/
#include<stdlib.h>
#include<stdio.h>

typedef struct _tree_{
    void* key;
    struct _tree_ *left;
    struct _tree_ *right;
}Tree;

char token;

Tree* createNode(void* token){

    Tree *node;

    node = (Tree*)malloc(sizeof(Tree));

    if (node != NULL){

        node->left = NULL;
        node->right = NULL;
        node->key = token;

        return node;

    }

    return NULL;
}

void left(Tree *node, void* temp){
    
    Tree* newnode = createNode(temp);

    if (newnode != NULL){
        node->left = newnode;
    }

}

void right(Tree *node, void* temp){

    Tree* newnode = createNode(temp);
    
    if (newnode != NULL){
        node->right = newnode;
    }
    
}

void error(){
    fprintf(stderr, "Error\n");
    exit(1);
}

void match(char expectedToken){
    if (token == expectedToken){
        token = getchar();
    } else {
        error();
    }
}

int factor();

int term(void){
    int temp = factor();

    while ((token == '*') ||(token == '/') || (token == '%')){
        switch (token){
            case '*':
                match('*');
                temp *= term();
                break;
            case '/':
                match('/');
                temp /= (int) term();
                break;
            case '%':
                match('%');
                temp %= term();
                break;
        }
    }

    return temp;
}

int exp(void){
    int temp;
    
    temp = term();

    while ((token == '+') || (token == '-')){
        switch (token){
            case '+':
                match('+');
                temp += term();
                break;
            case '-':
                match('-');
                temp -= term();
                break;
        }
    }

    return temp;
}

/*
Tree* expTree(void){
    
    Tree *temp, *novatemp;

    temp = createNode((void*)term());

    while (token == '+' || token == '-'){
        switch (token){
            case '+':
                match('+');
                novatemp = createNode((void*)token);
                left(novatemp, (void*)temp);
                right(novatemp, (void*)term());
                temp = novatemp;
                break;
            case '-':
                match('-');
                novatemp = createNode((void*)token);
                left(novatemp, (void*)temp);
                right(novatemp, (void*)term());
                temp = novatemp;
                break;
        }
    }
    return temp;
}
*/

Tree* expTree(void){

    Tree* temp, *novatemp;

    temp = createNode((void*)term());

    while (token == '+' || token == '-'){
        novatemp = createNode((void*)token);
        match(token);
        left(novatemp, (void*)temp->key);
        right(novatemp, (void*)term());
        temp = novatemp;
    }

    return temp;
}

int factor(void){
    int temp;

    if (token == '(') {
        match('(');
        temp = exp();
        match(')');
    } else if (isdigit(token)) {
        ungetc(token, stdin);
        scanf("%d", &temp);
        token = getchar();
    } else {
        error();
    }
    
    return temp;
}

void preOrder(Tree *node){
    
    if (node != NULL){
        if (node->key == (void*)'+' || node->key == (void*)'-'){
            printf("%c\n", (char*)node->key);
        } else {
            printf("%d\n", (int)node->key);
        }
        preOrder(node->left);
        preOrder(node->right);
    }
}

int main(int argc, char const *argv[])
{
    int result;
    token = getchar();

    Tree* result1;
    result1 = expTree();

    preOrder(result1);

    /*
    result = exp();
    if (token == '\n'){
        printf("Result = %d\n", result);
    } else {
        error();
    }
    */

    return 0;
}