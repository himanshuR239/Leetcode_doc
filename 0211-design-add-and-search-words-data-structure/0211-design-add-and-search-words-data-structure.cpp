struct Node {
    Node* links[26] = {nullptr};
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class WordDictionary {
private:
    Node* root;

    bool dfs(int ind, string &word, Node* node){
        if(!node) return false;
        if(ind == word.size()) return node->isEnd();

        char ch = word[ind];

        if(ch != '.'){
            if(!node->containsKey(ch)) return false;

            return dfs(ind+1, word, node->get(ch));
        }

        for(int i = 0; i < 26; i++){
            if(node->links[i] && dfs(ind+1, word, node->links[i])) return true;
        }

        return false;
    }

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return dfs(0, word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */