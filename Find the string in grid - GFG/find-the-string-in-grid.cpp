// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
  int di[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dj[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
bool dfs(vector<vector<char>> &mat, string target, int x, int y, int count)
{
  if(target[0]!=mat[x][y])
  return false;
  
  for(int i=0;i<8;i++){
      int newX=x+di[i];
      int newY=y+dj[i];
      int j;
      for(j=1;j<target.size();j++){
          
           if (newX < 0 || newY < 0 || newX >= mat.size() || newY >= mat[0].size() || mat[newX][newY] != target[j]) 
           break;
           newX+=di[i];
           newY+=dj[i];
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
      if(dfs(mat, target, i, j, 0)){
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