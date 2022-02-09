// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    string dir="DRUL";
    int di[4]={1,0,-1,0};
    int dj[4]={0,1,0,-1};
    void findPath(int i,int j,int n,string s,vector<string> &ans,vector<vector<int>>&m,vector<vector<int>>&vis){
        if(i>=n ||j>=n ||i<0||j<0||vis[i][j]==1 || m[i][j]==0) return;
        if(i==n-1 && j==n-1) {
            ans.push_back(s);
            return;
        }
        vis[i][j]=1;
        for(int x=0;x<4;x++){
            s+=dir[x];
            findPath(i+di[x],j+dj[x],n,s,ans,m,vis);
            s.pop_back();
        }
        vis[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<string> ans;
        findPath(0,0,n,"",ans,m,vis);
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