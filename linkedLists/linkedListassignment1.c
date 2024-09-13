#include <stdio.h>
#include <stdlib.h>
struct listInt{
    int value;
    int *link;
} headInt;
struct listChar{
    char value;
    int *link;
} headChar;
struct listString{
    char *value;
    int *link;
} headString;
void createListInt(struct listInt *head, int newValue){
    struct listInt *newNode=(struct listInt*)malloc(sizeof(struct listInt*));
    newNode->value=newValue;
    newNode->link=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        struct listInt *tempNode=head;
        while(tempNode->link!=NULL){
            tempNode=tempNode->link;
        }
        tempNode->link=newNode;
    }

}
void createListChar(struct listChar *head, char newValue){
    struct listChar *newNode=(struct listChar*)malloc(sizeof(struct listChar*));
    newNode->value=newValue;
    newNode->link=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        struct listChar *tempNode=head;
        while(tempNode->link!=NULL){
            tempNode=tempNode->link;
        }
        tempNode->link=newNode;
    }

}
void createListString(struct listString *head, char *newValue){
    struct listString *newNode=(struct listString*)malloc(sizeof(struct listString*));
    newNode->value=newValue;
    newNode->link=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        struct listString *tempNode=head;
        while(tempNode->link!=NULL){
            tempNode=tempNode->link;
        }
        tempNode->link=newNode;
    }

}
void printLists(struct listInt *headInt, struct listChar *headChar, struct listString *headString){
    printf("INTEGER LINKED LIST:\n");
    if(headInt==NULL){
        printf("LIST EMPTY\n");
    }
    else{
        struct listInt *temp=headInt;
        int i=0;
        while(temp!=NULL){
            printf("VALUE %d: %d\nLINK: %hd\n\n", i++, temp->value, temp->link);
            temp=temp->link;
        }
    }
    printf("\n\n");
    printf("CHARATCER LINKED LIST:\n");
    if(headChar==NULL){
        printf("LIST EMPTY\n");
    }
    else{
        struct listChar *temp=headChar;
        int i=0;
        while(temp!=NULL){
            printf("VALUE %d: %c\nLINK: %hd\n\n", i++, temp->value, temp->link);
            temp=temp->link;
        }
    }
    printf("\n\n");
    printf("STRING LINKED LIST:\n");
    if(headString==NULL){
        printf("LIST EMPTY\n");
    }
    else{
        struct listString *temp=headString;
        int i=0;
        while(temp!=NULL){
            printf("VALUE %d: %s\nLINK: %hd\n\n", i++, *temp->value, temp->link);
            temp=temp->link;
        }
    }
}
int main(){
    struct listInt *headInt=NULL;
    printf("INTERGER LINKED LIST:\nEnter size of linked list: ");
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int val;
        scanf("%d", &val);
        createListInt(headInt, val);
    }
    struct listChar *headChar=NULL;
    printf("CHARACTER LINKED LIST:\nEnter size of linked list: ");
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        char val;
        scanf("%[^\n]%*c", val);
        createListInt(headChar, val);
    }
    struct listString *headString=NULL;
    printf("STRING LINKED LIST:\nEnter size of linked list: ");
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        char *val;
        scanf("%[^\n]s", &val);
        createListInt(headString, &val);
    }
    printLists(headInt, headChar, headString);
}