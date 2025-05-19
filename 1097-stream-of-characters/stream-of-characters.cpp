class StreamChecker {
public:
    class Trie{
        public:
        Trie *child[26];
        bool isEnd = false;
    };
    
    void insert(string &s, Trie *root){
        Trie *cur = root;
        int n=s.size();
        for(int i=n-1; i>=0; --i){
            char ch = s[i];
            if(!cur->child[ch-'a']) cur->child[ch-'a'] = new Trie();
            cur=cur->child[ch-'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string &s, Trie *root){
        Trie *cur = root;
        int n=s.size();
        for(int i=n-1; i>=0; --i){
            char ch = s[i];
            if(!cur->child[ch-'a']) return false;
            cur=cur->child[ch-'a'];
            if(cur->isEnd) return true;
        }
        return false;
    }
    
    Trie *root;
    string str ="";
    StreamChecker(vector<string>& words) {
        root = new Trie();
        for(auto &w : words) insert(w,root);
    }
    
    bool query(char letter) {
        str.push_back(letter);
        return search(str,root);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */