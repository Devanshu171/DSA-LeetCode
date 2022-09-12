class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        sort(token.begin(),token.end());
        int score=0;
        int n=token.size();
        int i=0,j=n-1;
        int ans=0;
        while(i<=j){
        int ii=i,jj=j;
            if(score){
                power+=token[j--];
                cout<<power<<"add"<<endl;
                score--;
            }
                while(i<=j &&  power>=token[i]){
                    cout<<power<<"sub"<<endl;
                    power-=token[i++];
                    score++;
                ans=max(score,ans);
                }
        if(ii==i && jj==j) break;
            
        }
        return ans;
    }
};