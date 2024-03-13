#include <iostream>
using namespace std;

template <class type>
struct Deque{
    struct node{
        type data;
        node* prev;
        node* next;
    };

    node* head;
    node* tail;

    Deque(){
        tail = nullptr;
        head = nullptr;
    }

    void push_front(type x){
        node* p = new node;
        p -> data = x;
        p -> next = head;
        p -> prev = nullptr;
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
        p -> prev = tail;
        p -> next = nullptr;
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
    Deque <int> s;
    s.push_front(10);
    s.push_back(20);
    cout << s.front() << endl;
    cout << s.back() << endl;
    s.pop_front();
    s.push_back(1);
    cout << s.front() << endl;
    cout << s.back() << endl;

    return 0;
}