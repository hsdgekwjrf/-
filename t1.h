#include <iostream>
#include <cmath>
#include <random>
#include <ctime>

struct model{
	const double SELU(double x){
		double a = 1.050700987;
		double b = 1.673263242;
		if(x>0){
			return a*x;
		}
		else{
			return a*b*(std::exp(x)-1.0);
		}
	}
	
	double *i[10];
	double f[10] = {0,0,0,0,0,0,0,0,0,0};
	double *o;
	double fo = 0;
	void init(){
		std::random_device seed;
		std::mt19937 gen(seed());
		std::uniform_real_distribution<double> f_random(0.0,1.0);
		f[1] = f_random(gen);
		f[2] = f_random(gen);
		f[3] = f_random(gen);
		f[4] = f_random(gen);
		f[5] = f_random(gen);
		f[6] = f_random(gen);
		f[7] = f_random(gen);
		f[8] = f_random(gen);
		f[9] = f_random(gen);
		fo = f_random(gen);
	}
	void r1(){
		*o = SELU(fo + *i[1] * f[1] + *i[2] * f[2] + *i[3] * f[3] + *i[4] * f[4] + *i[5] * f[5] + *i[6] * f[6] + *i[7] * f[7] + *i[8] * f[8] + *i[9] * f[9]);
	}
	void set_f_i(double n,int num){
		f[num] = n;
	}
	void set_i(double *n,int num){
		i[num] = n;
	}
	void set_f(double n){
		fo = n;
	}
	void set_o(double *n){
		o = n;
	}
};
