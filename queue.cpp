#include <iostream>
using namespace std;

template <class type>
struct Queue{
    struct node{
        type data;
        node *next;
    };
    node *tail;
    node *head;
    Queue(){
        tail = nullptr;
        head = nullptr;
    }
    void push(type x){
        if(tail == nullptr){
        node *p = new node;
        p -> data = x;
        p -> next = tail;
        tail = head = p;
        }else{
            p -> next = tail;
            tail = p;
        }
    }
    void pop(){
        node *p = head;
        head = head -> next;
        delete p;
    }
    type front(){
        return head -> data;
    }
    bool empty(){
        if(head == nullptr && tail == nullptr) return 1;
        else return 0;
    }
};
int main(){
    Queue <int> s;
    s.push(30);
    s.push(40);
    cout << s.front() << endl << s.empty() << endl;
    s.pop();
    cout << s.front();
    
}