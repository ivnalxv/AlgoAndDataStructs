#include <bits/stdc++.h>
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0)
#define all(x) (x).begin(), (x).mid()
#define F first
#define S second
#define LOVE true

using namespace std;

typedef long long ll;

const ll mod =  999999937LL;

signed main() {
    fast;

    while (LOVE) {
        ll n;
        cin >> n;

        if (n == 0LL) {
            break;
        }

        vector<ll> up = {1LL, 0LL};
        vector<ll> dn = {0LL, 1LL};

        vector<ll> aUp = {3LL, 2LL};
        vector<ll> aDn = {2LL, 1LL};

        while (n) {
            vector<ll> tempUp(2), tempDn(2);

            if (n&1) {
                tempUp = {(aUp[0]*up[0] + aUp[1]*dn[0]) % mod, (aUp[0]*up[1] + aUp[1]*dn[1]) % mod};
                tempDn = {(aDn[0]*up[0] + aDn[1]*dn[0]) % mod, (aDn[0]*up[1] + aDn[1]*dn[1]) % mod};
                up = tempUp;
                dn = tempDn;
                n--;
            } else {
                tempUp[0] = (aUp[0]*aUp[0] + aUp[1]*aDn[0]) % mod;
                tempUp[1] = (aUp[0]*aUp[1] + aUp[1]*aDn[1]) % mod;
                tempDn[0] = (aDn[0]*aUp[0] + aDn[1]*aDn[0]) % mod;
                tempDn[1] = (aDn[0]*aUp[1] + aDn[1]*aDn[1]) % mod;

                aUp = tempUp;
                aDn = tempDn;
                n /= 2LL;
            }
        }

        cout << (up[0] + up[1]) % mod << endl;
    }

    return 0;
}
