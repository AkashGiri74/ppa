#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include"sll.h"


sll_t* create_list(void )
{
 return    get_node((0));
}
  node_t* get_node(data_t new_data )
{
      node_t* new_node=NULL;
      new_node=(node_t *)xmalloc(sizeof(node_t));
      new_node->data=new_data;
      new_node->next=NULL;
 }

 void * xmalloc(size_t size_in_bytes)
{  ///
    void *ptr=NULL;
    ptr=malloc(size_in_bytes);
    if (ptr==NULL)
    {
    fprintf(stderr,"error in memory allocation");
    exit(EXIT_FAILURE);
    }
    else
    {
      return (ptr);
    }
}

void show_list(sll_t * p_list,const char * msg)
{
    node_t *run=NULL;
    if(msg!=NULL)
    puts(msg);

    printf("[start]->");
    run=p_list->next;

    while
    (run
    '/////
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ;;!=NULL)
    {   printf("[%d]->",run->data);
        run=run->next;
    }
    puts("[stop]");
}