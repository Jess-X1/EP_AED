#include <iostream>
using namespace std;
int const maxi=100;

//clase del tipo elemento:
typedef class element{
public:
    int key; // TIPO DE VALOR
} element;

typedef class queue{
public:
    element list[maxi];
    int front=0, rear=0;

    //FUNCIONES ---------------------------------------
    //me dice si esta lleno
    int isfull(){
        if ((front==rear+1)%maxi) return 1;
        return 0;
    }

    int isempty() {
        if (front==rear) return 1;
        return 0;
    }

    void enqueue(element e) {
        rear = (rear+1)%maxi;
        list[rear]=e;
    };

    element dequeue(){
        front=(front+1)%maxi;
        return list[front];
    };

} queue;

element front(queue q) {
    return q.list[q.front+1];
}

int main(){
    queue Q;
    element e;
    e.key=2;
    Q.enqueue(e);
    e.key=3;
    Q.enqueue(e);
    cout<<front(Q).key<<' ';
    cout<<Q.dequeue().key<<' ';
    cout<<front(Q).key<<' ';
}