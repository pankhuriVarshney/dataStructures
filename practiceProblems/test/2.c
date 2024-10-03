#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

typedef struct queue{
    node *front;
    node *rear;
}queue;

void enqueue( queue *q, int data){
    node *newNode=(node *)malloc(sizeof(node));
    newNode->data=data;
    newNode->link=NULL;
    if(q->front==q->rear && q->rear==NULL){
        q->rear=newNode;
        q->front=newNode;
        return;
    }
    q->rear->link=newNode;
    q->rear=newNode;
}

int dequeue(queue *q) {
    if (q->front == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    
    node *temp = q->front;
    int dequeuedData = temp->data;
    
    q->front = q->front->link;
    
    if (q->front == NULL)  // If the queue becomes empty
        q->rear = NULL;
    
    free(temp);
    return dequeuedData;
}
void display(queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    node *temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}
int main() {
    queue *q;
    q->front=NULL;
    q->rear=NULL;  // Initialize the queue

    enqueue(q, 10);  // Enqueue 10
    enqueue(q, 20);  // Enqueue 20
    enqueue(q, 30);  // Enqueue 30

    display(q);      // Display the queue  // Peek the front element

    printf("%d dequeued from queue\n", dequeue(q));  // Dequeue the front element
    printf("%d dequeued from queue\n", dequeue(q));  // Dequeue the next element

    display(q);      // Display the queue after dequeuing
  // Peek the front element after dequeuing

    return 0;
}