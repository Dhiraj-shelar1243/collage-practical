#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node{char city[50];struct Node*l,*r;};
struct Node*insert(struct Node*n,char s[]){
    if(!n){n=malloc(sizeof(struct Node));strcpy(n->city,s);n->l=n->r=NULL;}
    else if(strcmp(s,n->city)<0)n->l=insert(n->l,s);
    else if(strcmp(s,n->city)>0)n->r=insert(n->r,s);
    return n;
}
void postorder(struct Node*n){if(n){postorder(n->l);postorder(n->r);printf("%s ",n->city);}}
int main(){struct Node*r=NULL;char s[50];int n,i;
printf("How many cities? ");scanf("%d",&n);
for(i=0;i<n;i++){printf("Enter city: ");scanf("%49s",s);r=insert(r,s);}
printf("Postorder: ");postorder(r);printf("\n");return 0;}
