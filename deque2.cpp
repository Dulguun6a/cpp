#include <iostream>
using namespace std;

template <class type>
struct Deque{
    struct node{
        type data;
        node *next;
        node *prev;
    };
    node *tail;
    node *head;
    Deque(){
        tail = nullptr;
        head = nullptr;
    }
    void push_back(type x){
        node *p = new node;
        p -> data = x;
        p -> next = nullptr;
        if(tail == nullptr){
        tail = head = p;
        }else{
            p -> next = tail;
            tail = p;
        }
    }
    void push_front(type x){
        node *p = new node;
        p -> data = x;
        p -> prev = nullptr;
        if(tail == nullptr){
        tail = head = p;
        }else{
            p -> next = head;
            head = p;
        }
    }
    void pop_front(){
        node *p = head;
        head = head -> next;
        delete p;
        if(head == nullptr){
            tail = nullptr;
        } else {
            head -> prev = nullptr;
        }
    }
    void pop_back(){
        node *p = tail;
        tail = tail -> prev;
        delete p;
        if(tail == nullptr){
            head = nullptr;
        } else {
            tail -> next = nullptr;
        }
    }
    type front(){
        return head -> data;
    }
    type back(){
        return tail -> data;
    }
    bool empty(){
        if(head == nullptr && tail == nullptr) return 1;
        else return 0;
    }
};
int main(){
    Deque <int> s;
    s.push_front(40);
    s.push_back(30);
    s.push_front(20);
    s.pop_back();
    cout  << s.back() << endl;
}