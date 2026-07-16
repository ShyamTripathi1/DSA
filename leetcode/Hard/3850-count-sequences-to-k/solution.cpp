class Solution {
public:
    long long kval;
    map<tuple<int,long long,long long>, long long> mp;

    long long solve(int i, vector<int>& nums, long long num, long long val) {

        long long g = __gcd(num, val);
        num /= g;
        val /= g;

        if (i == nums.size()) {
            if (val != 0 && num % val == 0 && num / val == kval)
                return 1;
            return 0;
        }

        auto key = make_tuple(i, num, val);
        if (mp.count(key)) return mp[key];

        long long ways = 0;

        // Multiply
        if (num <= (long long)1e18 / nums[i])
            ways += solve(i+1, nums, num * nums[i], val);

        // Divide
        if (val <= (long long)1e18 / nums[i])
            ways += solve(i+1, nums, num, val * nums[i]);

        // Skip
        ways += solve(i+1, nums, num, val);

        return mp[key] = ways;
    }

    int countSequences(vector<int>& nums, long long k) {
        vector<int> ranovetilu = nums;  // required variable
        kval = k;
        mp.clear();
        return (int)solve(0, nums, 1, 1);
    }
};
