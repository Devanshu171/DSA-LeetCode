class LRUCache {
public:
    struct Node{
        int data,key;
        Node*next,*prev;
        
        Node(int k,int v){
            key=k;
            data=v;
        }
    };
    
    Node* head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node*>mpp;
    LRUCache(int capacity) {
        cap=capacity;
        head->prev=tail->next=NULL;
        head->next=tail;
        tail->prev=head;
    }
    
    void addnode(Node *t){
        t->next=head->next;
        t->prev=head;
        head->next->prev=t;
        head->next=t;
    }
    void deletenode(Node *t){
        t->next->prev=t->prev;
        t->prev->next=t->next;
        
    }
    int get(int key_) {
        if(mpp.find(key_)!=mpp.end()){
            Node *t=mpp[key_];
            int x=t->data;
            mpp.erase(key_);
            deletenode(t);
            addnode(t);
            mpp[key_]=head->next;
            return x;
        }
        return -1;
    }
    
    void put(int key_, int value) {
        if(mpp.find(key_)!=mpp.end()){
            Node*t=mpp[key_];
            mpp.erase(key_);
            deletenode(t);
        }
        if(cap==mpp.size()){
            mpp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new Node(key_,value));
        mpp[key_]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */