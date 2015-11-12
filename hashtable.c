

#include "list.h"
#include "invert.h"
#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>



hash_table create_hash_table(int size)
{
	int i;
	int k=0;
	List* table=malloc(size*sizeof(List));
      
	for (i=0;i<=size-1;i++)
	{
	       
 	 table[i]=create_list();
        
	
       //  *table=create_list();
	}
    return table;
 
}

void clean_hash_table(hash_table table,int size)
{
  int i,k;
  k=0;
 // free(table);
  for (i=0;i<=size-1;i++)
	{
        //   printf("mpika stin hash clean \n");
	 clean_list(table[i]);  
 	 //free(table[i]);
         //k=sizeof(List)+k;
	
       //  *table=create_list();
	}
free(table);
}

int hash_function(long long int key,int size)
{
  int hash_result=key%size;
  return hash_result;
}

void print_all_hash_table(hash_table table,int size)
{
int i=0;
for (i=0;i<=size-1;i++)
{
        printf("to size tis ouras einai %d \n",table[i]->number);
	print_all_from_first(table[i]);

}
}

node* search_hash_table(hash_table table,long long phone,int size)
{
  int h=hash_function(phone,size);
  return search_list(table[h],phone);

}

void delete_record(hash_table table,int size,long long phone,Invert_List lista)
{
	node* komvos;
	int h=hash_function(phone,size);
	komvos=search_list(table[h],phone);
	if (komvos==NULL)
	{
	printf("we dont have this number \n");
	return;	

	}
	else
	{       

                komvos->ptrtown->num--;
		komvos->ptrtown->sum=komvos->ptrtown->sum-komvos->invoice;
		if(komvos->ptrtown->num==0)
		{
			if(komvos->ptrtown->next==NULL)
			{
				if(komvos->ptrtown->previous==NULL)
					lista->First=NULL;
				else 
					komvos->ptrtown->previous->next=NULL;
			}
			else if(komvos->ptrtown->previous==NULL)
			{
				komvos->ptrtown->next->previous=NULL;
				lista->First=komvos->ptrtown->next;			
			}
			else
			{
				komvos->ptrtown->next->previous=komvos->ptrtown->previous;
				komvos->ptrtown->previous->next=komvos->ptrtown->next;
			}	
			




			
			if(komvos->ptrtown->next1==NULL)
			{
				if(komvos->ptrtown->previous1==NULL)
					lista->First1=NULL;
				else 
					komvos->ptrtown->previous1->next1=NULL;
			}
			else if(komvos->ptrtown->previous1==NULL)
			{
				komvos->ptrtown->next1->previous1=NULL;
				lista->First1=komvos->ptrtown->next1;			
			}
			else
			{	
				komvos->ptrtown->next1->previous1=komvos->ptrtown->previous1;
				komvos->ptrtown->previous1->next1=komvos->ptrtown->next1;
			}						
			free(komvos->ptrtown->town);
			free(komvos->ptrtown);		
		}
		else	
		{	
			sort_invert(komvos->ptrtown,lista);
			if(komvos->ptrtown->ptr->record==komvos)
				sort_invert1(komvos->ptrtown,lista,0);
		}
		
		if (komvos->ptr->next==NULL)
		{
			if(komvos->ptr->previous==NULL)
 				komvos->ptrtown->ptr=NULL;
			else
				komvos->ptr->previous->next=NULL;		
		}
		else if(komvos->ptr->previous==NULL)
		{
			komvos->ptr->next->previous=NULL;
                        komvos->ptrtown->ptr=komvos->ptr->next;				
			
		}
		else
		{
			komvos->ptr->next->previous=komvos->ptr->previous;
			komvos->ptr->previous->next=komvos->ptr->next;
		}
		free(komvos->ptr);
		if (komvos->next==NULL)
		{
			if(komvos->previous==NULL)
				table[h]->First=NULL;			//=======
			else	
			 	komvos->previous->next=NULL;		
		}
		else if(komvos->previous==NULL)
		{
			komvos->next->previous=NULL;
                        table[h]->First=komvos->next;				
			
		}
		else
		{
			komvos->next->previous=komvos->previous;
			komvos->previous->next=komvos->next;
		}
		
			
	


     		free(komvos->town);
     		free(komvos->LastName);
     		free(komvos->FirstName);
		free(komvos);
		printf("Phone number %lld deleted successfully\n",phone);
	}
	
}









