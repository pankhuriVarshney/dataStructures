#include <iostream>
using namespace std;

class Queue{
    int MAX_SIZE;
    int front;
    int rear;
    int *queue;
    public:

    //constructor:
    Queue(int size) : MAX_SIZE(size), front(-1), rear(-1) {
        queue = new int[MAX_SIZE];  
    }
    //deconstructor:
    ~Queue(){
        free(queue);
    }

    //func to add nodes from rear end
    void enqueue(int val){
        if(rear==MAX_SIZE-1){
            cout<<"QUEUE OVERFLOW!"<<endl;
            return;
        }
        if(rear==-1){
            front=0;
        }
        queue[++rear]=val;
        cout<<"ADDED VAL: "<<val<<endl;
    }

    //func to remove nodes from front end
    void dequeue(){
        if(front==-1){
            cout<<"QUEUE UNDERFLOW"<<endl;
            return;
        }
        cout<<"DELETED VAL: "<<queue[front]<<endl;
        if(front==rear){
            queue[front]=0;
            front=rear=-1;
            return;
        }
        queue[front++]=0;
    }

    //func to display entire queue
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
    Queue q(size);  

    q.enqueue(10);
    q.display();

    q.enqueue(20);
    q.display();

    q.enqueue(30);
    q.display();

    q.enqueue(40);
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    return 0;
}
