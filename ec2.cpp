#include <iostream>
using namespace std;

struct Node {
    int data= 0;
    Node* next=nullptr;
    Node* prev=nullptr;
    Node* child=nullptr;
};

class list{
public:
    Node* head=nullptr;
    Node* tail=nullptr;

    void push_back(int x){
        Node* nodo = new Node;
        nodo->data = x;
        if (head!=nullptr){
            tail->next = nodo;
            nodo->prev = tail;
            tail=nodo;
        } else{
            head=nodo;
            tail=head;
        }

    }
    void push_child (int pos,list x) const{
        Node* chil = head;
        for (int i=0;i<=pos;i++){
            chil=chil->next;
        }
        chil->child=x.head;
    }
};

list crear(){
    list arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    return arr;
}

void print(list arr){
    Node* temp = arr.head;
    while (temp != nullptr) {
        cout << temp->data;
        temp=temp->next;
    }
}

void aplanar(list arr){
    Node* temp = arr.head;
    while (temp != nullptr) {
        if (temp->child!= nullptr) temp=temp->next;
        else{
            aplanar(temp->child->data);
            temp=temp->child;
            temp->next=temp->child;
            temp->next->prev=temp;
            temp->child= nullptr;
        }
    }
}

int main(){
    list arr1=crear();
    list arr2=crear();
    list arr3=crear();
    arr1.push_child(3,arr2);
    arr2.push_child(3,arr3);
    print(arr3);
}

/*
 list ARR;
    aplanar(ARR);
    print(ARR)


class BrowserHistory{
    public:
    Node* head=nullptr;
    Node* tail=nullptr;
    BrowserHistory (string page){
        head->data=page;
        head->next= nullptr;
        head->prev= nullptr;
        tail=head;
    }
    void visit (string url){
        Node* nodo = new Node;
        nodo->data = url;
        nodo->prev  = head;
        nodo->next = nullptr;
        head->next=nodo;
        tail = nodo;
        cout<<"Visit "<<url;
    }
    string back(int steps){
        Node* temp = tail;
        if (head!=nullptr && temp->prev!= nullptr){
            for(int i=1;i<=steps;i++){
                temp=temp->prev;
            }
        }
        if (temp->prev== nullptr){
            temp=head;
        } cout<<temp->data;
    }
    string forward(int steps){
        Node* temp = tail;
        if (head!=nullptr && temp->next!= nullptr){
            for(int i=1;i<=steps;i++){
                temp=temp->next;
            }
        }
        if (temp->next== nullptr){
            temp=head;
        } cout<<temp->data;
    }
};

int main() {
    BrowserHistory* browserHistory = new BrowserHistory("leetcode.com");
    browserHistory->visit("google.com");
    browserHistory->visit("facebook.com");
    browserHistory->visit("youtube.com");
    browserHistory->back(1);
    browserHistory->back(1);
    browserHistory->forward(1);
    browserHistory->visit("linkedin.com");
    browserHistory->forward(2);
    browserHistory->back(2);
    browserHistory->back(7);
}
 */