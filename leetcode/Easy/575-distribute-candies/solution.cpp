class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> mp ;
        for (int i = 0 ; i < candyType.size() ; ++i) {
            mp[candyType[i]] = 1 ;
        }
        int sum = 0 ;
        for (auto &it : mp) {
            sum = sum + it.second ;
        }
        if (sum <= candyType.size()/2) {
            return sum ;
        }
        else {
            return candyType.size()/2 ;
        }
    }
};
