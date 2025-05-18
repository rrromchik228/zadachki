#include <iostream>
#include <vector>
#define ll long long

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    ll n;
    std::cin >> n;
    std::vector<ll> a(n), pref(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        pref[i+1] = pref[i] + a[i];
    }
    for (int i = n; i >= 0; --i) {
        for (int j = 0; j < n - i; ++j) {
            if ((pref[j+i] - pref[j]) % 7 == 0) {
                std::cout << i << std::endl;
                return 0;
            }
        }
    }
    std::cout << 0 << std::endl;
    return 0;
}