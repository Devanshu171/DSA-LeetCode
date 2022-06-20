class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp=0;
        
        // XOR of all elements
        for(auto it:nums) temp^=it;
        
        // get right most set bit
        int firstSet=0;
        // cout<<temp<<endl;
        while(temp){
            if(temp & 1){
                break;
            }
            temp=temp>>1;
            firstSet++;
        }
        // cout<<firstSet<<endl;
        int set=0,unset=0;
        for(auto it:nums){
            
            if(it>>firstSet & 1){
                set^=it;
            }else{
                unset^=it;
            }
        }
        
        return {set,unset};
    }
};