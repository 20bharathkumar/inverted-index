#ifndef INV_H
#define INV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_NOT_FOUND -1

typedef enum
{
    SUC_S,
    FAIL_UR
}Sta_t;

typedef struct main_node
{
    char word[20];
    int file_count;
    struct main_node *main_link;
    struct sub_node *sub_link;
}m_node;

typedef struct sub_node
{
    int word_count;
    char f_name[20];
    struct sub_node *sub_link;
}s_node;

typedef struct node
{
    char *fname;
    struct node *link;
}link_l;

//create database
Sta_t create_database(m_node **arr, link_l **head, link_l **u_head);

//validation of CLA
Sta_t validate(char *argv[], link_l **head);

//validation of files
Sta_t valid_file(char *argv[], link_l **head);

//insert at last function
Sta_t insert_at_last(link_l **head, char *data);

//displaying database
Sta_t display_database(m_node **arr);

//search data in database
Sta_t search_inDB(m_node **arr, char *word);

//saving database to file
Sta_t save_database(m_node **arr,char *fname);

//updating database
Sta_t update_data(m_node **arr,link_l **head,char *fname);

#endif
