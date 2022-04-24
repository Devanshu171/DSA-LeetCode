class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        int s=0,e=n;
        while(s<=e){
            
            int cut1=s+(e-s)/2;
            int cut2=(n+m+1)/2-cut1;
            
            int left1= cut1==0?INT_MIN:nums1[cut1-1];
            int left2=cut2==0?INT_MIN:nums2[cut2-1];
            
            int right1= cut1==n?INT_MAX:nums1[cut1];
            int right2= cut2==m?INT_MAX:nums2[cut2];
            
            if(left1<=right2 && left2<=right1){
                if((n+m)&1){
                    return max(left1,left2)*1.00;
                }else{
                    return (max(left1,left2)+min(right1,right2))/2.0;
                }
            }else if(left1>right2){
                e=cut1-1;
            }else if(left2>right1){
                s=cut1+1;
            }
        }
        return 0.0;
    }
};