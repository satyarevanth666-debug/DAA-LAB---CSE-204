#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* top = NULL;
void push(int data) {
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> next = top;
    top = newnode;
    printf("Inserted = %d\n",newnode -> data);
}
void pop() {
    struct node* temp = top;
    printf("Deleted = %d\n", temp -> data);
    top = top -> next;
    free(temp);
    
}
void peek() {
    printf("Peek element is = %d\n",top -> data);
}
void display() {
    if (top == NULL) 
        printf("Stack is empty");
    struct node* temp = top;
    printf("Stack elements are : ");
    while(temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}
int main() {
    push(10);
    push(20);
    push(30);
    peek();
    display();
    pop();
    peek();
    display();
    return 0;
}