#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "invert.h"
#include "hashtable.h"
#include "max_min.h"
#include "filerecord.h"



int global=0;

int sizeofhash(char * Datafile){
FILE *fpb;
   MyRecord rec;
   int numOfrecords, i,h,lSize;
   long long int num;


   
  
  //Invert_List invert_list1=create_invert_list();
   
   fpb = fopen (Datafile,"rb");
   if (fpb==NULL) {
      	printf("Cannot open binary file\n");
      	return 1;
   	}

   
   fseek (fpb , 0 , SEEK_END);
   lSize = ftell (fpb);
   rewind (fpb);
   numOfrecords = (int) lSize/sizeof(rec);
	return numOfrecords/10;

}





 insert(long long num,char*FirstName,char*LastName,char*Town,float invoice,hash_table b,Invert_List invert_list,maxlist list)
{

   
node* komvos=search_hash_table(b,num,global);
if (komvos!=NULL)
	{
	printf("We have already this number in our database\n");
	return;		
	}	
	
int h;
h=hash_function(num,global);
	//printf("tha mpei stin oura %d \n",h);
	komvos=create_node(num,FirstName,LastName,Town,invoice);
	sort_maxlist(list,create_maxnode(komvos->phone));
        insert_to_end(b[h],komvos); 
	//print_all_from_first(b[h]);
        invert_node* city;
	
	
	city=search_list_invert(invert_list,Town);
	

        if (city==NULL)
	{
                city=create_invert_node(Town);
		insert_to_end_invert(invert_list,city);
		//insert_to_end_invert(invert_list1,city);
		
	}
	
	
        //
	insert_rec_to_invert (komvos,city,invert_list);
	printf("Phone number %lld added successfully.\n",num);
}







int load(char* Datafile,hash_table* b,Invert_List* invert_list,maxlist* Maxlist)
{

	   FILE *fpb;
   MyRecord rec;
   int numOfrecords, i,h,lSize;
   long long int num;
if(*b==NULL){
	printf("kainouriooo\n");
	*b=create_hash_table(global);
   	*invert_list=create_invert_list();
	*Maxlist=create_maxlist();}

   
  
  //Invert_List invert_list1=create_invert_list();
   
   fpb = fopen (Datafile,"rb");
   if (fpb==NULL) {
      	printf("Cannot open binary file\n");
      	return 1;
   	}

   
   fseek (fpb , 0 , SEEK_END);
   lSize = ftell (fpb);
   rewind (fpb);
   numOfrecords = (int) lSize/sizeof(rec);
	  node* komvos;
for (i=0; i<numOfrecords ; i++) {
     
      	fread(&rec, sizeof(rec), 1, fpb);
//      	printf("%s %s %s %s %-5.2f\n",rec.phone, rec.LastName, rec.FirstName, rec.Town, rec.invoice);
	num=atoll(rec.phone); 
        
	int tsa =insert(num,rec.FirstName,rec.LastName,rec.Town,rec.invoice,*b,*invert_list,*Maxlist);
}

fclose (fpb);

	
}

delete(hash_table b,int size,char* phonestring,Invert_List invert_list,maxlist list)
{   
	        
	long long phone=atoll(phonestring);
	node* komvos=search_hash_table(b,phone,global);
	if (komvos!=NULL)
	{
	
	delete_sort_maxlist(list,phone);
	delete_record(b,size,phone,invert_list);		
	}
	else{printf("we dont have this number\n");}
	//printf("%lld\n",phone);
	
	
}

query(char* phonestring,hash_table b,int size)
{
      if(b==NULL)
	{
	printf("Not Found\n");
	return;}
	long long phone=atoll(phonestring);
node*x= search_hash_table(b,phone,size);
	if(x==NULL){
		printf("Not Foundaaaaa\n");

       }
	else	
		printf("%lld  %s  %s  %s  %-5.2f\n",x->phone,x->LastName,x->FirstName,x->town,x->invoice);
	
}


