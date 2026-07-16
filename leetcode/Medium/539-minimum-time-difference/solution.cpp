class Solution {
public:
    int toMin(string &time) {
        return ((((time[0] - '0') * 10) + (time[1] - '0')) * 60) +
               (((time[3] - '0') * 10) + (time[4] - '0'));
//or
//        return stoi(time.substr(0 , 2)) * 60 + stoi(time.substr(3 , 2));

    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        for (int i = 0; i < timePoints.size(); i++) {
            minutes.push_back(toMin(timePoints[i]));
        }
        sort(minutes.begin(), minutes.end());
        int minimum = INT_MAX;
        for (int i = 0; i < minutes.size() - 1; i++) {
            int diff = abs(minutes[i] - minutes[i + 1]);
            minimum = min(minimum, diff);
        }
        int lastdiff = 1440 - minutes.back() + minutes.front();
        minimum = min(minimum, lastdiff);

        return minimum;
    }
};
