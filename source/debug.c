#include "sci_print.h"
#include "debug.h"

void debug_print(uint8_t *id,uint8_t *text)
{
    print(id);
    print_line(text);
}

void dump_memory(void *start,int size)
{
  int *ptr;
  int i;  
  ptr = (int *)start;
  print_line("----------------------------------------");
  print_line("---MEMORY DUMP--------------------------");
  print_line("----------------------------------------");
  print("base address : ");print_hex((int)ptr);print_line("");
  print_line("");print_line("address :: offset :: content");
  for(i = 0;i<size;i++)
      {
       print_hex((int)ptr);
       print(" :: ");
       print_hex((int)ptr-(int)start);
       print(" :: ");
       print_hex(*ptr);
       print_line(""); 
       ptr++;
      }
  print_line("----------------------------------------");  
}