#include <bits/stdc++.h>
#define MAXN 500050

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int segtree[MAXN], lazy[MAXN];

void build_tree(vector<int> &a, int loc, int low, int high)
{
    if(low == high)
    {
        segtree[loc] = a[low];
        return;
    }
    int mid = (low + high) >> 1;
    int left = loc << 1, right = left + 1;
    build_tree(a, left, low, mid);
    build_tree(a, right, mid + 1, high);
    segtree[loc] = segtree[left] + segtree[right];
}

void update_tree(int loc, int low, int high, int left, int right, int val)
{
    if(lazy[loc] != 0)
    {
        int l = loc << 1, r = l + 1;
        segtree[loc] += (high - low + 1) * lazy[loc];
        if(low != high)
        {
            lazy[l] += lazy[loc];
            lazy[r] += lazy[loc];
        }
        lazy[loc] = 0;
    }
    if(left > high || right < low)
        return;
    
    if(left <= low && right >= high)
    {
        int l = loc << 1, r = l + 1;
        segtree[loc] += (high - low + 1) * val;
        if(low != high)
        {
            lazy[l] += val;
            lazy[r] += val;
        }
        return;
    }
    int mid = (low + high) >> 1, l = loc << 1, r = l + 1;
    update_tree(l, low, mid, left, right, val);
    update_tree(r, mid + 1, high, left, right, val);
    segtree[loc] = segtree[l] + segtree[r];
}

int query_tree(int loc, int low, int high, int left, int right)
{
    if(lazy[loc] != 0)
    {
        int l = loc << 1, r = l + 1;
        segtree[loc] += (high - low + 1) * lazy[loc];
        if(low != high)
        {
            lazy[l] += lazy[loc];
            lazy[r] += lazy[loc];
        }
        lazy[loc] = 0;
    }
    if(left > high || right < low)
        return 0;
    if(left <= low && right >= high)
        return segtree[loc];
    int mid = (low + high) >> 1, l = loc << 1, r = l + 1;
    return query_tree(l, low, mid, left, right) + query_tree(r, mid + 1, high, left, right);
}

int main() 
{
	return 0;
}
