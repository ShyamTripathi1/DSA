class Solution {
public:
    bool isBalanced(string num) {
        int n = num.length();
        int sum =0;
        int count =0;

        for(int i =0;i<n;i++){
            if(i%2==0){
            sum+= (num[i]-'0');
            }
        }
            for(int j = 0;j<n;j++){
                if(j%2==1){
                    count += (num[j]-'0');
                }

            
            
        }
        return sum == count;
        
    }
};
