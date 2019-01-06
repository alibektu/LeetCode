class Solution {
public:
    int lengthLongestPath(string input) {
        istringstream ss(input);
        string token;
        unordered_map<int, int> path_len;
        path_len[0] = 0;
        size_t max_len = 0;
        while(getline(ss, token)) {
            int pos = token.find_last_of("\t");
            string name = (pos != string::npos) ? token.substr(pos+1) : token;
            int depth = token.length() - name.length();
            if (name.find('.') != string::npos) {
                max_len = max(max_len, path_len[depth] + name.length());
            } else {
                path_len[depth + 1] = path_len[depth] + name.length() + 1;
            }
        }
        
        return max_len;
    }
};
