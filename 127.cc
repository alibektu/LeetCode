class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> tail, head, *ptail, *phead;
    unordered_set<string> word_dic;

    for (auto word : wordList) {
      word_dic.insert(word);
    }

    if (word_dic.find(endWord) == word_dic.end()) {
      return 0;
    }

    head.insert(beginWord);
    tail.insert(endWord);

    int dist = 2;
    while (!head.empty() && !tail.empty()) {
      if (head.size() < tail.size()) {
        phead = &head;
        ptail = &tail;
      } else {
        phead = &tail;
        ptail = &head;
      }
      unordered_set<string> temp;
      for (auto itr = phead->begin(); itr != phead->end(); itr++) {
        string word = *itr;
        word_dic.erase(word);
        for (int p = 0; p < (int)word.length(); p++) {
          char letter = word[p];
          for (int k = 0; k < 26; k++) {
            word[p] = 'a' + k;
            if (ptail->find(word) != ptail->end()) return dist;
            if (word_dic.find(word) != word_dic.end()) {
              temp.insert(word);
              word_dic.erase(word);
            }
          }
          word[p] = letter;
        }
      }
      dist++;
      swap(*phead, temp);
    }
    return 0;
  }
};
