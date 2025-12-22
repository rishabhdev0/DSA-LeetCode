class MedianFinder {
public:
    priority_queue<int> max_heap_left;  
    priority_queue<int, vector<int>, greater<int>> min_heap_right;  
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap_left.empty() || max_heap_left.top() > num){
            max_heap_left.push(num);
        } else {
            min_heap_right.push(num);
        }
        
        // Balance the heaps
        // Condition 1: If max_heap_left has 2+ more elements than min_heap_right
        if(max_heap_left.size() > min_heap_right.size() + 1){
            min_heap_right.push(max_heap_left.top());
            max_heap_left.pop();
        }
        
        // Condition 2: If min_heap_right has more elements than max_heap_left
        if(min_heap_right.size() > max_heap_left.size()){
            max_heap_left.push(min_heap_right.top());
            min_heap_right.pop();
        }
    }
    
    double findMedian() {
        if(max_heap_left.size() == min_heap_right.size()){
            double med = (max_heap_left.top() + min_heap_right.top()) / 2.0;
            return med;
        }
        return max_heap_left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */