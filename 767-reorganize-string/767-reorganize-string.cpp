class Solution {
public:
    string reorganizeString(string s) {
        vector<int>count(26,0);
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
        }
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++){
            if(count[i]>0){
                pq.push({count[i],char(i+'a')});
            }
        }
        pair prev={-1,'#'};
        int k=0;
        char p='#';
        while(!pq.empty()){
            char ch=pq.top().second;
            int count=pq.top().first;
            // cout<<ch<<" "<<count<<endl;
          
            pq.pop();
            count--;
            
            s[k++]=ch;
        
            
            if(prev.first>0){
                pq.push(prev);
                  // cout<<prev.first<<" "<<prev.second<<endl;
            }
        prev={count,ch};
            

        }
        // cout<<k<<endl;
        if(k!=s.size()) return {""};
        return s;
    }
};