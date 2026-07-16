class MyCircularQueue {
public:
    vector<int> q;
    int size;
    int count;
    int front;
     int rear;

    MyCircularQueue(int k) {
        q=vector<int>(k);
        size=k;
         count =0;
         front=0;
         rear=0;

        

    }
    
    bool enQueue(int value) {

        if (count ==size) return false;
        q[rear]=value;
        rear =(rear+1)%size;
        count = count+1;
        return true;



        
    }
    
    bool deQueue() {
        if (count ==0) return false;
        front = (front+1)%size;
        count = count-1;
        return true;
        
    }
    
    int Front() {
        

        if(count == 0) return -1;
         return q[front];
    }
    
    int Rear() {
        if(count == 0) return -1; 
        return q[(rear-1+size)%size];
        
    }
    
    bool isEmpty() {
        return count == 0;
        
        
    }
    
    bool isFull() {
        return count == size;
        
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
