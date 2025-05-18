#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long

inline void solve() {
    int n; 
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> a(n);
    for (size_t i = 0; i < n; ++i) {
        a[i] = (s[i] - '0');
    }
    std::vector<int> pref(n);
    for (int i = 0; i < n; ++i) {
        pref[i] = (i ? pref[i-1] : 0) + a[i];
    }
    std::unordered_map<int, int> mp;
    mp[0] = 1;
    ll ans = 0ll;
    for (int i = 0; i < n; ++i) {
        int p = pref[i] - i - 1;
        mp[p] += 1;
        ans += mp[p] - 1;
    }
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}