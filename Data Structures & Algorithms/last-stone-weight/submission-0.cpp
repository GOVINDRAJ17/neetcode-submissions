class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;
        for(int stone:stones){
            maxheap.push(stone);
        }

        while(maxheap.size()>1){
            int x=maxheap.top();
            maxheap.pop();
            int y=maxheap.top();
            maxheap.pop();
            if(x!=y){
                maxheap.push(x-y);
            }
        }
        if(maxheap.empty())
        return 0;
        return maxheap.top();
    }
};
