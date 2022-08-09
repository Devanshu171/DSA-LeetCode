class Solution {
public:
    #define mod 1000000007
    int numFactoredBinaryTrees(vector<int>& nums) {
         unordered_map<int,long>mpp;
    int n=nums.size();
        sort(nums.begin(),nums.end());
   mpp[nums[0]] = 1;

  for (int i = 1; i < n; i++)
  {
    long cnt = 1;
    for (int j = 0; j < i; j++)
    {
      int k = nums[i] / nums[j];
      if (nums[i] % nums[j] == 0 && mpp.find(k) != mpp.end())
      {

        cnt = (cnt + mpp[nums[j]] * mpp[k]) % mod;
      }
    }
    mpp[nums[i]] = cnt;
  }

  int ans=0;
  for(auto it:mpp){
    ans=(ans+it.second)%mod;
  }

  return ans;
    }
};