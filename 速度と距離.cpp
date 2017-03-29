#include <iostream>
//設問（４）　速度
float velocity(float k,float v_0,float t) {
	//v = v0 + at
	float v = 0;
	v = v_0 + k * t;
	return v;
}
//設問（５）　距離　
float distance(float k,float v,float v_0,float t) {
	// x = v0t + 1/2 * a*t^2
	float x = 0;
	float v_0t = v_0 * t;
	float a = 0.5f * k;
	float t2 = t * t;
	x =  v_0t + a * t2;
	return x;
}

void main() {
	int birthday = 19960810;
	float v = 0;
	float v_0 = 1;
	float t = 3.2f;
	float x = 0;
	float k = static_cast<float>(birthday) / 10000000;

	v = velocity(k, v_0, t);
	std::cout << v << std::endl;

	x = distance(k, v, v_0, t);
	std::cout << x << std::endl;
}