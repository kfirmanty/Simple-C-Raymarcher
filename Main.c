#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int  MAX_ITERATIONS = 1000;


typedef struct{
	float x;
	float y;
	float z;
} Vector3;

Vector3 vec3Mul(Vector3 vec3, float multiplicant){
	Vector3 tempVec3;
	tempVec3.x = vec3.x*multiplicant;
	tempVec3.y = vec3.y*multiplicant;
	tempVec3.z = vec3.z*multiplicant;
	return tempVec3;
}

Vector3 vec3Add(Vector3 vec3, Vector3 add){
	Vector3 temp;
	temp.x = vec3.x + add.x;
	temp.y = vec3.y + add.y;
	temp.z = vec3.z + add.z;
	return temp;
}

Vector3 vec3Sub(Vector3 vec3, Vector3 sub){
	Vector3 temp;
	temp.x = vec3.x-sub.x;
	temp.y = vec3.y-sub.y;
	temp.z = vec3.z-sub.z;
	return temp;
}

Vector3 vec3Max(Vector3 v1, Vector3 v2){
	Vector3 maxVector;
	maxVector.x = fmaxf(v1.x,v2.x);
	maxVector.y = fmaxf(v1.y,v2.y);
	maxVector.z = fmaxf(v1.z,v2.z);
	return maxVector;
}
Vector3 vec3Maxf(Vector3 v1, float compare){
	Vector3 maxVector;
	maxVector.x = fmaxf(v1.x,compare);
	maxVector.y = fmaxf(v1.y,compare);
	maxVector.z = fmaxf(v1.z,compare);
	return maxVector;

} 

Vector3 vec3Abs(Vector3 vec3){
	Vector3 temp;
	temp.x = abs(vec3.x);
	temp.y = abs(vec3.y);
	temp.z = abs(vec3.z);
	return temp;
}

float vec3Length(Vector3 vec3){
	return sqrt(vec3.x*vec3.x+vec3.y*vec3.y+vec3.z*vec3.z);
} 

//Distance estimator for sphere
float distanceEstimator(Vector3 p){
	return vec3Length(p)-40.0;	
}

float rayMarch(Vector3 from, Vector3 direction){
	float stepSize = 0.1;
	
	int i = 0;
	for(i = 0; i<MAX_ITERATIONS; i++){
		Vector3 p = vec3Add(from,vec3Mul(direction,i*stepSize));	//Vector for current position of ray
		float distance = distanceEstimator(p);
		if(abs(distance)<0.1){
			return 255.0-((float)i/(float)MAX_ITERATIONS)*255.0;	
		}	

	}	
	return 0;
}

//Creates header for PPM image file format
int createFileHeader(FILE *file, int width, int height){
	fprintf(file,"P3\n%d %d\n256\n",width,height);
	return 0;
}

int main(int argc, char* argv[]){
	FILE* file = fopen("test.ppm","wb");
	createFileHeader(file,400,400);
	
	Vector3 direction;
	direction = (Vector3){.x=0.0,.y=0.0,.z=1};
	Vector3 from;
	from = (Vector3){.x=0,.y=0,.z=-100};
	int x = 0;
	int y = 0;
	for(y = 0; y<400; y++){
		fprintf(file," ");
		for(x = 0; x<400; x++){	
			from.x = x-100;
			from.y = y-100;
			int value = (int)rayMarch(from,direction);
			fprintf(file,"%d %d %d ",value,value,value);	
		}
		fprintf(file,"\n");
	}
	fclose(file);
	return 0;
}
