// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    struct Node{
      Node *links[26];
      int count=0;
        bool flag=false;
        
        bool containsKey(char ch){
            return (links[ch-'a']!=NULL);
        }
        
        void put(char ch,Node *node){
            links[ch-'a']=node;
        }
        
        Node *get(char ch){
            return links[ch-'a'];
        }
        void setEnd(){
            flag=true;
        }
    };
    
    class Trie{
      private: Node *root;
      
      public:
        
        Trie(){
            root=new Node();
        }
        
        void insert(string s){
            Node* node=root;
            for(int i=0;i<s.size();i++){
            char ch=s[i];
                if(!node->containsKey(ch)){
                    node->put(ch,new Node());
                }
             
                node=node->get(ch);
                   node->count++;
            }

            node->setEnd();
        }
       
        string getPrefix(string s){
            Node *node=root;
            int i=0;
            for(;i<s.size();i++){
                node=node->get(s[i]);
                if(node->count==1)break;

            }
            return s.substr(0,i+1);
        }
    };
  
    vector<string> findPrefixes(string arr[], int n)
    {
        Trie t;
        for(int i=0;i<n;i++) t.insert(arr[i]);
        vector<string>ans;
        for(int i=0;i<n;i++){
            ans.push_back(t.getPrefix(arr[i]));
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

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends