class Solution {
public:
    int totalFruit(vector<int>& a) {
        unordered_map<int,int>mpp;
        int i=0,j=0,ans=0;
        while(j<a.size()){
            mpp[a[j]]++;
            if(mpp.size()<=2){
                ans=max(ans,j-i+1);
                j++;
            }
            else if(mpp.size()>2){
                while(mpp.size()>2){
                    mpp[a[i]]--;
                    if(mpp[a[i]]==0)
                        mpp.erase(a[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};