#include <iostream>
using namespace std;

template<class type>
struct BST{
    struct node{
        type data;
        node *right;
        node *left;
    };
    node *root;
    node *current;
    BST(){
    root = nullptr;
    }
    void insert (type x){
        node *p = new node;
        p -> data = x;
        if(root == nullptr){
            root = p;
            root -> right = nullptr;
            root -> left = nullptr;
        }
        else if(root < p){
            root -> right = p;
            current = p;
            p -> right = nullptr;
            p -> left = nullptr;
        } else {
            root -> left = p;
            current = p;
            p -> right = nullptr;
            p -> left = nullptr;
        }
    }
    bool find(type x){
        node *p = new node;
        p -> data = x;
    }
};
int main(){
    BST <int> s;
    s.insert(40);
    s.insert(30);
}