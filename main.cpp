#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <climits>

using namespace std;

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto x = [](){ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

class Solution {
public:
    // Algorithm frpom https://javabypatel.blogspot.com/2017/05/count-trailing-zeros-in-factorial-of-number.html
    // 5*2 gives 10, 1 zero - as many zeros as n/5
    // 25 itself has 5*5 - as many more zeros as n/25
    int trailingZeroes(int n) {
      int mult = 5;
      int zeros = n / mult;
      int total = 0;
      int n5 = n / 5;
      while (zeros > 0) {
        total += zeros;
        if (mult > n5) break;
        mult *= 5;
        zeros = n / mult;
      }
      return total;
    }
};

void test1() {
  Solution S;
  cout << "0?" << S.trailingZeroes(3) << endl;
  // 5 4 3 2 1
  cout << "1?" << S.trailingZeroes(5) << endl;
  // 10 9 8 7 6 5 4 3 2 1 = 3628800
  cout << "2?" << S.trailingZeroes(10) << endl;
  // 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 = ...0000
  // / 10
  // 2 ,,,,,,, 1 ,,,,,, 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
  cout << "4 ?" << S.trailingZeroes(20) << endl;
  // fact(30) = ...0000000 = 7
  cout << "7 ?" << S.trailingZeroes(30) << endl;
  cout << "9 ?" << S.trailingZeroes(40) << endl;
  cout << "12 ?" << S.trailingZeroes(50) << endl;
  // 1808548329
  cout << "??? ?" << S.trailingZeroes(1808548329) << endl;
}

void test2() {
  Solution S;
}

void test3() {
  Solution S;
}

int main() {
  test1();
  test2();
  test3();
  cout << "Done!" << endl;
  
  return 0;
}