class Solution {
public:
    bool isValid(vector<int>&arr,int n,int mx,int k){
        int sum=0,sub=1;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>mx){
                sub++;
                sum=arr[i];
            }
            if(sub>k) return false;
        }
        return true;
        
    }
    int splitArray(vector<int>& nums, int m) {
        
        int sum=0,mx=INT_MIN;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mx=max(mx,nums[i]);
        }
        int start=mx,end=sum;
        int res=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(isValid(nums,n,mid,m)){
                res=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return res;
    }
};