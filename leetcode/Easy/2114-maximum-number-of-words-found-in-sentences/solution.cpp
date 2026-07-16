class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n = sentences.size();
        int maximum = 0;
        for(char i =0;i<n;i++){
            //int count =0;
            //for( char c: sentences[i]){
            //if(c != ' ') count++;
           // }
            int words = 1;
            for( char c: sentences[i]){
            if(c == ' ') words++;
            }
            maximum = max(maximum ,words);
        }
     return maximum;
        
    }
};
