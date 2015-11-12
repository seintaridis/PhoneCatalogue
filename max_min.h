struct head{
	struct maxnode* First;       //pointer to first node of list
	struct maxnode* Last;        //pointer to last node of list
        int number;
	int Max;
	int Min;
        
		
               //number of nodes

};


struct maxnode{
	long long int phone;
        struct maxnode* next;
	struct maxnode* previous;
	};






typedef struct head* maxlist; 
typedef struct maxnode maxnode;



maxlist create_maxlist(void);
maxnode* create_maxnode(long long number); 
int insert_to_maxend(maxlist list,maxnode* nd);
void print_all_from_maxfirst(maxlist list);
void sort_maxlist(maxlist list,maxnode*node);
void delete_sort_maxlist(maxlist list,long long int x);
void clean_maxlist(maxlist list);
void print_max(maxlist list);
void print_min(maxlist list);


//void print_all_from_maxfirst(maxlist list);
