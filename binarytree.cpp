#include <iostream>
using namespace std;

class Node{
    public:
    string info;
    Node* leftchild;
    Node* rightchild;

    //constructor for the node class
    Node (string i, Node* l, Node* r ){
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class BinaryTree {
    public:
    Node* ROOT;

    BinaryTree(){
        ROOT =nullptr; // initializing ROOT to null
    }

    void insert (string element) // insert a node in the binary search tree
    {
        Node* newNode = new Node(element, nullptr, nullptr);
        newNode->info = element; //assign vvalur to the data field of the new node
        newNode->leftchild = nullptr; // make the left child of the new node point to NULL
        newNode->rightchild = nullptr; // make the right child of the new node point to NULL
        
        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search (element, parent, currentNode); // locate the node which will be the parent pf the node to the insert

        if (parent == nullptr){ //if the parent is NULL (tree is empty)
            ROOT = newNode; // mark the new node as ROOT
            return; // Exit
        }
        
        if(element < parent->info) //if the value in the data field of the new node is less
        {
            ROOT = newNode; // make the left child of the parent point to the new node 
        }
        else if (element > parent -> info)// if the value in the data field of the new node is greater then that..
        {
            parent-> rightchild = newNode; //amke the right child of the parent point to the new node
        }
    }

    void search(string element, Node*& parent, Node*& currentNode){
        currentNode = ROOT;
        parent = NULL;
        while ((currentNode != NULL) && (currentNode->info != element)){
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }

    void inorder(Node* ptr){
        if (ROOT == NULL){
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr != NULL){
            inorder ( ptr->leftchild);
            cout << ptr->info << "";
            inorder (ptr->rightchild);
        }
    }

        void preorder(Node* ptr){
        if (ROOT == NULL){
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr != NULL){
            cout << ptr->info << "";
            preorder ( ptr->leftchild);
            preorder (ptr->rightchild);
        }
    }

        void postorder(Node* ptr){
        if (ROOT == NULL){
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr != NULL){
            postorder ( ptr->leftchild);
            postorder (ptr->rightchild);
            cout << ptr->info << "";
        }
    }
};

int main(){
    BinaryTree x;
    while (true){
        cout <<"\nMenu" << endl;
        cout << "1. implement insert operation" << endl;
        cout << "2. perform inorder traversal" << endl;
        cout << "3. perform preorder traversal" << endl;
        cout << "4. perform postorder traversal" << endl;
        cout << "5. exit" << endl;
        cout << "\nEnter your choice (1-5): ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch){
            case '1':{
                cout << "enter a word:";
                string word;
                cin >> word;
                x.insert(word);
                break;
            }
            case '2':{
                x.inorder(x.ROOT);
                break;
            }
            case '3':{
                x.preorder(x.ROOT);
                break;
            }
            case '4':{
                x.postorder(x.ROOT);
                break;
            }
        }
    }

}