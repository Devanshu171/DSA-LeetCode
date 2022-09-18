class Solution {
public:
    bool isvalid(string s,unordered_set<char>&st){
        for(int i=0;i<s.size();i++){
            if(st.count(s[i])) return false;
        }
        for(int i=0;i<s.size();i++){
            if(st.count(s[i]))
            {
                for(int j=i-1;j>=0;j--){
                    st.erase(s[j]);
                }
                return false;
            }           st.insert(s[i]);
        }
        return true;
    }
    int solve(int ind,vector<string>&arr,string temp,unordered_set<char>st){
        if(ind==arr.size()){
            cout<<temp<<endl;
            return temp.size();  
        }
        int count1=-1,count2=-1;
        if(isvalid(arr[ind],st)){
           count1= solve(ind+1,arr,temp+arr[ind],st);
            for(int i=0;i<arr[ind].size();i++){
                st.erase(arr[ind][i]);
            }
        }
       count2= solve(ind+1,arr,temp,st);
        return max(count1,count2);
    }
    int maxLength(vector<string>& arr) {
       unordered_set<char>st;
        return solve(0,arr,"",st);
    }
};