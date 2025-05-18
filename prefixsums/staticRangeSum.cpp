#include <iostream>
#include <vector>
#define ll long long

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    ll n, q;
    std::cin >> n >> q;
    std::vector<ll> a(n), pref(n + 1);
    for (ll i = 0; i < n; ++i) {
        std::cin >> a[i];
        pref[i+1] = pref[i] + a[i];
    }
    for (ll i = 0; i < q; ++i) {
        ll l, r;
        std::cin >> l >> r;
        std::cout << (pref[r] - pref[l]) << std::endl;
    }
    return 0;
}