population(char*town,Invert_List list)
{
	if (list==NULL)
		{
printf("Not Found\n");return;}
	invert_node* x=search_list_invert(list,town);
	if (x==NULL)
		printf("There is not this town in our list\n");
	else
		printf("%s:	%d\n",x->town,x->num);	

}

top(Invert_List list,int k)
{
	if (list==NULL)
{		printf("Not Found\n");return;}
  print_all_towns(list,k);

}

sum(char*town,Invert_List list)
{
	if (list==NULL)
		{printf("Not Found\n");return;}
	invert_node* x=search_list_invert(list,town);
	if (x==NULL)
		{printf("There is not this town in our list\n"); return;}
	else
		printf("%s:	%-5.2f\n",x->town,x->sum);

}

find_top(Invert_List list,int k,char* town)
{
	if (list==NULL)
		{printf("No records found for given town.\n"); return;}
print_all_from_town(list,town,k); 
}


find_top_spender(Invert_List list)
{

if (list==NULL)
	{printf("No top spenders found.\n"); return;}
print_all_towns1(list);
}


exit_p(hash_table b,Invert_List invert_list,maxlist Maxlist)
{
	clean_maxlist(Maxlist);
	clean_list_invert(invert_list);
	clean_hash_table(b,global);
	
}


int main (int argc, char** argv) 
{       

        int flag0=0;
int flag1=0;
int argu=0;
char load_buf[30];
char operation[30];
char conf[30];
int d;
char filename[30] ;
hash_table b=NULL;//=create_hash_table(20);
Invert_List invert_list=NULL;//=create_invert_list();
maxlist Maxlist=NULL;
while ((d = getopt(argc, argv, "loc:")) != -1)
        switch (d)
    {
        case 'l':
            flag0=1;
            argu = argu+2;
            strcpy(load_buf,argv[argu]);
            printf("Datafile:%s\n",load_buf);
		global=sizeofhash(load_buf);
		load(load_buf,&b,&invert_list,&Maxlist);
            break;
        case 'o':
            flag1=1;
            argu = argu+2;
            strcpy(operation,argv[argu]);
	    strcpy(filename,argv[argu]);
	    
            printf("Operations File:%s\n",operation);
            break;
        case 'c':
            argu = argu+2;
            strcpy(conf,argv[argu]);
            printf("i dont use config file \n");
		
            //strcpy(config_file_path, buf);
            //memset(buf,0,sizeof(buf));
            break;
        default:
            break;
    }


if (flag0==0)
	global=20;
        
	 
	FILE *filept ;
	char *token;
	if (flag1==1)
	 filept = fopen ( filename, "r" );
//	hash_table b=NULL;//=create_hash_table(20);
//   	Invert_List invert_list=NULL;//=create_invert_list();
//	maxlist Maxlist=NULL;
	printf("Welcome!!!\n");
       char pinakas[10]="\0";
	char file[30]="\0";
	char phone[12]="\0";
	char FirstName[30]="\0";
	char LastName[30]="\0";
        char Town[30]="\0";
	
		
	while(strcmp(pinakas,"e")!=0)
	{
	printf(">> ");
        scanf("%s",pinakas);
	if(strcmp(pinakas,"l")==0)
	{
		scanf("%s",file);
		global=sizeofhash(file);
		load(file,&b,&invert_list,&Maxlist);

	}
	
	else if(strcmp(pinakas,"i")==0)
	{
                float invoice=0;
		scanf("%s",phone);
		scanf("%s",FirstName);
		scanf("%s",LastName);
		scanf("%s",Town);
		scanf("%f",&invoice);
		
                long long num=atoll(phone);
		insert(num,FirstName,LastName,Town,invoice,b,invert_list,Maxlist);
		//delete(hash_table b,int size,char* phonestring,Invert_List invert_list)

	}
	else if(strcmp(pinakas,"d")==0)
	{
		scanf("%s",phone);
		delete(b,global,phone,invert_list,Maxlist);
		//delete(hash_table b,int size,char* phonestring,Invert_List invert_list)

	}
	else if(strcmp(pinakas,"p")==0)
	{
		scanf("%s",Town);
		population(Town,invert_list);
		//delete(hash_table b,int size,char* phonestring,Invert_List invert_list)

	}
	else if(strcmp(pinakas,"q")==0)
	{
		scanf("%s",phone);
		query(phone,b,global);
		//delete(hash_table b,int size,char* phonestring,Invert_List invert_list)

	}

	else if(strcmp(pinakas,"s")==0)
	{
		scanf("%s",Town);
		sum(Town,invert_list);
		//delete(hash_table b,int size,char* phonestring,Invert_List invert_list)

	}
        else if(strcmp(pinakas,"t")==0)
	{
		int x;
	
		scanf("%d",&x);
		top(invert_list,x);
		//delete(hash_table b,int size,char* phonestring,Invert_List invert_list)

	}
	else if(strcmp(pinakas,"ft")==0)
	{
		int x;
		scanf("%s",Town);	
		scanf("%d",&x);
		find_top(invert_list,x,Town);
		//delete(hash_table b,int size,char* phonestring,Invert_List invert_list)

	}
	else if(strcmp(pinakas,"fts")==0)
	{
		find_top_spender(invert_list);		//delete(hash_table b,int size,char* phonestring,Invert_List invert_list)

	}
	else if(strcmp(pinakas,"min")==0)
	{
		
		print_min(Maxlist);
//print_all_from_maxfirst(Maxlist);		//delete(hash_table b,int size,char* phonestring,Invert_List invert_list)

	}
	

	else if(strcmp(pinakas,"max")==0)
	{      
		print_max(Maxlist);		//delete(hash_table b,int size,char* phonestring,Invert_List invert_list)

	}
	else if(strcmp(pinakas,"o")==0)
	{
               char til[12];
		char onoma[30];
		char epitheto[30];
		char xreos[10];
		char perioxi[30];
		char arithmos[10];
		if ( filept != NULL )
   		{
      		char line [ 128 ]; /* or other suitable maximum line size */
      		while ( fgets ( line, sizeof line, filept ) != NULL ) /* read a line */
      		{
		
       //  if(strcmp(line[]))
	
		token = strtok(line," \n");
		if (token==NULL)
			{continue;}
		
		//token[3]='\0';
		//printf
		if(strcmp(token,"fts")==0)
		{
					
			find_top_spender(invert_list);
			
  	 		
		}
		else if(strcmp(token,"ft")==0)
		{
			
  	    			token = strtok(NULL, " \n");
				strcpy(perioxi,token);
				printf("perioxi = %s\n",perioxi);
				token= strtok(NULL, " \n");
				strcpy(arithmos,token);
  	 		
			int tso=atoi(arithmos);
			
			find_top(invert_list,tso,perioxi);
			
		}
		else if(strcmp(token,"t")==0)
		{
			
		
  	    			
				token= strtok(NULL, " \n");
				strcpy(arithmos,token);
  	 		
			int tso=atoi(arithmos);
			
			top(invert_list,tso);
			
		}
		else if(strcmp(token,"l")==0)
		{
			
		
  	    			
				token= strtok(NULL, " \n");
				strcpy(arithmos,token);
				global=sizeofhash(arithmos);
				load(arithmos,&b,&invert_list,&Maxlist);
  	 		
	
			
		}
		else if(strcmp(token,"s")==0)
		{
			

		
  	    			
				token= strtok(NULL, " \n");
				strcpy(perioxi,token);
				sum(perioxi,invert_list);
  	 		
	
			
		}
		else if(strcmp(token,"max")==0)
		{
			
		
  	    			
				print_max(Maxlist);
  	 		
	
			
		}
	        else if(strcmp(token,"min")==0)
		{
			
		
  	    		
				print_min(Maxlist);
  	 		
	
			
		}
		else if(strcmp(token,"i")==0)
		{
			
			token= strtok(NULL, " \n");
			strcpy(arithmos,token);
			long long phonenumber=atoll(arithmos);
			token= strtok(NULL, " \n");
			strcpy(onoma,token);
			token= strtok(NULL, " \n");
			strcpy(epitheto,token);
			token= strtok(NULL, " \n");
			strcpy(perioxi,token);
			token= strtok(NULL, " \n");
			strcpy(xreos,token);
			float no=atof(xreos);
			if(b==NULL){
			load("fefe",&b,&invert_list,&Maxlist);}
			insert(phonenumber,onoma,epitheto,perioxi,no,b,invert_list,Maxlist);
  	 		
	
			
		}
		else if(strcmp(token,"q")==0)
		{
			token= strtok(NULL, " \n");
			strcpy(arithmos,token);
			//long long phonenumber=atoll(arithmos);	
			query(arithmos,b,global);	

		}
		else if(strcmp(token,"d")==0)
		{
			token= strtok(NULL, " \n");
			strcpy(arithmos,token);
			//long long phonenumber=atoll(arithmos);	
			delete(b,global,arithmos,invert_list,Maxlist);	

		}
		else if(strcmp(token,"p")==0)
		{
			token= strtok(NULL, " \n");
			strcpy(perioxi,token);	
			population(perioxi,invert_list);	

		}
		
		else if(strcmp(token,"e")==0)
		{
			//printf("lalalalsldddd\n");
			exit_p(b,invert_list,Maxlist);
			//fclose ( filept );
			exit(0);	

		}
		
		
         //fputs ( line, stdout ); /* write the line */
		
 	     }
		
      //fclose ( filept );
   }
   else
   {
      perror ( filename ); /* why didn't the file open? */
   }		

	}
	}
	//fclose ( filept );
        exit_p(b,invert_list,Maxlist);	 
return 0;
}	
	/*load(argv[1],argc,b,invert_list);
	query(6957432298,b,20);
	delete_record(b,20,6957432298,invert_list);
	population("Athens",invert_list);
	top(invert_list,7);
    	sum("Athens",invert_list);

	printf("\n**************************************\n\n");
	find_top(invert_list,5,"Athens");
	printf("\n**************************************\n\n");
	find_top_spender(invert_list);
	*/
   /*FILE *fpb;
   MyRecord rec;
   int numOfrecords, i,h,lSize;
   long long int num;
   
   hash_table b=create_hash_table(20);
   Invert_List invert_list=create_invert_list();
  //Invert_List invert_list1=create_invert_list();
   if (argc!=2) {
      	printf("Correct syntax is: %s BinaryFile\n", argv[0]);
      	return(1);
   	}
   fpb = fopen (argv[1],"rb");
   if (fpb==NULL) {
      	printf("Cannot open binary file\n");
      	return 1;
   	}

   
   fseek (fpb , 0 , SEEK_END);
   lSize = ftell (fpb);
   rewind (fpb);
   numOfrecords = (int) lSize/sizeof(rec);
	  node* komvos;
for (i=0; i<numOfrecords ; i++) {
     
      	fread(&rec, sizeof(rec), 1, fpb);
//      	printf("%s %s %s %s %-5.2f\n",rec.phone, rec.LastName, rec.FirstName, rec.Town, rec.invoice);
	num=atoll(rec.phone); 
        h=hash_function(num,20);
	//printf("tha mpei stin oura %d \n",h);
	komvos=create_node(num,rec.FirstName,rec.LastName ,rec.Town,rec.invoice);
        insert_to_end(b[h],komvos); 
        invert_node* city;
	
	
	city=search_list_invert(invert_list,rec.Town);
	

        if (city==NULL)
	{
                city=create_invert_node(rec.Town);
		insert_to_end_invert(invert_list,city);
		//insert_to_end_invert(invert_list1,city);
		
	}
	
	
        //
	insert_rec_to_invert (komvos,city,invert_list);
	
}*/
//printf("vgika apo tin epanalipsi \n");
 //print_all_hash_table(b,10);
