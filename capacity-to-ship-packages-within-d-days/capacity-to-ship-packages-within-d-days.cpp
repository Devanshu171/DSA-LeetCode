class Solution {
public:
    bool isvalid(vector<int>&a,int Gdays,int mx)
    {
        int days=1;
        int capacity=0;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            capacity+=a[i];
           
            if(capacity>mx)
            {
                days++;
                capacity=a[i];
            }
        }
        if(days<=Gdays)
        return true;
        else
            return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int Tweight=0;
        int maxWeight=0;
        int res=-1;
        int n=weights.size();
        
        if(days>n)
            return res;
        
        for(int i=0;i<n;i++)
        {
            Tweight+=weights[i];
            maxWeight=max(maxWeight,weights[i]);
        }
        
        int end=Tweight;
        int start=maxWeight;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(isvalid(weights,days,mid))
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