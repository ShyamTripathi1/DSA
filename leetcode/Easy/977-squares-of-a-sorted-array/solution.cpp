class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
      int nn = a.size();
      vector<int> pos;
      vector<int> neg;
      for(int i =0;i<nn;i++){
        if(a[i]<0){
            neg.push_back(a[i]);
        }
        else{
            pos.push_back(a[i]);
        }
      }
      if(neg.size() == 0){ //only pos ele present
        for(int i =0;i<pos.size();i++){
            pos[i] = pos[i]*pos[i];
            
        }
        return pos;
      }
      if(pos.size() == 0){
         for(int i =0;i<neg.size();i++){
            neg[i] = neg[i]*neg[i];
           
            
        }
         reverse(neg.begin(),neg.end());
        return neg;
      }
      int i=0,j=0;
      int id =0;
      int n = neg.size();
      int m = pos.size();
      vector<int> res(n+m);
      for(int i =0;i<n;i++)
      neg[i] = neg[i] * neg[i];
      reverse(neg.begin(),neg.end());

      for(int i =0;i<m;i++){
        pos[i] = pos[i] *pos[i];

      }
      while(i<n && j<m){
        if(neg[i] <= pos[j] ){
        res[id] = neg[i];
        i++;
        id++;
        }
        else{
            res[id] = pos[j];
            j++;
            id++;

        }
      }
      while(i<n){
        res[id] = neg[i];
        i++;
        id++;
      }
      while(j<m){
        res[id]= pos[j];
        j++;
        id++;
      }
      return res;
    }
};
