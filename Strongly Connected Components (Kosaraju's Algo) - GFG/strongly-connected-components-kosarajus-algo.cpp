// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<int>adj[],vector<int>&vis,stack<int>&st){
	    vis[node]=1;
	    
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it,adj,vis,st);
	        }
	    }
	    st.push(node);
	}
	
	void dfs2(int node,vector<int>transposAdj[],vector<int>&vis){
	    vis[node]=1;
	    
	    for(auto it:transposAdj[node]){
	        if(!vis[it]){
	            dfs2(it,transposAdj,vis);
	        }
	    }
	    
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int>topo(V),vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        vector<int>transposAdj[V];
        
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                transposAdj[it].push_back(i);
            }
        }
    
        int ans=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                ans++;
                dfs2(node,transposAdj,vis);
            }
        }
        return ans;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends