class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
      int n = nums.size();
      vector<int>ans;
      vector<int>even,odd;
      for(int i=0;i<n;i++){
        if(i%2 ==0)even.push_back(nums[i]);
           else odd.push_back(nums[i]);
        
      }
      sort(even.begin(),even.end());
      sort(odd.begin(),odd.end(),greater<int>());
      int e=0,c=0;
      for(int i=0;i<n;i++){
        if(i%2==0) ans.push_back(even[e++]);
       else ans.push_back(odd[c++]);
      }
    return ans;
    }
};
