unsigned int veri10bit;
unsigned char i,j,sayac1=10,sayac2=10,k=0 ;

void interrupt()
{
if(INTCON.TMR0IF==1)
{
INTCON.TMR0IF=0;
//Kesme bayra?y reset
TMR0 = 100;
//PORTB.B1 = 1;
PORTB.B1 = 1;


for (i=1; i<sayac1; i++)
//duty
{ delay_us(100);
 }
PORTB.B1 = 0;
}

if(INTCON.TMR1IF==1)
{
k = k+1;
if(k>=32)
INTCON.TMR1IF=0;
{

//Kesme bayra?y reset
TMR1L = 100;
TMR1H=0x00;
PORTB.B2 = 1;

for (i=1; i<sayac2; i++)
//duty
{ delay_us(100);
 }
PORTB.B2 = 0;
}
k=0;
}
}

void main()
{


OPTION_REG=0x07; // prescaler rate=1/256, fosc/4
INTCON.GIE = 1; // Global Interrupt izin
INTCON.TMR0IE = 1; // Timer0 Interrupt izin
TMR0 = 100; // Timer0 ilk yükleme


T1CON = 0x21; // prescaler rate=1/4, fosc/4
INTCON.TMR1IE=1;
TMR1L = 100;
TMR1H=0x00;

ADCON1=0x80; //0.+5V giriþ,
TRISA = 0xFF; // PORTA giriþ
TRISC = 0; // PORTC giriþ
TRISB = 0; // PORTB çýkýþ

do
{
veri10bit = Adc_Read(0);
// 0. kanaldan oku
//PORTB = veri10bit;
// LSB 8 biti PORTB ye yaz
//PORTC = veri10bit >> 8;
// MSB 2 biti RC1-RC0 pinlerine yaz
sayac1=veri10bit/32;

veri10bit = Adc_Read(1);
//3. kanaldan oku
sayac2=veri10bit/32;

delay_ms(200);
}
while(1);
}