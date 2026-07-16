class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int>mp;
        string word = "";
        for(char ele:paragraph){
            if(isalpha(ele)){
            word += tolower(ele);
        }
       else{
    if(!word.empty()){
        mp[word]++;
        word.clear();
    }
}


        }
        if(!word.empty()){
             mp[word]++;
             word.erase();
        }
        string maxword = "";
        int f = 0;
        for(auto x:banned) mp.erase(x);
        for(auto &it :mp){
           //if(ban.count(it.first)) continue;
           if(it.second > f){
            f=it.second;
            maxword = it.first;
           }  
        }
        return maxword;
    }
};
