class Solution {
public:
    
    
    bool isvalid(vector<int>&a,int n,int b,int mx)
{
    int student=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>mx)
        {
            student++;
            sum=a[i];
        }
        if(student>b)
        return false;
        
    }
    return true;
    
}
    int splitArray(vector<int>& a, int b) {
         int max=a[0];
    int n=a.size();
    int sum=0;
    int res=-1;
if(b>n)
{
    return -1;
}
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(a[i]>max)
        max=a[i];

    }

    int start=max;
    int end=sum;
    while(start<=end)
    {
        int mid=start+(end-start)/2;

        if(isvalid(a,n,b,mid))
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