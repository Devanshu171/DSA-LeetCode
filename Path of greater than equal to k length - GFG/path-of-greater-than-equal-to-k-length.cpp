// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution {
public:

    bool solve(int node,int path,int k,vector<pair<int,int>>adj[],vector<int>vis){
        if(path>=k)
        return true;
        for(auto it:adj[node]){
            if(!vis[it.first]){
             vis[it.first]=1;
                if(solve(it.first,path+it.second,k,adj,vis))
                return true;
             vis[it.first]=0;
            }
        }
        return false;
    }
    bool pathMoreThanK(int v, int e, int k, int *a) 
    { 
       //  Code Here
       vector<pair<int,int>>adj[v];
       for(int i=0;i<3*e-2;i+=3){
           adj[a[i]].push_back({a[i+1],a[i+2]});
           adj[a[i+1]].push_back({a[i],a[i+2]});
       }
       vector<int>vis(v,0);
       vis[0]=1;
      return solve(0,0,k,adj,vis);
    } 
};




// { Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends