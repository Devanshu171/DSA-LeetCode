// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
   int dfs(vector<vector<char>> &mat, string target, int x, int y, int count)
{
  if (x < 0 || x == mat.size() || y < 0 || y == mat[0].size() || mat[x][y] != target[count])
    return 0;
  int found = 0;
  char temp = mat[x][y];
  mat[x][y] = '0';
  count++;
  if (count == target.size())
  {
    found += 1;
  }
  else
  {
    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++)
    {
      int newX = x + di[i];
      int newY = y + dj[i];
      found += dfs(mat, target, newX, newY, count);
    }
  }
  mat[x][y] = temp;
  return found;
}
int findOccurrence(vector<vector<char>> &mat, string target)
{
  int n = mat.size();
  int m = mat[0].size();
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      ans += dfs(mat, target, i, j, 0);
    }
  }
  return ans;
}
    
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}
  // } Driver Code Ends