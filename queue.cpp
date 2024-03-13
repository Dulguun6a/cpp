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
        node* p = new node;
        p -> data = x;
        p -> next = nullptr;
        if (tail == nullptr){
            head = tail = p;
        }else{
            tail -> next = p;
            tail = p;
        }
    }
    void pop(){
        if (tail == nullptr){
            return;
        }
        node* p = head;
        head = head -> next;
        if (head != nullptr){
        head -> next = nullptr;
        }else{
            tail = nullptr;
        }
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
    cout << s.front() << endl;
    s.pop();
    cout << s.front() << endl;
    s.pop();
    cout << s.empty();
}