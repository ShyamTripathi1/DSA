class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int penalty = 0;
        for(int i =0;i<n;i++){
            if(customers[i] == 'Y') penalty++;
        }
        int minPenalty = penalty;
        int bestHour = 0;
        for(int j =1;j<=n;j++){
            if(customers[j-1] == 'Y'){
                penalty--;
            }
            else{
                penalty++;
            }
            if(penalty < minPenalty){
                minPenalty = penalty;
                bestHour= j;
            }
        }

return bestHour;
        
    }
};
