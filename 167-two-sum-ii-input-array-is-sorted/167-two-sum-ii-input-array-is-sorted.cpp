class Solution {
public:
    vector<int> twoSum(vector<int>& a, int k) {
        
        int i=0;
        int j=a.size()-1;
        
        while(i<j)
        {
            if(a[i]+a[j]==k)
                return {i+1,j+1};
            else if(a[i]+a[j]>k)
                j--;
            else
                i++;
        }
        return {-1,-1};
    }
};