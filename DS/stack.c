#include <stdio.h>
#define SIZE 5

int stack[SIZE], top = -1;

void insert() {
    int x;
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &x);
    stack[++top] = x;
}

void delete() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Deleted: %d\n", stack[top--]);
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
