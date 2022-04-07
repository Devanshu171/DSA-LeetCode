class Solution {
public:
    int compress(vector<char>& chars) {
     
        int k=0;
        int n=chars.size();
        for(int i=0;i<n;i++){
            int count=1;
            while(i<n-1 && chars[i]==chars[i+1]){
                i++;
                count++;
            }
            
            chars[k++]=chars[i];
            if(count>1){
                string cnt=to_string(count);
                cout<<cnt.size()<<endl;
                for(int j=0;j<cnt.size();j++)
                    chars[k++]=cnt[j];
                
            }
        }
    
    
        return k;
    }
};