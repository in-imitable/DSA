#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    // Creating constructor to initialize the data for a node
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// PreOrder function for Binary Tree
void preOrderTraverse(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrderTraverse(root->left);
        preOrderTraverse(root->right);
    }
}

// PostOrder function for Binary Tree
void postOrderTraverse(node *root)
{
    if (root != NULL)
    {
        postOrderTraverse(root->left);
        postOrderTraverse(root->right);
        cout << root->data << " ";
    }
}

// InOrder function for Binary Tree
void inOrderTraverse(node *root)
{
    if (root != NULL)
    {
        inOrderTraverse(root->left);
        cout << root->data << " ";
        inOrderTraverse(root->right);
    }
}

//isBST() method for check whether a tree in Binary Search Tree or Not!
int isBST(node* root){
    static node* prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

int main()
{

    node *p = new node(6);
    node *p1 = new node(3);
    node *p2 = new node(4);
    node *p3 = new node(5);
    node *p4 = new node(2);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // cout << "Printing preorder tree elements:" << endl;
    // preOrderTraverse(p);

    // cout << "\nPrinting postorder tree elements:" << endl;
    // postOrderTraverse(p);

    cout << "\nPrinting inorder tree elements:" << endl;
    inOrderTraverse(p);

    if(isBST(p)){
        cout<<"\nIt is BST"<<endl;
    }
    else{
        cout<<"\nIt is not BST"<<endl;
    }

    return 0;
}