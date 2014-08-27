#include<stdio.h>
#include<stdlib.h>

class Node {
public:
    int x;
    int w;
    Node* next;
    Node(int n = 0,int v=0) : x(n),w(v), next(NULL) {}
};

class LinkedList {
public:
    Node* head;
    int num;

    LinkedList() : head(NULL), num(0) {
    }

    ~LinkedList() {
        while (head)Remove();
    }

    void Append(int n,int v=0) {
        Node* p = new Node(n,v);
        p->next = head;
        head = p;
        num++;
        return;
    }

    void Remove() {
        Node *p = head;
        head = head->next;
        free(p);
        num--;
        return;
    }

    void Print() {
        Node* p = head;
        while (p) {
            printf("%d ", p->x);
            p = p->next;
        }
        printf("\n");
        return;
    }
};

class Queue {
private:
    Node* head;
    Node *tail;
    int num;
public:

    Queue() : head(NULL), tail(NULL), num(0) {
    }

    ~Queue() {
        while (head)Dequeue();
    }

    void Enqueue(int n,int v=0) {
        Node* p = new Node(n,v);
        if (head == NULL) {
            head = p;
            tail = p;
            num++;
        } else {
            tail->next = p;
            tail = p;
            num++;
        }
        return;
    }

    int Dequeue() {
        int n = head->x;
        Node *p = head;
        head = head->next;
        free(p);
        num--;
        return n;
    }

    bool isEmpty() {
        return head == NULL;
    }

    int front() {
        return head->x;
    }

    int back() {
        return tail->x;
    }

    void Print() {
        Node* p = head;
        while (p) {
            printf("%d ", p->x);
            p = p->next;
        }
        printf("\n");
        return;
    }
};

class Stack {
private:
    Node* top;
    int num;
public:

    Stack() : num(0), top(NULL) {
    }

    ~Stack() {
        while (top)Pop();
    }

    void Push(int n,int v=0) {
        Node* p = new Node(n,v);
        p->next = top;
        top = p;
        num++;
        return;
    }

    int Pop() {
        int n = top->x;
        Node *p = top;
        top = top->next;
        free(p);
        num--;
        return n;
    }

    int Top() {
        return top->x;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void Print() {
        Node* p = top;
        while (p) {
            printf("%d ", p->x);
            p = p->next;
        }
        printf("\n");
        return;
    }
};


class Graph {
public:
    LinkedList *g;
    int num_of_vertices;

    Graph(int n) : num_of_vertices(n), g(new LinkedList[n + 1]) {
    }

    ~Graph() {
        delete[] g;
    }

    void Add(int x, int y,int v=0) {
        g[x].Append(y,v);
        g[y].Append(x,v);
        return;
    }

    void AddDirected(int x, int y, int v = 0) {
        g[x].Append(y, v);
        return;
    }

    void Print() {
        for (int i = 1; i <= num_of_vertices; ++i) {
            printf("%d :", i);
            g[i].Print();
        }
        return;
    }

    int * BFS(int source) {
        int* dist = new int[num_of_vertices + 1];
        for (int i = 0; i <= num_of_vertices; ++i)dist[i] = -1;
        dist[source] = 0;
        Queue q;
        q.Enqueue(source);
        while (!q.isEmpty()) {
            int u = q.Dequeue();
            Node*p = g[u].head;
            while (p) {
                if (dist[p->x] == -1) {
                    dist[p->x] = dist[u] + 1;
                    q.Enqueue(p->x);
                }
                p = p->next;
            }
        }
        return dist;
    }

    int* DFS(int source) {
        int* dist = new int[num_of_vertices + 1];
        for (int i = 0; i <= num_of_vertices; ++i)dist[i] = -1;
        dist[source] = 0;
        Stack s;
        s.Push(source);
        while (!s.isEmpty()) {
            int u = s.Pop();
            Node*p = g[u].head;
            while (p) {
                if (dist[p->x] == -1) {
                    dist[p->x] = dist[u] + 1;
                    s.Push(p->x);
                }
                p = p->next;
            }
        }
        return dist;
    }

    bool isConnected() {
        int* d = DFS(1);
        for (int i = 1; i <= num_of_vertices; ++i) {
            if (d[i] == -1)return false;
        }
        return true;
    }

    int stillUncoloured(int* color, int n) {
        for (int i = 1; i < n; i++) {
            if (color[i] == -1)return i;
        }
        return 0;
    }

    bool isBipartite() {
        int source;
        int* color = new int[num_of_vertices + 1];
        for (int i = 0; i <= num_of_vertices; ++i)color[i] = -1;
        while ((source = stillUncoloured(color, num_of_vertices + 1)) != 0) {
            color[source] = 0;
            Queue q;
            q.Enqueue(source);
            while (!q.isEmpty()) {
                int u = q.Dequeue();
                Node*p = g[u].head;
                while (p) {
                    if (color[p->x] == -1) {
                        color[p->x] = (color[u] == 0) ? 1 : 0;
                        q.Enqueue(p->x);
                    } else if (color[p->x] == color[u]) {
                        return false;
                    }
                    p = p->next;
                }
            }

        }
        delete [] color;
        return true;
    }

    Stack * Cycle() {
        int source = 1, parent = 0;
        int* par = new int[num_of_vertices + 1];
        for (int i = 0; i <= num_of_vertices; ++i)par[i] = -1;
        Stack * c = new Stack();
        par[source] = parent;
        Stack s;
        s.Push(source);
        while (!s.isEmpty()) {
            int u = s.Pop();
            Node*p = g[u].head;
            while (p) {
                if (par[p->x] == -1) {
                    par[p->x] = u;
                    s.Push(p->x);
                } else if (p->x != par[u] && c->isEmpty()) {
                    for (int x = u; x != par[p->x]; x = par[x])c->Push(x);
                    c->Push(par[p->x]);
                    c->Push(p->x);
                }
                p = p->next;
            }
        }
        delete[] par;
        return c;
    }
    
};

int main() {

}
