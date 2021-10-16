class Solution {
public:
    bool bs(int start,int end,vector<int>&a,int target)
    {
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(a[mid]==target)
                return true;
            
            else if(a[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return false;
    }
    
    int pv(vector<int>&a,int target)
    {
       int start=0;
        int end=a.size()-1;
        int n=a.size();
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
           if(a[mid]>a[(mid+1)%n])
               return mid;
            if(a[mid]<a[(mid+n-1)%n])
                return mid-1;
            
             if( mid!=end && start!=mid  && a[mid]==a[start] && a[mid]==a[end])
            {
                if(a[start]>a[(start+1)%n])
                    return start;
                    start++;
                if(a[end]<a[(end+n-1)%n])
                    return end-1;
                    end--;
            }
            
            
            else if(a[mid]>a[start] || a[mid]==a[start] && a[mid]>a[end])
                start=mid+1;
            else 
                end=mid-1;
            }
          return -1;    
        }
        
    
    bool search(vector<int>& nums, int target) {
        
        int pivot=pv(nums,target);
        bool first=bs(0,pivot,nums,target);
        if(first)
            return true;
         return bs(pivot+1,nums.size()-1,nums,target);
       
    }
};