class Solution {
public:
  
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int s=0,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]>arr[(mid-1+n)%n] && arr[mid]>arr[(mid+1)%n]) return mid;
            else if(arr[mid]>arr[(mid+1)%n]) e=mid-1;
            else if(arr[mid]<arr[(mid+1)%n]) s=mid+1;
            
        }
        return -1;
    }
};