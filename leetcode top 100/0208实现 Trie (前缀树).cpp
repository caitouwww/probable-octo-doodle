class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next,0,sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for(auto&w:word){
            if(node->next[w-'a']==nullptr){
                node->next[w-'a'] = new Trie();
            }
            node = node->next[w-'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for(auto&w:word){
            if(node->next[w-'a']==nullptr)return false;
            node = node->next[w-'a'];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for(auto&p:prefix){
            if(node->next[p-'a']==nullptr)return false;
            node = node->next[p-'a'];
        }
        return true;
    }
    bool isEnd;
    Trie* next[26];

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
