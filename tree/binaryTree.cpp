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
    void preorder(node *n){
        if(n==nullptr){
            return;
        }
        cout<<n->data<<"\t";
        if(n->left!=nullptr){
            preorder(n->left);
        }
        if(n->right!=nullptr){
            preorder(n->right);
        }
    }
    void postorder(node *n){
        if(n==nullptr)
            return;
        if(n->left!=nullptr){
            postorder(n->left);
        }
        if(n->right!=nullptr){
            postorder(n->right);
        }
        cout<<n->data<<"\t";
    }
    //inserting a node using recursion:
    node* insert(node *n, int val){
        
        if(n==NULL){
            node *newNode=new node(val);
            n=newNode;
        }
        if(val < n->data){
            n->left=insert(n->left, val);
        }
        else if(val > n->data){
            n->right=insert(n->right, val);
        }

        return n;
    };

    public:
    binaryTree(){
        this->root=nullptr;
    }
    
    //inserting a node without recursion:
    void addNode(int val){
        node *newNode=new node(val);
        if(root==nullptr){
            root=newNode;
            return;
        }
        node *temp=root;
        while(true){
            if(temp->data<val){
                if(temp->right==nullptr){
                    temp->right=newNode;
                    return;
                }
                temp=temp->right;
            }
            else if(temp->data>val){
                if(temp->left==nullptr){
                    temp->left=newNode;
                }
                temp=temp->left;
            }
            else{
                return;
            }
        }
    }

    //public functions for calling private funcs():
    void insert(int val){
        insert(root, val);
    }

    void inorderPrint(){
        inorderPrint(root);  
        cout << endl;

    }
    void preorder(){
        preorder(root);
        cout<<endl;
    }
    void postorder(){
        postorder(root);
        cout<<endl;
    }
};

int main(){
    binaryTree tree;
    tree.addNode(10);
    tree.addNode(5);
    tree.addNode(15);
    tree.addNode(3);
    tree.addNode(4);

    cout<<"INORDER TRAVERSAL:\t";
    tree.inorderPrint();
    cout<<"PREORDER TRAVERSAL:\t";
    tree.preorder();
    cout<<"POSTORDER TRAVERSAL:\t";
    tree.postorder();

    cout<<"\nUSING RECURSION:\n";
    binaryTree tree2;
    tree2.insert(10);
    tree2.insert(5);
    tree2.insert(3);
    tree2.insert(15);
    tree2.insert(4);
    cout<<"INORDER TRAVERSAL:\t";
    tree.inorderPrint();
    cout<<"PREORDER TRAVERSAL:\t";
    tree.preorder();
    cout<<"POSTORDER TRAVERSAL:\t";
    tree.postorder();


}