#include <xmc_gpio.h>

char str[]="I CAN MORSE";

unsigned short MC[256],count=0,i=0,j=0;

unsigned long d;

int main(void)
{
  const XMC_GPIO_CONFIG_t LED_config = \
        {.mode=XMC_GPIO_MODE_OUTPUT_PUSH_PULL,\
         .output_level=XMC_GPIO_OUTPUT_LEVEL_LOW,\
         .output_strength=XMC_GPIO_OUTPUT_STRENGTH_STRONG_SHARP_EDGE};

  XMC_GPIO_Init(P1_1, &LED_config);

  strcpy(str,strlwr(str));

  for(i=0;str[i]!='\0';++i)
  {
    switch(str[i])
    {
      case 'a': MC[j++]=1; MC[j++]=0; MC[j++]=3;
              break;
      case 'b': MC[j++]=3; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1;
              break;
      case 'c': MC[j++]=3; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=1;
              break;
      case 'd': MC[j++]=3; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1;
              break;
      case 'e': MC[j++]=1;
              break;
      case 'f': MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=1;
              break;
      case 'g': MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=1;
              break;
      case 'h': MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1;
              break;
      case 'i': MC[j++]=1; MC[j++]=0; MC[j++]=1;
              break;
      case 'j': MC[j++]=1; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3;
              break;
      case 'k': MC[j++]=3; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=3;
              break;
      case 'l': MC[j++]=1; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1;
              break;
      case 'm': MC[j++]=3; MC[j++]=0; MC[j++]=3;
              break;
      case 'n': MC[j++]=3; MC[j++]=0; MC[j++]=1;
              break;
      case 'o': MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3;
              break;
      case 'p': MC[j++]=1; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=1;
              break;
      case 'q': MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=3;
              break;
      case 'r': MC[j++]=1; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=1;
              break;
      case 's': MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1;
              break;
      case 't': MC[j++]=3;
              break;
      case 'u': MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=3;
              break;
      case 'v': MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=3;
              break;
      case 'w': MC[j++]=1; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3;
              break;
      case 'x': MC[j++]=3; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=3;
              break;
      case 'y': MC[j++]=3; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3;
              break;
      case 'z': MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1;
              break;
      case '0': MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3;
              break;
      case '1': MC[j++]=1; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3;
              break;
      case '2': MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3;
              break;
      case '3': MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3;
              break;
      case '4': MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=3;
              break;
      case '5': MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1;
              break;
      case '6': MC[j++]=3; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1;
              break;
      case '7': MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1;
              break;
      case '8': MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=1; MC[j++]=0; MC[j++]=1;
              break;
      case '9': MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=3; MC[j++]=0; MC[j++]=1;
              break;
      case ' ': MC[j++]=0;
              break;
    }
    MC[j++]=0; MC[j++]=0; MC[j++]=0;
  }  
  j-=2;

  i=0;

  for(d=0;d<3000000;++d);

  SysTick_Config(12000000);
  XMC_GPIO_SetOutputHigh(P1_1);

  while(1);

  return(0);
}

void SysTick_Handler(void)
{
  if(i<j)
  {
    if(MC[i]==++count)
    {
      count=0;
      ++i;
      XMC_GPIO_SetOutputLow(P1_1);
    }
    else if(MC[i]==0&&MC[i+1]!=0)
    {
      count=0;
      ++i;
      XMC_GPIO_SetOutputHigh(P1_1);
    }
    else if(MC[i]==0&&MC[i+1]==0)
    {
      count=0;
      ++i;
      XMC_GPIO_SetOutputLow(P1_1);
    }
  }
  else if(++count==49)
  {
    count=i=0;
    XMC_GPIO_SetOutputHigh(P1_1);
  }
}