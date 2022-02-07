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
    int bs(int start,int end, int x,bool flag, MountainArray &Arr){
             
        
        while(start<=end){
            int mid=start+(end-start)/2;
            int cur=Arr.get(mid);
            if(cur==x) return mid;
            else if(cur>x){
                if(flag) end=mid-1;
                else start=mid+1;
            }
            else{
                if(flag) start=mid+1;
                else  end=mid-1;
            }
        }
        return -1;
    }
   
    
    int findInMountainArray(int target, MountainArray &Arr) {
        
         int n=Arr.length();
        int start=0,end=n-1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            int right=Arr.get((mid+1)%n),left= Arr.get((mid-1+n)%n);
            int cur=Arr.get(mid);
            if( cur>right && cur>left) {
              
                 int ans=bs(0,mid,target,true,Arr);
        if(ans!=-1) return ans;
        else return bs(mid+1,n-1,target,false,Arr);
                
            }
            else if( cur>(right)) end=mid-1;
            else start=mid+1;
        }
        return -1;
       
    }
};