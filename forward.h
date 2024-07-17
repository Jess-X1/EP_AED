#include <iostream>

template <typename T>
class ForwardList : public List<T> {
    private:
        Node<T>* head;
        int nodes;
    
    public:
    
    ~ForwardList(){
            this->clear();	            
        }


    bool is_empty(){
        return this->head == nullptr;
    }

    int size(){
        return this->nodes;
    }

    T front(){
        if (!is_empty())
            return this->head->data;
        else
            throw("Lista vacía.");
    }

    T back(){
        if (!is_empty()){
            Node<T>* temp;
            temp = this->head;
            while(temp->next != NULL)
                temp = temp->next;
            
            T data = temp->data;
            return data;
        }
        else
            throw("Lista vacía.");
    }

    void push_front (T data){
        Node<T>* nodo = new Node<T>(data);

        if (!is_empty()){
            Node<T>* temp;
            temp = nodo;
            temp->next = this->head;
            this->head = temp;
        }

        else
            this->head = nodo;
        
        nodes++;
    }

    void push_back(T data){
        Node<T> *nodo = new Node<T>(data);

        if (!is_empty()){
            Node<T>* temp;
            temp = this->head;
            while(temp->next != NULL)
                temp = temp->next;
            
            temp->next = nodo;
            nodo->next = NULL;
        }
        else
            this->head = nodo;
        
        nodes++;
    }

    T pop_front(){

        if (!is_empty()){
            Node<T>* temp;
            T data;
            temp = this->head;
            
            this->head = this->head->next;
            data = temp->data;
            delete temp;

            nodes--;
            return data;
        }
        else
            throw("Lista vacía.");
    }

    T pop_back(){

        if (!is_empty()){
            T data;
            Node<T> *temp;
            temp = this->head;

            if (temp->next == NULL){
                data = this->head->data;
                delete head;
                this->head = nullptr;
                
                //return data;
            }
            else{

                while(temp->next->next != NULL)
                    temp = temp->next;
                
                data = temp->next->data;
                delete temp->next;
                
                //return data;
            }
            nodes--;
            return data;
            
        }
        else
            throw("Lista vacía.");
    }

    void clear(){
        
        if(!is_empty()){
            while(this->head != NULL){
                Node<T> *temp;
                temp = this->head;
                this->head = this->head->next;
                delete temp;
                nodes--;
            }
        }
        else
            throw("Lista vacia.");
        
    }

    void reverse(){
        Node<T>* temp = this->head;
        T dato;
        for (int n = 0; n < nodes; ++n){
            dato = pop_back();
            insert(dato, n);
        }
    }

    T insert(T data, int pos){
        if(!this->is_empty() && pos < this->nodes){
            Node<T>* temp = this->head;
            for(int i = 0; i < pos - 1; i++){
                temp = temp->next;
            }
            Node<T>* node = new Node<T>(data);
            node->next = temp->next;
            temp->next = node;          
            nodes++;
            return data;
        } else{
            throw ("Lista vacía");
        }
    }

    void sort(){
        if(!this->is_empty()){
            bool isSorted = this->is_sorted();
            while(!isSorted){
                isSorted = true;
                Node<T>* temp = this->head;      
                while(temp != nullptr && temp->next != nullptr){
                    if(temp->data > temp->next->data){
                        T aux = temp->data;
                        temp->data = temp->next->data;
                        temp->next->data = aux;
                        temp = temp->next;
                        isSorted = false;
                    }
                    temp = temp->next;
                }
            }
        } else{
            throw ("Lista vacía.");
        }
    }


    bool is_sorted(){
        if(head != nullptr){
            T prev = head->data;
            for(Node<T>* temp = head->next; temp!=nullptr; temp=temp->next){
                if(temp->data < prev)
                    return false;
                prev = temp->data;
            }
            return true;
        }
        else
            throw("Lista vacía.");
    }

    T& operator[](int pos){
        if(!this->is_empty() && pos < this->size()){
            Node<T>* temp = this->head;
            for(int i = 0; i < pos; i++){
                temp = temp->next;
            }
            return temp->data;
        } else{
            throw ("Lista vacía.");
        }
    }

};
