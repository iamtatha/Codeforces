#include<bits/stdc++.h>
using namespace std;

int solve(int a, int b, int c) {
    int count = a+b+c;
    return (count > 1) ? 1 : 0;
}

int main() {
    int n,ans = 0;
    cin >> n;
    while(n--) {
        int a,b,c;
        cin >> a >> b >> c;

        ans += solve(a,b,c);
    }

    cout << ans << endl;
    return 0;
}
