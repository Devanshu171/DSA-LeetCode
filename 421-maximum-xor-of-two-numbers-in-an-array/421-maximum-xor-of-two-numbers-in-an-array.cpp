class Solution {
public:
    struct Node{
     Node *links[2];
        bool flag=false;
        
        bool containsKey(int n){
            return (links[n]!=NULL);
        }
        Node *get(int n){
            return links[n];
        }
        void put(int n,Node *node){
            links[n]=node;
        }
        void setEnd(){
            flag=true;
        }
    };
    
    class Trie{
      
        private:  Node *root;
        
        public:
      
        Trie(){
            root=new Node();
        }

        void insert(int n){
            Node *node=root;
                    int num=0;
                for(int i=31;i>=0;i--){
                    int bit=(n>>i & 1);
                    if(bit==1) num=num|1<<i;
                    if(!node->containsKey(bit)){
                        node->put(bit,new Node());
                    }
                    node=node->get(bit);
                }
            node->setEnd();
        }
        int getMax(int n){
            int num=0;
            Node *node=root;
            for(int i=31;i>=0;i--){
                
                  int bit=(n>>i & 1);
                if(node->containsKey(!bit)){
                    if(bit==0) num=(num |1<<i); 
                    node=node->get(!bit);
                }else{
                    if(bit==1) num=(num |1<<i);
                     node=node->get(bit);
                }
                
               
            }

            return num^n;
        }
     
     
      
    };
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(int i=0;i<nums.size();i++){
            t.insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,t.getMax(nums[i]));
        }
        
        return ans;
    }
};