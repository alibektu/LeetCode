class WordDictionary {
public:
  /** Initialize your data structure here. */
  WordDictionary() {
    trieDict = new TrieNode();
  }

  /** Adds a word into the data structure. */
  void addWord(string word) {
    TrieNode* temp = trieDict;

    for (int i=0;i<word.length();i++) {
      int key=word[i]-'a';
      if (!temp->child[key]) {
        temp->child[key] = new TrieNode;
      }

      temp = temp->child[key];
    }

    temp->end_of_word = true;
  }

  /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool search(string word) {
    return search(word, 0, trieDict);
  }
private:
  struct TrieNode {
    TrieNode* child[26]={NULL};
    bool end_of_word = false;
  };

  bool search(string word, int index, TrieNode* node) {
    if (index >= word.length()) {
      return !!node && node->end_of_word;
    }

    bool exist = false;
    if (word[index] == '.') {
      for (int i=0;i<26;i++) {
        if (!!node->child[i]) {
          exist = exist || search(word, index+1, node->child[i]);
        }
      }
    } else if (!!node->child[ word[index]-'a' ]) {
      exist = exist || search(word, index+1, node->child[word[index]-'a']);
    }

    return exist;
  }

  TrieNode* trieDict;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
