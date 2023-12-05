#include <stdio.h>

void invertir(int caja[],int tamanio, int indice);

int main(int argc, char *argv[]) {
	int caja[8]={1,2,3,4,5,6,7,8};
	invertir(caja,8-1,0);
	for(int i=0; i<8;i++){
		printf("%d ",caja[i]);
	}
	return 0;
}

void invertir(int caja[],int tamanio, int indice){
	if(indice>tamanio){
	return;
	}
	int temp=caja[indice];
	caja[indice]=caja[tamanio];
	caja[tamanio]=temp;	
	invertir(caja,tamanio-1,indice+1);

}
