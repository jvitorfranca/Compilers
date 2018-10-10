/*  Calculadore aritmética 
    Análise Léxica
    Disciplina Compiladores
*/
#include<stdlib.h>
#include<stdio.h>

char token;

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

int main(int argc, char const *argv[])
{
    int result;
    token = getchar();

    result = exp();
    if (token == '\n'){
        printf("Result = %d\n", result);
    } else {
        error();
    }

    return 0;
}