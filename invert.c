#include "list.h"
#include "invert.h"
#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>


#include <string.h>






invert_node* create_invert_node(char* town)
{
	invert_node* komvos;
	char* citi=(char*)malloc(30*sizeof(char));
	strcpy(citi,town);
	komvos=malloc(sizeof(invert_node));
	komvos->town=citi;
	komvos->sum=0;
	komvos->num=0;
        komvos->ptr=NULL;
	komvos->next=NULL;
	komvos->previous=NULL;
	komvos->next1=NULL;
	komvos->previous1=NULL;
	return komvos;
	 




}

Invert_List create_invert_list(void)
{
	Invert_List riza=malloc(sizeof(struct invert_root));
       
	riza->First=NULL;
	riza->First1=NULL;
	riza->Last=NULL;
	printf("created list\n");
	return riza;
}




void insert_to_end_invert(Invert_List list,invert_node* nd)
{
        
  invert_node* ptr=NULL;
  invert_node* ptr1=NULL;
  if (list->First==NULL)
 	list->First=nd;
   else
   {
    ptr=list->First;
    while (ptr->next!=NULL)	
    {
     
    
     ptr=ptr->next;
    }
    nd->previous=ptr;
    ptr->next=nd;
			

   }
		


if (list->First1==NULL)
 	list->First1=nd;
   else
   {
    ptr1=list->First1;
    while (ptr1->next1!=NULL)	
    {
     
    
     ptr1=ptr1->next1;
    }
    nd->previous1=ptr1;
    ptr1->next1=nd;
			

   }
        
        
        
		
	

}

invert_node* search_list_invert(Invert_List list,char* town)
{
	invert_node* ptr=NULL;
  
  if (list->First==NULL)
  	printf("list is empty \n");
  else
   {
    ptr=list->First;
    while (ptr!=NULL)	
    {//printf("kolisa");
	//printf("kolisa");
     if(strcmp(ptr->town,town)==0)
     {
	//printf("there is\n");
        return ptr;
	}
    
     ptr=ptr->next;
    }		

   }
return ptr;


}

void clean_list_invert(Invert_List list)
{
invert_node* ptr;
invert_node* cleaner;  
  if (list->First!=NULL)
 {
 
   
    ptr=list->First;
   
    while (ptr!=NULL)	
    {
     
     cleaner=ptr;
     ptr=ptr->next;
     
     
     free(cleaner->town);
     
     //cleaner->town=NULL;
     //cleaner->FirstName=NULL;
     //cleaner->LastName=NULL;
     free(cleaner);
	
    }		
  }  
    
  free(list);

}




void sort_invert1(invert_node* town,Invert_List list,int x)
{
		invert_node* komvos;
		komvos=list->First1;
	int po=0;

        //printf("town=%s komvos=%s",town->town,komvos->town);
	////
if (x==1){
	if((town->previous1==NULL)||(town->next1==NULL&&town->ptr->record->invoice<town->previous1->ptr->record->invoice))//||town==komvos)
	{//do nothing
          //  printf("town == %s",town->town);
	}
	else
	{	
		
		town->previous1->next1=town->next1;
		if(town->next1!=NULL)
		{	town->next1->previous1=town->previous1;
		//	printf("edw eimaste\n");
			}
		while(town->ptr->record->invoice<komvos->ptr->record->invoice && town!=komvos)
	{

		komvos=komvos->next1;

	}
		if(komvos->previous1==NULL)
		{	
			town->previous1=NULL;
			town->next1=list->First1;
			list->First1=town;
			town->next1->previous1=town;
		}
		else
		{
		town->previous1=komvos->previous1;
		komvos->previous1=town;
		town->previous1->next1=town;
		town->next1=komvos;
			

		}
	}	

	}
else
{
	
	if(town->previous1==NULL)
		{
		
		list->First1=town->next1;
		
		list->First1->previous1=NULL;
		komvos=list->First1;}
	else
	{town->previous1->next1=town->next1;
	 if(town->next1!=NULL)
	   town->next1->previous1=town->previous1;
		
         }
	//printf("to epomeno tis athinas einai %f\n",town->ptr->next->record->invoice);
	komvos=list->First1;	
	invert_node* node=list->First1->next1;
while(komvos!=NULL && town->ptr->next->record->invoice<komvos->ptr->record->invoice )
	{
		node=komvos;
		komvos=komvos->next1;
			
		
	}
	if(komvos==NULL)
		{
			node->next1=town;
			town->previous1=node;
			town->next1=NULL;

		}
	else if(komvos->previous1==NULL)
		{	
			town->previous1=NULL;
			town->next1=list->First1;
			list->First1=town;
			town->next1->previous1=town;
		}
		
		else
		{
		town->previous1=komvos->previous1;
		komvos->previous1=town;
		town->previous1->next1=town;
		town->next1=komvos;
			

		}






}

}








