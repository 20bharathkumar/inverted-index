#include "inverted.h"

Sta_t search_inDB(m_node **arr, char *word)
{
    int ind,count = 0;

    //finding the index
    if(word[0]>= 65 && word[0]<=91)
	ind = word[0]%'A';
    if(word[0]>= 96 && word[0]<=122)
	ind = word[0]%'a';
    else
	ind = 26;

    //if index is empty data not found
    if(arr[ind] == NULL)
	return DATA_NOT_FOUND;

    m_node *m_temp = arr[ind];

    //if array index not empty travers and search in each main node if word not found return data not found
    while(m_temp != NULL)
    {
	if(strcmp(m_temp->word,word) == 0)
	{
	    printf("INFO : word \"%s\" is present in %d files\n",word,m_temp->file_count);
	    s_node *s_temp = m_temp->sub_link;
	    count = 0;
	    while(s_temp != NULL)
	    {
		printf("%s -> %d times\n",s_temp->f_name,s_temp->word_count);

		s_temp = s_temp->sub_link;
	    }
	    return SUC_S;
	}
	m_temp = m_temp->main_link;
    }
    return DATA_NOT_FOUND;

}
