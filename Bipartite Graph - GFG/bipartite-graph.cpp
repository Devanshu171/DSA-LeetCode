// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

bool dfs(int node,int clr,vector<int>adj[],vector<int>&color,vector<int>&vis){
    vis[node]=1;
    color[node]=clr;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(!dfs(it,!clr,adj,color,vis)){
                return false;
            }
        }else if(color[it]==clr){
            return false;
        }
    }
    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>color(V,-1),vis(V,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            if(!dfs(i,0,adj,color,vis))
	            return false;
	        }
	    }
	    
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends