#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

void addBegin(node **head, int data){
    node *newNode=(node *)malloc(sizeof(node));
    newNode->data=data;
    newNode->link=*head;
    *head=newNode;
}

void addEnd(node **head, int data){
    node *newNode=(node *)malloc(sizeof(node));
    newNode->data=data;
    newNode->link=NULL;
    if(*head==NULL){
        *head=newNode;
        return;
    }
    node *temp=*head;
    while(temp->link!=NULL)
        temp=temp->link;
    temp->link=newNode;
}

void addAt(node **head, int data, int pos){
    node *newNode=(node *)malloc(sizeof(node));
    newNode->data=data;
    newNode->link=NULL;
    if(*head==NULL && pos==1){
        *head=newNode;
        return;
    }
    if(*head==NULL || pos<=0)
        return;
    if(pos==1){
        newNode->link=*head;
        *head=newNode;
        return;
    }
    node *temp=*head;
    int i;
    for(i=1; i<pos-1&&temp->link!=NULL; i++, temp=temp->link);
    if(i<pos-1)
        return;
    newNode->link=temp->link;
    temp->link=newNode;
}

void delBegin(node **head){
    if(*head==NULL){
        return;
    }
    node *temp=*head;
    *head=(*head)->link;
    free(temp);
}

void delEnd(node **head){
    if(*head==NULL){
        return;
    }
    if((*head)->link == NULL){ 
        free(*head);
        *head = NULL;
        return;
    }
    node *temp=*head;
    node *prev;
    while(temp->link!=NULL){
        prev=temp;
        temp=temp->link;
    }
    prev->link=NULL;
    free(temp);
}

void delAt(node **head, int pos){
    if(*head==NULL)
        return;
    node *temp=*head;
    if(pos == 1){
        *head = (*head)->link;
        free(temp);
        return;
    }
    node *prev=*head;
    int i;
    for(i=1; i<pos && temp->link!=NULL; i++, prev=temp, temp=temp->link);
    if(i<pos){
        return;
    }
    prev->link=temp->link;
    free(temp);
}   

void display(node *head){
    node *temp=head;
    while(temp!=NULL){
        printf("%d->", temp->data);
        temp=temp->link;
    }
    printf("NULL\n");
}

void sort(node **head){
    if(*head==NULL)
        return;
    for(node *i=*head; i!=NULL; i=i->link){
        for(node *j=i; j!=NULL; j=j->link){
            if(i->data>j->data){
                int temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
}

node* concat(node *a, node *b){
    if(a==NULL)
        return b;
    node *temp=a;
    while(temp->link!=NULL)
        temp=temp->link;
    temp->link=b;
    return a;
}

node* intersec(node *a, node *b){
    if(a==NULL || b==NULL)
        return NULL;
    node *temp=NULL;
    for(node *i=a; i!=NULL; i=i->link){
        for(node *j=b; j!=NULL; j=j->link){
            if(i->data==j->data){
                addEnd(&temp, i->data);
            }
        }
    }
    return temp;
}

void reverse(node **head){
    if(*head==NULL){
        return;
    }
    node *temp=*head;
    node *prev=NULL, *next;
    while(temp!=NULL){
        next=temp->link;
        temp->link=prev;
        prev=temp;
        temp=next;
    }
    *head=prev;
}

int main(){
    node *head=NULL;
    addBegin(&head, 10);
    addEnd(&head, 20);
    addAt(&head, 15, 2);
    display(head);
    sort(&head);
    node *head2=NULL;
    addBegin(&head2,20);
    addBegin(&head2,90);
    addBegin(&head2,10);
    sort(&head2);
    display(head2);
    //node *conc=concat(head, head2);
    //display(conc);
    node *inter=intersec(head, head2);
    display(inter);

    reverse(&head2);
    display(head2);
}