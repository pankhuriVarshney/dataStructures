#include <stdio.h>
#include <stdlib.h>

struct node {
    int a;
    struct node* ptr;
};

void insertBegin(struct node **head, int val);
void insertEnd(struct node **head, int nextData);
void insertAfterNode(struct node **head, int val, int after);
void printList(struct node* head);

void insertBegin(struct node **head, int val){
    struct node *newNode=(struct node*)malloc(sizeof(struct node*));
    newNode->a=val;
    newNode->ptr=NULL;
    if(*head==NULL){
        *head=newNode;
    }
    else{
        newNode->ptr=*head;
        *head=newNode;
    }
}
void insertEnd(struct node **head, int nextData){
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
void insertAfterNode(struct node **head, int val, int after){
    struct node *newNode=(struct node*)malloc(sizeof(struct node*));
    newNode->a=val;
    if(*head==NULL){
        printf("INVALID! LIST IS EMPTY\n");
    }
    else{
        struct node *temp=*head;
        while(temp->ptr!=NULL && temp->a!=after){
            temp=temp->ptr;
        }
        if(temp->a==after){
            newNode->ptr=temp->ptr;
            temp->ptr=newNode;
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
        printf("%d\t",temp->a);
        temp=temp->ptr;
    }
    printf("\n");
}

int main(){
    struct node *head=NULL;
    while(1){
        printf("Enter 1: to create linked list\nEnter 2: to insert at beginning\nEnter 3: to insert at the end\nEnter 4: to insert after a specific node\nEnter 5: to display list\nEnter 6: to exit\nEnter your choice: ");
        int ch;
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                printf("Enter the initial size of Linked List: ");
                int size;
                scanf("%d", &size);
                for(int i=0; i<size; i++){
                    printf("Enter a node value: ");
                    int val;
                    scanf("%d", &val);
                    insertEnd(&head, val);
                }
                break;
            }
            case 2:{
                printf("Enter a number: ");
                int num;
                scanf("%d", &num);
                insertBegin(&head, num);
                break;
            }
            case 3:{
                printf("Enter a number: ");
                int num;
                scanf("%d", &num);
                insertEnd(&head, num);
                break;
            }
            case 4:{
                printf("Enter a number: ");
                int num, index;
                scanf("%d", &num);
                printf("Enter a node after which the number will be added: ");
                scanf("%d", &index);
                insertAfterNode(&head, num, index);
                break;
            }
            case 5:{
                printList(head);
                break;
            }
            case 6:{
                goto end;
            }
            default:
            printf("INVALID CHOICE\n");
        }
    }
    end: printf("\n");
    return 0;
}
