class MyCalendar {
public:
vector<pair<int,int>> ans;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(int i =0;i<ans.size();i++){
            int s = ans[i].first;
            int e = ans[i].second;
            if(max(s,startTime)<min(e,endTime)) return false;
        }
        ans.push_back({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
