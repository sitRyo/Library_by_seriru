#include <bits/stdc++.h>
using namespace std;

/* こちらから拝借しました。 http://drken1215.hatenablog.com/entry/2019/09/16/014600 */
// TODO: 後で自分で書き直す。

// Z algorithm
// 前処理でO(N)で配列lcpを求める。
// S自身とS[i:]とが、先頭から最大で何文字一致しているかをO(1)で求めることができる。
vector<int> Zalgo(const string &S) {
    int N = (int)S.size();
    vector<int> res(N);
    res[0] = N;
    int i = 1, j = 0;
    while (i < N) {
        while (i+j < N && S[j] == S[i+j]) ++j;
        res[i] = j;
        if (j == 0) {++i; continue;}
        int k = 1;
        while (i+k < N && k+res[k] < j) res[i+k] = res[k], ++k;
        i += k, j -= k;
    }
    return res;
}

// ZアルゴリズムとはSとS[i, |S|]の最長接頭辞の長さを記録した配列を作るもの。
// つまり、S[0, 2], S[2, |S|] の共通接頭辞を求めるには、min(2, lcp[2])
// 例えば、この問題では ababa
// Sと, S[2:|S|]のlcpは3、だけどS[0, 1], S[2, |S|] の最大接頭辞は2