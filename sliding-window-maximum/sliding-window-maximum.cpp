class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>de;
        vector<int>vec;
        int n=nums.size();
        // if size of vector is less then window 
        if(n<=k)
            return {*max_element(nums.begin(),nums.end())};
        
        
        int i=0,j=0;
        
        while(j<n)
        {       // pop back all the element before jth element because we don't need them as 
            //maxinum would be jth 
            while(de.size()!=0 && de.back()<nums[j])
                de.pop_back();
            
            de.push_back(nums[j]);
            
            if(j-i+1<k)
                j++;
            
            else if(j-i+1==k)
            {
                vec.push_back(de.front());
                
                // for sliding if nums[i] is the element at front of de we pop it and move the window
                if(de.front()==nums[i])
                    de.pop_front();
                
                i++;
                j++;   
            }
        }
        return vec;
        
    }
};