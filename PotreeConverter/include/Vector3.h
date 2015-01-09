
#ifndef VECTOR3_H
#define VECTOR3_H

#include <math.h>
#include <iostream>

using std::ostream;
using std::max;

template<class T>
class Vector3{

public:
	T x,y,z;

	Vector3(){
		x = 0;
		y = 0;
		z = 0;
	}

	Vector3(T x, T y, T z){
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3(T value){
		this->x = value;
		this->y = value;
		this->z = value;
	}

	Vector3(const Vector3<T> &other)
		:x(other.x), y(other.y), z(other.z)
	{

	}

	~Vector3(){

	}

	T length(){
		return sqrt(x*x + y*y + z*z);
	}

	T squaredLength(){
		return x*x + y*y + z*z;
	}

	T distanceTo(Vector3<T> p){
		return ((*this) - p).length();
	}

	T squaredDistanceTo(Vector3<T> p){
		return ((*this) - p).squaredLength();
	}

	T maxValue(){
		return max(x, max(y,z));
	}

	Vector3<T> operator-(const Vector3<T>& right) const {
		return Vector3<T>(x - right.x, y - right.y, z - right.z);
	}

	Vector3<T> operator+(const Vector3<T>& right) const {
		return Vector3<T>(x + right.x, y + right.y, z + right.z);
	}

	Vector3<T> operator*(const T &a) const{
		return Vector3<T>(x * a, y * a, z * a);
	}

	Vector3<T> operator/(const T &a) const{
		return Vector3<T>(x / a, y / a, z / a);
	}

	Vector3<T> operator/(const Vector3<T> &a) const{
		return Vector3<T>(x / a.x, y / a.y, z / a.z);
	}

	friend ostream &operator<<( ostream &output,  const Vector3<T> &value ){ 
		output << "[" << value.x << ", " << value.y << ", " << value.z << "]" ;
		return output;            
	}
};

#endif