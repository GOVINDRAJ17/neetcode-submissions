class Solution {
public:
    vector<vector<int>> result;
    vector<int> permutation;
    void backtrack(vector<int>& nums,vector<bool>& used){
        if(permutation.size()==nums.size()){
            result.push_back(permutation);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i])
                continue;
            permutation.push_back(nums[i]);
            used[i]=true;

            backtrack(nums,used);

            permutation.pop_back();
            used[i]=false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        backtrack(nums,used);
        return result;
    }
};
