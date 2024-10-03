#include <iostream>
using namespace std;

class Stack{
    int MAX_SIZE;
    int top;
    int *stack;
    public:
    Stack(int size): MAX_SIZE(size), top(-1){
        stack=new int[MAX_SIZE];
    }

    ~Stack(){
        delete[] stack;
    }

    void push(int val){
        if(top==MAX_SIZE-1){
            cout<<"STACK OVERFLOW!"<<endl;
            return;
        }
        stack[++top]=val;
        cout<<"ADDED: "<<val<<endl;
    }
    void pop(){
        if(top==-1){
            cout<<"STACK UNDERFLOW!"<<endl;
            return;
        }
        cout<<"REMOVED: "<<stack[top]<<endl;
        stack[top--]=0;
    }
    void display(){
        if(top<0){
            cout<<"EMPTY STACK"<<endl;
            return;
        }
        for(int i=0; i<=top; i++){
            cout<<stack[i]<<"\t";
        }
        cout<<endl;
    }
};

int main(){
    cout<<"STACK USING ARRAYS: \nEnter the Max Size: ";
    int size;
    cin>>size;
    Stack s(size);
    s.push(10);
    s.display();

    s.push(20);
    s.display();

    s.push(30);
    s.display();

    s.push(40);
    s.display();

    s.pop();
    s.display();

    s.pop();
    s.display();

    s.pop();
    s.display();

    s.pop();
    s.display();
}