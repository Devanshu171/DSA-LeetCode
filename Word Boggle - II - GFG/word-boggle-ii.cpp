// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
 bool isValid(int x,int y,int n,int m,string &s,int indx,vector<vector<char>>&board){
        return (x>=0 && y>=0 && x<n && y<m && board[x][y]==s[indx]);
    }
    bool solve(int x,int y,int indx,int n,int m,string &s,vector<vector<char>>&board){
        
        
       if(!isValid(x,y,n,m,s,indx,board)) return false;
          if(indx==s.size()-1) return true;
            // cout<<x<<" "<<y<<" "<<s<<endl;
        char temp=board[x][y];
        board[x][y]='#';
    int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
            for(int i=0;i<8;i++){
              if(solve(x+dx[i],y+dy[i],indx+1,n,m,s,board)){
                     board[x][y]=temp;
              return true;
              }
            }
        
        board[x][y]=temp;
        return false;
    
    }
    bool doesExist(string &word,vector<vector<char>>&board,int n,int m){
        
	        for(int i=0;i<n;i++){
	            for(int j=0;j<m;j++){  
                	    if(solve(i,j,0,n,m,word,board))
                	        return true;
	              }
             }
        return false;
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& words) {
	      int n=board.size();
	    int m=board[0].size();
	   

	    vector<string>ans;
	    unordered_set<string>st;
	    for(auto word:words){
                if(!st.count(word) && doesExist(word,board,n,m)){
                    st.insert(word);
                    ans.push_back(word);
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
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends