class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int num : nums){
            freq[num]++;
        }

        vector<vector<int>> bucket(nums.size()+1);
        for(auto x : freq){
            bucket[x.second].push_back(x.first);
        }


        vector<int> ans;
        //traverse
        for(int i =bucket.size()-1;i>=0 && ans.size()<k ; i--){
            for(int num : bucket[i]){
                ans.push_back(num);
                if(ans.size() == k){
                    break;
                }
            }

        }
        return ans;
    }
};
