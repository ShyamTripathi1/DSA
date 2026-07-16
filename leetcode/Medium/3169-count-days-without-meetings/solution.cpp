class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(),meetings.end());
        int start=0,end=0;
        int sum =0;
        for(int i =0;i<n;i++){
            if(meetings[i][0] > end){
                sum += meetings[i][0]-end-1;
            }
            end = max(end,meetings[i][1]);
        }
        if(end < days){
            sum += days-end;
        }
        return sum;
    }
};
