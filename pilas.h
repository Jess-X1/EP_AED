#include <iostream>
using namespace std;
int const maxi=100;

//clase del tipo elemento:
typedef class element{
public:
    int key; // TIPO DE VALOR
} element;

//clase del tipo pila
typedef class stack{
public:
    element list[maxi];
    int top; //index of the top element

    //FUNCIONES ---------------------------------------
    //me dice si esta lleno
    int isfull (){
        if (top>=maxi-1) return 1;
        else return 0;
    }
    //eleimina" el valor en posicion top
    void pop(){(top)--;}

    //agrega el valor e en posición top
    void push(int x){
        element e;
        e.key=x;
        (top)++;
        list[top]=e;
    }
} stack;

//me brinda el elemento TOP del stack
element top(stack *s){ return s->list[s->top]; };

void print(stack pila){
    auto arr=pila.list;
    for(int i=0; i<pila.top+1; i++){
        cout<<arr[i].key;
    }
}

int main(){
    stack pila;
    pila.top=-1;
    top(&pila);
    pila.push(2);
    pila.push(3);
    print(pila);
    element a;
    a.key=2;
}