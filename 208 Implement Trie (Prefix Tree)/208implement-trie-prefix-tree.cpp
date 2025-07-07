class TrieNode {
public:
    TrieNode* children[26]; // Pointers to child nodes for 'a' to 'z'
    bool isEndOfWord;       // Marks end of a word

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode(); // Root is an empty node
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a'; // Map character to index 0-25
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index]; // Move to the child
        }
        node->isEndOfWord = true; // Mark end of word
    }

    /** Returns true if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
                return false;
            node = node->children[index];
        }
        return node->isEndOfWord; // Must be end of a word, not just prefix
    }

    /** Returns true if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
                return false;
            node = node->children[index];
        }
        return true; // Found the prefix path
    }
};
