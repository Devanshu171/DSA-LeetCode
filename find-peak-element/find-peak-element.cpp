class Solution {
public:
    int findPeakElement(vector<int>& a) {
         int start=1;
        int n=a.size();
        int end=n-2;
        
             if(n==1)
            return 0;
        
        if(a[0]>a[1])
            return 0;
        
        if(a[n-2]<a[n-1])
            return n-1;
   
        while(start<=end)
        {
            int mid = start+(end - start)/2;
            
            if(a[mid]>a[(mid+1)] && a[mid]>a[(mid-1)])
                return mid;
            else if(a[mid]>a[mid+1])
                end=mid-1;
            else if(a[mid]<a[mid+1])
                start= mid+1;
            
        }
        return 0;
    }
};