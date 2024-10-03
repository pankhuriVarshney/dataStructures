#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};
void search(Node *n, int key){
    if(n==NULL){
        cout<<("KEY NOT FOUND\n");
        return;
    }
    if(n->data==key){
        cout<<("KEY FOUND!\n");
        return;
    }
    if(key>n->data){
        search(n->right, key);
    }
    else{
    search(n->left, key);
    }
}

int main(){
    Node *root=new Node(8);
    root->left=new Node(3);
    root->right=new Node(10);
    root->left->left=new Node(1);
    root->left->right=new Node(6);
    root->left->right->left=new Node(4);
    root->left->right->right=new Node(7);
    root->right=new Node(10);
    root->right->right=new Node(14);

    search(root, 4);
}