void sort_invert(invert_node* town,Invert_List list)
{
	//printf("kalimera %s\n",town->town);
		invert_node* komvos;
		komvos=list->First;
	

        //printf("town=%s komvos=%s",town->town,komvos->town);
	////
	if(town->previous==NULL||(town->next==NULL&&town->num<town->previous->num))//||town==komvos)
	{//do nothing
          //  printf("town == %s",town->town);
	}
	else
	{	
		
		town->previous->next=town->next;
		if(town->next!=NULL)
		{	town->next->previous=town->previous;
		//	printf("edw eimaste\n");
			}
		while(town->num<komvos->num && town!=komvos)
	{

		komvos=komvos->next;

	}
		if(komvos->previous==NULL)
		{	
			town->previous=NULL;
			town->next=list->First;
			list->First=town;
			town->next->previous=town;
		}
		else
		{
		town->previous=komvos->previous;
		komvos->previous=town;
		town->previous->next=town;
		town->next=komvos;
			

		}
	}	


}








void insert_rec_to_invert (struct node* record,invert_node* town,Invert_List list)
{
	pointer* ptr;
        pointer* bag;
	invert_node* komvos;
  	ptr=malloc(sizeof(pointer));
	town->num++;
	town->sum=town->sum+record->invoice;
	
		

	//sort_invert(town,list);
	//sort_invert1(town,list,1);




	
        
        if(town->ptr==NULL)
   	{
		ptr->record=record;
		ptr->record->ptr=ptr;
		ptr->record->ptrtown=town;
		ptr->next=NULL;  
		ptr->previous=NULL;  		
		town->ptr=ptr;
		sort_invert(town,list);
		sort_invert1(town,list,1);
        }
	else
	{	
		
		ptr->record=record;
		ptr->record->ptr=ptr;
		ptr->record->ptrtown=town;
		if(ptr->record->invoice>=town->ptr->record->invoice)
		{ 	ptr->next=town->ptr;///
			ptr->previous=NULL;
                        ptr->next->previous=ptr;
			town->ptr=ptr;
			sort_invert(town,list);
			sort_invert1(town,list,1);
			return;
		}
		else
		{                
			bag=town->ptr;
			while (bag->next!=NULL)
			{
				
				if(ptr->record->invoice>=bag->next->record->invoice)
					{	
						ptr->next=bag->next;
						ptr->previous=bag;
						bag->next=ptr;
						ptr->next->previous=ptr;
						sort_invert(town,list);
						sort_invert1(town,list,1);		
						return;					
					}
				bag=bag->next;	
					
			}
			if (bag->next==NULL)
			{	bag->next=ptr;
				ptr->next=NULL;
				ptr->previous=bag;
			}   
			sort_invert(town,list);
			sort_invert1(town,list,1);    
			//sort_invert1(town,lista);		
		}		
	}
	
}

void print_all_from_town(Invert_List lista,char* town,int k)              //tipwse olous tous ofeiletes
{
	int count=0;
  pointer* ptr;
  invert_node* poli;
  poli=search_list_invert(lista,town);
  if (poli==NULL)
	return;
  pointer* list=poli->ptr;
  if (list==NULL)
  	printf("list is empty \n");
  else
   {
    ptr=list;
    while (ptr!=NULL)	
    {if (count==k)
	break;
     printf("%lld	%-5.2f \n",ptr->record->phone,ptr->record->invoice);
     ptr=ptr->next;
	count++;
    }		

   } 

}

void print_all_towns(Invert_List list,int k)
{
	invert_node* ptr=NULL;
  int count=0;
  if (list->First==NULL)
  	printf("list is empty \n");
  else
   {
    ptr=list->First;
    while (ptr!=NULL)	
    {if(count==k)
	break;
     printf("%s:	%d \n",ptr->town,ptr->num);
    count++;
     ptr=ptr->next;
    }		

   }
//return ptr;


}

/*invert_node* lastNode(invert_node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}*/


void print_all_towns1(Invert_List list)
{
	invert_node* ptr=NULL;
  
  if (list->First1==NULL)
  	printf("list is empty \n");
  else
   {
    ptr=list->First1;
    while (ptr!=NULL)	
    {
     printf("%s %lld %-5.2f   \n",ptr->town,ptr->ptr->record->phone,ptr->ptr->record->invoice);
    
     ptr=ptr->next1;
    }		

   }
}
//return ptr;






