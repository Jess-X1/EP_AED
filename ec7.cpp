#include <iostream>
#include <string>
#include <vector>
using namespace std;
int const maxi=100;

// COLAS
template <typename T2>
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
    void enqueue(T2* node) {
        rear = (rear+1)%maxi;
        list[rear]=node;
    };
    T2* dequeue(){
        front=(front+1)%maxi;
        return list[front];
    };
};
template <typename T2>
T2* front(queue<T2> q) {return q.list[q.front+1];}

// NODOS BST
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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
            case 4: {//breadth
                if (n==nullptr) return;
                queue<TreeNode> q;
                q.enqueue(n);
                while (!q.isempty()){
                    TreeNode* node = q.dequeue();
                    cout<<node->val<<' ';
                    if(node->left != nullptr)
                        q.enqueue(node->left);
                    if(node->right != nullptr)
                        q.enqueue(node->right);
                    //solo para imprimir como "arbol"
                    auto actual = front(q);
                    if (!q.isempty() && (actual->val<node->val || node->right==actual)) cout<<endl;
                } break;}
            default: return;
        }
    }
public:
    TreeNode* root= nullptr;
    void insert(int value) {recuri(root, value);}
    void find(int value) {recurf(root, value);}
    void remove(int value) {recurr(root, nullptr, value);}
    void breadth(){ordenes(root,4); cout<<endl;}
};

// NODOS AVL
struct NodeBT {
    int data;
    int h=0;
    int f=0;
    NodeBT *left= nullptr;
    NodeBT *right= nullptr;
};

// ARBOL AVL
class AVL{
private:
    bool recuri(NodeBT* &node, int value){
        //SI NO LO ENCUENTRA
        if(node==nullptr) {
            auto* nuevo = new NodeBT;
            nuevo->data=value;
            node = nuevo;
            return true;
        }
            // proceso recursivo
        else if(value < node->data)
            return recuri(node->left, value);
        else if(value > node->data)
            return recuri(node->right, value);
            //SI LO ENCUENTRA
        else return false;
    }
    bool recurf(NodeBT* &node, int value){
        //SI NO LO ENCUENTRA
        if(node==nullptr) return false;
            // proceso recursivo
        else if(value < node->data)
            return recurf(node->left, value);
        else if(value > node->data)
            return recurf(node->right, value);
        //SI LO ENCUENTRA
        return true;
    }
    bool recurr(NodeBT* &node, NodeBT* viejo, int value){
        //SI NO LO ENCUENTRA
        if(node==nullptr) return false;
            // proceso recursivo
        else if(value < node->data)
            return recurr(node->left,node,value);
        else if(value > node->data)
            return recurr(node->right, node, value);
        //SI LO ENCUENTRA
        del(node,viejo);
        return true;
    }
    int del(NodeBT* &node, NodeBT* viejo){
        // Se supone que lo encontramos
        int save=node->data;
        //Eliminar un nodo con 2 hijos
        if(node->left!=nullptr && node->right!=nullptr) {
            NodeBT *temp = node->right;
            viejo=temp;
            while (temp->left != nullptr) temp = temp->left;
            node->data = del(temp,viejo); //chapo al sucesor
        }//Eliminar una HOJA
        else if(node->left==nullptr && node->right==nullptr) {
            if (viejo->left==node) viejo->left=nullptr;
            if (viejo->right==node) viejo->right=nullptr;
            delete node;
        }
            //Eliminar un nodo con 1 hijo
        else {
            if(node->left!=nullptr) node->data=del(node->left,node);
            else if(node->right!=nullptr) node->data=del(node->right,node);
        }
        return save;
    }
    static void RRote(NodeBT* &Y){
        NodeBT* Z = Y->left;
        Y->left = Z->right;
        Z->right = Y;
        Y = Z;
    };
    static void LRote(NodeBT* &X){
        NodeBT* Z = X->right;
        X->right = Z->left;
        Z->left = X;
        X = Z;
    };
public:
    NodeBT* root= nullptr;
    void insert(int value) {recuri(root, value); h(root); f(root); balanced(root);}
    void find(int value) {recurf(root, value);}
    void remove(int value) {recurr(root, nullptr, value); h(root); f(root); balanced(root);}

