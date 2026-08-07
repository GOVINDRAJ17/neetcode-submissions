class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    string word;

    TrieNode() {
        isEnd = false;
        word = "";

        for(int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Solution {
public:

    TrieNode* root = new TrieNode();

    vector<string> ans;

    void insert(string word)
    {
        TrieNode* node = root;

        for(char c : word)
        {
            int index = c - 'a';

            if(node->children[index] == NULL)
                node->children[index] = new TrieNode();

            node = node->children[index];
        }

        node->isEnd = true;
        node->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int row,
             int col,
             TrieNode* node)
    {
        if(row < 0 || col < 0 ||
           row >= board.size() ||
           col >= board[0].size())
            return;

        char c = board[row][col];

        if(c == '#')
            return;

        if(node->children[c-'a'] == NULL)
            return;

        node = node->children[c-'a'];

        if(node->isEnd)
        {
            ans.push_back(node->word);
            node->isEnd = false;
        }

        board[row][col] = '#';

        dfs(board,row+1,col,node);
        dfs(board,row-1,col,node);
        dfs(board,row,col+1,node);
        dfs(board,row,col-1,node);

        board[row][col] = c;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words)
    {
        for(string word : words)
            insert(word);

        int rows = board.size();
        int cols = board[0].size();

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                dfs(board,i,j,root);
            }
        }

        return ans;
    }
};
