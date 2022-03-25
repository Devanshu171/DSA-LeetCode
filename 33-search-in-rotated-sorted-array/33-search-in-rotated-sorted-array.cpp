class Solution {
public:
    int pivot(vector<int>&arr){
        int s=0,e=arr.size()-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(arr[mid]>=arr[0])
                s=mid+1;
            else
                e=mid;
        }
        return s;
    }
    int bs(vector<int>&arr,int s,int e,int x){
        
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==x)
                return mid;
            else if(arr[mid]>x)
                e=mid-1;
            else
                s=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pvt=pivot(nums);
        cout<<pvt<<endl;
        int ans1=bs(nums,0,pvt-1,target);
        if(ans1!=-1)
            return ans1;
        else 
            return bs(nums,pvt,nums.size()-1,target);
        
    }
};