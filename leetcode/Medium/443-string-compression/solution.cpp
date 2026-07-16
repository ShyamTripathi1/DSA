class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int ansIndex = 0;
        int n = chars.size();

        while (i < n) {
            int j = i + 1;

            // Count how many times chars[i] repeats
            while (j < n && chars[i] == chars[j]) {
                j++;
            }

            // Place the character
            chars[ansIndex++] = chars[i];

            int count = j - i; // ✅ Fix: count should be j - i

            // If more than 1 occurrence, convert count to string and store each digit
            if (count > 1) {
                string cnt = to_string(count);
                for (char ch : cnt) {
                    chars[ansIndex++] = ch;
                }
            }

            // Move to the next group
            i = j;
        }

        return ansIndex;
    }
};

