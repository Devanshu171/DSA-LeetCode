class MyCircularQueue {
public:
    int *arr;
    int size,front,rear;
    MyCircularQueue(int k) {
        arr=new int[k+1];
        size=k+1;
        front=0;
        rear=0;
        
    }
    
    bool enQueue(int value) {
        if(!isFull()){
            rear=(rear+1)%size;
            arr[rear]=value;
            return true;
        }else{
            return false;
        }
    }
    
    bool deQueue() {
          if(!isEmpty()){
             front=(front+1)%size;
            return true;
        }else{
            return false;
        }
    }
    
    int Front() {
         if(!isEmpty()){
            return arr[(front+1)%size]; 
        }else{
            return -1;
        }
    }
    
    int Rear() {
        if(!isEmpty()){
            cout<<rear<<"r--r"<<arr[rear]<<endl;
            return arr[rear];
        }else{
            return -1;
        }
    }
    
    bool isEmpty() {
        // cout<<front<<" "<<rear<<endl;
        if(front==rear) return true;
        return false;
    }
    
    bool isFull() {
        // cout<<front<<" "<<rear<<endl;
        if((rear+1)%size==front) return true;
        return false;
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