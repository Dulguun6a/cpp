#include <iostream>
using namespace std;

template <class type>
struct deque{
    struct node{
        type data;
        node* prev;
        node* next;
    };

    node* head;
    node* tail;

    deque(){
        tail = nullptr;
        head = nullptr;
    }

    void push_front(type x){
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

    void push_back(type x){
        node* p = new node;
        p -> data = x;
        p -> prev = nullptr;
        if (head == nullptr){
            tail = head = p;
        }else{
            head -> prev = p;
            head = p;
        }
    }

    void pop_front(){
        if (tail == nullptr){
            return;
        }
        node* p = tail;
        tail = tail -> prev;
        delete p;
        return;
    }

    void pop_back(){
        if (tail == nullptr){
            return;
        }
        node* p = head;
        head = head -> prev;
        if (head != nullptr){
        head -> next = nullptr;
        }else{
            tail = nullptr;
        }
        delete p;
    }

    type front(){
        return tail -> data;
    }

    type back(){
        return head -> data;
    }

    bool empty(){
        if(head == nullptr && tail == nullptr) return 1;
        else return 0;
    }
};

int main(){
    deque<int> q;
    q.push_front(10);
    q.push_back(20);
    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop_front();
    q.push_back(1);
    cout << q.front() << endl;
    cout << q.back() << endl;

    return 0;
}