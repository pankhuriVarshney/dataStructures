#include <iostream>
#include <stdlib.h>
using namespace std;


class Queue{
    int MAX_SIZE;
    int front;
    int rear;
    int *queue;
    public:
    Queue(int size){
        MAX_SIZE=size;
        queue=(int *)malloc(sizeof(int)*MAX_SIZE);
        front=rear=-1;
    }
    ~Queue(){
        free(queue);
    }
    void enqueue(int val){
        if(rear==-1){
            front++;
            rear++;
            queue[rear]=val;
            return;
        }
        if(rear==MAX_SIZE-1){ //queue overflow
            cout<<"QUEUE OVERFLOW"<<endl;
            return;
        }        
        queue[++rear]=val;
        cout<<"ADDED VAL: "<<val<<endl;
    }
    void dequeue(){
        if(front==-1){//queue underflow
            cout<<"QUEUE UNDERFLOW"<<endl;
            return;
        }
        if(front==MAX_SIZE-1 || front==rear){
            cout<<"DELETED VAL: "<<queue[front]<<endl;
            queue[front]=0;
            front=rear=-1;
            return;
        }
        cout<<"DELETED VAL: "<<queue[front]<<endl;
        queue[front++]=0;
    }
    void display(){
        if(front>rear || front==-1){
            cout<<"EMPTY QUEUE"<<endl;
            return;
        }
        for(int i=front; i<=rear; i++){
            cout<<queue[i]<<"\t";
        }
        cout<<endl;
    }
};

int main(){
    cout<<"QUEUE USING ARRAYS: \nEnter Max Size: ";
    int size;
    cin>>size;
    Queue *q=new Queue(size);
    q->enqueue(10);
    q->display();
    q->enqueue(20);
    q->display();
    q->enqueue(30);
    q->display();
    q->enqueue(40);
    q->display();
    q->dequeue();
    q->display();
    q->dequeue();
    q->display();
    q->dequeue();
    q->display();
    q->dequeue();
    q->display();
}
