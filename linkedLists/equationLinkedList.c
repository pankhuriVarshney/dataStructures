#include <stdio.h>
#include <stdlib.h>

struct node {
    float coeff;
    int pow;
    struct node* ptr;
};

void addNode(struct node **head, float coeff, int pow);
void printList(struct node* head);

void addNode(struct node **head, float coeff, int pow){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->coeff=coeff;
    newNode->pow=pow;
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
        printf("%gx^%d + ", temp->coeff, temp->pow);
        temp=temp->ptr;
    }
    printf("0\n");
}
struct node* addEquations(struct node* eq1, struct node* eq2){
    struct node* eq3=NULL;
    if(eq1==NULL && eq2==NULL){
        printf("NO EQUATIONS\n");
        return;
    }
    else if(eq1==NULL){
        eq3=eq2;
        return;
    }
    else if(eq2==NULL){
        eq3=eq1;
        return;
    }
    else{
        struct node *temp1=eq1;
        struct node *temp2=eq2;
        struct node *temp3=eq3;
        while(temp1!=NULL && temp2!=NULL){
            
        }
    }
}
int main(){
    struct node* eq1=NULL;
    struct node* eq2=NULL;
    addNode(&eq1, 3, 4);
    addNode(&eq1, 2, 3);
    addNode(&eq1, -9, 2);
    addNode(&eq1, 4, 1);
    addNode(&eq1, -5, 0);

    addNode(&eq2, 5, 5);
    addNode(&eq2, -3, 3);
    addNode(&eq2, 8, 1); 

    printList(eq1);
    printList(eq2);
    return 0;
}