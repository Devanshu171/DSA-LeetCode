class Solution {
public:
    
   vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char, int> data;
        vector<string> wordsAnswer;
        for(int i = 0; i < words2.size(); i++){
            string word = words2[i];
            map<char,int> tempData;
            for(int j = 0; j< word.size(); j++){
                tempData[word[j]]++;
            }

            for(auto k : tempData){
                data[k.first] = max(data[k.first], k.second);
            }
        }


        map<char,int> data2;

        for(int i = 0; i < words1.size(); i++){
            string word = words1[i];
            map<char,int> tempData;
            for(int j = 0; j < word.size(); j++){
                tempData[word[j]]++;
            }
            bool flag = true;
            for(auto k : data){
                if(k.second > tempData[k.first]){
                    flag = false;
                }
            }

            if(flag){
                wordsAnswer.push_back(word);
            }

        }
        
        return wordsAnswer;

    }
};