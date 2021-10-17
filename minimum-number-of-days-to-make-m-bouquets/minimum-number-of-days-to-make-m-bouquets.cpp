class Solution
{
public:
    bool isvalid(vector<int> &a, int m, int k, int mid, int n)
    {
            // int n = arr.size();
        int count=0;
        for(int i=0; i<n; i++) {
            if(mid>=a[i]) count++;
            else count=0;
            if(count==k) {m--; count=0;}
            if(m==0) return true;
        }
        return false;
    }
    int minDays(vector<int> &a, int m, int k)
    {

        int n = a.size();

        int mins = INT_MAX;
        int maxs = 0;
        int res = -1;
if(m*k>n) return -1;
        for (int i = 0; i < n; i++)
        {
            maxs = max(maxs, a[i]);
            mins = min(mins, a[i]);
        }

        int start = mins;
        int end = maxs;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (isvalid(a, m, k, mid, n))
            {
                res = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }

        return res;
    }
};