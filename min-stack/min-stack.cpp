
class MinStack {
    private:
    int data;
    MinStack *next;
    

public:
    MinStack *rare=NULL;
MinStack *front=NULL;

    
    MinStack(){
        rare=NULL;
        front=NULL;
    }
    
    void push(int val) {
         MinStack *t=new  MinStack;
        t->data=val;
        t->next=NULL;
        if(front==NULL){
            rare=front=t;
        }
        else
        {
            t->next=front;
            front=t;
        }
        
    }
    
    void pop() {
        
        if(front!=NULL){
         MinStack *t=front;
        front=front->next;
        delete t;
        }
        
    }
    
    int top() {
            if(front!=NULL)
     return front->data;
        else 
            return NULL;
        
    }
    
    int getMin() {
       MinStack *k=front;
        int minx=INT_MAX;
        while(k!=NULL){
            minx=min(k->data,minx);
            k=k->next;
        }
        return minx;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */