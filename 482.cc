class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int num_a=0;
        for (int i=0;i<S.length();i++) {
            num_a += isalpha(S[i]) || isdigit(S[i])? 1: 0;
        }

        int len = num_a + ((num_a-1)/K);
        vector<char> v;
        v.resize(len);
        int i=S.length()-1;
        int j=0;
        int k=0;
        while (i>=0) {
            if (isalpha(S[i]) || isdigit(S[i])) {
                v[len-j-1] = toupper(S[i]),j++;
                
                k++;
                if (k%K==0 && k!=num_a) {
                    v[len-j-1] = '-',j++;
                }
            }
            i--;
        }
        
        string res(v.begin(), v.end());
        return res;
    }
};
