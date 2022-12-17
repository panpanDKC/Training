#include <stdio.h>
#include <stdlib.h>
#include "db_list.h"

db_list* init_dbl(){
	db_list* res = malloc(sizeof(db_list));
	res->data = 0;
	res->next = NULL;
	res->prev = NULL;
	return res;
}

void add_dbl(db_list* db, int x){
	db_list* tmp = db;
	db_list* add = init_dbl();
	add->data = x;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = add;
	add->prev = tmp;
}

void insert_dbl(db_list* db, int x, size_t i){
	db_list* ins = init_dbl();
	ins->data = x;

	db_list* tmp = db->next;
	while(tmp != NULL && i != 0){
		tmp = tmp->next;
		i--;
	}

	//TODO
}

int remove_dbl(db_list* db, int x){
	db_list* tmp = db->next;

	while(tmp != NULL){
		if(tmp->data == x){
			tmp->prev->next = tmp->next;
			if(tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			free(tmp);
			return 0;
		}
		tmp = tmp->next;
	}
	return 1;
}

size_t len_dbl(db_list* db){
	db_list* tmp = db;
	size_t len = 0;
	while(tmp->next != NULL){
		tmp = tmp->next;
		len++;
	}
	return len;
}

int is_empty_dbl(db_list* db){
	return db->next == NULL;
}

void print_db(db_list* db){
	printf("[ ");

	db_list* tmp = db->next;
	while(tmp != NULL){
		printf(" %d <->",tmp->data);
		tmp = tmp->next;
	}
	printf(" NULL ]\n");
}

int main(){
	db_list* test = init_dbl();
	add_dbl(test, 45);
	add_dbl(test, 5);
	add_dbl(test, 19);
	print_db(test);

	remove_dbl(test,5);
	print_db(test);

	printf("len : %zu\n",len_dbl(test));

	return 0;
}
