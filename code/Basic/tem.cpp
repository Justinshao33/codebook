#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define int long long
#define all(a) begin(a), end(a)
#define rep(a, b, c) for (int a = b; a < c; a++)
#define pb push_back
#define F first
#define S second
#define SZ(x) (x).size()

bool chmin(auto& a, auto b) { return (b < a and (a = b, true)); }
bool chmax(auto& a, auto b) { return (a < b and (a = b, true)); }

void solve() {
    //
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1; cin >> t;
    while (t--) solve();
}
