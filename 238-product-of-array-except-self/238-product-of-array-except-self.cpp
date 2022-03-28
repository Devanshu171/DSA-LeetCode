class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
          int n=arr.size();
        vector<int>ans(n,0);
        int countZero=0;
        int product=1;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                countZero++;
            }else{
                product*=arr[i];
            }
        }
        
        if(countZero==0){
            for(int i=0;i<n;i++){
                ans[i]=product/arr[i];
            }
        }else if(countZero==1){
            for(int i=0;i<n;i++){
                if(arr[i]==0){
                    ans[i]=product;
                    break;
                }
            }
        }
        return ans;
    }
};