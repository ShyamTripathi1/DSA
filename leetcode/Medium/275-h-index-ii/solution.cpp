class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n= citations.size();
        int count =0;
        for(int i=n-1;i>=0;i--){
            if(citations[i]>count){
                count++;
            }
            else{
                break;
            }
        }
        return count;
        
    }
};
