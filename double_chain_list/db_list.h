#include <stdio.h>

typedef struct db_list{
	int data;
	struct db_list* next;
	struct db_list* prev;
}db_list;

//ACTIONS

//Initialize a new list.
db_list* init_dbl();

//Append at the end of the "db" list the "x" int.
void add_dbl(db_list* db, int x);

//Insert the "x" element at the "i" position
//in the "db" list.
//If i > sizeof(db) then append at the end.
//If i < sizeof(db) then insert at the begining.
void insert_dbl(db_list* db, db_list* x, size_t i);

//Return 0 and remove it if the element is
//in the list.
//Return 1 otherwise.
int remove_dbl(db_list* db, int x);

void __insert_sort_dbl(db_list* ins, db_list* res);
//Sort the "db" list using an insert sort.
//return the sorted list.
db_list* insert_sort_dbl(db_list* db);

//Reverse in place the "db" list.
void reverse_dbl(db_list* db);

//INFO

//Return the len of "db".
size_t len_dbl(db_list* db);

//Return 1 is "db" is empty.
//Return 0 otherwise.
int is_empty_dbl(db_list* db);

//Print the "db" list.
void print_db(db_list* db);

//Return 1 if the "db" is sorted.
//Reutrn 0 otherwise.
int is_sorted_dbl(db_list* db);
