class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a=m-1;
        int b=n-1;
        int k=m+n-1;
        // start form end i.e m+n-1 so the zeros will not be a problem
        while(a>=0 && b>=0)
        {
            if(nums1[a]>nums2[b])   nums1[k--]=nums1[a--];
            
            else  nums1[k--]=nums2[b--];
                
        }
        
        while(b>=0)  nums1[k--]=nums2[b--];
    }
};