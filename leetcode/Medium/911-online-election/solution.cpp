class TopVotedCandidate {
public:   
   vector<int>times;
    vector<int>ans;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
      this->times = times;
      int max_vote = 0;
      int n = times.size();
      vector<int>cnt(n+1,0);
      int leader = -1;
      for(int i =0;i<persons.size();i++){
        int p = persons[i];
        cnt[p]++;
        if(cnt[p]>=max_vote){
            max_vote = cnt[p];
            leader = p;
        }
        ans.push_back(leader);
      }
      
    }
    int q(int t) {
          int l=0;
          int r = times.size()-1;
          int x = 0;
          while(l<=r){
            int m = (l+r)/2;
          if(times[m]<=t){
            x = m;
            l=m+1;
          }
          else{
            r=m-1;

          }
          }
          return ans[x];
          
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
