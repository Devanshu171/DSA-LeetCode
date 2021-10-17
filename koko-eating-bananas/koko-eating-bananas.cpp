class Solution {
public:
    bool isvalid(vector<int>&a,int mx,int n,int h,int sum)
    {
            int ho=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]%mx==0)
                ho+=a[i]/mx;
            if(a[i]%mx!=0)
                ho+=(a[i]/mx)+1;
            if(ho>h)
                return false;
                
        }
            return true;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int sum=*max_element(piles.begin(),piles.end());
        int res=-1;
              
        int start=1;
        int end=sum;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isvalid(piles,mid,n,h,sum))
            {
                res=mid;
                end=mid-1;
            }
            else
                start=mid+1;
            
        }
        return res;
        
    }
};