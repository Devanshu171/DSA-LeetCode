// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
        
       bool flag=false;
        void func(int ind,vector<int>arr,int sum,int n,int k){
            if(ind==n){
                if(sum%k==0 && sum!=0){
                    flag=true;
                }
                return;
            }
            sum+=arr[ind];
            func(ind+1,arr,sum,n,k);
            sum-=arr[ind];
            func(ind+1,arr,sum,n,k);
            
        }
        
        
		int DivisibleByM(vector<int>nums, int m){
		    // Code here
		    func(0,nums,0,nums.size(),m);
		    return flag;
		    
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans  = ob.DivisibleByM(nums, m);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends