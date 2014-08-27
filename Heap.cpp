class MaxHeap{
private:
    int* heap;
    int size;
    int Maxsize;
    
        
    int Parent(int i){return (i-1)>>1;}
    int Left(int i){return (i<<1) + 1;}
    int Right(int i){return (i+1)<<1;}
    
    void swap(int* x,int* y){*x=*x^*y;*y=*x^*y;*x=*x^*y;}
public:
    MaxHeap(int n):Maxsize(n),heap(new int[n]),size(0){}
    ~MaxHeap(){delete[] heap;}
    
    void TakeArray(int n,int* l){
        size=n;
        for(int i=0;i<n;++i)heap[i]=l[i];
        MakeMaxHeap();
    }

    void MaxHeapify(int s){
        int left,right,largest;
        while(1) {
            largest = s;
            left=Left(s);
            right=Right(s);
            if(left<size && heap[left] > heap[largest])largest = left;
            if(right<size && heap[right] > heap[largest])largest = right;
            if(largest!=s){
                swap(&heap[s],&heap[largest]);
                s=largest;
            }
            else break;
        }
    }
    
    void MakeMaxHeap(){
        for(int i=Parent(size-1);i>=0;--i)MaxHeapify(i);
    }
    
    void Insert(int i){
        if(size<Maxsize){
            heap[size]=i;
            int k = size;
            size++;
            while(k>0 && heap[k]>heap[Parent(k)]){
                swap(&heap[k],&heap[Parent(k)]);
                k=Parent(k);
            }
        }
    }
    
    void HeapSort(){
        int k=size;
        while(size>1){
            swap(&heap[0],&heap[size-1]);
            size--;
            MaxHeapify(0);
        }
        for(int i=0;i<k;++i)printf("%d ",heap[i]);
    }
    
    int Max(){return heap[0];}
    
    int ExtractMax(){
        int x = heap[0];
        swap(&heap[0], &heap[size - 1]);
        size--;
        MaxHeapify(0);
        return x;
    }
    
    void Print(){
        for(int i=0;i<size;++i)printf("%d ",heap[i]);
        printf("\n");
    }
};

class MinHeap{
private:
    int* heap;
    int size;
    int Maxsize;
    
        
    int Parent(int i){return (i-1)>>1;}
    int Left(int i){return (i<<1) + 1;}
    int Right(int i){return (i+1)<<1;}
    
    void swap(int* x,int* y){*x=*x^*y;*y=*x^*y;*x=*x^*y;}
public:
    MinHeap(int n):Maxsize(n),heap(new int[n]),size(0){}
    ~MinHeap(){delete[] heap;}
    
    void TakeArray(int n,int* l){
        size=n;
        for(int i=0;i<n;++i)heap[i]=l[i];
        MakeMinHeap();
    }

    void MinHeapify(int s){
        int left,right,smallest;
        while(1) {
            smallest = s;
            left=Left(s);
            right=Right(s);
            if(left<size && heap[left] < heap[smallest])smallest = left;
            if(right<size && heap[right] < heap[smallest])smallest = right;
            if(smallest!=s){
                swap(&heap[s],&heap[smallest]);
                s=smallest;
            }
            else break;
        }
    }
    
    void MakeMinHeap(){
        for(int i=Parent(size-1);i>=0;--i)MinHeapify(i);
    }
    
    void Insert(int i){
        if(size<Maxsize){
            heap[size]=i;
            int k = size;
            size++;
            while(k>0 && heap[k]>heap[Parent(k)]){
                swap(&heap[k],&heap[Parent(k)]);
                k=Parent(k);
            }
        }
    }
    
    int Min(){return heap[0];}
    
    int ExtractMin(){
        int x = heap[0];
        swap(&heap[0], &heap[size - 1]);
        size--;
        MinHeapify(0);
        return x;
    }
    
    void Print(){
        for(int i=0;i<size;++i)printf("%d ",heap[i]);
        printf("\n");
    }
};
