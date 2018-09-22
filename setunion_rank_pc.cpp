#include <bits/stdc++.h>
 
using namespace std;
 
int disjointSet[4000010], ranka[4000010];
 
int findParent(int node)
{
	int temp = node, temp1 = ranka[node];
	while(disjointSet[node] != -1)
	{
		node = disjointSet[node];
		ranka[node] -= temp1;
	}
	if(temp != node)
	{
		disjointSet[temp] = node;
		ranka[node] += temp1;
	}
	return node;
}
 
void merge(int u, int v)
{
	int uParent = findParent(u);
	int vParent = findParent(v);
	if(uParent != vParent)
	{
		if(ranka[uParent] <= ranka[vParent])
		{
			disjointSet[uParent] = vParent;
			ranka[vParent] += ranka[uParent];
		}
		else
		{
			disjointSet[vParent] = uParent;
			ranka[uParent] += ranka[vParent];
		}
	}
}

int main()
{
  return 0;
}
