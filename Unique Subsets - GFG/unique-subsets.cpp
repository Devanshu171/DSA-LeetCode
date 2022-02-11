// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void solve(int ind,int n,vector<vector<int>>&ans,vector<int>&arr,vector<int>&temp){
        
            ans.push_back(temp);
            for(int i=ind;i<n;i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            temp.push_back(arr[i]);
            solve(i+1,n,ans,arr,temp);
            temp.pop_back();
        }
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        vector<int>temp;
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        solve(0,arr.size(),ans,arr,temp);
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
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends