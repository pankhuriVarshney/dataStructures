#include <stdio.h>
#include <stdlib.h>

struct node {
    int a;
    struct node* ptr;
};

void addNode(struct node **head, int nextData);
void addNodeAt(struct node **head, int val, int index);
void printList(struct node* head);
void deleteNodeAt(struct node **head, int index);

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

void addNodeAt(struct node **head, int val, int index){
    struct node *newNode=(struct node*)malloc(sizeof(struct node*));
    newNode->a=val;
    if(*head==NULL &&index==0){
        *head=newNode;
    }
    else{
        struct node *temp=*head;
        int i=0;
        while(temp->ptr!=NULL && i<index-1){
            temp=temp->ptr;
            i++;
        }
        if(i==index-1){
            newNode->ptr=temp->ptr;
            temp->ptr=newNode;
        }
        else{
            printf("INVALID OPERATION! INDEX OUT OF BOUND\n");
        }
    }
}

void deleteNodeAt(struct node **head, int index){
    if(*head==NULL){
        return;
    }
    else{
        struct node *temp1=*head;
        struct node *temp2=temp1->ptr;
        int i=0;
        while(temp2->ptr!=NULL && i<index-1){
            temp1=temp2;
            temp2=temp2->ptr;
            i++;
        }
        if(i==index-1){
            temp1->ptr=temp2->ptr;
        }
        else{
            printf("INVALID OPERATION! INDEX OUT OF BOUND\n");
        }
    }
}
void printList(struct node* head){
    struct node *temp=head;
    if(head==NULL)
        printf("LINKED LIST EMPTY\n");
    int i=1;
    while(temp!=NULL){
        printf("NODE %d:\nDATA: %d\nPOINTER: %p\n\n", i++, temp->a, temp->ptr);
        temp=temp->ptr;
    }
}

int main(){
    struct node* head=NULL;
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 60);
    printf("ORIGINAL LIST:\n"); 
    printList(head);
    addNodeAt(&head, 38, 2);
    printList(head);
    // addNodeAt(&head, 2, 2);
    // printf("AFTER ADDITION OF INDEX 2:\n");
    // printList(head);
    // deleteNodeAt(&head, 3);
    // printf("AFTER DELETION AT INDEX 3:\n");
    // printList(head);
    return 0;
}