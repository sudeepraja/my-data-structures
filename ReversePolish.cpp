#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;


class Node{
public:
    char x;
    Node* next;
    Node(int n=0):x(n),next(NULL){}
};

class Queue{
private:
    Node* head;
    Node *tail;
    int num;
public:
    Queue():head(NULL),tail(NULL),num(0){}
    
    ~Queue() {
        while(head)Dequeue();
    }

    void Enqueue(char n){
        Node* p = new Node(n);
        if(head==NULL) {
            head = p;
            tail=p;
            num++;
        }
        else{
            tail->next=p;
            tail=p;
            num++;
        }
        return;
    }

    int Dequeue() {
        int n = head->x;
        Node *p = head;
        head=head->next;
        free(p);
        num--;
        return n;
    }
    
    bool isEmpty(){
        return head==NULL;
    }
    
    char front(){
        return head->x;
    }
    
    char back(){
        return tail->x;
    }
    
    void Print(){
        Node* p=head;
        while(p){
            printf("%c",p->x);
            p=p->next;
        }
        printf("\n");
        return;
    }
};

class Stack{
private:
    Node* top;
    int num;
public:
    Stack():num(0),top(NULL){}
    ~Stack(){
        while(top)Pop();
    }
    
    void Push(char n) {
        Node* p = new Node(n);
        p->next = top;
        top = p;
        num++;
        return;
    }
    
    char Pop() {
        int n = top->x;
        Node *p = top;
        top = top->next;
        free(p);
        num--;
        return n;
    }
    
    char Top(){
        return top->x;
    }
    
    bool isEmpty(){
        return top==NULL;
    }

    void Print() {
        Node* p = top;
        while (p) {
            printf("%c", p->x);
            p = p->next;
        }
        printf("\n");
        return;
    }
};

int val(char s){
    if(s=='(')return 0;
    if(s=='+')return 1;
    if(s=='-')return 2;
    if(s=='*')return 3;
    if(s=='/')return 4;
    if(s=='^')return 5;
}

bool isLessorEq(char s,char t){
    return val(s)<=val(t);
}
int main(){

    int n;
    char s[400];
    scanf(" %d",&n);
    while(n){
        scanf(" %400[^\n]",s);
        Stack stack;
        Queue out;
        for(int i=0;i<strlen(s);i++){
            if(s[i]>='a'&& s[i]<='z'){
                out.Enqueue(s[i]);
            }
            else if(s[i]=='(')stack.Push(s[i]);
            else if(s[i]==')'){
                while(stack.Top()!='(')out.Enqueue(stack.Pop());
                stack.Pop();
            }
            else{
                if(stack.isEmpty())stack.Push(s[i]);
                else{
                    while((!stack.isEmpty()) && isLessorEq(s[i],stack.Top()))out.Enqueue(stack.Pop());
                    stack.Push(s[i]);
                }
            }
        }
        while(!stack.isEmpty()){
            out.Enqueue(stack.Pop());
        }
        out.Print();
        n--;
    }
    return 0;
}
