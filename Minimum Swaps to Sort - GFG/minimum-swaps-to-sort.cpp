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
	    vector<pair<int,int>>vec;
	    for(int i=0;i<n;i++){
	        vec.push_back({arr[i],i});
	    }
	    sort(vec.begin(),vec.end());
	    int count=0;
	    for(int i=0;i<n;i++){
	        while(i!=vec[i].second){
	            swap(vec[i],vec[vec[i].second]);
	            count++;
	            
	        }
	    }
	    return count;
	    
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