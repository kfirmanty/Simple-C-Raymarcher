#ifndef VECTOR3 
#define VECTOR3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

#endif