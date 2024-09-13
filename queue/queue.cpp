#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *link;

    node(int data){
        this->data=data;
        this->link=nullptr;
    }
};

class LinkedList {
public:
    node *head;

public:
    LinkedList() {
        this->head = nullptr;
    }
    ~LinkedList() {
    node *current = head;
    while (current != nullptr) {
        node *next = current->link;
        delete current;
        current = next;
        }
    }

    void addAtEnd(int data) {
        node *newNode = new node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            node *temp = head;
            while (temp->link != nullptr) {
                temp = temp->link;
            }
            temp->link = newNode;
        }
    }

    void displayList() {
        node *temp = head;
        while (temp != nullptr) {
            std::cout << temp->data <<"\t";
            temp = temp->link;
        }
        cout << endl;
    }
};

class queue{
    private:
        LinkedList &q;
        node *front;
        node *rear;
    
    public:
    queue(LinkedList &q) : q(q) {
        front = q.head;
        if (front == nullptr) {
            rear = nullptr;
        } else {
            node *temp = front;
            while (temp->link != nullptr) {
                temp = temp->link;
            }
            rear = temp;
        }
    }
    
    void enqueue(int data){
        node *newNode = new node(data);
        if (rear != nullptr) {
            rear->link = newNode;
            rear = newNode;
        } else {
            front = rear = newNode;
        }
    }

    void dequeue(){
        if(front == nullptr){
            cout<<"QUEUE UNDERFLOW\n";
            return;
        }
        else{
            node *temp=front;
            front=front->link;
            delete temp;
            if(front == nullptr) {
                rear = nullptr; // Set rear to nullptr if queue becomes empty
            }
        }
    }
};


int main(){
    LinkedList li;
    li.addAtEnd(10);
    li.addAtEnd(20);
    li.addAtEnd(30);
    li.addAtEnd(40);
    li.addAtEnd(50);

    queue qu(li);
    li.displayList();
    qu.enqueue(60);
    li.displayList();
    qu.dequeue();
    li.displayList();
}