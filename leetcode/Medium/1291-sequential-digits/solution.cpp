class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> qt;
        for(int i = 1;i<=8;i++){
            qt.push(i);
        }
        vector<int> res;
        while(!qt.empty()){
            int temp = qt.front();
            qt.pop();
            if(temp >= low && temp<= high){
                res.push_back(temp);
            }
            int last_digit = temp%10;
            if(last_digit+1 <= 9){
                qt.push(temp*10+(last_digit+1));
            }
        }
        return res;
    }
};
