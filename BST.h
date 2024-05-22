#include <iostream>
using namespace std;
int const maxi=100;

// NODOS AVL
struct NodeBT {
    int data;
    int h=0;
    int f=0;
    NodeBT *left= nullptr;
    NodeBT *right= nullptr;
};
// NODOS BST
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// PILAS
template <typename T2=TreeNode>
class stack{
public:
    T2* list[maxi];
    int top=-1; //index of the top element
    int isfull (){
        if (top>=maxi-1) return 1;
        else return 0;
    }
    int isempty(){
        if(top==-1) return 1;
        else return 0;
    }
    T2* pop(){
        TreeNode* xd=list[top];
        (top)--;
        return xd;
    }
    void push(T2* x){
        (top)++;
        list[top]=x;
    }
};

// COLAS
template <typename T2=TreeNode>
class queue{
public:
    T2* list[maxi];
    int front=0, rear=0;
    int isfull(){
        if ((front==rear+1)%maxi) return 1;
        return 0;
    }
    int isempty() {
        if (front==rear) return 1;
        return 0;
    }
    void enqueue(TreeNode* node) {
        rear = (rear+1)%maxi;
        list[rear]=node;
    };
    T2* dequeue(){
        front=(front+1)%maxi;
        return list[front];
    };
};
TreeNode* front(queue<> q) {return q.list[q.front+1];}

// ARBOL BST
class BST {
private:
    bool recuri(TreeNode* &node, int value){
        //SI NO LO ENCUENTRA
        if(node==nullptr) {
            auto* nuevo = new TreeNode;
            nuevo->val=value;
            node = nuevo;
            return true;
        }
            // proceso recursivo
        else if(value < node->val)
            return recuri(node->left, value);
        else if(value > node->val)
            return recuri(node->right, value);
            //SI LO ENCUENTRA
        else return false;
    }
    bool recurf(TreeNode* &node, int value){
        //SI NO LO ENCUENTRA
        if(node==nullptr) return false;
            // proceso recursivo
        else if(value < node->val)
            return recurf(node->left, value);
        else if(value > node->val)
            return recurf(node->right, value);
        //SI LO ENCUENTRA
        return true;
    }
    bool recurr(TreeNode* &node, TreeNode* viejo, int value){
        //SI NO LO ENCUENTRA
        if(node==nullptr) return false;
            // proceso recursivo
        else if(value < node->val)
            return recurr(node->left,node,value);
        else if(value > node->val)
            return recurr(node->right, node, value);
        //SI LO ENCUENTRA
        del(node,viejo);
        return true;
    }
    int del(TreeNode* &node, TreeNode* viejo){
        // Se supone que lo encontramos
        int save=node->val;
        //Eliminar un nodo con 2 hijos
        if(node->left!=nullptr && node->right!=nullptr) {
            TreeNode *temp = node->right;
            viejo=temp;
            while (temp->left != nullptr) temp = temp->left;
            node->val = del(temp,viejo); //chapo al sucesor
        }//Eliminar una HOJA
        else if(node->left==nullptr && node->right==nullptr) {
            if (viejo->left==node) viejo->left=nullptr;
            if (viejo->right==node) viejo->right=nullptr;
            delete node;
        }
            //Eliminar un nodo con 1 hijo
        else {
            if(node->left!=nullptr) node->val=del(node->left,node);
            else if(node->right!=nullptr) node->val=del(node->right,node);
        }
        return save;
    }
    void ordenes(TreeNode* n,int tipo){
        switch (tipo) {
            case 1: //preorder
                if (n==nullptr) return;
                cout<<n->val<<' ';
                ordenes(n->left,tipo);
                ordenes(n->right,tipo);
                break;
            case 2: //inorder
                if (n==nullptr) return;
                ordenes(n->left,tipo);
                cout<<n->val<<' ';
                ordenes(n->right,tipo);
                break;
            case 3: //postorder
                if (n==nullptr) return;
                ordenes(n->left,tipo);
                ordenes(n->right,tipo);
                cout<<n->val<<' ';
                break;
            case 4: {//breadth
                if (n==nullptr) return;
                queue<> q;
                q.enqueue(n);
                while (!q.isempty()){
                    TreeNode* node = q.dequeue();
                    cout<<node->val; cout<<' ';
                    if(node->left != nullptr)
                        q.enqueue(node->left);
                    if(node->right != nullptr)
                        q.enqueue(node->right);

                    //solo para imprimir como "arbol"
                    auto actual = front(q);
                    if (!q.isempty() && (actual->val<node->val || node->right==actual)) cout<<endl;
                } break;}
            case 5: {//depth
                if (n==nullptr) return;
                stack<> stack;
                stack.push(n);
                while(!stack.isempty()) {
                    TreeNode *node = stack.pop();
                    cout<<node->val<<' ';
                    if(node->right != nullptr)
                        stack.push(node->right);
                    if(node->left != nullptr)
                        stack.push(node->left);
                } break;}
            default: return;
        }
    }
public:
    TreeNode* root= nullptr;
    void insert(int value) {recuri(root, value);}
    void find(int value) {recurf(root, value);}
    void remove(int value) {recurr(root, nullptr, value);}

    NodeBT* bst2avl(TreeNode* feo){
        if (feo==nullptr) return nullptr;
        NodeBT* yap= new NodeBT;
        yap->data=feo->val;
        yap->left=bst2avl(feo->left);
        yap->right=bst2avl(feo->right);
        return yap;
    }

    void breadth(){ordenes(root,4); cout<<endl;}
    void preorder(){ordenes(root,1); cout<<endl;}
    void inorder(){ordenes(root,2); cout<<endl;}
    void postorder(){ordenes(root,3); cout<<endl;}
    void depth(){ordenes(root,5); cout<<endl;}
};
