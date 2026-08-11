class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newintervals) {
        vector<vector<int>> result;
        int i=0,n=intervals.size();

        while(i<n && intervals[i][1]<   newintervals[0]){
            result.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0] <= newintervals[1]){
            newintervals[0]=min(newintervals[0],intervals[i][0]);
            newintervals[1]=max(newintervals[1],intervals[i][1]);
            i++;
        }
        result.push_back(newintervals);
        while(i < n){
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
