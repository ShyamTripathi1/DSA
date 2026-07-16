class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int n = aliceSizes.size();
        int m = bobSizes.size();
        int sumAlice =0 , sumBob =0;
        for(int x:aliceSizes) sumAlice += x;
        for(int y:bobSizes) sumBob += y;
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((aliceSizes[i]-bobSizes[j]) == (sumAlice - sumBob)/2){
                ans.push_back(aliceSizes[i]);
                ans.push_back(bobSizes[j]);
                return ans;
                }
            }
        }
        return ans;
    }
};
