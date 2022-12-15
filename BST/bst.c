#include <string.h>
#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include "queue.h"

bst* init_bst(int d){
	bst* res = malloc(sizeof(bst));
	res->data = d;
	res->l = NULL;
	res->r = NULL;
	return res;
}

void print_bst(bst* b){
	printf("(%d",b->data);
	if(b->l != NULL){
		print_bst(b->l);
	}
	printf(" ");
	if(b->r != NULL){
		print_bst(b->r);
	}
	printf(")");
}

void add_bst(bst* b, int v){
	if(v < b->data){
		if(b->l == NULL){
			b->l = init_bst(v);
		}
		else{
			add_bst(b->l,v);
		}
	}
	else{
		if(b->r == NULL){
			b->r = init_bst(v);
		}
		else{
			add_bst(b->r,v);
		}
	}
}

bst* get_bst(bst* b, int x){
	if(x == b->data)
		return b;

	if(x > b->data){
		if(b->r != NULL)
			return get_bst(b->r,x);
	}
	else{
		if(b->l != NULL)
			return get_bst(b->l,x);
	}
	err(1,"There is no %d in the tree !\n",x);
}

bst* get_max_bst(bst* b){
	if(b->r != NULL){
		get_max_bst(b->r);
	}
	return b;
}

bst* rm_bst(bst* b, int x){

}

int main(){
	bst* test = init_bst(4);

	for(int i = 0; i < 10; i++){
		add_bst(test,i);
	}
	print_bst(test);
	printf("\n");
	bst* tmp = get_bst(test,10);
	printf("get : %d\n",tmp->data);

	return 0;
}
