class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int ele : arr){
            mp[ele]++;
        }
        vector<int> freq;
        
        for(const auto& pair:mp){
            freq.push_back(pair.second);
        }
        sort(freq.begin(),freq.end());
        int cnt = 0;
        for(int ele : freq){
            if(k>=ele){
                k-= ele;
                cnt++;
            }
            else{
                break;
            }
        }

        return freq.size()-cnt;
    }
};
