#include <stdio.h>

typedef struct db_list{
	int data;
	struct db_list* next;
	struct db_list* prev;
}db_list;


db_list* init_dbl();
void add_dbl(db_list* db, int x);
int remove_dbl(db_list* db, int x);
size_t len_dbl(db_list* db);
int is_empty_dbl(db_list* db);
void print_db(db_list* db);
void insert_dbl(db_list* db, int x, size_t i);
