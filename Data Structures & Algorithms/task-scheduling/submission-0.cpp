class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char task:tasks)
            freq[task-'A']++;
        
        priority_queue<int> maxheap;
        for(int f: freq){
            if(f>0)
                maxheap.push(f);
        }
        queue<pair<int,int>> q;
        int time=0;
        while(!maxheap.empty()|| !q.empty()){
            time++;
            if(!maxheap.empty()){
                int count=maxheap.top();
                maxheap.pop();
                count--;
                if(count>0)
                    q.push({count,time+n});
            }
            if(!q.empty()&& q.front().second==time){
            maxheap.push(q.front().first);
            q.pop();
        }
        }
        
        return time;
    }
};
