class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>month={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=1;i<=12;i++) month[i]+=month[i-1];
        int aad=month[stoi(arriveAlice.substr(0,2))-1]+stoi(arriveAlice.substr(3));
        int ald=month[stoi(leaveAlice.substr(0,2))-1]+stoi(leaveAlice.substr(3));
        int bad=month[stoi(arriveBob.substr(0,2))-1]+stoi(arriveBob.substr(3));
        int bld=month[stoi(leaveBob.substr(0,2))-1]+stoi(leaveBob.substr(3));
        cout<<aad<<" "<<ald<<endl;
        cout<<bad<<" "<<bld<<endl;
        int mpp[366]={0};
        int ans=0;
        for(int i=aad;i<=ald;i++) mpp[i]++;
        for(int i=bad;i<=bld;i++){
             mpp[i]++;
            if(mpp[i]==2) ans++;
        }
        return ans;

    }
};