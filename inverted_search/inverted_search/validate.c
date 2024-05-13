#include "inverted.h"

Sta_t validate(char *argv[],link_l **head)
{
    if(valid_file(argv,head) == SUC_S)	//if files are valid
    {
	printf("INFO : file names stored\n");
	link_l *temp = *head;
	printf("head");
	//printing the files in list
	while(temp != NULL)
	{
	    printf(" -> %s",temp->fname);
	    temp = temp->link;
	}
	printf("\n");
	return SUC_S;
    }
    else
    {
	printf("Error : there are no files\n");
	return FAIL_UR;
    }
}

Sta_t valid_file(char *argv[], link_l **head)
{
    //checking if cla files are valid or not
    int i=1,flag=0;
    while(argv[i] != NULL)
    {
	if(strchr(argv[i],'.') != NULL)
	{
	    if(strcmp(strchr(argv[i],'.'),".txt") == 0)	//if file is valid
	    {
		FILE *temp = fopen(argv[i],"r");	//open in read mode
		if(temp != NULL)
		{
		    fseek(temp, 0, SEEK_END);		//seek end to get the word count
		    if(ftell(temp) != 0)		//if count is not 0
		    {
			link_l *t = *head;
			while(t != NULL)
			{
			    if(strcmp(t->fname,argv[i]) == 0)	//check if file name repeated or not
			    {
				break;	//if repeated dont insert
			    }
			    t = t->link;
			}
			if(t == NULL)	//if file does not exist in list 
			{
			    if(insert_at_last(head, argv[i]) == FAIL_UR)	//insert file name in list
				return FAIL_UR;
			}
		    }
		    else
		    {
			printf("Error : %s file is empty.\n", argv[i]);
		    }
		}
		else
		{
		    //fclose(temp);
		    printf("Error : %s file does not exist\n",argv[i]);
		}
	    }
	    else
	    {
		printf("Error : %s is not valid file\n", argv[i]);
	    }
	}
	else
	{
	    printf("Error : %s is not valid file\n", argv[i]);
	}
	i++;
    }

}

Sta_t insert_at_last(link_l **head, char *data)
{
    //creating node
    link_l *neww = malloc(sizeof(link_l));
    //checking node is created
    if(neww == NULL)
	return FAIL_UR;
    //adding data
    neww->fname = data;
    neww->link = NULL;
    //updating head
    if(*head == NULL)
    {
	*head = neww;
	return SUC_S;
    }
    //adding new node at last
    link_l *temp = *head;
    while(temp->link != NULL)
    {
	temp = temp->link;
    }
    temp->link = neww;
    return SUC_S;
}
