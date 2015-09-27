//Homework 1, Problem 2
//Fit a Simple Linear Regression
//Liam Abbott, leabbott

#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char * argv[])
{
	double n = argc-1.0;
	double x_bar;
	double y_bar;
	double beta_one;
	double beta_one_num;
	double beta_one_den;
	double beta_zero;

	for (int i=1; i<argc; i++)
	{
		x_bar = x_bar + i;
		y_bar = y_bar + atof(argv[i]);
	}

	x_bar = x_bar/n;
	y_bar = y_bar/n;

	for (int j=1; j<argc; j++)
	{
		beta_one_num = beta_one_num + (j-x_bar)*(atof(argv[j])-y_bar);
		beta_one_den = beta_one_den + ((j-x_bar)*(j-x_bar));
	}

	beta_one = beta_one_num/beta_one_den;
	beta_zero = y_bar - (beta_one*x_bar);

	cout.precision(8);
	cout << beta_zero << " " << beta_one << endl;

	return 0;
}
