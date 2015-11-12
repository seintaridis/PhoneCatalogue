


struct pointer
{
	struct node* record;
	struct pointer* next;
	struct pointer* previous;

};

//typedef int akaireos;

struct invert_root
{
 struct invert_node* First;
 struct invert_node* Last;
 struct invert_node* First1;
 struct invert_node* First2;

};


struct invert_node
{
	char* town;
	int num;
	float sum;
	struct invert_node* next;
	struct invert_node* previous; 
	struct invert_node* next1;
	struct invert_node* previous1; 
	struct invert_node* next2;
	struct invert_node* previous2;       
	struct pointer* ptr;
};


typedef struct invert_node invert_node;
typedef struct invert_root* Invert_List;
typedef struct pointer pointer;

Invert_List create_invert_list(void); 
void insert_to_end_invert(Invert_List list,invert_node* nd);
invert_node* search_list_invert(Invert_List list,char* town);
invert_node* create_invert_node(char* town);
void clean_list_invert(Invert_List list);
void insert_rec_to_invert(struct node* record,invert_node* town,Invert_List list);
void print_all_from_town(Invert_List lista,char* town,int k) ;
void print_all_towns(Invert_List list,int k);
void sort_invert(invert_node* town,Invert_List List);
void sort_invert1(invert_node* town,Invert_List list,int x);
void print_all_towns1(Invert_List list);
//invert_node* lastNode(invert_node *root);

