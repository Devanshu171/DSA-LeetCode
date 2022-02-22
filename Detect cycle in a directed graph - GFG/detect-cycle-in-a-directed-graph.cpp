// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool check(int node,vector<int>&vis,vector<int>&visdfs,vector<int>adj[]){
        vis[node]=1;
        visdfs[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(check(it,vis,visdfs,adj)) return true;
            }else if(visdfs[it]) return true;
        }
        visdfs[node]=0;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int>vis(v,0),visdfs(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(check(i,vis,visdfs,adj)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends