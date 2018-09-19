#include <bits/stdc++.h>
#define MAXN 500050

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct node
{
    int val;
    node *child[2];
    node()
    {
        val = 0;
        for(int i = 0; i < 2; i++)
            child[i] = NULL;
    }
};

node *version[MAXN];

void initialize()
{
    version[0] = new node();
    version[0]->child[0] = version[0];
    version[0]->child[1] = version[0];
}

node* insert(node *prev, unsigned val, int bitcount)
{
    node *root = new node();
    node *temp = root;
    for(int i = bitcount; i >= 0; i--)
    {
        root->val = prev->val + 1;
        int loc = (val >> i) & 1;
        int opposite = 1 - loc;
        root->child[opposite] = prev->child[opposite];
        root->child[loc] = new node();
        root = root->child[loc];
        prev = prev->child[loc];
    }
    root->val = prev->val + 1;
    return temp;
}

int maxXOR(node *curr, node *prev, int x, int bitcount)
{
    int result = 0;
    for(int i = bitcount; i >= 0; i--)
    {
        int loc = (x >> i) & 1;
        int opposite = 1 - loc;
        int count = (curr->child[opposite]->val) - (prev->child[opposite]->val);
        if(count == 0)
        {
            curr = curr->child[loc];
            prev = prev->child[loc];
        }
        else
        {
            curr = curr->child[opposite];
            prev = prev->child[opposite];
            result |= (1 << i);
        }
    }
    return result ^ x;
}

int kthSmallest(node *curr, node *prev, int k, int bitcount)
{
    int result = 0;
    for(int i = bitcount; i >= 0; i--)
    {
        int count = curr->child[0]->val - prev->child[0]->val;
        if(k > count)
        {
            curr = curr->child[1];
            prev = prev->child[1];
            result |= (1 << i);
            k -= count;
        }
        else
        {
            curr = curr->child[0];
            prev = prev->child[0];
        }
    }
    return result;
}

int smallerThanX(node *curr, node *prev, int x, int bitcount)
{
    int result = 0;
    for(int i = bitcount; i >= 0; i--)
    {
        int loc = (x >> i) & 1;
        int opposite = 1 - loc;
        if(loc == 1)
        {
            int left = curr->child[0]->val - prev->child[0]->val;
            result += left;
            curr = curr->child[1];
            prev = prev->child[1];
        }
        else
        {
            curr = curr->child[0];
            prev = prev->child[0];
        }
    }
    int temp = curr->val - prev->val;
    return result + temp;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	initialize();
	return 0;
}
