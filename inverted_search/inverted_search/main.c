/*
NAME: BHARATHKUMAR K
DATE: 13/5/2024
DESCRIPTION: Inverted Search(Index)
SAMPLE INPUT:
SAMPLE OUTPUT:
 */

#include "inverted.h"
int main(int argc, char *argv[])
{
    link_l *head = NULL;
    link_l *s_head = NULL;

    int choice,flag = 0,res;
    char word[20],fname[20],u_fname[20];
    m_node *arr[27] = {NULL};

    //if arguments more than one 
    if(argc > 1)
    {
	//validating the files
	if(validate(argv,&head) == SUC_S)
	{
	    //if list is empty
	    if(head == NULL)
	    {
		printf("Error : file validation failed\n");
		return 0;
	    }
	    printf("INFO : file validation is done\n");
	}
	else
	{
	    printf("Error : file validation failed\n");
	    return 0;
	}
	while(1)
	{
	    printf("===============================================================================================\n");
	    printf("1. Create DATABASE\n2. Display DATABASE\n3. Search\n4. Save\n5. Update\n6. Exit\nEnter your choice: ");
	    scanf("%d",&choice);	//taking choice from user
	    switch(choice)
	    {
		case 1:
		    if(flag == 0)	//for creating database once
		    {
			if(create_database(arr,&head,&s_head) == SUC_S)
			{
			    printf("INFO : Database created successfully\n");
			    flag = 1;
			}
			else
			{
			    printf("INFO : Database creation failed\n");
			}
		    }
		    else
		    {
			printf("Error : database is already exist\n");
		    }
		    break;
		case 2:
		    printf("===============================================================================================\n");
		    printf("INFO : Selected display option\n");
		    if(display_database(arr) == FAIL_UR)
		    {
			printf("Error : database displaying failed\n");
		    }
		    break;
		case 3:
		    printf("===============================================================================================\n");
		    printf("INFO : selected search option\n");
		    printf("Enter the word to search: ");
		    scanf(" %s",word);	//take word from user for search
		    if((res = search_inDB(arr,word)) == DATA_NOT_FOUND)
		    {
			printf("Error : word is not in data base\n");
		    }
		    else if(res == FAIL_UR)
		    {
			printf("Error : array index is empty\n");
		    }
		    break;
		case 4:
		    printf("===============================================================================================\n");
		    printf("INFO : selected save\n");
		    printf("Enter the file name: ");
		    scanf(" %s",fname);	//take file name from user
		    if(save_database(arr,fname) == FAIL_UR)
			printf("Error : saving failed\n");
		    break;
		case 5:
		    printf("===============================================================================================\n");
		    printf("INFO : selected update\n");
		    if(flag == 0)	//if database is not created then only update
		    {
			printf("Enter the file name: ");
			scanf(" %s",u_fname);
			if(update_data(arr,&s_head,u_fname) == SUC_S)
			{
			    printf("INFO : database is updated\n");
			}
			else
			{
			    printf("Error : database updation failed\n");
			}
		    }
		    else
		    {
			printf("Error : database is already created\n");
		    }
		    break;
		case 6:
		    return 0;	//exiting from program
		default:
		    printf("Error : Invalid Choice\n");
	    }
	}
    }
    else
    {
	printf("Error : Enter the valid number of arguments\n");
    }


    return 0;
}

