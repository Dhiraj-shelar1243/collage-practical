#include <stdio.h>
#include <ctype.h>
char s[100]; int top=-1;
int prec(char c){if(c=='+'||c=='-')return 1;if(c=='*'||c=='/')return 2;if(c=='^')return 3;return 0;}
int main(){
    char in[100],out[100],c; int i,k=0;
    printf("Enter infix expression: "); scanf("%99s",in);
    for(i=0;in[i];i++){
        c=in[i];
        if(isalnum(c))out[k++]=c;
        else if(c=='(')s[++top]=c;
        else if(c==')'){while(top>=0&&s[top]!='(')out[k++]=s[top--];if(top>=0)top--;}
        else {while(top>=0&&s[top]!='('&&prec(s[top])>=prec(c))out[k++]=s[top--];s[++top]=c;}
    }
    while(top>=0)out[k++]=s[top--];
    out[k]='\0'; printf("Postfix expression: %s\n",out); return 0;
}