    int h(NodeBT* n){
        int hi=-1;
        int hd=-1;
        if (n->left!=nullptr) hi=h(n->left);
        if (n->right!= nullptr) hd=h(n->right);
        n->h=max(hi,hd)+1;
        return n->h;
    };
    int f(NodeBT* n){
        int hi=-1;
        int hd=-1;
        if (n->left!=nullptr) {
            hi=n->left->h;
            f(n->left);
        }
        if (n->right!= nullptr) {
            hd=n->right->h;
            f(n->right);
        }
        return n->f=hi-hd;
    };

    void balanced(NodeBT* &n){
        if (n->left!= nullptr) balanced(n->left);
        if (n->right!= nullptr) balanced(n->right);
        if (n->f>=2){
            if (n->left->f<=-1) {LRote(n->left); RRote(n);}
            else RRote(n);
            h(root); f(root);
            balanced(n);
        } if (n->f<=-2){
            if (n->right->f>=1) {RRote(n->right); LRote(n);}
            else LRote(n);
            h(root); f(root);
            balanced(n);
        }
    }
};

/* ARBOL comun
class tree{
public:
    TreeNode* root= nullptr;
    bool insert(TreeNode* &node, int value) {
        auto* nuevo = new TreeNode; nuevo->val=value;
        if (node==nullptr) {node=nuevo; return true;}
        if (node!= nullptr) return false;
        if (insert(node->left,value)) return true;
        if (insert(node->right,value)) return true;
    }
};*/

class Solution {
public:
    //ejer 1 comprobar si el arbol está balanceado
    bool ok;
    int hs(TreeNode* root){
        if (root== nullptr) return 0;
        int hi=hs(root->left)+1;
        int hd=hs(root->right)+1;
        if (abs(hi-hd)>=2) ok=false;
        return max(hi,hd);
    }
    bool isBalanced(TreeNode* root) {
        ok=true;
        hs(root);
        return ok;
    }

    //ejer 2 balancear un arbol a partir de un BST
    NodeBT* bst2avl(TreeNode* feo){
        if (feo==nullptr) return nullptr;
        NodeBT* yap= new NodeBT;
        yap->data=feo->val;
        yap->left=bst2avl(feo->left);
        yap->right=bst2avl(feo->right);
        return yap;
    }
    TreeNode* avl2bst(NodeBT* feo){
        if (feo==nullptr) return nullptr;
        TreeNode* yap= new TreeNode;
        yap->val=feo->data;
        yap->left=avl2bst(feo->left);
        yap->right=avl2bst(feo->right);
        return yap;
    }
    TreeNode* balanceBST(TreeNode* root) {
        NodeBT* dnv;
        dnv=bst2avl(root);
        //ARBOL balanced
        AVL ord;
        ord.root=dnv;
        ord.h(ord.root);
        ord.f(ord.root);
        ord.balanced(ord.root);
        return avl2bst(ord.root);
    }

    //ejer 3 "balancear un arbol" si me dan un array desordenado

    vector<int> BubbleSort(vector<int>& arr){
        for(int i=0; i<arr.size(); i++)
            for(int j=0;j<arr.size();j++)
                if(arr[j]>arr[i]) swap(arr[j],arr[i]);
        return arr;
    }

    TreeNode* sortedarr2avl(vector<int> arr,int ini, int fin){
        if (ini>fin) return nullptr;
        int mitad=(ini+fin)/2;
        TreeNode* nodo=new TreeNode;
        nodo->val=arr[mitad];
        nodo->right=sortedarr2avl(arr,mitad+1,fin);
        nodo->left=sortedarr2avl(arr,ini,mitad-1);
        return nodo;
    }

    TreeNode* solve(vector<int> arr){
        arr= BubbleSort(arr);
        int ini=0;
        int fin=arr.size()-1;
        return sortedarr2avl(arr,ini,fin);
    }
};

int main(){
    /*
    BST arbol;
    int nums[]={1,2,3,4,5,6};
    for (auto i:nums) arbol.insert(i);

    arbol.breadth();
    cout<<endl;

    Solution s;
    cout<<s.isBalanced(arbol.root)<<endl;
    arbol.breadth();
    cout<<endl;

    BST ola;
    ola.root=s.balanceBST(arbol.root);
    ola.breadth();
    cout<<s.isBalanced(ola.root)<<endl;*/
    vector<int> o={2, 4, 1, 3, 5, 6, 7};
    Solution s;
    BST arbol;
    arbol.root=s.solve(o);
    arbol.breadth();
}