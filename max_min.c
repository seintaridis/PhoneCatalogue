#include<stdlib.h>
#include <stdio.h>
#include "max_min.h"

maxlist create_maxlist(void)
{
	maxlist riza=malloc(sizeof(struct head));
       
	riza->First=NULL;
	riza->Last=NULL;
	riza->number=0;
	riza->Max=0;
	riza->Min=0;
	printf("created list\n");
	return riza;
}


maxnode* create_maxnode(long long number)
{
        maxnode* komvos;
        komvos=malloc(sizeof(maxnode));
        komvos->phone=number;
	komvos->next=NULL;
	komvos->previous=NULL;
	return komvos;
}




int insert_to_maxend(maxlist list,maxnode* nd)
{
	if(list->Last==NULL && list->First==NULL)
	{
	
	list->Last=nd;
	list->First=nd;
	
	
	}
	else
	{
		list->Last->next=nd;
		nd->previous=list->Last;
 		list->Last=nd;
	}
        
        
        list->number++;
}

int insert_to_maxstart(maxlist list,maxnode* nd)
{
	if(list->Last==NULL && list->First==NULL)
	{
	
	list->Last=nd;
	list->First=nd;
	
	
	}
	else
	{
		nd->next=list->First;
		list->First->previous=nd;
		list->First=nd;
	}
        
        
        list->number++;
}







void sort_maxlist(maxlist list,maxnode*node)
{
	maxnode* komvos=NULL;
  int iparxeiarithmos=0;
	if (list->First==NULL && list->Last==NULL)
		{insert_to_maxend(list,node);
		return;}
	if (iparxeiarithmos==1)
		return;
	else
	{
		if (node->phone>list->Last->phone)
			insert_to_maxend(list,node);
		else if(node->phone<list->First->phone)
			insert_to_maxstart(list,node);
		else
		{
				komvos=list->Last->previous;
				while(komvos!=NULL)
				{
				if (komvos->phone<node->phone)
				{
					node->previous=komvos;
					node->next=komvos->next;
					komvos->next->previous=node;
					komvos->next=node;
					break;

				}
				komvos=komvos->previous;
				}
						
	

		}
	}



}


void delete_sort_maxlist(maxlist list,long long int x)
{
	maxnode* komvos=NULL;
  int iparxeiarithmos=1;
	if (iparxeiarithmos==0)
		return;
	if (list->First==NULL && list->Last==NULL)
		{
		return;}
	if(list->First==list->Last)
	{
	free(list->First);
	list->Last=NULL;
	list->First=NULL;
	return;

	}
	
	else
	{
		if (x==list->Last->phone)
		{
			
			list->Last=list->Last->previous;
			free(list->Last->next);
			list->Last->next=NULL;
			

		}
		else if(x==list->First->phone)
		{
			list->First=list->First->next;
			free(list->First->previous);
			list->First->previous=NULL;
			
		}
		else
		{
				komvos=list->Last->previous;
				while(komvos!=NULL)
				{
				if (komvos->phone==x)
				{
					komvos->previous->next=komvos->next;
					komvos->next->previous=komvos->previous;
					free(komvos);
					break;

				}
				komvos=komvos->previous;
				}
						
	

		}
	}



}



void clean_maxlist(maxlist list)
{

maxnode* ptr;
maxnode* cleaner; 

  if (list->First!=NULL)
 {
 
   
    ptr=list->First;
   
    while (ptr!=NULL)	
    {
     
     cleaner=ptr;
     ptr=ptr->next;
     
     
    
     
     
     
     //cleaner->town=NULL;
     //cleaner->FirstName=NULL;
     //cleaner->LastName=NULL;
     free(cleaner);
	
    }		
  }  
    
  free(list);



}

















void print_all_from_maxfirst(maxlist list)
{
  maxnode* ptr;
  
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

void print_min(maxlist list)
{
	if (list==NULL || list->First==NULL)
	{
	printf("there isnt min\n");
	return;
	}
  printf("min is %lld\n",list->First->phone);

}
void print_max(maxlist list)
{
if (list==NULL|| list->First==NULL)
{printf("there isnt max\n");
	return;}
printf("max is %lld\n",list->Last->phone);
}





