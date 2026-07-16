class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
    string result = "";
    for(int i =0;i<32;i++){
        int rem = n%2;
        result += to_string(rem);
        n /= 2;
    }
    //reverse(result.begin(),result.end());
    return stoul(result,nullptr,2);
    //return decimal;    
       
    }
};
