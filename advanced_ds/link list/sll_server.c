#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include"sll.h"

sll_t * create_list(void)
{
    return (get_node(0));
}
node_t * get_node (data_t new_data)
{
node_t * new_node =NULL;

  new_node=(node_t*)xmalloc(sizeof(node_t));
  new_node->data=new_data;
  new_node->next=NULL;
}

void * xmalloc(size_t size_in_bytes)
{///node_t
    void * ptr=NULL;

    ptr=malloc(size_in_bytes);
    if(ptr==NULL)
    {
        fprintf(stderr,"error in memory alocation ");
        exit(EXIT_FAILURE);
    }
    return (ptr);
}

void show_list(sll_t * p_list,const char * msg)
{
    node_t * run=NULL;
    if(msg !=NULL)
       puts(msg);
    printf("\n[start]->");
    run=p_list->next;
    while(run !=NULL)
    {
        printf("[%d]->",run ->data);
        run=run->next;
    }   
    puts("[stop]");
}
status_t insert_start(sll_t* p_list,data_t new_data)
{
    node_t * new_node=NULL;
    new_node=get_node(new_data);
    new_node->next=p_list->next;
    p_list->next=new_node;

    return success;
}
status_t insert_end(sll_t * p_list,data_t new_data)
{
    node_t * run =NULL;
    run=p_list->next;
    while(run->next!=NULL)
    {
        run=run->next;
    }
    run->next=get_node(new_data);
    return success;
}
status_t insert_after(sll_t* p_list ,data_t e_data,data_t new_data)
{
    node_t * run=NULL;
    node_t * new_node=NULL;
    run=p_list->next;
    while (run!=NULL)
    {  if(run->data==e_data)
      {
        new_node=get_node(new_data);
        new_node->next=run->next;
        run->next=new_node;
        return(success);
     }
     run=run->next;  
    }
    return list_data_not_found;
}
status_t insert_before(sll_t* p_list ,data_t e_data,data_t new_data)
{    node_t *run=p_list->next;
    node_t* run_before=p_list;
    node_t* new_node=NULL;
    while (run!=NULL)
    { 
        if(run->data==e_data)
        {
          new_node=get_node(new_data);
          new_node->next=run;
          run_before->next=new_node;

          return(success);
        }
        run_before=run;
        run=run->next;
    }
    return list_data_not_found;
    
}
