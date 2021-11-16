#include <cstdio>

class Node {
public:
	Node* link;
	int data;
	Node(int val=0, Node* next = NULL) : data(val), link(next) {}
};

class LinkedList{
public:
	Node *head;
	LinkedList() { head = NULL; }
};

int main(){
	int n, k;
	scanf(" %d %d", &n, &k);
	if(k == 1){
		printf("<");
		for(int i = 1; i < n; ++i)
			printf("%d, ", i);
		printf("%d>\n", n);
	}
	else{
		LinkedList list;
		list.head = new Node(1);
		Node *tmp = list.head;
		for(int i = 2; i <= n; ++i){
			tmp->link = new Node(i);
			tmp = tmp->link;
		}
		tmp->link = list.head;
		tmp = list.head;
		printf("<");
 		for(int i = 0; i < n; ++i){
			for(int j = 0; j < k-2; ++j)
				tmp = tmp->link;
			Node *del = tmp->link;
			tmp->link = del->link;
			tmp = tmp->link;
			printf("%d", del->data);
			if(i < n-1)	printf(", ");
			delete del;
		}
		printf(">\n");
	}
}