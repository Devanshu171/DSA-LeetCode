// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    struct Node{
        int data;
        Node *left,*right;
        Node(int temp){
            data=temp;
            left=right=NULL;
        }
    };
    void InsertInBST(Node *&root,int x){
        if(!root){
            root=new Node(x);
            
        }
            Node *cur=root,*prev=NULL;
            while(cur){
                prev=cur;
                if(cur->data<x){
                    cur=cur->right;
                }else{
                    cur=cur->left;
                }
            }
            if(prev->data<x){
                prev->right=new Node(x);
            }else{
                prev->left=new Node(x);
            }
          
    }
    int getUpperBound(Node *root,int x){
        Node *cur=root;
        int ans=-1;
        while(cur){
            if(cur->data>x){
                ans=cur->data;
                cur=cur->left;
            }else{
                cur=cur->right;
            }
        }
        return ans;
    }
    void print(Node *root){
        if(!root)
        return;
        print(root->left);
        cout<<root->data<<" ";
        print(root->right);
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        
        Node *root=NULL;
        for(int i=n-1;i>=0;i--){
           InsertInBST(root,arr[i]);
            arr[i]=getUpperBound(root,arr[i]);
        }
        // print(root);
        // cout<<endl;
        return arr;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}
  // } Driver Code Ends