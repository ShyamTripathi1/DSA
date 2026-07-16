class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mini = INT_MAX;
        //int n = nums.size();
        for(int x:nums){
            if(x%2 == 1) x *= 2;
                pq.push(x);
            
                mini = min(mini,x);
            
        }
        int ans = pq.top()-mini;
        while(pq.top()%2 == 0){
            int x = pq.top();
            pq.pop();
            x /= 2;
            mini = min(mini,x);
            pq.push(x);
             ans = min(ans,pq.top()-mini);
        
        }
        return ans;
    }
};
