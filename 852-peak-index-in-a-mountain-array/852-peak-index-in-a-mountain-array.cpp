class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0, n=arr.size(),end=n-1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]>arr[(mid+1)%n] && arr[mid]>arr[(mid-1+n)%n]) return mid;
            else if(arr[mid]>arr[(mid+1)%n]) end=mid-1;
            else if(arr[mid]<arr[(mid+1)%n]) start=mid+1;
        }
        return -1;
    }
};