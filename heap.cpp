#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    int* heap;
    int capa;
    int heap_size;
    void heapifyup(int index) {
        while (index != 0 && heap[padre(index)] < heap[index]) {
            swap(heap[index], heap[padre(index)]);
            index = padre(index);
        }
    } //solo se aplica hasta la raiz
    void heapifydown(int index) {
        int mayor=index;
        int hijoizq=left(index);
        int hijoder=right(index);
        if (hijoizq<heap_size && heap[hijoizq]>heap[mayor]) mayor=hijoizq;
        if (hijoder<heap_size && heap[hijoder]>heap[mayor]) mayor=hijoder;
        if (mayor!=index) {
            swap(heap[index],heap[mayor]);
            heapifydown(mayor);
        }
    } //solo se aplica hasta la hoja
    int padre(int index) {return (index-1)/2;}
    int left(int index) {return (2*index+1);}
    int right(int index) {return (2*index+2);}

public:
    MaxHeap(int capa) {
        this->capa=capa;
        heap_size=0;
        heap=new int[capa];
    }
    ~MaxHeap() {delete[] heap;}

    int size() const {return heap_size;}
    bool empty() const {return heap_size==0;}
    void insert(int element) {
        if (heap_size==capa) {cout<<"No se puede"<<endl; return;}
        heap[heap_size] = element;
        heapifyup(heap_size);
        heap_size++;
    }
    int popMax() {
        if (heap_size==0) {cout<<"No hay max"<<endl; return -1;}
        int guard=heap[0];
        heap[0]=heap[--heap_size];
        heapifydown(0);
        return guard;
    }
    int getMax() const {
        if (heap_size==0) {cout<<"No hay max"<<endl; return -1;}
        return heap[0];
    }
    int* top(){return heap;}
    void sort(){
        int cant=0;
        while (size()){
            int guard=popMax();
            heap[heap_size]=guard;
            cant++;
        } heap_size=cant;
    }
    void print() const {
        for (int i=0; i<heap_size; i++) cout<<heap[i]<<" ";
        cout<<endl;
    }
};

class MinHeap {
private:
    int* heap;
    int capa;
    int heap_size;
    void heapifyup(int index) {
        while (index != 0 && heap[padre(index)] > heap[index]) {
            swap(heap[index], heap[padre(index)]);
            index = padre(index);
        }
    }
    void heapifydown(int index) {
        int menor=index;
        int hijoizq=left(index);
        int hijoder=right(index);
        if (hijoizq<heap_size && heap[hijoizq]<heap[menor]) menor=hijoizq;
        if (hijoder<heap_size && heap[hijoder]<heap[menor]) menor=hijoder;
        if (menor!=index) {
            swap(heap[index],heap[menor]);
            heapifydown(menor);
        }
    }
    int padre(int index) {return (index-1)/2;}
    int left(int index) {return (2*index+1);}
    int right(int index) {return (2*index+2);}

public:
    MinHeap(int capa) {
        this->capa=capa;
        heap_size=0;
        heap=new int[capa];
    }
    ~MinHeap() {delete[] heap;}

    int size() const {return heap_size;}
    bool empty() const {return heap_size==0;}
    void insert(int element) {
        if (heap_size==capa) {cout<<"No se puede"<<endl; return;}
        heap[heap_size] = element;
        heapifyup(heap_size);
        heap_size++;
    }
    void popMin() {
        if (heap_size==0) {cout<<"No hay max"<<endl; return;}
        heap[0]=heap[--heap_size];
        heapifydown(0);
    }
    int getMin() const {
        if (heap_size==0) {cout<<"No hay max"<<endl; return -1;}
        return heap[0];
    }
    void print() const {
        for (int i=0; i<heap_size; i++) cout<<heap[i]<<" ";
        cout<<endl;
    }
};
/*
int main() {
    MaxHeap h(10);
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(6);
    h.insert(7);
    h.insert(8);

    h.print();

    cout<<"Valor Max: "<<h.getMax()<<endl;
    h.deleteMax();
    h.print();


    MinHeap h2(10);

    h2.insert(30);
    h2.insert(20);
    h2.insert(15);
    h2.insert(5);
    h2.insert(10);

    h2.printHeap();  // Output should be: 5 10 15 30 20

    std::cout << "Min value: " << h2.getMin() << std::endl;  // Output should be: 5

    h2.deleteMin();
    h2.printHeap();  // Output should be: 10 20 15 3

}*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    vector<int> gen;

    vector<int> simplelist2vector(ListNode* o){
        vector<int> poder;
        ListNode* temp=o;
        while(temp!=nullptr) {
            poder.push_back(temp->val);
            temp=temp->next;
        }
        return poder;
    }
    ListNode* vector2simplelist(vector<int> o){
        ListNode* head= nullptr;
        for (auto i:o){
            ListNode* nodo = new ListNode;
            nodo->val = i;
            nodo->next = head;
            head = nodo;
        }
        return head;
    }
    ListNode* array2simplelist(int* o,int t){
        ListNode* head= nullptr;
        for (int i=0; i<t; i++){
            ListNode* nodo = new ListNode;
            nodo->val = o[i];
            nodo->next = head;
            head = nodo;
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto i:lists){
            ListNode* temp=i;
            while(temp!=nullptr) {
                gen.push_back(temp->val);
                temp=temp->next;
            }
        }
        MaxHeap mh(gen.size());
        for (auto i:gen) mh.insert(i);
        mh.print();
        mh.sort();
        return array2simplelist(mh.top(),mh.size());
    }
};

int main(){
    Solution s;
    ListNode n1(10, nullptr);
    ListNode n2(22,&n1);
    ListNode n3(3,&n2);
    ListNode n4(47,&n3);
    ListNode n5(15,&n4);
    ListNode n6(6,&n5);
    ListNode m1(11, nullptr);
    ListNode m2(2,&m1);
    ListNode m3(35,&m2);
    ListNode m4(7,&m3);
    ListNode m5(58,&m4);
    ListNode m6(3,&m5);
    vector<ListNode*> ola;
    ola.push_back(&n6);
    ola.push_back(&m6);
    cout<<s.mergeKLists(ola);
}
