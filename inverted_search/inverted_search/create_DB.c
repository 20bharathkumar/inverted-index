#include "inverted.h"

Sta_t create_database(m_node **arr, link_l **head, link_l **u_head)
{ 
    link_l *temp = *head;
    link_l *u_temp = *u_head;
    FILE *fptr;
    char contnt[100];
    int ind;

    //run loop till file name list reaches NULL
    while(temp != NULL)
    {
	//checking if files exist in update files list
	while(u_temp != NULL)
	{
	    if(strcmp(u_temp->fname, temp->fname) == 0)
	    {
		printf("INFO : %s file already exist\n",temp->fname);
		break;
	    }
	    u_temp = u_temp->link;
	}
	//if the file doesnot exist in update file list create database for it
	if(u_temp == NULL)
	{
	    fptr = fopen(temp->fname, "r");	//file opening
	    while(fscanf(fptr,"%s",contnt) != -1)	//taking word from the file
	    {
		if(contnt[0]>=65 && contnt[0]<=90)	//fetching the index
		    ind = contnt[0]%'A';
		else if(contnt[0]>=97 && contnt[0]<=122)
		    ind = contnt[0]%'a';
		else
		    ind = 26;

		if(arr[ind] == NULL)			//if index is empty
		{
		    m_node *new_main = malloc(sizeof(m_node));	//create a main node

		    //if(new_main == NULL || new_sub == NULL)
		    //  return FAIL_UR;
		    new_main->file_count = 1;
		    new_main->main_link = NULL;
		    strcpy(new_main->word, contnt);

		    s_node *new_sub = malloc(sizeof(s_node));	//and create a sub node and link to main node
		    new_sub->word_count = 1;
		    new_sub->sub_link = NULL;
		    strcpy(new_sub->f_name,temp->fname);

		    new_main->sub_link = new_sub;

		    arr[ind] = new_main;			//after creation add the main node to array index
		}
		else
		{
		    m_node *m_temp = arr[ind]; 			//if index is not empty take two pointers
		    m_node *m_prev = arr[ind];

		    while(m_temp)				//run loop till last main node
		    {
			if(strcmp(contnt,m_temp->word) == 0)	//compare the word with main node word
			{
			    s_node *s_temp = m_temp->sub_link;	//if word matches take two pointers 
			    s_node *s_prev = m_temp->sub_link;
			    while(s_temp != NULL)		//run loop till sub node reaches null
			    {
				if(strcmp(s_temp->f_name,temp->fname) == 0)	//if file name matches increment word count
				{
				    (s_temp->word_count)++;
				    break;
				}
				s_prev = s_temp;
				s_temp = s_temp->sub_link;
			    }
			    if(s_temp == NULL)		//if file name does not matches create a sub node and increment file count
			    {
				s_node *new_sub = malloc(sizeof(s_node));
				new_sub->word_count = 1;
				new_sub->sub_link = NULL;
				strcpy(new_sub->f_name,temp->fname);

				(m_temp->file_count)++;

				s_prev->sub_link = new_sub;
			    }
			    break;
			}
			m_prev = m_temp;
			m_temp = m_temp->main_link;
		    }
		    if(m_temp == NULL)		//if the word not present create main node and link to last main node
		    {
			m_node *new_main = malloc(sizeof(m_node));
			s_node *new_sub = malloc(sizeof(s_node));

			if(new_main == NULL && new_sub == NULL)
			    return FAIL_UR;

			new_main->file_count = 1;
			new_main->main_link = NULL;
			strcpy(new_main->word, contnt);

			new_sub->word_count = 1;
			new_sub->sub_link = NULL;
			strcpy(new_sub->f_name,temp->fname);

			new_main->sub_link = new_sub;
			m_prev->main_link = new_main;
		    }
		}
	    }
	}
	temp = temp->link;
    }
    return SUC_S;
}
