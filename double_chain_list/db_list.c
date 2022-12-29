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

void insert_dbl(db_list* db, db_list* x, size_t i){
	db_list* tmp = db;
	while(tmp->next != NULL && i != 0){
		tmp = tmp->next;
		i--;
	}
	if(tmp->next == NULL){
		tmp->next = x;
		x->prev = tmp;
		x->next = NULL;
	}
	else{
		db_list* t = tmp->next;
		tmp->next = x;
		x->prev = tmp;
		x->next = t;
		t->prev = x;
	}
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
	printf("[");

	db_list* tmp = db->next;
	while(tmp != NULL){
		printf(" %d <->",tmp->data);
		tmp = tmp->next;
	}
	printf(" NULL ]\n");
}

int is_sorted_dbl(db_list* db){
	db_list* tmp = db->next;
	if(tmp == NULL)
		return 1;
	while(tmp->next != NULL && tmp->data < tmp->next->data){
		tmp = tmp->next;
	}
	if(tmp->next == NULL)
		return 1;
	return 0;
}

void __insert_sort_dbl(db_list* ins, db_list* res){
	db_list* tmp = res->next;
	if(tmp == NULL){
		insert_dbl(res,ins,0);
		return;
	}

	int i = 0;
	while(tmp != NULL && tmp->data < ins->data){
		tmp = tmp->next;
		i++;
	}
	insert_dbl(res,ins,i);
}

db_list* insert_sort_dbl(db_list* db){
	db_list* tmp = db->next;
	db_list* res = init_dbl();
	while(tmp != NULL){
		//print_db(res);
		db_list* tmp2 = tmp->next;
		__insert_sort_dbl(tmp, res);
		tmp = tmp2;
	}
	return res;
}

void reverse_dbl(db_list* db){
	db_list* tmp = db->next;
	if(tmp == NULL || tmp->next == NULL){
		return;
	}

	struct db_list* curr = tmp->next;
    tmp->next = NULL;
    while(curr->next != NULL)
    {
        struct db_list* swap = curr->next;
        curr->next = tmp;
		curr->prev = swap;
        tmp = curr;
        curr = swap;
    }
    curr->next = tmp;
	curr->prev = db;
    db->next = curr;

}

int main(){
	db_list* test = init_dbl();
	add_dbl(test, 4);
	add_dbl(test, 1);
	add_dbl(test, 9);
	print_db(test);

	db_list* x = init_dbl();
	x->data = 8;
	insert_dbl(test, x, 1);
	print_db(test);

	printf("len : %zu\n",len_dbl(test));
	printf("is_sorted : %d\n",is_sorted_dbl(test));

	db_list* test_sorted = insert_sort_dbl(test);
	printf("is_sorted : %d\n",is_sorted_dbl(test_sorted));
	print_db(test_sorted);

	reverse_dbl(test_sorted);
	print_db(test_sorted);

	return 1;
}
