// Trie Node definition
class TrieNode {
public:
    TrieNode* children[26];  // Pointers to children nodes for 'a' to 'z'
    string word = "";        // Stores complete word at the end node

    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr; // Initialize all children as null
    }
};

class Solution {
private:
    TrieNode* root;                 // Root of the Trie
    vector<string> result;          // Stores the matched words
    int m, n;                       // Dimensions of the board
    vector<vector<char>> board;     // Copy of the board for DFS use

public:
    Solution() {
        root = new TrieNode();      // Create the root node of the Trie
    }

    // Function to insert a word into the Trie
    void insert(string& word) {
        TrieNode* node = root;      // Start at the root
        for (char ch : word) {
            int idx = ch - 'a';     // Map character to index 0-25
            if (!node->children[idx])
                node->children[idx] = new TrieNode(); // Create node if needed
            node = node->children[idx]; // Move to next node
        }
        node->word = word;          // Store the complete word at the last node
    }

    // DFS function to explore the board starting from board[i][j]
    void dfs(int i, int j, TrieNode* node) {
        char ch = board[i][j];          // Current character
        int idx = ch - 'a';             // Convert char to index

        TrieNode* nextNode = node->children[idx];  // Move to corresponding child in Trie
        if (!nextNode) return;          // If no such child, path is invalid

        // If a complete word ends here, add to result
        if (!nextNode->word.empty()) {
            result.push_back(nextNode->word);  // Found a word
            nextNode->word = "";               // Avoid duplicate matches
        }

        board[i][j] = '#';     // Mark the current cell as visited

        // All 4 directions: up, down, left, right
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for (auto& dir : dirs) {
            int ni = i + dir[0];     // New row
            int nj = j + dir[1];     // New column

            // Check if next cell is within bounds and not visited
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] != '#') {
                dfs(ni, nj, nextNode);  // Recurse to next cell
            }
        }

        board[i][j] = ch;  // Backtrack: restore the character
    }

    // Main function to find all words from the list in the board
    vector<string> findWords(vector<vector<char>>& _board, vector<string>& words) {
        board = _board;               // Copy board for use in DFS
        m = board.size();            // Rows
        n = board[0].size();         // Columns

        // Build Trie from the list of words
        for (string& word : words)
            insert(word);            // Insert each word into the Trie

        // Start DFS from every cell in the board
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dfs(i, j, root);     // Start DFS from each cell

        return result;               // Return all matched words
    }
};
