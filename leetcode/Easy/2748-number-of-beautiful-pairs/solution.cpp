class Solution {
public:
int first(int x){
    while(x>=10) x/=10;
        return x;
    }

    int countBeautifulPairs(vector<int>& nums) {
        
        int cnt =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a = first(nums[i]);
                int b = nums[j]%10;
                if(gcd(a,b)==1){
                    cnt++;
                }
            }
        }
      return cnt;  
    }
};
