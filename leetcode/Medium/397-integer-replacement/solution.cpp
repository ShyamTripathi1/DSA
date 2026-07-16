class Solution {
public:
    int integerReplacement(int n) {
        long long num = n;
                int count = 0;
                        while (num > 1) {
                                    std::cout << "num: " << num << "\n";
                                                if (num % 2 == 0) {
                                                                num /= 2;
                                                                            } else {
                                                                                            if (num == 3 || ((num >> 1) & 1) == 0) {
                                                                                                                num -= 1;
                                                                                                                                } else {
                                                                                                                                                    num += 1;
                                                                                                                                                                    }
                                                                                                                                                                                }
                                                                                                                                                                                            count++;
                                                                                                                                                                                                    }
                                                                                                                                                                                                            return count;
        
    }
};
