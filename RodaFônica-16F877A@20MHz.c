//GERA SINAL DA RODA FÔNICA: 60-2 DENTES @ 3000 rpm

#include <16f877A.h>
#include <stdio.h>
#include <stdlib.h>
#use delay (clock=20000000)
#fuses HS, NOWDT, PUT, BROWNOUT, LVP, DEBUG
#zero_RAM
int x,dente;

#int_timer1
void trata_int_timer1()
	{
		if(x==1)
			{
				set_timer1(65286);
				x=0;
				dente++;
				if(dente<59)output_high(pin_c0);
				if(dente==60)dente=0;
			}
		else
			{
				set_timer1(64121);
				x=1;
				output_low(pin_c0);
  			}
	}

 void main()
	 {
		 setup_adc_ports(RA0_RA1_RA3_ANALOG);
		 setup_adc(ADC_CLOCK_DIV_8);
		 setup_psp(PSP_DISABLED);
		 setup_spi(FALSE);
		 setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
		 setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);
		 setup_timer_2(T2_DIV_BY_4,250,1);
		 set_tris_a(0xFF);
		 set_tris_b(0xFF);
		 set_tris_c(0xFE);
		 set_tris_d(0x00);
		 set_tris_e(0x00);
		 disable_interrupts(global);
		 X=1;
		 dente=0;
		 output_low(pin_c0);
		 enable_interrupts(global);
		 set_timer1(64121);
		 clear_interrupt(int_timer1);
		 enable_interrupts(int_timer1);
		 while(true);
	}
	
	
