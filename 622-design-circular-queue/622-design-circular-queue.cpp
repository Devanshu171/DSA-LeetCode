class MyCircularQueue {
    private:
    int *arr;
    int size,front,rear;
public:
    MyCircularQueue(int k) {
        arr=new int[k+1];
        size=k+1;
        front=0;
        rear=0;
    }
    
    bool enQueue(int value) {
        cout<<"rear-->"<<rear<<"front-->"<<front<<endl;
        if((rear+1)%size==front){
            cout<<"val-->"<<value<<endl;
            return false;
        }
          rear=(rear+1)%size;
        arr[rear]=value;
      
        return true;
    }
    
    bool deQueue() {
        if(front==rear)
            return false;
        front=(front+1)%size;
        return true;
    }
    
    int Front() {
        if(front==rear)
            return -1;
        else
            return arr[(front+1)%size];
    }
    
    int Rear() {
        if(front==rear)
            return -1;
        else
            return arr[rear];
    }
    
    bool isEmpty() {
        return front==rear;
    }
    
    bool isFull() {
        return ((rear+1)%size==front);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */