#include <iostream>
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
    }

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
    }

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

    void deleteMax() {
        if (heap_size==0) {cout<<"No hay max"<<endl; return;}
        heap[0]=heap[--heap_size];
        heapifydown(0);
    }

    int getMax() const {
        if (heap_size==0) {cout<<"No hay max"<<endl; return -1;}
        return heap[0];
    }

    void printHeap() const {
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

    void deleteMin() {
        if (heap_size==0) {cout<<"No hay max"<<endl; return;}
        heap[0]=heap[--heap_size];
        heapifydown(0);
    }

    int getMin() const {
        if (heap_size==0) {cout<<"No hay max"<<endl; return -1;}
        return heap[0];
    }

    void printHeap() const {
        for (int i=0; i<heap_size; i++) cout<<heap[i]<<" ";
        cout<<endl;
    }
};

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

    h.printHeap();

    cout<<"Valor Max: "<<h.getMax()<<endl;
    h.deleteMax();
    h.printHeap();


    MinHeap h2(10);

    h2.insert(30);
    h2.insert(20);
    h2.insert(15);
    h2.insert(5);
    h2.insert(10);
    h2.printHeap();
    cout << "Min value: "<<h2.getMin()<<endl;
    h2.deleteMin();
    h2.printHeap();
}
