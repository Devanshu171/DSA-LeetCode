class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        // to store staring indices of anagram
        vector<int>ans;
        
        // to store frequency of p
        unordered_map<char,int>mpp; 
        
        for(auto i:p)
            mpp[i]++;
        
        // size of the window
        int k=p.size();  
         // no. of distinct character
        int count=mpp.size(); 
        
        
        int i=0,j=0;
         while(j<s.size())
         {      
             if(mpp.find(s[j])!=mpp.end()){
                 mpp[s[j]]--;
                 
             // if the frequency is zero it means we have the required no. of frequency of that character
             if(mpp[s[j]]==0)
                 count--;
             }
             if(j-i+1<k)
                 j++;
             
             else if(j-i+1==k)
             {
                 // if count is zero it means we have all the character and their frequency  in the window
                 if(count==0)
                     ans.push_back(i);
                 
                 // for moving the window 
                 // we increment the frequency of i'th character  
                 if(mpp.find(s[i])!=mpp.end()){
                     mpp[s[i]]++;
                     
                     // if ith character comes in existence ( meaning we  dont have required frequency of the character )
                     // we increment distinct character
                      if(mpp[s[i]]==1) count++; 
                 }
                    
                 j++; i++;
             }
         }
            
        return ans;
        
    }
};