#include <stdio.h>
#include <stdlib.h>

struct node {
    int a;
    struct node* ptr;
};

void addNode(struct node **head, int nextData);
void printList(struct node* head);
int searchNode(struct node **head, int value);

void addNode(struct node **head, int nextData){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->a=nextData;
    newNode->ptr=NULL;

    if(*head==NULL){
        *head=newNode;
    }
    else{
        struct node *temp=*head;
        while(temp->ptr!=NULL){
            temp=temp->ptr;
        }
        temp->ptr=newNode;
    }
}

void printList(struct node* head){
    struct node *temp=head;
    if(head==NULL)
        printf("LINKED LIST EMPTY\n");
    int i=1;
    while(temp!=NULL){
        printf("%d\t",temp->a);
        temp=temp->ptr;
    }
    printf("\n");
}
void reverseList(struct node **head){
    if(*head==NULL)
        return;
    else{
        struct node *t1=*head;
        struct node *t2=t1->ptr;
        t1->ptr=NULL;
        while(t2!=NULL){
            struct node *temp=t2->ptr;
            t2->ptr=t1;
            t1=t2;
            t2=temp;
        }
        *head=t1;
    }
}
int main(){
    struct node* head=NULL;
    printf("Enter the initial size of Linked List: ");
    int size;
    scanf("%d", &size);
    for(int i=0; i<size; i++){
        printf("Enter a node value: ");
        int val;
        scanf("%d", &val);
        addNode(&head, val);
    }
    printList(head);
    reverseList(&head);
    printList(head);
    return 0;
}