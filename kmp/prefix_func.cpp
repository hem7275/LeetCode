#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll mridul = LLONG_MAX;
ll mod = 1e9 + 7;

vector<ll> prefix_function(string s)
{
    ll n = (ll)s.length();
    vector<ll> pi(n);
    for (ll i = 1; i < n; i++)
    {
        ll j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;

    }
    return pi;
}


vector<ll> count_prefix(vector<ll> &pi)
{
    ll n = pi.size();
    vector<ll> ans(n + 1);
    for (int i = 0; i < n; i++)
        ans[pi[i]]++;
    for (int i = n - 1; i > 0; i--)
        ans[pi[i - 1]] += ans[i];
    for (int i = 0; i <= n; i++)
        ans[i]++;
    return ans;
}

ll LongestPalindromicPrefix(string str)
{

    
    string temp = str + '?';
    reverse(str.begin(), str.end());
    temp += str;
    ll n = temp.size();
    vector<ll> lps=prefix_function(temp);
    return temp[n - 1];
}

int main()
{
    string s;
    cin >> s;
    vector<ll> a = prefix_function(s);
    for(auto x:a)
        cout << x << " ";
}