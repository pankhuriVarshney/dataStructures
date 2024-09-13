#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *right;
    node *left;

    node(int data){
        this->data=data;
        right=nullptr;
        left=nullptr;
    }
};

class binaryTree{
    private:
    node *root;
    void inorderPrint(node *n){
        if(n == nullptr) return;  

        if(n->left != nullptr) {
            inorderPrint(n->left);
        }
        cout << n->data << "\t";
        if(n->right != nullptr) {
            inorderPrint(n->right);
        }
    }

    public:
    binaryTree(){
        this->root=nullptr;
    }

    void addNode(int val){
        node *newNode=new node(val);
        if(root==nullptr){
            root=newNode;
            return;
        }
        else{
            node *temp=root;
            while(temp->right!=nullptr && temp->left!=nullptr){
                if(temp->data<val){
                    temp=temp->right;
                }
                else{
                    temp=temp->left;
                }
            }
            if(temp->data<val)
                temp->right=newNode;

            else if(temp->data>val)
                temp->left=newNode;
        }
    }

    void inorderPrint(){
        inorderPrint(root);  
        cout << endl;

    }

};

int main(){
    binaryTree tree;
    tree.addNode(10);
    tree.addNode(5);
    tree.addNode(15);
    tree.addNode(3);

    tree.inorderPrint();
}