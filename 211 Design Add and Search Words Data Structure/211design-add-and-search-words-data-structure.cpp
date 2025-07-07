// Each node in the Trie
class WordNode {
public:
    WordNode* children[26]; // Pointers to child nodes for each letter a-z
    bool isEnd;             // Marks end of a complete word

    // Constructor: initializes children to nullptr and isEnd to false
    WordNode() {
        isEnd = false;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

// The main WordDictionary class
class WordDictionary {
private:
    WordNode* root; // Root of the Trie

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new WordNode(); // Create root node
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordNode* node = root;
        for (char ch : word) {
            int index = ch - 'a'; // Convert character to index (0 to 25)
            if (!node->children[index]) {
                // If child node doesn't exist, create it
                node->children[index] = new WordNode();
            }
            node = node->children[index]; // Move to the next node
        }
        node->isEnd = true; // Mark end of the inserted word
    }

    /** Returns true if there is any word in the data structure 
        that matches the given word, where '.' can match any letter. */
    bool search(string word) {
        return searchHelper(word, 0, root); // Start from root and index 0
    }

    // Recursive helper to support '.' wildcards
    bool searchHelper(const string& word, int pos, WordNode* node) {
        // If current node is null, return false
        if (!node) return false;

        // If we've reached the end of the word
        if (pos == word.size()) {
            return node->isEnd; // Return true only if it's a complete word
        }

        char ch = word[pos];
        if (ch == '.') {
            // '.' means we must try all possible children
            for (int i = 0; i < 26; ++i) {
                // If a path exists, try to match remaining characters
                if (searchHelper(word, pos + 1, node->children[i])) {
                    return true; // Early return if any path works
                }
            }
            return false; // None matched
        } else {
            // Normal character: go down that specific child
            int index = ch - 'a';
            return searchHelper(word, pos + 1, node->children[index]);
        }
    }
};
