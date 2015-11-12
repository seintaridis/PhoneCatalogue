
struct root{
	struct node* First;       //pointer to first node of list
	struct node* Last;        //pointer to last node of list
        int number;
        
		
               //number of nodes

};




struct node{
	long long int phone;
        struct node* next;
	struct node* previous;
        char *town;
	char *LastName;
	char *FirstName;
	float invoice;
	struct pointer* ptr;
	struct invert_node* ptrtown;
};

typedef struct node node;
typedef struct root* List; 

List create_list(void);     //create root of a list
node* create_node(long long number,char* name,char* surname,char* town,float debt);
int insert_to_end(List list,node* nd);        //inser node nd to the end of the List list
void print_all_from_first(List list);
void clean_list(List list);
int size_of_list(List list);
node* search_list(List list,long long phone);
