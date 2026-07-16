class Solution {
public:
    int mirrorReflection(int p, int q) {
          int g = gcd(p, q);
        p /= g;
        q /= g;
       if(p % 2 == 1 && q % 2 == 1) return 1;
        if(p % 2 == 1 && q % 2 == 0) return 0;
        if(p % 2 == 0 && q % 2 == 1) return 2;
        return -1;
    }
};
