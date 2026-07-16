class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
       // unordered_map<string,int> mp;
        ans.push_back(words[0]);
        for(int i =1;i<n;i++){
            string prev = words[i-1];
            string curr = words[i];
            sort(prev.begin(),prev.end());
            sort(curr.begin(),curr.end());

            if(prev != curr){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
