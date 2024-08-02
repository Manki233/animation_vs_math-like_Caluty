#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

struct mar {
	int n;
	int m [105] [105];
	
	mar mul (mar b) {
		mar res;
		
		res. n = n;
		memset (res. m, 0, sizeof res. m);
		
		for (int i = 1 ; i <= n ; i ++) {
			for (int j = 1 ; j <= n ; j ++) {
				for (int k = 1 ; k <= n ; k ++) {
					res. m [i] [j] = (res. m [i] [j] + m [i] [k] * b. m [k] [j]) % mod;
				}
			}
		}
		
		return res;
	}
};

mar fpow (mar n, int k) {
	mar res;
	res. n = n. n;
	
	memset (res. m, 0, sizeof res. m);
	
	for (int i = 1 ; i <= n. n ; i ++) {
		res. m [i] [i] = 1;
	}
	
	while (k) {
		if (k & 1) {
			res = res. mul (n);
		}
		
		n = n. mul (n);
		
		k /= 2;
	}
	
	return res;
}

int n, k;

signed main () {
	cin >> n >> k;
	
	mar m;
	m. n = n;
	
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ; j <= n ; j ++) {
			cin >> m. m [i] [j];
		}
	}
	
	mar ans = fpow (m, k);
	
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ; j <= n ; j ++) {
			cout << ans. m [i] [j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
