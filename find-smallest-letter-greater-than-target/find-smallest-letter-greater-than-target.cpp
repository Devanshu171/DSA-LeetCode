class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char target) {
        
        int start=0;
        int end=l.size()-1;
        
        if(target-'a'>=l[end]-'a')
        {
            return l[start];
        }
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
             if(l[mid]-'a'<=target-'a')
            start=mid+1;
            
            else 
                end=mid-1;
             
        }
        
        return l[start];
        
    }
};