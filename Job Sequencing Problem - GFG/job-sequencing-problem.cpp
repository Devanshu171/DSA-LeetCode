// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp( struct Job a,struct Job b){
        
        return a.profit>b.profit;
    }
  
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,cmp);
         int ans=arr[0].dead;
        for(int i=1;i<n;i++){
        ans=max(ans,arr[i].dead);
        }
        // cout<<ans<<endl;
        vector<int>occupied(ans+1,-1);
        int prof=0;
        int jb=0;
        for(int i=0;i<n;i++){
            int cur_pf=arr[i].profit;
            int cur_dl=arr[i].dead;
            for(int j=cur_dl;j>0;j--){
            if(occupied[j]==-1){
                occupied[j]=arr[i].id;
                // cout<<cur_pf<<" ";
                prof+=cur_pf;
                jb++;
                break;
            }
            
            }
            
        }
        return {jb,prof};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends