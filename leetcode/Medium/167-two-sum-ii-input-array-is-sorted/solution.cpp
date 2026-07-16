class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //sort(numbers.begin(),numbers.end());
        int n = numbers.size();
        int i =0,j=n-1;
        while(i<j){
            int sum = numbers[i]+numbers[j];
            if(sum == target)
                return {i+1,j+1};
            if(sum < target)
            i++;
            else if(sum > target)
            j--;
            
        }
        return {};
    }
};
