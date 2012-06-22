#include "sci_print.h"
#include "sci_receive.h"
#include "debug.h"
#define DUMP_COLUMNS 4

void debug_print(uint8_t *id,uint8_t *text)
{
    print(id);
    print_line(text);
}

void dump_memory(void *start,int size)
{
  int *ptr;
  int i,j;  
  ptr = (int *)start;
  print_line("----------------------------------------");
  print_line("---MEMORY DUMP--------------------------");
  print_line("----------------------------------------");
  print("base address : ");print_hex((int)ptr);print_line("");
  print_line("");
  print_line("address    :: offset     :: content    |        address    :: offset     :: content    |        address    :: offset     :: content    |        address    :: offset     :: content    |");
  //convert size in bytes to int
  for(i = 0;i<size/4;i+=DUMP_COLUMNS)
      {
       for(j = 0;j < DUMP_COLUMNS;j++)
       {
          print_hex((int)ptr);
          print(" :: ");
          print_hex((int)ptr-(int)start);
          print(" :: ");
          print_hex(*ptr);
          print(" | \t");
          ptr++;
       }

       print_line("");        
      }
  print_line("----------------------------------------");  
}

void dump_memory_promt(uint8_t * question,int address,int size)
{
     volatile int *ptr;          
          if(promt_question(question))
             {
                ptr = (int *) address;
                dump_memory((void*)ptr,size);
             }
}