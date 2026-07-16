class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
       // char a = letters[0];
        int n=letters.size();
        sort(letters.begin(),letters.end());
        for(int i=0;i<n;i++){
           if(letters[i]>target){
              return letters[i];
                break;
            }
        }
 
        return letters[0];    
    }
    
};