//invert_node* city=search_list_invert(invert_list,"Peraias");
//print_all_towns(invert_list);
//delete_record(b,20,6967623575,invert_list);
//delete_record(b,20,6957432298,invert_list);
//delete_record(b,20,6952413338,invert_list);
//delete_record(b,20,6946054312,invert_list);
//delete_record(b,20,6957567858,invert_list);
//delete_record(b,20,6961853667,invert_list);
//delete_record(b,20,6955444815,invert_list);
//delete_record(b,20,6948370923,invert_list);
//delete_record(b,20,6967420476,invert_list);
/*  xreos=116.000000 noumero=6964775616
///////peiraias///
xreos=93.000000 noumero=6955444815
xreos=26.000000 noumero=6948370923

xreos=126.000000 noumero=6967623575
xreos=114.000000 noumero=6957432298
xreos=111.000000 noumero=6952413338
xreos=94.000000 noumero=6946054312
xreos=83.000000 noumero=6957567858
xreos=37.000000 noumero=6946839004
xreos=28.000000 noumero=6968326810



////////////////////////////////
xreos=113.000000 noumero=6950086759
xreos=106.000000 noumero=6969988541
xreos=88.000000 noumero=6949066533
xreos=72.000000 noumero=6965692547
xreos=40.000000 noumero=6956907738
xreos=40.000000 noumero=6953691771
xreos=21.000000 noumero=6958166951
xreos=20.000000 noumero=6961853667
xreos=18.000000 noumero=6962164961
xreos=18.000000 noumero=6967420476
 */
