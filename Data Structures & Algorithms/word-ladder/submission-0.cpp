class Solution {
public:
    int ladderLength(string beginword, string endword, vector<string>& wordlist) {
        unordered_set<string> words(wordlist.begin(),wordlist.end());

        if(words.find(endword)==words.end())
            return 0;

        queue<string> q;
        q.push(beginword);
        int level=1;
        words.erase(beginword);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string word=q.front();
                q.pop();
                for(int i=0;i<word.length();i++){
                    char original=word[i];
                    for(char c='a';c<='z';c++){
                        if(c==original)
                            continue;
                        word[i]=c;
                        if (words.find(word) != words.end()) {
                            if (word == endword) {
                                return level + 1;
                            }
                            q.push(word);
                            words.erase(word);
                        }
                    }word[i] = original;
                }
            }
            level++;
        }
        return 0;
    }
};
