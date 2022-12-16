

typedef struct bst{
	int data;
	struct bst* l;
	struct bst* r;
} bst;


bst* init_bst(int d);
void add_bst(bst* b, int v);
void print_bst(bst* b);
bst* get_bst(bst* b, int x);
bst* get_max_bst(bst* b);
void rm_bst(bst* b, int x);
void destroy_bst(bst* b);
