#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *link;
};

void addEnd(struct node **head, int num) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->num = num;
    newNode->link = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *temp = *head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void addStart(struct node **head, int num) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->num=num;
    newNode->link = *head; 
    *head = newNode;
}

struct node* sum(struct node **list1, struct node **list2) {
    if (*list1 == NULL && *list2 == NULL) {
        printf("Empty Lists\n");
        return NULL;
    } else if (*list1 == NULL) {
        return *list2;
    } else if (*list2 == NULL) {
        return *list1;
    } else {
        struct node *temp1 = *list1;
        struct node *temp2 = *list2;
        struct node *sumList = NULL; 

        while (temp1 != NULL && temp2 != NULL) {
            int sum = temp1->num + temp2->num;
            addEnd(&sumList, sum);
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
        while (temp1 != NULL) {
            addEnd(&sumList, temp1->num);
            temp1 = temp1->link;
        }
        while (temp2 != NULL) {
            addEnd(&sumList, temp2->num);
            temp2 = temp2->link;
        }

        return sumList;
    }
}

void makeList(struct node **head, int num) {
    if (num == 0) {
        return;
    }
    addStart(head, num % 10);
    makeList(head, num / 10);
}

void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d\t", temp->num);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    printf("Enter two numbers: \n");
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    struct node *list1 = NULL;
    makeList(&list1, num1);
    printf("List 1: \n");
    display(list1);

    struct node *list2 = NULL;
    makeList(&list2, num2);
    printf("List 2: \n");
    display(list2);

    struct node *list3 = sum(&list1, &list2);
    printf("Sum List: \n");
    display(list3);

    return 0;
}
