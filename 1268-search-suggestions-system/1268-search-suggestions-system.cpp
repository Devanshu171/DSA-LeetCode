class Solution {
public:
    pair<int,int> pvt(vector<string>& products, string searchWord,int i){
           int s=0,e=products.size()-1;
            int is=-1,ie=-1;
              while(s<=e){
            int mid= s+(e-s)/2;
          string s1 = products[mid].substr(0,i+1);
            string s2=searchWord.substr(0,i+1);
            if(s1==s2){
                is=mid;
                e=mid-1;
            }else if(s1<s2){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
          s=0,e=products.size()-1;
            while(s<=e){
            int mid= s+(e-s)/2;
          string s1 = products[mid].substr(0,i+1);
            string s2=searchWord.substr(0,i+1);
            if(s1==s2){
                ie=mid;
               s=mid+1;
            }else if(s1<s2){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return {is,ie};
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>>ans;
        for(int i=0;i<searchWord.size();i++){
                            
            pair<int,int> pts =pvt(products,searchWord,i);
            int sindx=pts.first;
            int eindx=pts.second;
            
  
            vector<string>temp;
            if(sindx!=-1){
                int cnt=1;
           
            while(sindx<=eindx&& cnt<=3){
                temp.push_back(products[sindx]);
                sindx++;
                cnt++;
            }
            }
                ans.push_back(temp);
        
        }
        
        return ans;
    }
};