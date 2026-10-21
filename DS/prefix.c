#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[100]; int top=-1;
int prec(char c){if(c=='+'||c=='-')return 1;if(c=='*'||c=='/')return 2;if(c=='^')return 3;return 0;}
int main(){
    char in[100],out[100],c,t; int i,k=0,n;
    printf("Enter infix expression: "); scanf("%99s",in);
    n=strlen(in);
    for(i=0;i<n/2;i++){t=in[i];in[i]=in[n-1-i];in[n-1-i]=t;}
    for(i=0;i<n;i++){if(in[i]=='(')in[i]=')';else if(in[i]==')')in[i]='(';}
    for(i=0;i<n;i++){
        c=in[i];
        if(isalnum(c))out[k++]=c;
        else if(c=='(')s[++top]=c;
        else if(c==')'){while(top>=0&&s[top]!='(')out[k++]=s[top--];if(top>=0)top--;}
        else {while(top>=0&&s[top]!='('&&(prec(s[top])>prec(c)||(prec(s[top])==prec(c)&&c=='^')))out[k++]=s[top--];s[++top]=c;}
    }
    while(top>=0)out[k++]=s[top--];
    out[k]='\0';
    for(i=0;i<k/2;i++){t=out[i];out[i]=out[k-1-i];out[k-1-i]=t;}
    printf("Prefix expression: %s\n",out);return 0;
}
