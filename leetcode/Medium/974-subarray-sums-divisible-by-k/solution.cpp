class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>m;
        m[0]=1;
        int PrefixSum =0,rem,total =0;
        for(int i=0;i<n;i++){
            PrefixSum+= nums[i];
            rem = PrefixSum%k;
            if(rem < 0)
             rem += k;
                if( m.count(rem))
                {
                    total += m[rem];
                    m[rem]++;
                }
                else
                m[rem]++;
            }
           
     return total;
        
    }
};
