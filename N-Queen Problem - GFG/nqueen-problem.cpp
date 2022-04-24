// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isSafe(int row, int col,int n,vector<vector<int>>&board){
    int i=row-1,j=col;
    for(;i>=0;i--){
        if(board[i][col]==1)
        return false;
    }
    
    i=row-1,j=col-1;
    for(;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1)
        return false;
    }
    i=row-1,j=col+1;
    for(;i>=0 && j<n;i--,j++){
        if(board[i][j]==1)
        return false;
    }
    
    return true;
} 
void solve(int row,int n,vector<vector<int>>&board,vector<vector<int>>&ans,vector<int>temp){
    if(row==n){
        ans.push_back(temp);
        return;
    }
    for(int col=0;col<n;col++){
        if(isSafe(row,col,n,board)){
            board[row][col]=1;
            temp[col]=row+1;
            solve(row+1,n,board,ans,temp);
            temp[col]=-1;
            board[row][col]=0;
        }
    }
}
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<vector<int>>ans;
        vector<int>temp(n,-1);
        solve(0,n,board,ans,temp);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends