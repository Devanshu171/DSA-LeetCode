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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie t;
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),[&](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        sort(nums.begin(),nums.end());
        int j=0;
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int a=queries[i][1];
            int indx=queries[i][2];
            // cout<<x<<" "<<a<<" "<<indx<<endl;
            while(j<nums.size() && nums[j]<=a) t.insert(nums[j++]);
            // cout<<j<<endl;
            if(j==0)ans[indx]=-1;
           else ans[indx]=t.getMax(x);
        }
        return ans;
        
    }
};