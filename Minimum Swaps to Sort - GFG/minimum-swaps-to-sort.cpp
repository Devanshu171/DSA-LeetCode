// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&arr)
	{
	    // Code here
	    int n=arr.size();
	    unordered_map<int,int>mpp;
	    for(int i=0;i<n;i++){
	        mpp[arr[i]]=i;
	    }
	    int i=0;
	    int ans=0;
	    sort(arr.begin(),arr.end());
	    while(i<n){
	        if(i!=mpp[arr[i]]){
	            swap(arr[i],arr[mpp[arr[i]]]);
	            ans++;
	        }else{
	            i++;
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
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends