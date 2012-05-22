#include "sci_print.h"
#include "stdio.h"
#include "string.h"
void sciDisplayText(sciBASE_t *sci, uint8_t *text)
{
    while(*text != '\0')
    {
        while ((UART->FLR & 0x4) == 4); /* wait until busy */
        sciSendByte(UART,*text++);      /* send out text   */
    };
}

void new_line()
{
      sciDisplayText(UART,"\n\r");
}

void print(uint8_t *text)
{
     sciDisplayText(UART,text);
}

void print_line(uint8_t *text)
{
      sciDisplayText(UART,text);
      new_line();
}

void print_digit(int number)
{
  uint8_t text[1];
  text[0] = number + 48;
  text[1] = '\0';
  sciDisplayText(UART,text);
}

void print_number(int number)
{
  int base = 1;
  int tmp = 0;
  while( number/base > 0 )
  {
    base*=10;    
  } 
  while( base > 1)
  {
    base/=10;
    tmp = number/(base*10);
    print_digit((number-number%base-tmp*base*10)/base);   
  }
}


void print_hex(int number)
{
    uint8_t  text_buffer[10];
    sprintf((char*)text_buffer,"0x%X",number);    
    print(text_buffer);    
    if(strlen(text_buffer)<10)    
        for(int i = 0;i<  10 - strlen(text_buffer);i++)
            print(" ");
}

void boot_message()
{
   print_line("");
   print_line("*****************************");
   print_line("Hercules Devel. Project: ");
   print_line("OpenSafety Over Ethernet ");
   print_line("");
   print_line("   Cristiano W. Araujo       ");
   print_line("*****************************");
   print_line("");  
}