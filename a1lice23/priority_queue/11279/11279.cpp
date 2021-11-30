#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int> q;

int main() {
	
	int m;
	int n[100000]={0};
	scanf("%d", &m);
	
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &n[i]);
	}
	
	for(int j = 0; j < m; j++)
	{
		if(n[j]==0)
		{
			if(q.size()==0)
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", q.top());
				q.pop();
			}
			
		}
		else
		{
			q.push(n[j]);
		}
	}
	
	return 0;
}