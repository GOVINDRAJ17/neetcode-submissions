class TrieNode {
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

class PrefixTree{
public:
    TrieNode* root;
    PrefixTree(){
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node=root;
        for(char c:word){
            int index=c-'a';
            if(node->children[index] == nullptr)
                node->children[index] =new TrieNode();

            node=node->children[index];
        }
        node->isend=true;
    }
    
    bool search(string word) {
        TrieNode* node=root;
        for(char c:word){
            int index=c-'a';
            if(node->children[index] == nullptr)
                return false;

            node=node->children[index];
        }
        return node->isend;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(char c:prefix){
            int index=c-'a';
            if(node->children[index] == nullptr)
                return false;

            node=node->children[index];
        }
        return true;
    }
};
