class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        vector<int> ans;
        for(int i =0;i<n;i++){
            string c = operations[i];
                if(c == "C") ans.pop_back();
                else if(c == "D") ans.push_back(2*ans.back());
                else if(c == "+") ans.push_back(ans[ans.size()-1]+ans[ans.size()-2]); 
                else ans.push_back(stoi(c)); 
            }
        
        int cnt =0;
        for(int y: ans){
            cnt+= y;
        }
        return cnt;
        
    }
};
