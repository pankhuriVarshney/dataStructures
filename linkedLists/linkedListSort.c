#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void sort(struct node **head){
    struct node *temp1= *head;
    struct node *temp2;
    while(temp1!=NULL){
        temp2=temp1->link;
        while(temp2!=NULL){
            if(temp1->data>temp2->data){
                int temp3=temp1->data;
                temp1->data=temp2->data;
                temp2->data=temp3;
            }
            temp2=temp2->link;
        }
        temp1=temp1->link;
    }
}

void addEnd(struct node **head, int data){
    struct node *newNode=(struct node*)malloc(sizeof(struct node*));
    newNode->data=data;
    newNode->link=NULL;
    if(*head==NULL){
        *head=newNode;
    }
    else{
        struct node *temp=*head;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=newNode;
    }
}

void printList(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d\t", temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int main(){
    struct node *head=NULL;
    addEnd(&head, 30);
    addEnd(&head, 40);
    addEnd(&head, 10);
    addEnd(&head, 80);
    addEnd(&head, 20);
    printList(head);
    sort(&head);
    printList(head);
}