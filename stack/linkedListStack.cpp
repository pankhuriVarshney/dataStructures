#include <iostream>
using namespace std;

class Stack {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* top;      
    int MAX_SIZE;  
    int currentSize; 

public:
    Stack(int size) : top(nullptr), MAX_SIZE(size), currentSize(0) {}

    ~Stack() {
        while (top) {
            pop();  // Destructor to clean up memory
        }
    }

    // Push a value onto the stack
    void push(int val) {
        if (currentSize == MAX_SIZE) {  // Check if stack has reached its max size
            cout << "STACK OVERFLOW!" << endl;
            return;
        }
        Node* newNode = new Node(val);  // Create a new node
        newNode->next = top;  // Link the new node to the current top
        top = newNode;  // Make the new node the top of the stack
        currentSize++;  // Increment the current size
        cout << "ADDED: " << val << endl;
    }

    // Pop the top value from the stack
    void pop() {
        if (top == nullptr) {
            cout << "STACK UNDERFLOW!" << endl;
            return;
        }
        Node* temp = top;  // Temporary pointer to hold the top node
        cout << "REMOVED: " << top->data << endl;
        top = top->next;  // Move the top to the next node
        delete temp;  // Delete the old top node
        currentSize--;  // Decrement the current size
    }

    // Display the stack elements
    void display() {
        if (top == nullptr) {
            cout << "EMPTY STACK" << endl;
            return;
        }
        Node* temp = top;  // Temporary pointer to traverse the stack
        while (temp) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

    // Check if the stack is full
    bool isFull() const {
        return currentSize == MAX_SIZE;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return currentSize == 0;
    }
};

int main() {
    int maxSize;
    cout << "Enter the Max Size of the Stack: ";
    cin >> maxSize;

    Stack s(maxSize);

    s.push(10);
    s.display();

    s.push(20);
    s.display();

    s.push(30);
    s.display();

    s.push(40);  // Might hit overflow if max size is small
    s.display();

    s.pop();
    s.display();

    s.pop();
    s.display();

    s.pop();
    s.display();

    s.pop();
    s.display();

    return 0;
}
