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

int countNodes(struct node* head){
    struct node *temp=head;
    int count=0;
    if(head!=NULL){
        while(temp!=NULL){
            count++;
            temp=temp->ptr;
        }
    }
    return count;
}

void middleNode(struct node *head){
    int count=countNodes(head);
    struct node *temp=head;
    printf("MIDDLE NODE(S):\n");
    if (count%2!=0){ 
        for(int i=0;i<count/2; i++){
            temp=temp->ptr;
        }
        printf("%d\n", temp->a);
    }
    
    if(count%2==0){
        for(int i=0;i<count/2-1; i++){
            temp=temp->ptr;
        }
        printf("%d\n", temp->a);
        temp=temp->ptr;
        printf("%d\n", temp->a);
    }    
}

int searchNode(struct node **head, int value){
    if(*head==NULL){
        return -1;
    }
    else{
        struct node *temp=*head;
        int i=0;
        while(temp->ptr!=NULL&&temp->a!=value){
            temp=temp->ptr;
            i++;
        }
        if(temp->a==value){
            return i;
        }
        else{
            return -1;
        }
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
    printf("COUNT OF NODES: %d\n", countNodes(head));
    middleNode(head);
    int value;
    printf("Enter a value to be searched: ");
    scanf("%d", &value);
    int index=searchNode(&head, value);
    if(index==-1){
        printf("NODE NOT PRESENT\n");
    }
    else printf("NODE FOUND AT INDEX: %d\n", index);
    return 0;
}