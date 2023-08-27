#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int tos=-1;

char opstack[50];

void push(char item);
char pop();
bool isoperator(char item);
void infixtopostfix(char infix[],char postfix[]);
int precedence(char item);

void push(char item){
    tos++;
    opstack[tos]=item;

}

char pop(){
    char item;
    item=opstack[tos];
    tos--;
    return item;
}

bool isoperator(char item){
    if(item=='^' || item=='$' || item=='+' || item=='-' || item=='*' || item=='/'){
        return true;
    }
    else
        return false;
}

int precedence(char item){
    if(item=='$' || item=='^'){
        return 3;
    }
    else if(item=='*' || item=='/'){
        return 2;
    }
    else if(item=='+' || item=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

void infixtopostfix(char infix[],char postfix[]){
    int i=0,j=0;
    char item,x;

    push('#');

    item=infix[i];

    while(item!='\0'){
        if(item=='('){
            push(item);
        }
        else if(isdigit(item) || isalpha(item)){
            postfix[j]=item;
            j++;
        }
        else if(isoperator(item)){
            x=pop();
            while(isoperator(x) && precedence(x)>=precedence(item)){
                postfix[j]=x;
                j++;
                x=pop();
            }
            push(x);
            push(item);
        }
        else if(item==')'){
            x=pop();
            while(x!='('){
                postfix[j]=x;
                j++;
                x=pop();
            }
        }
        i++;
        item=infix[i];
    }

    while(opstack[tos]!='#'){
        char item=pop();
        postfix[j]=item;
        j++;
    }
    postfix[j]='\0';

}

int main(){

    char infix[50],postfix[50];

    printf("Enter the infix expression:\n");
    gets(infix);

    infixtopostfix(infix,postfix);

    printf("\npostfix expression is:\n");
    puts(postfix);



    return 0;
}
