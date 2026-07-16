class Solution {
public:
    double average(vector<int>& salary) {
        int maxVal = *max_element(salary.begin(), salary.end());
        int minVal = *min_element(salary.begin(), salary.end());
        int sum =0;
        for(int i=0;i<salary.size();i++){
            if(salary[i]!=maxVal && salary[i]!=minVal){
                sum = sum+salary[i];
            }
        }
        return double(sum)/(salary.size()-2);
    }
};
