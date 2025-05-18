#include <iostream>
#include <vector>
#include <tuple>
#define ll long long

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    std::vector<std::tuple<int, int, int>> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        int first, second, third;
        std::tie(first, second, third) = pref[i];
        pref[i+1] = std::make_tuple(first + (a[i] == 1), second + (a[i] == 2), 
            third + (a[i] == 3));
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        std::cin >> l >> r;
        int left_first, left_second, left_third;
        int right_first, right_second, right_third;
        std::tie(left_first, left_second, left_third) = pref[l-1];
        std::tie(right_first, right_second, right_third) = pref[r];
        std::cout << (right_first - left_first) << ' ' << (right_second - left_second) << ' ' << 
            (right_third - left_third) << std::endl;
    }
    return 0;
}