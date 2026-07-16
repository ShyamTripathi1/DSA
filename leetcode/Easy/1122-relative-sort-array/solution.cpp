class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        sort(arr1.begin(), arr1.end());  // sort arr1
        vector<int> ans;

        // Add elements of arr2 in the order they appear
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < arr1.size(); j++) {
                if (arr1[j] == arr2[i]) {
                    ans.push_back(arr1[j]);
                    arr1[j] = -1; // mark as used
                }
            }
        }

        // Add remaining elements of arr1
        for (int i = 0; i < arr1.size(); i++) {
            if (arr1[i] != -1) {
                ans.push_back(arr1[i]);
            }
        }

        return ans;
    }
};

