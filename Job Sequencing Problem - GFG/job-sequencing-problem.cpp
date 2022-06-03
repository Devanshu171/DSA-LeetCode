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
    static bool cmp(Job &a ,Job &b){
            return a.profit>b.profit;
        }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
                sort(arr,arr+n,cmp);
                int total=0;
                int jobs=0;
                int maxdead=-1;
                for(int i=0;i<n;i++){
                    maxdead=max(maxdead,arr[i].dead);
                }
                vector<int>slot(maxdead+1,-1);
                for(int i=0;i<n;i++){
                    int deadline=arr[i].dead;
                    int profit=arr[i].profit;
                    for(int j=deadline;j>=1;j--){
                        if(slot[j]==-1){
                            slot[j]=arr[i].id;
                            total+=profit;
                            jobs++;
                            break;
                        }
                    }
                }
                
                // for(int i=1;i<=maxdead;i++){
                //     cout<<slot[i]<<endl;
                // }
                return {jobs,total};
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