class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n = deck.size();
        int cnt =1;
        int g=0;
        for(int i=1;i<=n;i++){
            if(i<n && deck[i] == deck[i-1]){
                cnt++;
            }
            else{
                g = gcd(g,cnt);
                cnt =1;
            }
        }
        return g>=2;
    }
};
