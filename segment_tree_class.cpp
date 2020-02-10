#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
    private:
        vector<int> segtree;
        int n;
        void build_helper(int i, int low, int high, vector<int> &arr) {
            if (low == high) {
                segtree[i] = arr[low];
                return;
            }
            int mid = (low + high) / 2;
            build_helper(2 * i, low , mid, arr);
            build_helper(2 * i + 1, mid + 1, high, arr);
            segtree[i] = segtree[2 * i] + segtree[2 * i + 1];
        }
        int query_helper(int i, int l, int r, int ql, int qr) {
            if(ql > r || qr < l)
                return 0;
            if(l >= ql && r <= qr)
                return segtree[i];
            int mid = (l + r) / 2;
            return query_helper(2 * i, l, mid, ql, qr) +
                   query_helper(2 * i + 1, mid + 1, r, ql, qr);
        }
        void update_helper(int i, int l, int r, int update_idx, int update_value) {
            if (l == r) 
                return;
            int mid = (l + r) / 2;
            segtree[i] += update_value;
            if (update_idx <= mid)
                update_helper(2 * i, l, mid, update_idx, update_value);
            else
                update_helper(2 * i + 1, mid + 1, r, update_idx, update_value);
        }
    public:
        SegmentTree(vector<int> &arr) {
            n = arr.size();
            segtree.resize(4 * n);
            build_helper(1, 0, n - 1, arr);
            for(auto i : segtree) {
                cout << i << " ";
            }
            cout << endl;
        }

        int query(int l, int r) {
            return query_helper(1, 0, n - 1, l, r);
        }

        void update(int idx, int value) {
            update_helper(1, 0, n - 1, idx, value);
        }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    SegmentTree segmentTree = SegmentTree(arr);
    int n;
    cin >> n;
    while(n--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1)
            segmentTree.update(x, y);
        else
            cout << segmentTree.query(x, y) << endl;
    }
    return 0;
}
