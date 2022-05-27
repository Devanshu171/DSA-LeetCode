// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	  int board[1001][1001];
    bool isValid(int x,int y,int n){
        return (x>=1 && x<=n && y>=1 && y<=n && board[x][y]==-1);
        return false;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int xx=TargetPos[0],yy=TargetPos[1];
	    for(int i=0;i<=N;i++){
	        for(int j=0;j<=N;j++){
	            board[i][j]=-1;
	        }
	    }
	     int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
	    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
	    queue<pair<int,int>>q;
	    q.push({KnightPos[0],KnightPos[1]});
	    board[KnightPos[0]][KnightPos[1]]=0;
	    while(!q.empty()){
	        int x=q.front().first;
	        int y=q.front().second;
	        q.pop();
	        if(x==xx && y==yy){
	            return board[xx][yy];
	        }
	        for(int i=0;i<8;i++){
	            int newX=x+dx[i];
	            int newY=y+dy[i];
	            if(isValid(newX,newY,N)){
	                board[newX][newY]=board[x][y]+1;
	                q.push({newX,newY});
	            }
	        }
	    }
	    return board[xx][yy];
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends