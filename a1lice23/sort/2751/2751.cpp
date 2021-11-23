#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
	int num[1000000];
int main(int argc, char** argv) {
	
	int size;

	
	scanf("%d", &size);
	
	for(int i =0; i<size; i++)
	{
		scanf("%d", &num[i]);
	}
	
	sort(num, num + size);

	for(int g = 0; g < size; g++)
	{
		printf("%d\n", num[g]);
	}
	
	
	return 0;
}