#include "inverted.h"

Sta_t display_database(m_node **arr)
{
    int flag = 0,count = 0;
    for(int i=0; i<27; i++)
    {
	if(flag == 0)
	{
	    printf("\033[0;033m[index]\t\tword\t\t\tfilecount\tfilename\t\twordcount\n\033[0m");
	    flag = 1;
	}
	if(arr[i] != NULL)
	{
	    m_node *m_temp = arr[i];
	    while(m_temp != NULL)
	    {
		printf("[%d]\t\t%-13s\t\t%-5d",i,m_temp->word,m_temp->file_count);

		s_node *s_temp = m_temp->sub_link;
		count = 0;
		while(s_temp != NULL)
		{
		    if(count > 0)
			printf("\t\t\t\t\t");

		    printf("\t\t%-10s\t\t%-5d", s_temp->f_name, s_temp->word_count);
		    printf("\n");
		    count++;
		    s_temp = s_temp->sub_link;
		}
		m_temp = m_temp->main_link;
		printf("\n");
	    }
	}
    }
    if(flag == 1)
	return SUC_S;
    else
	return FAIL_UR;
}
