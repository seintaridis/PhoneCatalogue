#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include <string.h>
#include "invert.h"
#include "hashtable.h" 
#define maximum 30
node* create_node(long long x,char* name,char* surname,char* town,float debt)
{       
        char* onoma;
	char* epitheto;
	char*poli;
	onoma=malloc(maximum*sizeof(char));
	epitheto=malloc(maximum*sizeof(char));
	poli=malloc(maximum*sizeof(char));        
	
	//printf("mpika stin create \n");
        node* komvos;
        komvos=malloc(sizeof(node));
       // printf("3\n");
	//printf("to onoma einai %s \n",name);
        //printf("to size t onomatos einai %ld\n",sizeof(komvos->FirstName));
        //komvos->FirstName[25]='\0';
	komvos->invoice=debt;
        komvos->phone=x;
	komvos->next=NULL;
	komvos->previous=NULL;
        strcpy(onoma,name);
	strcpy(epitheto,surname);
	strcpy(poli,town);
        //strcpy(komvos->FirstName,name);
        komvos->FirstName=onoma;
	komvos->LastName=epitheto;
	komvos->town=poli;
	//strcpy(komvos->LastName,surname);
	//strcpy(komvos->town,town);	
        //printf("to kainourio onoma einai %s \n",test);


	//printf("created node  phone=%lld xreos=%f onoma=%s epitheto=%s town=%s\n",komvos->phone,komvos->invoice,komvos->FirstName,komvos->LastName,komvos->town);
	return komvos;
}


List create_list(void)
{
	List riza=malloc(sizeof(struct root));
       
	riza->First=NULL;
	riza->Last=NULL;
	riza->number=0;
	//printf("created list\n");
	return riza;
}



int insert_to_end(List list,node* nd)
{
        node* komvos;
        if(list->First==NULL)
	{
	
	
	list->First=nd;
	
	
	}
	else
	{
		komvos=list->First;
	while(komvos->next!=NULL)
	{

	komvos=komvos->next;
	}
	nd->previous=komvos;
	komvos->next=nd;
	}
        
        
        list->number++; 
		
	

}


void print_all_from_first(List list)
{
  node* ptr;
  
  if (list->First==NULL)
  	printf("list is empty \n");
  else
   {
    ptr=list->First;
    while (ptr!=NULL)	
    {
     printf("noumero=%lld\n",ptr->phone);
     ptr=ptr->next;
    }		

   } 

}



node* search_list(List list,long long phone)
{
  node* ptr=NULL;
  
  if (list->First==NULL)
  	printf("list is empty \n");
  else
   {
    ptr=list->First;
    while (ptr!=NULL)	
    {
     if(ptr->phone==phone)
     {
	//printf("there is\n");
        return ptr;
	}
    
     ptr=ptr->next;
    }		

   }
return ptr;
}



void clean_list(List list)
{
node* ptr;
node* cleaner; 
pointer* pointer1;
pointer* pointer2; 
  if (list->First!=NULL)
 {
 
   
    ptr=list->First;
    int ts=0;
    while (ptr!=NULL)	
    {
     
     cleaner=ptr;
     ptr=ptr->next;
     
     ts++;
    
     
     
     free(cleaner->ptr);
     free(cleaner->town);
     free(cleaner->LastName);
     free(cleaner->FirstName);
     //cleaner->town=NULL;
     //cleaner->FirstName=NULL;
     //cleaner->LastName=NULL;
     free(cleaner);
	
    }		
  }  
    
  free(list);

}
 

int size_of_list(List list)
{
 	int size1=list->number;
 	int size2=0;
 	node* ptr; 
 	if (list->First==NULL)
  	{
   		if (size2==size1)
  	        {   
			printf("to size einai %d \n",size1);
			return size1;
         	}
                printf("ERRORRRRRRR\n");	
        }
  	else
   	{
    		ptr=list->First;
    		while (ptr!=NULL)	
    		{
     			size2++;
     			ptr=ptr->next;
   
    		}		
  
   	}

	if (size1==size2)
 	{
  		printf("to size einai %d \n",size1); 
  		return size1;
 	}
 	printf("ERRORRRRRRR\n");
}






