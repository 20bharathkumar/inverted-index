#include "inverted.h"

Sta_t save_database(m_node **arr, char *fname)
{
    if(strcmp(strchr(fname, '.'),".txt") == 0)	//check if file is valid file or not
    {
	FILE *fptr = fopen(fname, "w");	//open file in write mode and save the database datas in it
	for(int i=0; i<27; i++)
	{
	    if(arr[i] != NULL)
	    {
		m_node *m_temp = arr[i];
		//fprintf(fptr,"%c",'#');
		while(m_temp != NULL)
		{
		    fprintf(fptr,"%c%d;%s;%d;",'#',i,m_temp->word,m_temp->file_count);
		    s_node *s_temp = m_temp->sub_link;
		    while(s_temp != NULL)
		    {
			fprintf(fptr,"%s;%d;",s_temp->f_name,s_temp->word_count);
			s_temp = s_temp->sub_link;
		    }
		    fprintf(fptr,"%c\n",'#');
		    m_temp = m_temp->main_link;
		}
	    }
	}
	return SUC_S;
    }
    else
    {
	printf("Error : enter a valid file\n");
	return FAIL_UR;
    }
}
