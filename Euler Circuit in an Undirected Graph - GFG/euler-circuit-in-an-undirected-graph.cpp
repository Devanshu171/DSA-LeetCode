// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
void dfs(int node,vector<int>adj[],vector<int>&vis){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
}

	bool isEularCircuitExist(int n, vector<int>adj[]){
	    // Code here
	    int maxDeg=-1;
    int node;
    // int countOdd=0;
    for(int i=0;i<n;i++){
        if(adj[i].size() & 1)
        return false;
        if(adj[i].size()>maxDeg){
            maxDeg=adj[i].size();
            node=i;
        }
    }

    // vector<int>vis(n,0);
    // dfs(node,adj,vis);
    // for(int i=0;i<n;i++){
    //     if(vis[i]==0 && adj[i].size()>1){
    //         return false;
    //     }
    // }
    
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
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends