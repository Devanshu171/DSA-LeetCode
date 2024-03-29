// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>adj){
	    // Code here
	    vector<int>dist(n,1e6+7);
	    dist[0]=0;
	    for(int i=1;i<=n-1;i++){
	        for(auto it:adj){
                int  v=it[1];
	            int u=it[0];
	            int w=it[2];
	            if(dist[u]+w<dist[v]){
	                dist[v]=dist[u]+w;
	            }
	        }
	    }
	    
	     for(auto it:adj){
	            int  v=it[1];
	            int u=it[0];
	            int w=it[2];
	            if(dist[u]+w<dist[v]){
                    return true;	            
	                
	            }
	        }
	        
	        return false;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends