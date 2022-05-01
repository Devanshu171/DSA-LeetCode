// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
    struct Node{
        int data;
        int key;
        Node *next,*prev;
        Node(int k,int x){
            key=k;
            data=x;
            next=NULL;
            prev=NULL;
        }
    };
    int size;
    Node *head,*tail;
    unordered_map<int,Node*>mpp;

    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
       
       size=cap;
       head=NULL;
       tail=NULL;
    }
    

    void deleteNode(Node *k){
       
            if(k==head){
                 head=head->next;
                // head->prev=NULL;
            }else if(k==tail){
                tail=tail->prev;
            //     tail->next=NULL;
               
            }else{
                k->prev->next=k->next;
                k->next->prev=k->prev;
            }
            delete k;
                 
    }
    
    void addNode(Node *k){
        if(!head){
            head=k;
            tail=k;
        }else{
            k->next=head;
            head->prev=k;
            head=k;
        }
    }
        //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(mpp.find(key)==mpp.end())
        return -1;
        
        int val=mpp[key]->data;
        deleteNode(mpp[key]);
        // cout<<"del"<<endl;
        mpp.erase(key);
        Node *temp=new Node(key,val);
        addNode(temp);
        // cout<<"add"<<endl;
        mpp[key]=temp;
        return val;
        
    }
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        
        if(mpp.find(key)!=mpp.end()){
            deleteNode(mpp[key]);
            mpp.erase(key);
        }else if(mpp.size()==size){
                mpp.erase(tail->key);
                deleteNode(tail);
            }
          Node *temp=new Node(key,value);
            addNode(temp);
            mpp[key]=temp;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends