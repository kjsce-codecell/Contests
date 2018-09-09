#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
 
int numFac(int n) {
  int ret = 0;
  for(int i = 1; i <= n; i++)
    if (n%i == 0)
      ret++;
  return ret;
}
 
int bestCombo(vector <int> digits) {
  sort(digits.begin(), digits.end());
  int best = 999999;
  int bestnum = -1;
  do {
    int num = 0;
    for(int i = 0; i < digits.size(); i++) {
      num *= 10;
      num += digits[i];
    }
    if (best > numFac(num)) {
    best = numFac(num);
    bestnum = num;
    }
  }
  while(next_permutation(digits.begin(), digits.end()));
 
  return bestnum;
}
 
vector<int> digits;
int d;
 
int main() {
  int nc = 0;
  cin >> nc;
  string line;
  getline(cin, line);
  while(nc--) {
    getline(cin, line);
    stringstream sin(line);
    digits.clear();
    while(sin >> d) digits.push_back(d);
    cout << bestCombo(digits) << endl;
  }
  return 0;
} 