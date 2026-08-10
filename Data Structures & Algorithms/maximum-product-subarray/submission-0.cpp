class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];

        int answer = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            int num = nums[i];

            int oldMax = maxProd;
            int oldMin = minProd;

            maxProd = max({
                num,
                oldMax * num,
                oldMin * num
            });

            minProd = min({
                num,
                oldMax * num,
                oldMin * num
            });

            answer = max(answer, maxProd);
        }

        return answer;
    }
};
