class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        // Start from the last digit
        for(int i = digits.size() - 1; i >= 0; i--) {

            // If digit is less than 9,
            // simply add 1 and we are done
            if(digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // If digit is 9, it becomes 0
            digits[i] = 0;
        }

        // If we reach here, every digit was 9
        digits.insert(digits.begin(), 1);

        return digits;
    }
};