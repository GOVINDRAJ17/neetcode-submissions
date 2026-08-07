class TrieNode{
public:
    TrieNode* children[26];
    bool isend;
    TrieNode()
    {
        isend=false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};


class WordDictionary {
public:
    TrieNode* root; 
    WordDictionary() {
         root=new TrieNode(); 
    }

    void addWord(string word) {
        TrieNode* node=root;
        for(char c : word){
            int index = c-'a';
            if(node->children[index] ==nullptr){
                node->children[index]=new TrieNode();
            }
            node = node->children[index];
        }    
        node->isend=true;
    }
    
    bool dfs(TrieNode* node,string& word,int index){
        if(index==word.length()){
            return node->isend;
        }
        char c =word[index];
        if(c=='.')
        {
            for(int i=0;i<26;i++){
                if(node->children[i] != nullptr){
                    if(dfs(node->children[i] , word,index+1))
                        return true;
                }
            }
            return false;
        }
        int child=c-'a';
        if(node->children[child]==nullptr){
            return false;
        }
        return dfs(node->children[child] , word,index+1);


    }


    bool search(string word) {
        return dfs(root, word, 0);
    }
};
