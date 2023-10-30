#include<bits/stdc++.h>
using namespace std;


struct node{
	int val;
	node* next;
};

node* head;


node* createNode(int x){
	node* temp = new node;
	temp->val = x;
	temp->next = NULL;
	return temp;
}
void insert_back(int x){
	node* temp = createNode(x);
	if(!head){
		head = temp;
	}
	else{
		node* dummy = head;
		while(dummy && dummy->next){
			dummy = dummy->next;
		}
		dummy->next = temp;
	}
}

void deletenode(int x){
	node* prevptr = NULL;
	node* currptr = head;
	if(head == NULL)return;
	while(currptr){
		if(currptr->val == x){
			if(prevptr != NULL){
				prevptr->next = currptr->next;
				currptr->next = NULL;
				delete(currptr);
				currptr = prevptr->next;
			}
		}
		prevptr = currptr;
		currptr = currptr->next;
	}
}

void printll(){
	node* temp = head;
	while(temp){
		cout<<temp->val<<" ";
		temp = temp->next;
	}
	cout<<endl;
}



int main(){
	head = NULL;
	insert_back(3);
	insert_back(5);
	insert_back(7);
	insert_back(7);
	insert_back(9);
	printll();
	deletenode(7);
	printll();
	return 0;
}