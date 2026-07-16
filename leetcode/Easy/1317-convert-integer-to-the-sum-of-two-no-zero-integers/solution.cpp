class Solution {
public:
bool hasZero(int x){
    if(x==0) return true;
    while(x>0){
        if(x%10==0) return true;
        x/=10;
    }
    return false;
}

    vector<int> getNoZeroIntegers(int n) {
        for(int i=0;i<n;i++){
            int b=n-i;
            if(!hasZero(i) && !hasZero(b)){
                return {i,b};
            }
        }
        return {};
    }
};
