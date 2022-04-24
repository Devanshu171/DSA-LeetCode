// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku.
    bool getEmptyCell(int grid[N][N],int &row,int &col){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]==0){
                    row=i;
                    col=j;
                    return true;
                }
            }
        }
        return false;
    }
    bool valid(int row,int col,int grid[N][N],int num){
        for(int i=0;i<N;i++){
            if(grid[row][i]==num || grid[i][col]==num)
            return false;
        }
        int rf=(row/3)*3,cf=(col/3)*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[rf+i][cf+j]==num)
                return false;
            }
        }
        
        return true;
        
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        
        int row,col;
        if(!getEmptyCell(grid,row,col)){
            return true;
        }else{
            for(int i=1;i<=N;i++){
                if(valid(row,col,grid,i)){
                    grid[row][col]=i;
                    if(SolveSudoku(grid))
                    return true;
                    grid[row][col]=0;
                }
            }
        }
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
         for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends