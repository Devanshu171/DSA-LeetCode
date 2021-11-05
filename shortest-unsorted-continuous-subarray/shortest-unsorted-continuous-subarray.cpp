class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start;
        int end;
        
        int n=nums.size();
        int a[n];
        for(int i=0;i<n;i++){
            a[i]=nums[i];
        }
        sort(a,a+n);
        bool flag=false;
        for(int i=0;i<n-1;i++){
            if(a[i]!=nums[i]){
                start=i;
                flag=true;
                break;
            }
        }
        if(!flag) return 0;
        
        
        
        for(int j=n-1;j>0;j--){
            if(a[j]!=nums[j]){
                end=j;
                break;
            }
        }
        return end-start+1;
    }
};