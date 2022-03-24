// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
  int di[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dj[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
bool dfs(vector<vector<char>> &mat, string target,int n,int m, int x, int y, int count)
{
    if(mat[x][y]!=target[count] )
    return false;
    count++;
    for(int i=0;i<8;i++){
        int nx=x+di[i];
        int ny=y+dj[i];
        int j=1;
        for(;j<target.size();j++){
            if(nx<0 || nx==n || ny<0 ||ny==m|| mat[nx][ny]!=target[j] ) break;
            count++;
            nx+=di[i];
            ny+=dj[i];
            
        }
        if(j==target.size())
             return true;
    }
    return false;
   
}

vector<vector<int>>searchWord(vector<vector<char>>&mat, string target){ 
	    
  int n = mat.size();
  int m = mat[0].size();
  vector<vector<int>>ans;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(dfs(mat, target,n,m, i, j, 0)){
            ans.push_back({i,j});
      }
    }
  }
  return ans;
	    
	 
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends