#include <iostream>
#include <vector>
#define ll long long 

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> beauty(n);
        for (int i = 0; i < n; ++i) { std::cin >> beauty[i]; }

        std::vector<int> pref_max(n);
        std::vector<int> suff_max(n);
        for (int i = 0; i < n; ++i) {
            pref_max[i] = beauty[i] + i;
            suff_max[i] = beauty[i] - i;
        }
        for (int i = 1; i < n; ++i) { pref_max[i] = std::max(pref_max[i-1], pref_max[i]); }
        for (int i = n - 2; i >= 0; --i) {
            suff_max[i] = std::max(suff_max[i], suff_max[i+1]);
        }
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            ans = std::max(ans, pref_max[i-1] + beauty[i] + suff_max[i+1]);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}