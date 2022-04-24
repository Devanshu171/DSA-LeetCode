// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isValid(int x,int y,int n,vector<vector<int>> &vis,vector<vector<int>> &m){
        return x>=0 && x<n && y>=0 && y<n && vis[x][y]==0 && m[x][y]==1;
    }
    void solve(int x,int y,vector<vector<int>> &m,int n,vector<vector<int>>&vis,vector<string>&ans,string temp){
        if(x==n-1 && y==n-1){
            ans.push_back(temp);
            return;
        }
        vis[x][y]=1;
        string dir="DLRU";
        int di[4]={1,0,0,-1};
        int dj[4]={0,-1,1,0};
        
        for(int i=0;i<4;i++){
            int newX=x+di[i];
            int newY=y+dj[i];
            if(isValid(newX,newY,n,vis,m)){
                temp.push_back(dir[i]);
                solve(newX,newY,m,n,vis,ans,temp);
                temp.pop_back();
            }
        }
        vis[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
       
        vector<string>ans;
         if(m[0][0]==0)
        return ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        solve(0,0,m,n,vis,ans,"");
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends