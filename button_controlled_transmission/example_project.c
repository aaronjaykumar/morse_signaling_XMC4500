#include <xmc_gpio.h>

char str[]="I CAN MORSE";

unsigned short MC1[256],MC2[1024],f1=0,f2=0,i=0,j=0,k=0,n=0;

unsigned long p,t1=0,t2=0,t3=0;

const XMC_GPIO_CONFIG_t Button_config = \
      {.mode=XMC_GPIO_MODE_INPUT_TRISTATE,\
       .output_level=XMC_GPIO_OUTPUT_LEVEL_LOW,\
       .output_strength=XMC_GPIO_OUTPUT_STRENGTH_STRONG_SHARP_EDGE};
const XMC_GPIO_CONFIG_t LED_config = \
      {.mode=XMC_GPIO_MODE_OUTPUT_PUSH_PULL,\
       .output_level=XMC_GPIO_OUTPUT_LEVEL_LOW,\
       .output_strength=XMC_GPIO_OUTPUT_STRENGTH_STRONG_SHARP_EDGE};

int main(void)
{
  SysTick_Config(12000000);
  
  XMC_GPIO_Init(P1_14,  &Button_config);
  XMC_GPIO_Init(P1_15,  &Button_config);
  XMC_GPIO_Init(P1_1, &LED_config);

  strcpy(str,strlwr(str));

  for(i=0;str[i]!='\0';++i)
  {
    switch(str[i])
    {
      case 'a': MC1[j++]=1; MC1[j++]=0; MC1[j++]=3;
              break;
      case 'b': MC1[j++]=3; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1;
              break;
      case 'c': MC1[j++]=3; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=1;
              break;
      case 'd': MC1[j++]=3; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1;
              break;
      case 'e': MC1[j++]=1;
              break;
      case 'f': MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=1;
              break;
      case 'g': MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=1;
              break;
      case 'h': MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1;
              break;
      case 'i': MC1[j++]=1; MC1[j++]=0; MC1[j++]=1;
              break;
      case 'j': MC1[j++]=1; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3;
              break;
      case 'k': MC1[j++]=3; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=3;
              break;
      case 'l': MC1[j++]=1; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1;
              break;
      case 'm': MC1[j++]=3; MC1[j++]=0; MC1[j++]=3;
              break;
      case 'n': MC1[j++]=3; MC1[j++]=0; MC1[j++]=1;
              break;
      case 'o': MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3;
              break;
      case 'p': MC1[j++]=1; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=1;
              break;
      case 'q': MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=3;
              break;
      case 'r': MC1[j++]=1; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=1;
              break;
      case 's': MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1;
              break;
      case 't': MC1[j++]=3;
              break;
      case 'u': MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=3;
              break;
      case 'v': MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=3;
              break;
      case 'w': MC1[j++]=1; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3;
              break;
      case 'x': MC1[j++]=3; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=3;
              break;
      case 'y': MC1[j++]=3; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3;
              break;
      case 'z': MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1;
              break;
      case '0': MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3;
              break;
      case '1': MC1[j++]=1; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3;
              break;
      case '2': MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3;
              break;
      case '3': MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3;
              break;
      case '4': MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=3;
              break;
      case '5': MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1;
              break;
      case '6': MC1[j++]=3; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1;
              break;
      case '7': MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1;
              break;
      case '8': MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=1; MC1[j++]=0; MC1[j++]=1;
              break;
      case '9': MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=3; MC1[j++]=0; MC1[j++]=1;
              break;
      case ' ': MC1[j++]=0;
              break;
    }
    MC1[j++]=0; MC1[j++]=0; MC1[j++]=0;
  }  
  j-=2;

  while(1)
  {
    if(XMC_GPIO_GetInput(P1_14)==0&&f1==0&&f2==0)
    {
      f1=1;
      i=k=0;
      t1=t2;
      t3+=(12000000-PPB->SYST_CVR)*100/12000000;
      t2=t3;
      SysTick_Config(12000000);
      XMC_GPIO_SetOutputHigh(P1_1);
    }
    else if(XMC_GPIO_GetInput(P1_15)==0&&f1==0&&f2==0)
    {
      f2=1;
      n=0;
      if(t2==0)
      {
        MC2[n++]=3; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=0; MC2[n++]=0;
      }
      for(p=10;(t2-t1)%(p/10)!=t2-t1&&t2!=0;p*=10);
      for(p/=10;p!=1;p/=10)
      {
        switch(((t2-t1)%p)/(p/10))
        {
          case 0: MC2[n++]=3; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=3;
                  break;
          case 1: MC2[n++]=1; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=3;
                  break;
          case 2: MC2[n++]=1; MC2[n++]=0; MC2[n++]=1; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=3;
                  break;
          case 3: MC2[n++]=1; MC2[n++]=0; MC2[n++]=1; MC2[n++]=0; MC2[n++]=1; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=3;
                  break;
          case 4: MC2[n++]=1; MC2[n++]=0; MC2[n++]=1; MC2[n++]=0; MC2[n++]=1; MC2[n++]=0; MC2[n++]=1; MC2[n++]=0; MC2[n++]=3;
                  break;
          case 5: MC2[n++]=1; MC2[n++]=0; MC2[n++]=1; MC2[n++]=0; MC2[n++]=1; MC2[n++]=0; MC2[n++]=1; MC2[n++]=0; MC2[n++]=1;
                  break;
          case 6: MC2[n++]=3; MC2[n++]=0; MC2[n++]=1; MC2[n++]=0; MC2[n++]=1; MC2[n++]=0; MC2[n++]=1; MC2[n++]=0; MC2[n++]=1;
                  break;
          case 7: MC2[n++]=3; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=1; MC2[n++]=0; MC2[n++]=1; MC2[n++]=0; MC2[n++]=1;
                  break;
          case 8: MC2[n++]=3; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=1; MC2[n++]=0; MC2[n++]=1;
                  break;
          case 9: MC2[n++]=3; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=3; MC2[n++]=0; MC2[n++]=1;
                  break;
        }
        MC2[n++]=0; MC2[n++]=0; MC2[n++]=0;
      }
      n-=2;
      
      t3+=(12000000-PPB->SYST_CVR)*100/12000000;
      SysTick_Config(12000000);
      i=k=0;
      XMC_GPIO_SetOutputHigh(P1_1);
    }
  }

  return(0);
}

void SysTick_Handler(void)
{
  t3+=100;
  if(f1==1)
  {
    if(i<j)
    {
      if(MC1[i]==++k)
      {
        k=0;
        ++i;
        XMC_GPIO_SetOutputLow(P1_1);
      }
      else if(MC1[i]==0&&MC1[i+1]!=0)
      {
        k=0;
        ++i;
        XMC_GPIO_SetOutputHigh(P1_1);
      }
      else if(MC1[i]==0&&MC1[i+1]==0)
      {
        k=0;
        ++i;
        XMC_GPIO_SetOutputLow(P1_1);
      }
    }
    else f1=i=k=0;
  }
  else if(f2==1)
  {
    if(i<n)
    {
      if(MC2[i]==++k)
      {
        k=0;
        ++i;
        XMC_GPIO_SetOutputLow(P1_1);
      }
      else if(MC2[i]==0&&MC2[i+1]!=0)
      {
        k=0;
        ++i;
        XMC_GPIO_SetOutputHigh(P1_1);
      }
      else if(MC2[i]==0&&MC2[i+1]==0)
      {
        k=0;
        ++i;
        XMC_GPIO_SetOutputLow(P1_1);
      }
    }
    else f2=i=k=0;
  }
}