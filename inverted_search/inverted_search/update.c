#include "inverted.h"

Sta_t update_data(m_node **arr,link_l **head,char *fname)
{
    char data[1024];
    int ind;
    if(strchr(fname,'.') != NULL && strcmp(strchr(fname,'.'),".txt") == 0)	//checkif if the file is valid or not
    {
	FILE *fptr = fopen(fname,"r");	//opeing file
	if(fptr != NULL)		//if file has the data
	{
	    while(fscanf(fptr,"%s",data) != -1)	//scan the data and store in array
	    {
		if(data[0] == '#' && data[strlen(data)-1] == '#')	//check if line has the indecator
		{
		    char *dt = strtok(data,"#;");			//fetching index
		    ind = atoi(dt);					//converting to number
		    m_node *new_main = malloc(sizeof(m_node));		//creating node

		    strcpy(new_main->word,strtok(NULL,";"));		//storing data
		    new_main->file_count = atoi(strtok(NULL,";"));
		    new_main->main_link = NULL;
		    new_main->sub_link = NULL;

		    for(int i=0; i<new_main->file_count; i++)		//run loop for file count times
		    {
			s_node *new_sub = malloc(sizeof(s_node));	//create sub node

			strcpy(new_sub->f_name,strtok(NULL,";"));	//add data
			new_sub->word_count = atoi(strtok(NULL,"#;"));
			new_sub->sub_link = NULL;

			s_node *s_temp = new_main->sub_link;
			if(s_temp == NULL)				//if there is no sub nodes
			{
			    new_main->sub_link = new_sub;
			}
			else
			{
			    while(s_temp->sub_link != NULL)		//if there are sub nodes travers till null and add the node
			    {
				s_temp = s_temp->sub_link;
			    }
			    s_temp->sub_link = new_sub;
			}

			link_l *t = *head;
			while(t != NULL)		//inserting the file name in update list
			{
			    if(strcmp(t->fname,new_sub->f_name) == 0)	//if file name exist do not inseret
			    {
				printf("Error : %s file already present\n",new_sub->f_name);
				break;
			    }
			    t = t->link;
			}
			if(t == NULL)		//if file does not exist insert to list
			{
			    if(insert_at_last(head, new_sub->f_name) == FAIL_UR)
				return FAIL_UR;
			}
		    }
		    if(arr[ind] == NULL)	//if array index is empty 
		    {
			arr[ind] = new_main;	//insert at array index
		    }
		    else			//if array index is not empty
		    {
			m_node *m_temp = arr[ind];	//insert at last main node
			m_node *m_prev = arr[ind];

			while(m_temp != NULL)
			{
			    m_prev = m_temp;
			    m_temp = m_temp->main_link;
			}
			m_prev->main_link = new_main;
		    }

		}
		else
		{
		    printf("Error : %s not a valid file\n",fname);
		    return FAIL_UR;
		}
	    }
	}
	else
	{
	    printf("Error : %s file doesnot exist\n",fname);
	    return FAIL_UR;
	}
    }
    else
    {
	printf("Error : pass a valid file name\n");
	return FAIL_UR;
    }
}
