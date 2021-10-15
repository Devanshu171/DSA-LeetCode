/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int BS(int start,int end,int k, MountainArray &a)
    {
        bool flag=a.get(start)<a.get(start+1);
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int mide=a.get(mid);
            if(mide==k)
                return mid;
            
            else if(mide>k)
            {
                if(flag)
                    end=mid-1;
                else
                    start=mid+1;
            }
            else
            {
                if(flag)
                    start=mid+1;
                else
                    end=mid-1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &a) {
        
        int start=1;
        int n=a.length();
        int end=n-2;
        int left,right;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            int mide=a.get(mid);
            left=a.get((mid-1));
            right=a.get((mid+1));
            
            if(mide>right && mide>left)
            {
                int first=BS(0,mid,target,a);
                
                if(first!=-1)
                    return first;
                int second=BS(mid,n-1,target,a);
                    return second;
                
                
            }
            else if(mide>right)
                end=mid-1;
            else if(mide<right)
                start=mid+1;
                 
        }
        return -1;

    }
};