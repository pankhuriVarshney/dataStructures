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
    
    int countNodes(node* root) {
        if (root == NULL)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int sumNodes(node* root) {
        if (root == NULL)
            return 0;
        return root->data + sumNodes(root->left) + sumNodes(root->right);
    }

    node* findMin(node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    node* findMax(node* root){
        while(root->right!=nullptr){
            root=root->right;
        }
        return root;
    }

    node* delNode(node* root, int key) {
        if (root == nullptr) {
            return root;  
        }

        if (key < root->data) {
        } else if (key > root->data) {
            root->right = delNode(root->right, key); 
        } else {
            // Case 1: Node with no children (leaf node)
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            // Case 2: Node with only one child
            else if (root->left == nullptr) {
                node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                node* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Node with two children
            else {
                // node* temp = findMin(root->right);  
                node *temp=findMax(root->left);
                root->data = temp->data;           
                // root->right = delNode(root->right, temp->data);  
                root->left=delNode(root->left, temp->data);
            }
        }
        return root;
    }


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
                    return;
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
    void count(){
        int c=countNodes(root);
        cout<<"COUNT:\t"<<c<<endl;
    }
    void sum(){
        int s=sumNodes(root);
        cout<<"SUM: "<<s<<endl;
    }

    void delNode(int key){
        root=delNode(root, key);
    }
};

int main(){
    binaryTree tree;
    tree.addNode(56);
    tree.addNode(78);
    tree.addNode(45);
    tree.addNode(22);
    tree.addNode(72);
    tree.addNode(90);
    tree.addNode(66);
    tree.addNode(43);
    tree.addNode(73);
    tree.addNode(101);
    tree.addNode(65);
    tree.addNode(67);

    cout<<"INORDER TRAVERSAL:\t";
    tree.inorderPrint();
    cout<<"PREORDER TRAVERSAL:\t";
    tree.preorder();
    cout<<"POSTORDER TRAVERSAL:\t";
    tree.postorder();


    tree.delNode(43);
    cout<<"DELETING 43 (inorder):\t";
    tree.inorderPrint();
    tree.delNode(56);
    cout<<"DELETING 56 (preorder):\t";
    tree.preorder();
    tree.delNode(101);
    cout<<"IDELETING 101 (postorder):\t";
    tree.postorder();
}