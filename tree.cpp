#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;

int Max(int a,int b){return (a>b)?a:b;}
void print_spaces(int x){for(int i=0;i<x;++i)printf(" ");}

class Node{
public:
    int value;
    Node* left;
    Node *right;
    Node(int a):value(a),left(NULL),right(NULL){}
};

class BinarySearchTree{
private:

    void InorderHelper(vector<vector<int>>& t,Node* x,int s) {
        if (x == NULL)return;
        InorderHelper(t,x->left,s+1);
        t[s].push_back(x->value);
        InorderHelper(t,x->right,s+1);
    }
    
    int LevelsHelper(Node* x){
        if(x==NULL)return 0;
        else return 1+Max(LevelsHelper(x->right),LevelsHelper(x->left));
    }
    
    int Levels(){
        Node* x = root;
        return LevelsHelper(x);
    }
    
public:
    Node* root;
    int num_of_elements;
    BinarySearchTree():root(NULL),num_of_elements(0){};

    void Insert(int n) {
        Node* p = new Node(n);
        if(root==NULL){
            root=p;
            num_of_elements++;
        }
        else{
            Node** x=&root;
            while(*x!=NULL){
                if(n<(*x)->value)x=&(*x)->left;
                else x=&(*x)->right;
            }
            *x=p;
            num_of_elements++;
        }
    }
    
    
    void Print(){
        int h=Levels();
        vector<vector<int>> t(h);
        InorderHelper(t,root,0);
        for(int i=0;i<h;++i){
            printf("%d: ",i+1);
            print_spaces((1<<(h-i-1))-1);
            for(int j=0;j<t[i].size();++j){               
                printf("%d",t[i][j]);
                print_spaces((1<<(h-i))-1);
            }
            printf("\n");
        }
    }
    

};

int main(){
    BinarySearchTree t;
    t.Insert(7);
    t.Insert(3);
    t.Insert(11);
    t.Insert(1);
    t.Insert(5);
    t.Insert(9);
    t.Insert(13);
    t.Insert(0);
    t.Insert(2);
    t.Insert(4);
    t.Insert(6);
    t.Insert(8);
    t.Insert(10);
    t.Insert(12);
    t.Insert(14);
    t.Print();
}