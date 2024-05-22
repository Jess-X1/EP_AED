#include <iostream>
#include <vector>
#include <string>
using namespace std;

// NODOS BST
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BT{ // un tipo de arbol feo
public:
    TreeNode* root= nullptr;
    TreeNode* arr2bt(int* arr,int inicio, int final){
        if (inicio>=final) return nullptr;
        TreeNode* nuevo= new TreeNode;
        if (arr[inicio]==-1) nuevo=nullptr;
        else nuevo->val=arr[inicio];
        if (nuevo!=nullptr) nuevo->left= arr2bt(arr,inicio*2+1,final);
        if (nuevo!=nullptr) nuevo->right= arr2bt(arr,inicio*2+2,final);
        return nuevo;
    }
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
    void insert(int value) {recuri(root, value);}
};

class Solution {
public:
    //ejer 1 me dice si un sub arbol pertenece a otro
    TreeNode* get_node(TreeNode* node, int value){
        if (node->val==value) return node;
        if (node->left) {
            TreeNode* xd= get_node(node->left,value);
            if (xd) return xd;
        }
        if (node->right) {
            TreeNode* xd= get_node(node->right,value);
            if (xd) return xd;
        }
        return nullptr;
    }

    bool compare(TreeNode* root, TreeNode* subRoot){
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;
        if (root->val==subRoot->val){
            auto ci=compare(root->left,subRoot->left);
            auto cd=compare(root->right,subRoot->right);
            return ci && cd;
        } else return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot) return false;
        root=get_node(root,subRoot->val);
        return compare(root,subRoot);
    }

    //ejer 2
    vector <TreeNode*> ola;
    vector <TreeNode*> deph(TreeNode* root){
        if (root->left== nullptr && root->right== nullptr) ola.push_back(root);

    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {

    }

    //ejer 3
    BT a;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        for (auto i: preorder) {
            a.insert(i);
        }
        return a.root;
    }


};

int main(){
    Solution s;
    /*
    BT a1,a2;
    int arr1[]={3,4,5,1,2};
    int arr2[]={4, 1,-1};
    a1.root=a1.arr2bt(arr1,0,sizeof(arr1)/sizeof(arr1[0]));
    a2.root=a2.arr2bt(arr2,0,sizeof(arr2)/sizeof(arr2[0]));
    cout<<s.isSubtree(a1.root,a2.root);*/

    /*
    vector<int> vec= {8,5,1,7,10,12};
    cout<<s.bstFromPreorder(vec)->right->val;
     */


}