#include <stdio.h>

typedef struct db_list{
	int data;
	struct db_list* next;
	struct db_list* prev;
}db_list;

//ACTIONS
db_list* init_dbl();
void add_dbl(db_list* db, int x);
void insert_dbl(db_list* db, db_list* x, size_t i);
int remove_dbl(db_list* db, int x);
void __insert_sort_dbl(db_list* ins, db_list* res);
db_list* insert_sort_dbl(db_list* db);

//INFO
size_t len_dbl(db_list* db);
int is_empty_dbl(db_list* db);
void print_db(db_list* db);
int is_sorted_dbl(db_list* db);
