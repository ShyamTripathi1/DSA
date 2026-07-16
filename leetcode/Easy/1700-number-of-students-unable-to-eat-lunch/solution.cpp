class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        sort(students.begin(),students.end());
        int count0 = 0;
        int count1 =0 ;
        for(int i =0;i<n;i++){
            if(students[i]==0){
                count0++;

            }
            else{
                count1++;
            }
        }
        for(int j=0;j<sandwiches.size();j++){
            if(sandwiches[j]==0){
                if(count0>0){
                    count0= count0-1;

                }
                else{
                    break;
                }
            }
            else{
                if(count1>0){
                    count1 = count1-1;
                }
                else{
                    break;
                }
            }
        }

   return count0+count1;
        
    }
};
