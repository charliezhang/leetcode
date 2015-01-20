#include<iostream>
using namespace std;

#define DB(x) (cout << #x << ": " << x << endl)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        if (s3.size() == 0 || (s1.size() == 0 && s2 == s3) || (s2.size() == 0 && s1 == s3)) {
            return true;
        }
        bool D[s1.size() + 1][s2.size() + 1];
        D[0][0] = 1;

        for (int i = 0; i <= s1.size(); ++i) {
            for (int j = 0; j <= s2.size(); ++j) {
                if (i == 0 && j == 0) {
                     continue;
                 }
                if (i == 2 && j == 2) {
                  DB(i);
                  DB(j);
                  DB(D[i-1][j]);
                  DB(s1[i-1]);
                  DB(s3[i+j-1]);
                }
                D[i][j] =  (i > 0 && D[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                    (j > 0 && D[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            cout << i << ", " << j << ", " << D[i][j] << endl;
            }
        }
        return D[s1.size()][s2.size()]; 
    }
};

#define TEST(a, b, c) (cout << (s.isInterleave(a, b, c) ? "true" : "false") << endl)
int main() {
  Solution s;
  TEST("ab", "bc", "bbac");
  TEST("aa", "ab", "abaa");
}