//delete_record(b,20,6960086297,invert_list);
//delete_record(b,20,6957432298,invert_list);
//delete_record(b,20,6952413338,invert_list);

//print_all_towns(invert_list);


//print_all_towns(invert_list);

//printf("\n\n\n\n\n");
//print_all_towns1(invert_list);
//print_all_towns(invert_list1);
//invert_node *root=lastNode(invert_list->First);
//printf("town============%s\n",root->town);
//print_all_from_town(invert_list,"Sparta");
//print_all_from_first(b[1]);
//node* test;
 //test=search_hash_table(b,6959455149,20);
 //if (test==NULL)
  //printf("we dont have this number\n");
//else
//  printf("the name of number is %s \n",test->FirstName);
 //clean_list_invert(invert_list);
 
 //clean_hash_table(b,20);
   //print_all_from_first(b[1]);
//printf("Records found in file %d \n", numOfrecords);



//fclose (fpb);


//printf("kleinwwwww \n");












	/*hash_table b=create_hash_table(2);
	long long x=5;
	//List a=create_list();
        //size_of_list(a);
        //printf("molis dimiourgithike i lista exei arithmo %d \n ",a->number);
	insert_to_end(b[1],create_node(1));
	insert_to_end(b[1],create_node(2));
	insert_to_end(b[1],create_node(3));
	print_all_from_first(b[1]);
        size_of_list(b[1]);
	//clean_list(b[1]);
	
	clean_hash_table(b,2);
        
	return 0;*/
//}














































/*FILE *fpb;
	MyRecord rec;
	int numOfrecords, i;
   

	if (argc!=2) 
	{
      		printf("Correct syntax is: %s BinaryFile\n", argv[0]);
      		return(1);
   	}

	fpb = fopen (argv[1],"rb");
   
	if (fpb==NULL) 
	{
	      	printf("Cannot open binary file\n");
	      	return 1;
   	}

	numOfrecords=numofrecord(fpb);
   	
	for (i=0; i<numOfrecords ; i++) 
	{
	      	fread(&rec, sizeof(rec), 1, fpb);
	      	printf("%s %s %s %s %-5.2f\n",rec.phone, rec.LastName, rec.FirstName, rec.Town, rec.invoice);
   	}

	fclose (fpb);
}





int numofrecord(FILE* fpb)
{
	int numOfrecords;
	long lSize;
	fseek (fpb , 0 , SEEK_END);
	lSize = ftell (fpb);
	rewind (fpb);
	numOfrecords = (int) lSize/sizeof( MyRecord);
	return numOfrecords;

}




*/


