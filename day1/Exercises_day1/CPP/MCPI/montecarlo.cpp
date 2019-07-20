#include <iostream>
#include <cmath>
#include <stdio.h>
#include <random>

using namespace std;


int circle (double x, double y)
{
	int r = (x*x + y*y <=1)*1;
	return r;
}

int main ()
{
	using namespace std;
  	const int nrolls=1000;  // number of experiments
  	
	//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	//std::default_random_engine generator (seed);
	//
	//uniform_real_distribution<double> distribution (-1.0,1.0)
	
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(-1.0,1.0);

  	double x=0;
	double y=0;
	double sum =0;

  	for (int i=0; i<nrolls; ++i) {
		x = distribution(generator);
    		y = distribution(generator);
		int g = circle (x,y);
		cout << "x is " << x << "y is " << y << "g is "<< g << endl;
		sum = sum + g;
		cout << "sum " << sum << endl;
	}
	cout << "Pi is approximately: " <<  sum/nrolls*4 << endl;
	return  sum/nrolls*4;
}
	 

