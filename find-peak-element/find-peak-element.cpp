class Solution {
public:
    int findPeakElement(vector<int>& a) {
         int start=0;
        int n=a.size();
        int end=n-1;
        if(n==1)
            return 0;
        while(start<=end)
        {
            int mid = start+(end - start)/2;
            
            if(a[mid]>a[(mid+1)%n] && a[mid]>a[(mid+n-1)%n])
                return mid;
            else if(a[mid]>a[mid+1])
                end=mid-1;
            else if(a[mid]<a[mid+1])
                start= mid+1;
            
        }
        return 0;
    }
};