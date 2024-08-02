#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n;
int s [N], rk [N], ans;

struct Node {
	int num, id;
	
	bool operator < (Node b) {
		if (num == b. num) {
			return id < b. id;
		}
		return num < b. num;
	}
} a [N]; 
inline int lowbit (int x) {
   return x & -x;
}
int query (int x) {
 int sum = 0;
  while (x) {
           sum += s [x];
         x -= lowbit (x);
      }
     return sum;
}
void update (int x, int k) {
   while (x <= n)
                s [x] += k, x += lowbit (x);
}

int main () {
	cin >> n;
	
	for (int i = 1 ; i <= n ; i ++) {
		cin >> a [i]. num;
		a [i]. id = i;		
	}
	
	sort (a + 1, a + n + 1);
	
	for (int i = 1 ; i <= n ; i ++) {
		rk [i] = a [i]. id;
		
//		cout << rk [i];
		
		update (rk [i], 1);
		ans += query (n) - query (rk [i]);
	}
	
	cout << ans;
	
	return 0;
}
