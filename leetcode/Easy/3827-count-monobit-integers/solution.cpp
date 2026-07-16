class Solution {
public:
    int countMonobit(int n) {
        int count = 1; 
        int nums = 1;

        while (nums <= n) {
            count++;
            nums = (nums << 1) | 1;
        }
        return count;
    }
};
