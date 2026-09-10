struct Node{
    Node* links[26] = {NULL};
    // bool flag = false;
    string word = "";

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    // void setEnd(){
    //     flag = true;
    // }

    // bool isEnd(){
    //     return flag;
    // }
};

class Solution {
private:
    Node* root = new Node();

    void insert(string &word) {
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                node->put(ch, new Node());
            }

            node = node->get(ch);
        }
        // node->setEnd();
        node->word = word; // marks end of word
    }

    void dfs(int r, int c, Node* node, vector<string> &ans, vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        char ch = board[r][c];
        if(ch == '#' || !node->containsKey(ch)) return;

        node = node->get(ch);

        if(!node->word.empty()){
            ans.push_back(node->word);
            node->word = "";
        }

        board[r][c] = '#';

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc]  != '#'){
                dfs(nr, nc, node, ans, board);
            }
        }
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        vector<string> ans;

        for(string &w : words){
            insert(w);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(i, j, root, ans, board);
            }
        }
        
        return ans;
    }
};