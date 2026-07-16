class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
       // if(left.size() == 0 || num < left.top()) left.push(num);
        //else right.push(num);
        left.push(num);
        int a=left.top();
        left.pop();
        right.push(a);
        
       if(left.size()<right.size()){
        int b = right.top();
        right.pop();
        left.push(b);
        
       }


        
    }
    
    double findMedian() {
        if(left.size() >right.size()) return left.top();
        else return (left.top() + right.top())/2.0;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
