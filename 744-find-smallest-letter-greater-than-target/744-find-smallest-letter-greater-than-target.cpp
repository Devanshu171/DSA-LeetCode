class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char x) {
        int n = arr.size();
        int start=0,end=n-1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]>x) end=mid-1;
            else start=mid+1;
        }
        return arr[(start)%n];
    }
};