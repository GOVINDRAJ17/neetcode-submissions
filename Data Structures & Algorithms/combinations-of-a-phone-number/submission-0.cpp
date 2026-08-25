class Solution {
public:
    vector<string> result;
    string current;
    vector<string> keypad={
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };

    void backtrack(string& digits,int index){
        if(index==digits.length()){
            result.push_back(current);
            return;
        }
        string letters=keypad[digits[index] -'0'];
        for(auto c:letters){
            current.push_back(c);
            backtrack(digits,index+1);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
            return {};
        backtrack(digits,0);
        return result;
    }
};
