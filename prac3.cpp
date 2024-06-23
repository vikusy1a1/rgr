#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  int q;
  cin >> q;

  while (q--) {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (auto& price : prices) {
      cin >> price;
    }

    // Добавляем 'n' в список захвата лямбда-функции
    auto new_price = [&prices, n]() { 
      long long total_sum = accumulate(prices.begin(), prices.end(), 0LL);
      return (total_sum + n - 1) / n; 
    };

    cout << new_price() << endl;
  }

  return 0;
}
