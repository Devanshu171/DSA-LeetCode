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
	int isEularCircuit(int V, vector<int>adj[]){
	    // Code here
	    int maxDeg=INT_MIN;
	    int node=0;
	    int oddCount=0;
	    
                for(int i=0;i<V;i++){
                    int deg=adj[i].size();
                    if(deg & 1) oddCount++;
                    if(deg>maxDeg){
                        maxDeg=deg;
                        node=i;
                    }
                }
	    
	   // cout<<node<<endl;
	    vector<int>vis(V,0);
	    dfs(node,adj,vis);
	    for(int i=0;i<V;i++){
	        if(vis[i]==0 && adj[i].size()>0){
	            return 0;
	        }
	    }
	    if(oddCount==0)
	    return 2;
	    else if(oddCount==2)
	    return 1;
	    else
	    return 0;
	    
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
		int ans = obj.isEularCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}  // } Driver Code Ends