#include <fstream>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
double a1, b1, c1, a, b;
int n,func_chose,type_input;




void start(){
		cout << "Chose the function for next working\n\
		1.y = a*x^3 + b*x + c\n\
		2.y = a *sin(x+b)+c\n\
		3.y=a/(x+b)+c\n " << endl;
}

double function(double x){
	double func_array[3] = {a1*pow(x,3)+b1*x+c1, a1*sin(x+b1)+c1, (a1/(x+b1))+c1};
	return func_array[func_chose];
}

double primitive_function(double x ){
	double func_array[3] = {(a1*pow(x,4))/4 +(b1*pow(x,2))/2+c1*x, -a1*cos(b1+x)+c1*x, a1*log(abs(b1+x))+c1*x};
}


double input_number(char prompt[], double lowest, double biggest) {
	double result;
	do {
    std::cout << prompt;
		std::cin >> result;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(100500, '\n');
      std::cout << "Bad number :(" << std::endl;
    } else if (!(result >= lowest && result <= biggest)) {
			std::cout << "Bad number :(" << std::endl;
		}
	} while (result < lowest or result > biggest);

	return result;
}


int main(){
	start();
	func_chose = (int)input_number("Input yor function\n",1,3);
	type_input = (int)input_number("1. keyboard input\n2. File input\n",1.0,2.0);
	a1 = input_number("Input A coefficient\n",-1000,1000);
	b1 = input_number("Input B coefficient\n",-1000,1000);
	c1 = input_number("Input C coefficient\n",-1000,1000);
	a = input_number("Low limit integration\n",-1000,1000);
	b = input_number("High limit integration\n",-1000,1000);
	n = (int)input_number("Separate interval\n",0,500);

	double sum = 0;
	double step = (b-a)/n;

	double Ig = 0;
	double h=(b-a)/n;
	double xi;
	double Ei;
	for (int i=1; i<=n-1; i++)
	{
	xi = a +i*h;
	Ei = ((b+a)/2)+((b-a)/2)*xi;
	Ig+=((b-a)/2)*function(Ei);
	}

	double Integral_of_gauss = Ig;
	cout<< "Приближённое значение интеграла: " << Integral_of_gauss  <<endl;

	double Integral_target=primitive_function(b)-primitive_function(a);
	cout<< "Точное значение интеграла: " << Integral_target <<endl;

	double absolute_error=(Integral_target - Integral_of_gauss)/Integral_target;
	cout<< "Абсолютная погрешность: " << absolute_error <<endl;

	double relative_error = (absolute_error/Integral_target);
	cout<< "Относительная погрешность: " << relative_error  <<endl;

	return 0;
}