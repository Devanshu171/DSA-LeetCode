// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    void dfs(int node,int start,int mini,vector<vector<int>>adj[],vector<vector<int>>&ans,vector<int>&out){
      
        for(auto it:adj[node]){
            if(out[it[0]]==1){
                mini=min(mini,it[1]);
                dfs(it[0],start,mini,adj,ans,out);
            }else if(out[it[0]]==0){
                 mini=min(mini,it[1]);
                ans.push_back({start,it[0],mini});
                return;
            }
        }
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<vector<int>>adj[n+1],ans;
        vector<int>in(n+1,0),out(n+1,0),vis(n+1,0);
        for(int i=0;i<p;i++){
            in[b[i]]++;
            out[a[i]]++;
            adj[a[i]].push_back({b[i],d[i]});
        }
        int tap=0,tank=0;
        for(int i=1;i<=n;i++){
            if(in[i]==0 && out[i]!=0){
                tank++;
            }else if(in[i]!=0 && out[i]==0){
                tap++;
            }
        }
        // vector<int>temp;
        
        for(int i=1;i<=n;i++){
            if(in[i]==0 && out[i]!=0){
                int mini=INT_MAX;
                dfs(i,i,mini,adj,ans,out);
            }
        }
        
        return ans;
        
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends