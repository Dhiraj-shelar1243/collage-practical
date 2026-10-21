#include <stdio.h>
#include <stdlib.h>
struct Node{int prn;char name[50];float marks;struct Node*next;};
struct Node*head=NULL;
void insert(){
    struct Node*n=malloc(sizeof(struct Node)),*p;
    if(!n)return;
    printf("Enter PRN, name and marks: ");
    scanf("%d %49s %f",&n->prn,n->name,&n->marks);
    n->next=NULL;
    if(!head)head=n;
    else{p=head;while(p->next)p=p->next;p->next=n;}
}
void delete(){
    int id;struct Node*p=head,*prev=NULL;
    printf("Enter PRN to delete: ");scanf("%d",&id);
    while(p&&p->prn!=id){prev=p;p=p->next;}
    if(!p){printf("Student not found\n");return;}
    if(prev)prev->next=p->next;else head=p->next;
    free(p);printf("Student deleted\n");
}
void display(){
    struct Node*p=head;
    while(p){printf("PRN: %d Name: %s Marks: %.2f\n",p->prn,p->name,p->marks);p=p->next;}
    if(!head)printf("List is empty\n");
}
int main(){
    int c;
    do{printf("\n1.Insert 2.Delete 3.Display 4.Exit\nChoice: ");scanf("%d",&c);
    switch(c){case 1:insert();break;case 2:delete();break;case 3:display();break;case 4:break;default:printf("Invalid choice\n");}
    }while(c!=4);
    return 0;
}
