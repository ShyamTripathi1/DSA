class FreqStack {
public:
priority_queue<pair<int,pair<int,int>>>pq;
unordered_map<int,int>freq;
        int pos = 0;
    FreqStack() {     
    }
    
    void push(int val) {
    pq.push({++freq[val],{++pos,val}});
    }
    int pop() {
         auto value = pq.top();
       pq.pop();
       int x = value.second.second;
       freq[x]--;
       return x; 
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
