class KthLargest {
public:
int K;
    priority_queue<int,vector<int>,greater<int>>maxi;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int x:nums){
            maxi.push(x);
            if(maxi.size()>k){
                maxi.pop();
            }
        }
        
    }
    
    int add(int val) {
        maxi.push(val);
        if(maxi.size()>K){
            maxi.pop();
        }
        return maxi.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
