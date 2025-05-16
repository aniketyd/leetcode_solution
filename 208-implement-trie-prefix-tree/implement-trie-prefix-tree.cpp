struct Node {
    Node* links[26];
    bool f = false;
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* nd = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (nd->links[index] == nullptr) {
                nd->links[index] = new Node();
            }
            nd = nd->links[index];
        }
        nd->f = true;
    }

    bool search(string word) {
        Node* nd = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (nd->links[index] == nullptr) {
                return false;
            }
            nd = nd->links[index];
        }
        return nd->f;
    }

    bool startsWith(string prefix) {
        Node* nd = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (nd->links[index] == nullptr) {
                return false;
            }
            nd = nd->links[index];
        }
        return true;
    }
};
