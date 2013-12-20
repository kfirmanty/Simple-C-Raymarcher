#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Vector3.h"
#include "RayMarcher.c"
#include "Messages.h"

//Creates header for PPM image file format
int createFileHeader(FILE *file, int width, int height){
	fprintf(file,"P3\n%d %d\n256\n",width,height);
	return 0;
}

int main(int argc, char* argv[]){
	if(argc != 5){
		printf("%s",HELP_MESSAGE);
		return -1;
	}
	const int width = atoi(argv[2]);
	const int height = atoi(argv[3]);
	const int maxIterations = atoi(argv[4]);
	if(width == 0 || height == 0){
		printf("%s",BAD_WIDTH_HEIGHT_OR_MAX_ITERATIONS);
		return -1;
	}
	FILE* file = fopen("test.ppm","wb");
	
	createFileHeader(file,width,height);
	
	Vector3 direction;
	direction = (Vector3){.x=0.0,.y=0.0,.z=1};
	Vector3 from;
	from = (Vector3){.x=0,.y=0,.z=-100};
	int x = 0;
	int y = 0;
	int sampleRate = height/10;
	int loadCount = 0;
	
	for(y = 0; y<height; y++){
		fprintf(file," ");
		for(x = 0; x<width; x++){	
			from.x = x-100;
			from.y = y-100;
			int value = (int)rayMarch(from,direction,maxIterations);
			fprintf(file,"%d %d %d ",value,value,value);	
		}
		fprintf(file,"\n");
		if(y % sampleRate == 0){
			loadCount++;
			printf("\r%i created",loadCount*10);
		}
	}
	fclose(file);
	return 0;
}
