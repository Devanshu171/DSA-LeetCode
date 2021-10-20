class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
          
        int n=a.size();
       int i=0;
        while(i<n)
        {
            if( a[i]<=n && a[i]>0 && a[a[i]-1]!=a[i] )
                swap(a[a[i]-1],a[i]);
            else
                i++;
        }
         
        
      
        
        for(int j=0;j<n;j++)
        {
            if( a[j]!=j+1)
                return j+1;
        }
        return n+1;
    }
};