#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void cabezera(void);
void centro(void);
void base(void);
double introducir_valor(char x[],char y[]);

int main(int argc, char *argv[]) {
	
	int cont, pulsacion,sw;
	char tit[]=("\n\t\t\t== CALCULADORA DE PESO CORPORAL ==");
	char tex[]="\n\n\tIntroduzca tu peso (kg.):\n   > ";
	char tex2[]="\n\n\tIntroduzca ahora tu altura (cm.):\n   > ";
	double peso, altura, IMC, min, max, ideal, f_id, f_sub, f_baj, p_ob, p_so;
		
	do{
		system("color 70");
		
		peso=introducir_valor(tit,tex);
		altura=introducir_valor(tit,tex2);
		        
		if ( altura > 3 ) {
			ideal = (0.75*(altura-150))+50;			//calcula el peso ideal
			altura = altura/100;					//convierte peso del cm. al m.
		}
		else 
			ideal=(0.75*((altura*100)-150))+50; 
		     
		IMC=peso/(altura*altura);
		
		printf("%s",tit);
		printf("\n\n\n  - Un cuerpo con peso %.2lf kg. y con altura %.2lf m. optiene los siguientes \nresultados:\n",peso,altura);
		printf("\n");
		cabezera();
		printf("\n%c%-40s%c%.1lf kg/m%c.                     %c\n",186,"1: IMC (Indice de Masa Corporal)",186,IMC,253,186);
		centro();
		printf("º2: Estado corporal:                     º");
		if(IMC<18.5){
			sw=1;
			printf("BAJO PESO ");
			if(IMC<16) 
				printf("(DELGADEZ SEVERA)     ");
			else if(IMC<17 && IMC>=16) 
				printf("(DELGADEZ MODERADA)   ");
			else if(IMC<18.5 && IMC>=17) 
				printf("(DELGADEZ LEVE)       ");
		}
		else if(IMC<25 && IMC>=18.5){
			sw=2;
			printf("NORMAL                          ");
		}
		else if(IMC<30 && IMC>=25){
			sw=3;
			printf("SOBREPESO (PREOBESO)            ");
		}
		else if(IMC>=30){
			sw=4;
			printf("OBESIDAD ");
			if(IMC<35)
				printf("(OBESIDAD LEVE)        ");
			else if(IMC>=35 && IMC<40)
				printf("(OBESIDAD MEDIA)       ");
			else if(IMC>=40)
				printf("(OBESIDAD MORBIDA)     ");		
		}
		printf("%c\n",186);
		
		min = 18.5*altura*altura; 
		max = 25*altura*altura; 
		 
	
		if(peso<ideal) 
			f_id=ideal-peso; 
		else 
			f_id=peso-ideal;
	
		centro ();
		printf("%c3: Rango de peso normal:                %c%.2f kg. - %.2f kg.           %c\n",186,186,min,max,186);
		centro ();
		printf("%c4: Peso ideal:                          %c%.2f kg.                       %c\n",186,186,ideal,186);
		centro ();
		printf("%c5: Diferencia entre tu peso e ideal:    %c%.2f kg.",186,186,f_id); if(f_id<10) printf(" "); printf("                       %c\n",186);
		base ();
		//printf("\n\tOBSERBACIONES:\n");
		switch(sw){
			case 1:
				f_sub=min-peso;
				printf("\n\n       %c%cCUIDADO!!\n",173,173);
				printf("\n  a- Te falta subir %.2f kg. para que tengas peso normal.\n",f_sub);
				break;
			case 2:
				f_sub=max-peso;
				f_baj=peso-min;
				printf("\n\n      %c%cFELICIDADES!!\n",173,173);
				printf("\n  a- Te falta subir %.2f kg. para tener sobrepeso.\n",f_sub);
				printf("  b- Pero, si bajas %.2f kg. tendras bajo peso.\n",f_baj);
				break;
			case 3:
				p_ob = 30*altura*altura;
				//p_so=25*altura*altura;
				f_sub = p_ob-peso;
				f_baj = peso-max;
				printf("\n\n       %c%cCUIDADO!!\n",173,173);
				printf("\n  a- Si subes %.2f kg. m%cs, tendr%cs obesidad;\n",f_sub,160,160);
				printf("  b- Pero si bajase %.2f kg, ya tendrias peso normal.\n",f_baj);
				break;
			case 4:
				f_baj=peso-(30*altura*altura);
				printf("\n\n       %c%cCUIDADO!!\n",173,173);
				printf("\n  a- Si bajas %.2f kg., tendrias solo sobrepeso;\n",f_baj);
				printf("  b- Pero para que tengas peso normal, debes bajar %.2f kg. ",(peso-max));
				break;
		}
		
		do{
			printf("\n\n\t%cDeseas (C)alcular de nuevo o (S)alir?\n   > ",168);
			pulsacion=getche ();
		}while(pulsacion!=67 && pulsacion!=99 && pulsacion!=115 && pulsacion!=83);
		
		
		system("cls");
		
	}while (pulsacion==67 || pulsacion==99);
	
	return 0;
	
}


void cabezera(void){
		int c;
		printf("%c",201);
		for(c=0;c<73;c++){
			if(c!=40)
				printf("%c",205);
			else
				printf("%c",203);	
		}
		printf("%c",187);
	}
	
	void centro(void){
		int c;
		printf("%c",204);
		for(c=0;c<73;c++){
			if(c!=40)
				printf("%c",205);
			else
				printf("%c",206);	
		}
		printf("%c\n",185);
	}
	
	void base(void){
		int c;
		printf("%c",200);
		for(c=0;c<73;c++){
			if(c!=40)
				printf("%c",205);
			else
				printf("%c",202);	
		}
		printf("%c\n",188);
	}


double introducir_valor(char tit[],char texto[]){
	char caracter; /* variable para almacenar los caracteres introducidos por el usuario */
	char valores[ 10 ]; /* crea un arreglo de caracteres */
	int i = 0, sw=0, i_p=0; /* i:contador de indice, sw:bandera de introduccion de ".", i_p:indice de la posicion del punto */
	valores[ i ] = '\0';
	
	printf("%s",tit);
	printf( "%s",texto);
	caracter = getch();
	system("cls");
		
	while (  caracter != 13 || i==0 || valores[i-1]=='.') {
		
		if(isdigit(caracter) || (caracter=='.' && sw==0 && i!=0)){
			
			if(caracter=='.'){
				i_p = i;
				sw=1;
			} 
			
			valores[ i++ ] = caracter;
			valores[ i ] = '\0';
		}	
		else if(caracter==8 && i>0){             //8: caracter de retroceso
			valores[--i] = '\0';
			if (i_p == i) sw=0;
		}
		else printf("\a");		
	
		
		printf("%s",tit);
		printf( "%s",texto );
		printf( "%s",valores );
		caracter = getch();
		system("cls");
	}
	 
	return (atof(valores));
}
	
