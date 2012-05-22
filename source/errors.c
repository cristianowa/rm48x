
#include "errors.h"
#include "sci_print.h"

void delay()
{
     int i;
     for(i = 0;i < 1000000;i++);  
}

void abortError()
{
  
#ifdef ERROR_POLICE_LOOP
    print_line("Erro Policy : LOOP");      
    print_line("device will stay in infinite loop");  
    print_line("please reboot device manually");  
    while(1);  
#endif

#ifdef ERROR_POLICE_REBOOT
    print_line("Erro Policy : REBOOT");  
    delay();
    print_line("");
    print_line("Rebooting ...");
    //TODO: reboot
#endif

#ifdef ERROR_POLICE_NONE
    print_line("Erro Policy : NONE");
    print_line("ignoring error, returning");  
    return;
#endif
  
}


void _undef(void)
{
  print_line(" xxxxxxxxxxxxxxxxx ");
  print_line("  undefined error  ");
  print_line(" xxxxxxxxxxxxxxxxx ");
  abortError();
}

void _prefetch()
{
  print_line(" xxxxxxxxxxxxxxxxx ");
  print_line("  prefetch error   ");
  print_line(" xxxxxxxxxxxxxxxxx ");  
 abortError();
}

void _data()
{  
  print_line(" xxxxxxxxxxxxxxxxx ");
  print_line("    data error     ");
  print_line(" xxxxxxxxxxxxxxxxx ");  
  abortError();
}