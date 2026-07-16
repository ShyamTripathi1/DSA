class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n = s.size();
        sort(s.begin(),s.end());
        int freq =0;
        int count = 1;
        for(int i =1;i<n;i++){
            if(s[i]== s[i-1]){
                count++;
            }
            
            else{
                if(freq ==0 ){
                    freq = count;
                }
                else if(count != freq){
                    return false;
                }
                count =1;

                }
            }
            if(freq ==0 ) freq = count;
            else if(count != freq) return false;

        
        return true;
    }
};
