// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    struct Node{
	        string symbol;
	        int freq;
	        Node* left,*right;
	        bool isLeaf;
	        Node(string symbol,int freq){
	            this->symbol=symbol;
	            this->freq=freq;
	            left=right=NULL;
	            isLeaf=false;
	        }
	    };
	    
	    struct cmp{
	        bool operator()(Node *a,Node *b){
	            return a->freq>b->freq;
	        }
	    };
	    void preOrder(Node *node,string path,vector<string>&res){
	        if(!node)
	            return;
	            if(node->isLeaf){
	                res.push_back(path);
	            }
	            preOrder(node->left,path+"0",res);
	            preOrder(node->right,path+"1",res);
	    }
		vector<string> huffmanCodes(string s,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<Node*,vector<Node*>,cmp>pq;
		    
		    Node *node,*node1,*node2,*newNode,*root;
		    vector<string>res;
		    for(int i=0;i<N;i++){
		        node=new Node(string(1,s[i]),f[i]);
		        node->isLeaf=true;
		        pq.push(node);
		    }
		    
		    while(pq.size()!=1){
		        node1=pq.top();
		        pq.pop();
		        node2=pq.top();
		        pq.pop();
		        newNode=new Node((node1->symbol+node2->symbol),node1->freq+node2->freq);
		        newNode->left=node1;
		        newNode->right=node2;
		        pq.push(newNode);
		    }
		    preOrder(pq.top(),"",res);
		    return res;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends