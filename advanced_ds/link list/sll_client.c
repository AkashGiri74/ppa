#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>
#include"sll.h"

void main ()
{    status_t status;
    sll_t* p_list=NULL;
   p_list= create_list();
   show_list(p_list,"after create list ");

  status= insert_start(p_list,10);
  show_list(p_list,"after insert at start");
  status= insert_start(p_list,20);
  show_list(p_list,"after insert at start");
  status= insert_start(p_list,32);
  show_list(p_list,"after insert at start");
  status= insert_start(p_list,11);
  show_list(p_list,"after insert at start");
   status=insert_end(p_list,70);
   show_list(p_list,"after insert at end");
   status=insert_after(p_list,20,-5000);
   show_list(p_list,"insert after");
   status=insert_before(p_list,11,-235000);
   show_list(p_list,"insert before");
}