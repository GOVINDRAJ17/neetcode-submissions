class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26,0);
        vector<int> count2(26,0);

    

        for(int c : s1)
            count1[c - 'a']++;
        
        int windowsize=s1.size();
        for(int i=0;i<s2.size();i++){
            count2[s2[i] -'a']++;

            if(i>=windowsize)
                count2[s2[i-windowsize] -'a']--;
            if(count1==count2)
                return true;
        }
        return false;
    }
};
