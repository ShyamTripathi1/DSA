class Solution {
public:
    bool isLongPressedName(string name, string typed) {    
        int i =0;
        if(name[0]!=typed[0]){
            return false;
        }
        
       for(int j =0; j<typed.length();j++){
           if(name[i]==typed[j]){
               i++;
           }
           if(name[i] != typed[j]  && name[i-1] != typed[j]){
               return false;
           }
       }
     

    if(i==name.length()){
        return true;
    }
    return false;

    }
};
