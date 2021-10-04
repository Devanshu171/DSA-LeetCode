class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        vector<int>mpp(1001,0); 
        
        for(int i=0;i<arr1.size();i++)
            mpp[arr1[i]]++;      //element count
        
        vector<int>ans;
         for(int i=0;i<arr2.size();i++) // for all that are present in arr2
         {
               while(mpp[arr2[i]]>0)
                 {
                     ans.push_back(arr2[i]);
                     mpp[arr2[i]]--;
                 }     
         }
        
     
        for(int i=0;i<mpp.size();i++) // for those who are not present in arr2
        {
             while(mpp[i]>0)
                 {
                     ans.push_back(i);
                     mpp[i]--;
                 }
        }
       
        return ans;
    }
    
    
     
};