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
        p -> prev = tail;
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
        p -> next = head;
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
    }
    void pop_back(){
        node *p = tail;
        tail = tail -> prev;
        delete p;
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
    s.push_front(30);
    cout << s.back();
    s.pop_front();
    cout << endl << s.front();
}