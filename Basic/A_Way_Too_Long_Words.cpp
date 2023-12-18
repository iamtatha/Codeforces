#include<bits/stdc++.h>
using namespace std;

string solve(string &word) {
    int n = word.size();
    if(n <= 10)
        return word;

    string ans;
    ans += word[0];
    ans += to_string(n-2);
    ans += word[n-1];

    return ans;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        string word;
        cin >> word;

        cout << solve(word) << endl;
    }

    return 0;
}