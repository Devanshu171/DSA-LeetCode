// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
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
                if(n>>i & 1){
                    if(node->containsKey(0)){ 
                        node=node->get(0);
                    }else{
                         num=(num|1<<i);
                        node=node->get(1);
                    }
                }else{
                    if(node->containsKey(1)){
                        num=(num|1<<i);
                        node=node->get(1);
                    }else{
                        node=node->get(0);
                    }
                }
               
            }

            return num^n;
        }
     
     
      
    };

    int max_xor(int nums[] , int n)
    {
        //code here
        Trie t;
        for(int i=0;i<n;i++){
            t.insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,t.getMax(nums[i]));
        }
        
        return ans;
    }
    
};


// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}


  // } Driver Code Ends