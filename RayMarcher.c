#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Vector3.h"

//Distance estimator for sphere
float sphere(Vector3 p){
	return vec3Length(p)-40.0;	
}

float box(Vector3 p){
	Vector3 bounds;
	bounds = (Vector3){.x = 10,.y = 20,.z = 40};
	return vec3Length(vec3Maxf(vec3Sub(vec3Abs(p),bounds),0.0));
}

float rayMarch(Vector3 from, Vector3 direction, const int maxIterations){
	float stepSize = 0.1;
	
	int i = 0;
	for(i = 0; i<maxIterations; i++){
		Vector3 p = vec3Add(from,vec3Mul(direction,i*stepSize));	//Vector for current position of ray
		float distance = box(p);
		if(abs(distance)<0.1){
			return 255.0-((float)i/(float)maxIterations)*255.0;	
		}	

	}	
	return 0;
}