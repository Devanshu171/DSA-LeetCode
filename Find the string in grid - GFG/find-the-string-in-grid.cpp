// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
bool isValid(vector<vector<char>>grid,int x,int y,string s,int indx){
    return (x>=0 && x<grid.size() && y>=0 && y<grid[0].size() &&grid[x][y]==s[indx]);
}
bool search(vector<vector<char>>grid,int x,int y,string s){
    if(grid[x][y]!=s[0])
    return false;
    // cout<<x<<" "<<y<<endl;
   int di[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dj[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    
    for(int i=0;i<8;i++){
        int  newx=x+di[i];
        int newy=y+dj[i];
        int j=1;
        for(;j<s.size();j++){
            if(isValid(grid,newx,newy,s,j)){
            // cout<<newx<<" "<<newy<<endl;
                newx+=di[i];
                newy+=dj[i];
            }else{
                break;
            }
        }
        if(j==s.size())
        return true;
        
    }
    return false;
}
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>>ans;
	    for(int i=0;i<grid.size();i++){
	        for(int j=0;j<grid[0].size();j++){
	           // cout<<i<<" "<<j<<endl;
	                if(search(grid,i,j,word))
	                ans.push_back({i,j});
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