#include <stdio.h>
#include <stdlib.h>

struct a{
	unsigned int pos;
	unsigned int pix;
};

int main(){
	FILE *ffoto;
	FILE *faux;

	unsigned int tamano,inicioDatos,anchoImagen,altoImagen,tamanopunto;
	int i=0,j=0;
	
	
	ffoto=fopen("a.bmp","rb+");
	faux=fopen("AUXILIAR","rb");


	struct a pixels;
	rewind(ffoto);
	printf("%d",sizeof(pixels.pix));

	while (!feof(faux))
	{
		
		//printf("hola ");
		fread(&pixels,4,2,faux);
	//	printf("pos --> %d \n",(pixels.pos+54));
		rewind(ffoto);
		fseek(ffoto,pixels.pos*3+54,SEEK_SET);
		fwrite(&pixels.pix,3,1,ffoto);
 	}


	
	
	
	fclose(ffoto);
	fclose(faux);
	
	
	
}
