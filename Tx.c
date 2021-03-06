/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.2 Evaluation
Automatic Program Generator
� Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 11-Jul-2017
Author  : Freeware, for evaluation and non-commercial use only
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega16.h>
#include <stdlib.h>
#include <delay.h>

// Alphanumeric LCD functions
#include <alcd.h>

int count=0;
char ch[10];

// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void)
{           
        count++; 
        lcd_gotoxy(0,1);
        itoa(count,ch);
        lcd_puts(ch);
}

#define ADC_VREF_TYPE 0x00

// Read the AD conversion result
unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=0x40;
// Wait for the AD conversion to complete
while ((ADCSRA & 0x10)==0);
ADCSRA|=0x10;
return ADCW;
}

// Declare your global variables here

void main(void)
{
// Declare your local variables here

int x,y,z,co=0;
char a[10];

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0x00;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0x00;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0x00;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=0x00;
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: On
// INT0 Mode: Falling Edge
// INT1: Off
// INT2: Off
GICR|=0x40;
MCUCR=0x02;
MCUCSR=0x00;
GIFR=0x40;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// USART initialization
// USART disabled
UCSRB=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC Clock frequency: 125.000 kHz
// ADC Voltage Reference: AREF pin
// ADC Auto Trigger Source: Free Running
ADMUX=ADC_VREF_TYPE & 0xff;
ADCSRA=0xA6;
SFIOR&=0x1F;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTC Bit 0
// RD - PORTC Bit 1
// EN - PORTC Bit 2
// D4 - PORTC Bit 4
// D5 - PORTC Bit 5
// D6 - PORTC Bit 6
// D7 - PORTC Bit 7
// Characters/line: 16
lcd_init(16);

// Global enable interrupts
#asm("sei")

while (1)
      {
      DDRB=0b11110000;
       if(PINB.0==1&&PINB.1==1&&PINB.2==0&&PINB.3==1)
       {
        while(PINB.0==1&&PINB.1==1&&PINB.2==0&&PINB.3==1);
        co++;
        co%=2;
       }
       if(co==0)
       {
        if(PINB.0==0&&PINB.1==1&&PINB.2==0&&PINB.3==0)
        {
         PORTB.4=1;
         PORTB.5=0;
         PORTB.6=1;
         PORTB.7=0;
         delay_ms(300);
        } 
        else if(PINB.0==0&&PINB.1==0&&PINB.2==0&&PINB.3==1)
        {
         PORTB.4=0;
         PORTB.5=1;
         PORTB.6=0;
         PORTB.7=1;
         delay_ms(300); 
        } 
        else if(PINB.0==0&&PINB.1==0&&PINB.2==1&&PINB.3==0)  
        {
         PORTB.4=1;
         PORTB.5=0;
         PORTB.6=0;
         PORTB.7=0;
         delay_ms(300);
        }
        else if(PINB.0==0&&PINB.1==1&&PINB.2==1&&PINB.3==0)
        {
         PORTB.4=0;
         PORTB.5=0;
         PORTB.6=1;
         PORTB.7=0;
         delay_ms(300);
        }
         PORTB.4=0;
         PORTB.5=0;
         PORTB.6=0;
         PORTB.7=0;
       }
       if(co==1)
       {
        x=read_adc(0);
        itoa(x,a); 
        lcd_gotoxy(0,0);
        lcd_puts(a);
        lcd_putsf(","); 
        y=read_adc(1);
        itoa(y,a);  
        lcd_puts(a);
        lcd_putsf(","); 
        z=read_adc(2);
        itoa(z,a);  
        lcd_puts(a);
        lcd_putsf("   ");
       
        if((x<490&&x>400)&&(y<380&&y>395)&&(z>288&&z<310))
        {  
         PORTB.4=1;
         PORTB.5=0;
         PORTB.6=1;
         PORTB.7=0;
        }
        else if((x<410&&x>390)&&(y>350&&y<330)&&(z<390&&z>350))
        {
         PORTB.4=0;
         PORTB.5=1;
         PORTB.6=0;
         PORTB.7=1;
        }
        else if((x<410&&x>335)&&(y<400&&y>340)&&(z>300&&z<339))
        {
         PORTB.4=0;
         PORTB.5=0;
         PORTB.6=1;
         PORTB.7=0;
        }
        else if((x<410&&x>305)&&(y<325&&y>255)&&(z>315&&z<370))
        {
         PORTB.4=1;
         PORTB.5=0;
         PORTB.6=0;
         PORTB.7=0;
        }
       }
      }
}
