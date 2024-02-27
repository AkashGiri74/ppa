#include<stdio.h>
#include<stdlib.h>
#include"sll.h"

int main ()
{
    sll_t* p_list=NULL;
    p_list=create_list();

    show_list(p_list,"after create list ");
    
}