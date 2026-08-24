class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;

    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxheap.empty() || num<=maxheap.top()){
            maxheap.push(num);
        }else{
            minheap.push(num);
        }
        if(maxheap.size() > minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        if(minheap.size() > maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        
    }
    
    double findMedian() {
        if(maxheap.size()>minheap.size()){
            return maxheap.top();
        }
        return(maxheap.top() + minheap.top() )/2.0;
    }
};
