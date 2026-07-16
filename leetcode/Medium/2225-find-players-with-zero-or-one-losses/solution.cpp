class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> zero_loss;
        unordered_set<int> one_loss;
        unordered_set<int> many_loss;
        int n = matches.size();

        for(int i=0; i<n; i++){
            int winner = matches[i][0];
            int loser  = matches[i][1];
        if(one_loss.find(winner) == one_loss.end() && many_loss.find(winner) == many_loss.end()){
                zero_loss.insert(winner);
            }
            if(zero_loss.find(loser) != zero_loss.end()){
                zero_loss.erase(loser);
                one_loss.insert(loser);
            }
            else if(one_loss.find(loser) != one_loss.end()){
                one_loss.erase(loser);
                many_loss.insert(loser);
            }
            else if(many_loss.find(loser) == many_loss.end()){
                one_loss.insert(loser);
            }
        }
        vector<int> v0(zero_loss.begin(), zero_loss.end());
        vector<int> v1(one_loss.begin(), one_loss.end());

        sort(v0.begin(), v0.end());
        sort(v1.begin(), v1.end());

        return {v0, v1};
    }
};

