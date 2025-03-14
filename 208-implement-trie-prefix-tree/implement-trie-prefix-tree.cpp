struct TrieNode {
    TrieNode* links[26];
    bool flag;

    bool containsKey(char c){
        return links[c - 'a'] != NULL;
    }

    void add(TrieNode* newNode, char c){
        links[c - 'a'] = newNode;
    }

    TrieNode* get(char c){
        return links[c - 'a'];
    }

    bool isEnd(){
        return flag;
    }

    void setEnd(){
        flag = true;
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word){
            if(!node->containsKey(c)){
                TrieNode* newNode = new TrieNode();
                node->add(newNode, c);
            }
            node = node->get(c);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char c : word){
            if(!node->containsKey(c)){
                return false;
            }
            node = node->get(c);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c : prefix){
            if(!node->containsKey(c)){
                return false;
            }
            node = node->get(c);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */