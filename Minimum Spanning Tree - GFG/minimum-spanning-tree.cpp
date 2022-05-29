// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	struct Edge{
	    int u,v,w;
	    Edge(int u,int v,int w){
	        this->u=u;
	        this->v=v;
	        this->w=w;
	    }
	};
	
	class DSU{
	    private:
	    vector<int>parent,rank;
	    public:
	    DSU(int V){
	        for(int i=0;i<=V;i++){
	            parent.push_back(i);
	            rank.push_back(0);
	        }
	    }
	    
	    int findPar(int u){
	        if(parent[u]==u){
	            return u;
	        }
	        
	        return parent[u]=findPar(parent[u]);
	    }
	    
	    void Union(int u,int v){
	        u=findPar(u);
	        v=findPar(v);
	        if(u==v) return;
	        
	        if(rank[u]>rank[v]){
	            parent[v]=u;
	            rank[u]+=rank[v];
            }else{
                parent[u]=v;
                rank[v]+=rank[u];
            }
	    }
	};
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<Edge>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                edges.push_back(Edge(i,it[0],it[1]));
            }
        }
        
        sort(edges.begin(),edges.end(),[&](Edge &a,Edge&b){
            return a.w<b.w;
        });
        DSU dsu(V);
        int ans=0;
        // for(auto it:edges){
        //     cout<<it.u<<"--"<<it.v<<endl;
        // }
        for(int i=0;i<edges.size();i++){
           int u= edges[i].u;
           int v=edges[i].v;
           int w=edges[i].w;
           if(dsu.findPar(u)!=dsu.findPar(v)){
               ans+=w;
               dsu.Union(u,v);
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
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends