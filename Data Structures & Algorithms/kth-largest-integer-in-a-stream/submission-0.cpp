class KthLargest {
public:
    int k;
    priority_queue<int ,vector<int>,greater<int>> minheap;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto num:nums){
            minheap.push(num);
            if(minheap.size()>k)
            minheap.pop();}

    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size()>k)
            minheap.pop();
        return minheap.top();
        
    }
};
