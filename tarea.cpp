#include <iostream>
using namespace std;

struct node{
    int data=0;                 // valor del nodo
    node* next= nullptr;        // puntero del nodo
};
class list{
    public:
    node* head= nullptr;        // cabeza de la lista, iniciada en NULL

    int& operator[](int index) {
        int cont=0;
        node *temp = head;
        while (temp != nullptr && cont != index) {
            temp = temp->next;
            cont++;
        } if (index < 0 || index >= cont) throw out_of_range("Índice fuera de rango");
        return temp->data;
    }
    void push_front(int x){
        node* nodo = new node;
        nodo->data = x;
        nodo->next = head;
        head = nodo;
    };
    void front() const{
        if (head==nullptr) return;
        cout<<head->data;
    }
    void back() const{
        if (head==nullptr) return;
        node* temp = head;
        while (temp->next != nullptr) temp=temp->next;
        cout<<temp->data;
    }
    void push_back(int x) const{
        if (head==nullptr) return;
        node* temp = head;
        while (temp->next != nullptr) temp=temp->next;
        node* nodo = new node;
        temp->next=nodo;
        nodo->data = x;
        nodo->next = nullptr;
    }
    void pop_front(){
        if (head==nullptr) return;
        node* temp = head;
        head=head->next;
        delete temp;
    }
    void pop_back(){
        if (head==nullptr) return;
        if (head->next==nullptr){
            delete head;
            head= nullptr;
        } else{
            node* temp = head;
            while (temp->next->next != nullptr) temp=temp->next;
            delete temp->next;
            temp->next= nullptr;
        }
    }
    bool empty(){
        bool condi=false;
        if (head==nullptr) condi=true;
        return condi;
    }
    int size(){
        int len=0;
        node* temp = head;
        while (temp != nullptr) {temp=temp->next; len++;}
        return len;
    }
    void clear(){
        node* temp = head;
        while (temp != nullptr) {
            head=head->next;
            delete temp;
            temp=head;
        }
    }
    //void sort(){};
    void reverse(){
        node* temp = head;
        node* temp2;
        int cont=0;
        while (temp != nullptr) {
            cont++;
            node* temp3 = temp;
            push_front(temp->data);
            if (cont==1) temp2=head;
            temp=temp->next;
            temp2->next=temp;
            delete temp3;
        } delete temp;
    }
};

list crear(){
    list arr;
    arr.push_front(6);
    arr.push_front(5);
    arr.push_front(4);
    arr.push_front(3);
    arr.push_front(2);
    return arr;
}

void print(list arr){
    node* temp = arr.head;
    while (temp != nullptr) {
        cout << temp->data;
        temp=temp->next;
    }
}

int main(){
    list arr=crear();
    //arr.reverse();
    cout<<arr[1];
    //cout<<arr.size()<<endl;
    print(arr);
}