#include<iostream>
#define _USE_MATH_DEFINES
#include<cmath>
#include <vector>
#include<cstdlib>
#include<fstream>
#include <bits/stdc++.h>
double f(double,double);	// to mono pou allazo einai h sinartisi
void rungekutta(std::vector<double>&,std::vector<double>&,double,int);
int main()
{
	std::vector<double>x;
	std::vector<double>y;
	double low,up;
	std::cout<<"Enter limits"<<std::endl;
	std::cin>>low;
	std::cin>>up;
	double h;
	std::cout<<"Enter h"<<std::endl;
	std::cin>>h;
	std::cout<<"Enter initial conditions:"<<std::endl;
	std::cout<<"Enter x0"<<std::endl;
	double x0,y0;
	std::cin>>x0;
	std::cout<<"Enter y0"<<std::endl;
	std::cin>>y0;
	x.push_back(x0);
	y.push_back(y0);		//arxiki sinthiki y(0)=1
	std::cout<<"x0= "<<x[0]<<"\n"<<"y0= "<<y[0]<<std::endl;
	int n; // n einai oi upodiaireseis
	n=1.0*(up-low)/h;
	rungekutta(x,y,h,n);
	std::cout<<"the size of array x is = "<<x.size()<<std::endl;
	std::cout<<"the size of array y is = "<<y.size()<<std::endl;
	int i;
	std::ofstream myfile("askrungeutta.dat");
	for(i=0;i<x.size();i++)
	{
		std::cout<<"x"<<i<<"= "<<x[i]<<"\n"<<"y"<<i<<"= "<<y[i]<<std::endl;
		myfile<<x[i]<<"\t"<<y[i]<<std::endl;
	}
	std::cin.get();
}
double f(double a,double b)
{
	return (a-exp(a))/(b+exp(b));
}
void rungekutta(std::vector<double>& x,std::vector<double>& y,double h,int n)
{
	int i;
	double k1,k2,k3,k4,tmp;
	for(i=0;i<n;i++)
	{
		k1=h*f(x[i],y[i]);
		k2=h*f(x[i]+h/2,y[i]+k1/2);
		k3=h*f(x[i]+h/2,y[i]+k2/2);
		k4=h*f(x[i]+h,y[i]+k3);	
		x.push_back(x[i]+h);
		tmp=y[i]+(1.0/6)*(k1+2*k2+2*k3+k4);
		y.push_back(tmp);		
		//std::cout<<"epanalipsi"<<i<<"\n"<<"k1="<<k1<<"\n"<<"k2="<<k2<<"\n"<<"k3="<<k3<<"\n"<<"k4="<<k4<<std::endl;
	}
}
