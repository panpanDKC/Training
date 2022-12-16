#include <string.h>
#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include "bst.h"

bst* init_bst(int d){
	bst* res = malloc(sizeof(bst));
	res->data = d;
	res->l = NULL;
	res->r = NULL;
	return res;
}

void destroy_bst(bst* b){
	if(b->l != NULL){
		destroy_bst(b->l);
		b->l = NULL;
	}
	if(b->r != NULL){
		destroy_bst(b->r);
		b->r = NULL;
	}
	free(b);	
}

void print_bst(bst* b){
	printf("<%d",b->data);
	if(b->l != NULL){
		print_bst(b->l);
	}
	if(b->r != NULL){
		print_bst(b->r);
	}
	printf(">");
}

void add_bst(bst* b, int v){
	printf("curr : %d | v : %d\n",b->data,v);
	if(v < b->data){
		printf("less\n");
		if(b->l == NULL){
			b->l = init_bst(v);
		}
		else{
			add_bst(b->l,v);
		}
	}
	else{
		printf("more\n");
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



void rm_bst(bst* b, int x){
	if(x == b->data){
		bst* tmp;
		if(b->l != NULL){
			tmp = get_max_bst(b->l);
			printf("tmp data : %d\n",tmp->data);
			b->l = tmp->l;
			b->r = tmp->r;
			b->data = tmp->data;
		}
		else if(b->r != NULL){
			tmp = b->r;
			b->r = tmp->r;
			b->data = tmp->data;
		}
		else{
			//pointeur du dessus = NULL
		}
	}
	else{
		if(x > b->data){
			if(b->r != NULL)
				rm_bst(b->r, x);
			else
				errx(1,"There is no %d is this tree !\n",x);
		}
		else{
			rm_bst(b->l, x);
			if(b->l != NULL)
				rm_bst(b->l, x);
			else
				errx(1,"There is no %d is this tree !\n",x);
		}

	}
}

int main(){
	bst* test = init_bst(5);

	// for(int i = 0; i < 10; i++){
	//	add_bst(test,i);
	//}
	add_bst(test, 3);
	add_bst(test, 2);
	add_bst(test, 4);
	add_bst(test, 7);
	add_bst(test, 6);
	print_bst(test);
	printf("\n");

	rm_bst(test,6);
	print_bst(test);

	destroy_bst(test);
	return 0;
}
