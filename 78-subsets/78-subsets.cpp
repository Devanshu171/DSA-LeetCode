class Solution {
public:

    vector<vector<int>> subsets(vector<int>& arr) {
        int n = arr.size();
  int subset_ct = (1 << n); // 2^n
  vector<vector<int>> ans;
  for (int mask = 0; mask < subset_ct; mask++)
  {
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
      if ((mask & (1 << i)) != 0) // (mask & (1<<i))!=0
        temp.push_back(arr[i]);
    }
    ans.push_back(temp);
  }
  return ans;
    }
};