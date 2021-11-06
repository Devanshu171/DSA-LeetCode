class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        vector<int>left;
        vector<int>right(n);
        
        int mx=-1;
        
        for(int i=0;i<n;i++){
             mx=max(mx,a[i]);
            left.push_back(mx);
        }
        mx=-1;
        
        for(int i=n-1;i>=0;i--){
            mx=max(mx,a[i]);
            right[i]=mx;
        }
        
        int water=0;
        for(int i=0;i<n;i++){
            water+=min(left[i],right[i])-a[i];
        }
        return water;
    }
};