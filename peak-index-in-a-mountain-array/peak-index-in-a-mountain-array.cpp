class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int start=1;
        int end=a.size()-2;
        
        while(start<=end)
        {
            int mid = start+(end - start)/2;
            
            if(a[mid]>a[mid+1] && a[mid]>a[mid-1])
                return mid;
            else if(a[mid]>a[mid+1])
                end=mid-1;
            else if(a[mid]<a[mid+1])
                start= mid+1;
            
        }
        return 0;
    }
};