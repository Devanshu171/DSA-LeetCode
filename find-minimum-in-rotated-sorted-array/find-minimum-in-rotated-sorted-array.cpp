class Solution {
public:
    int findMin(vector<int>& a) {
         int n=a.size();
       
        int start=0;
        int end=n-1;
           
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
               int prev=(mid+n-1)%n;
            int next=(mid+1)%n;
            
             if(a[start]<a[end])
            return a[start];
            

            else if(a[mid]<=a[prev] && a[mid]<=a[next])
                return a[mid];
            else
            {
                if(a[mid]>=a[start])
                    start=mid+1;
                else if(a[mid]<=a[end])
                    end=mid-1;
            }
        }
        return 0;
    }
};