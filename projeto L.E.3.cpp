#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
	 int x, y, r, a, soma1, soma2, rest1, rest2, comp1, comp2, ques, quant, quav, quai;
	 float pv, pin;
	 int cpf[11];
	 int resu1[9];
	 int resu2[10];
	 int pridi[2][9];
	 int segdi[2][10];
 main(){
 	setlocale(LC_ALL, "Portuguese");
 	do{
 		r=10;
		 for(x=0; x<11; x++){
		 	printf("Digite o %dº número do seu CPF:",x+1);
			scanf("%d",&cpf[x]);
			while((cpf[x]<0)||(cpf[x]>9)){
				printf("Resposta inválida! Redigite:");
				scanf("%d",&cpf[x]);
			}
		 }	
		 for(y=0; y<9; y++){
		 	pridi[0][y]=cpf[y];
		 	//
		 	pridi[1][y]=r;
		 	r=r-1;
		 	//
		 	resu1[y]=pridi[0][y]*pridi[1][y];
		 	soma1=soma1+resu1[y];
		 }
		 rest1=soma1%11;
		 if(rest1<2){
		 	comp1=0;
		 }else{
		 	comp1=11-rest1;
		 }
		 r=11;
		 for(y=0; y<9; y++){
		 	segdi[0][y]=cpf[y];
		 }
		 segdi[0][9]=comp1;
		 for(y=0; y<10; y++){
		 	segdi[1][y]=r;
		 	//
		 	resu2[y]=segdi[0][y]*segdi[1][y];
		 	soma2=soma2+resu2[y];
		 	r=r-1;
		 }
		 rest2=soma2%11;
		 if(rest2<2){
		 	comp2=0;
		 }else{
		 	comp2= 11-rest2;
		 }
		 if((cpf[9]==comp1)&&(cpf[10]==comp2)){
		 	printf("CPF valido\n");
		 	quav++;
		 }else{
		 	printf("CPF invalido\n");
		 	quai++;
		 }
		 quant++;
		 printf("Quer continuar? 1- sim/ 2- não\n");
         scanf("%d",&ques);
         while((ques!=1)&&(ques!=2)){
         	printf("Resposta invalida! Redigite:\n");
         	scanf("%d",&ques);
		 }
		 soma1=0;
		 soma2=0;
	 }while(ques==1);
	 printf("CPF's' testados: %d\n", quant);
	 printf("CPF's' validos: %d\n", quav);
	 printf("CPF's' invalidos: %d\n", quai);
	 pv=(quav*100)/quant;
     pin=(quai*100)/quant;
	 printf("Porcentagem de CPF's validos: %f%", pv);
	 printf("Porcentagem de CPF's invalidos: %f%", pin);	
 }
