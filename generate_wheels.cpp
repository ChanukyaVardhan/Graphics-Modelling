#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double center_x=0.6,center_y=-0.3,center_z=0.0,r=0.25,theta=2,red=0.3,green=0.0,blue=0.0;

	for (int i = 0; i < 360; i+=theta)
	{
		cout<<center_x+0.3<<","<<center_y<<","<<center_z+0.05<<","<<0.5<<","<<0.5<<","<<0.5<<endl;
		cout<<center_x+0.3+r*cos(i*M_PI/180)<<","<<center_y+r*sin(i*M_PI/180)<<","<<center_z<<","<<0.2<<","<<0.2<<","<<0.2<<endl;
		cout<<center_x+0.3+r*cos((i+theta)*M_PI/180)<<","<<center_y+r*sin((i+theta)*M_PI/180)<<","<<center_z<<","<<0.2<<","<<0.2<<","<<0.2<<endl;
	}

	for (int i = 0; i < 360; i+=theta)
	{
		cout<<-center_x<<","<<center_y<<","<<center_z+0.05<<","<<0.5<<","<<0.5<<","<<0.5<<endl;
		cout<<-center_x+r*cos(i*M_PI/180)<<","<<center_y+r*sin(i*M_PI/180)<<","<<center_z<<","<<0.2<<","<<0.2<<","<<0.2<<endl;
		cout<<-center_x+r*cos((i+theta)*M_PI/180)<<","<<center_y+r*sin((i+theta)*M_PI/180)<<","<<center_z<<","<<0.2<<","<<0.2<<","<<0.2<<endl;
	}

	center_z=-1.5;

	for (int i = 0; i < 360; i+=theta)
	{
		cout<<center_x+0.3<<","<<center_y<<","<<center_z-0.05<<","<<0.5<<","<<0.5<<","<<0.5<<endl;
		cout<<center_x+0.3+r*cos(i*M_PI/180)<<","<<center_y+r*sin(i*M_PI/180)<<","<<center_z<<","<<0.2<<","<<0.2<<","<<0.2<<endl;
		cout<<center_x+0.3+r*cos((i+theta)*M_PI/180)<<","<<center_y+r*sin((i+theta)*M_PI/180)<<","<<center_z<<","<<0.2<<","<<0.2<<","<<0.2<<endl;
	}

	for (int i = 0; i < 360; i+=theta)
	{
		cout<<-center_x<<","<<center_y<<","<<center_z-0.05<<","<<0.5<<","<<0.5<<","<<0.5<<endl;
		cout<<-center_x+r*cos(i*M_PI/180)<<","<<center_y+r*sin(i*M_PI/180)<<","<<center_z<<","<<0.2<<","<<0.2<<","<<0.2<<endl;
		cout<<-center_x+r*cos((i+theta)*M_PI/180)<<","<<center_y+r*sin((i+theta)*M_PI/180)<<","<<center_z<<","<<0.2<<","<<0.2<<","<<0.2<<endl;
	}


	// windows
	// back window
	red = 0.5; green = 0.5; blue = 0.5;
	double x,y;
	x = -center_x+0.05; y = 0.17 + (5/3.0)*(x + 0.6)  + 0.001;
	cout<<x<<","<<y<<","<<z_1-0.05<<","<<red<<","<<green<<","<<blue<<endl;
	x = -center_x+0.3-0.05; y = 0.17 + (5/3.0)*(x + 0.6)  + 0.001;
	cout<<x<<","<<y<<","<<z_1-0.1-0.05<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<x<<","<<y<<","<<z_2+0.1+0.05<<","<<red<<","<<green<<","<<blue<<endl;

	x = -center_x+0.05; y = 0.17 + (5/3.0)*(x + 0.6)  + 0.001;
	cout<<x<<","<<y<<","<<z_1-0.05<<","<<red<<","<<green<<","<<blue<<endl;
	x = -center_x+0.3-0.05; y = 0.17 + (5/3.0)*(x + 0.6)  + 0.001;
	cout<<x<<","<<y<<","<<z_2+0.1+0.05<<","<<red<<","<<green<<","<<blue<<endl;
	x = -center_x+0.05; y = 0.17 + (5/3.0)*(x + 0.6)  + 0.001;
	cout<<x<<","<<y<<","<<z_2+0.05<<","<<red<<","<<green<<","<<blue<<endl;

	// front window
	x = center_x-r/2+0.3-0.3+0.05; y = 0.67 - (5/3.0)*(x - 0.475)  + 0.001;
	cout<<x<<","<<y<<","<<z_1-0.1-0.05<<","<<red<<","<<green<<","<<blue<<endl;
	x = center_x-r/2+0.3-0.05; y = 0.67 - (5/3.0)*(x - 0.475)  + 0.001;
	cout<<x<<","<<y<<","<<z_1-0.05<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<x<<","<<y<<","<<z_2+0.05<<","<<red<<","<<green<<","<<blue<<endl;

	x = center_x-r/2+0.3-0.3+0.05; y = 0.67 - (5/3.0)*(x - 0.475)  + 0.001;
	cout<<x<<","<<y<<","<<z_1-0.1-0.05<<","<<red<<","<<green<<","<<blue<<endl;
	x = center_x-r/2+0.3-0.05; y = 0.67 - (5/3.0)*(x - 0.475)  + 0.001;
	cout<<x<<","<<y<<","<<z_2+0.05<<","<<red<<","<<green<<","<<blue<<endl;
	x = center_x-r/2+0.3-0.3+0.05; y = 0.67 - (5/3.0)*(x - 0.475)  + 0.001;
	cout<<x<<","<<y<<","<<z_2+0.1+0.05<<","<<red<<","<<green<<","<<blue<<endl;


	// side glass
	// back side glass
	x = -center_x + 0.35; y = center_y+0.4+0.07+0.5 - 0.07;
	cout<<x<<","<<y<<","<<z_1-0.1+0.02<<","<<red<<","<<green<<","<<blue<<endl;
	x = 0.05;
	cout<<x<<","<<y<<","<<z_1-0.1+0.02<<","<<red<<","<<green<<","<<blue<<endl;
	y = center_y+0.4+0.07 + 0.07;
	cout<<x<<","<<y<<","<<z_1+0.001<<","<<red<<","<<green<<","<<blue<<endl;

	x = -center_x + 0.35; y = center_y+0.4+0.07+0.5 - 0.07;
	cout<<x<<","<<y<<","<<z_1-0.1+0.02<<","<<red<<","<<green<<","<<blue<<endl;
	x = 0.05; y = center_y+0.4+0.07 + 0.07;
	cout<<x<<","<<y<<","<<z_1+0.001<<","<<red<<","<<green<<","<<blue<<endl;
	x = -center_x + 0.35;
	cout<<x<<","<<y<<","<<z_1+0.001<<","<<red<<","<<green<<","<<blue<<endl;

	x = -center_x + 0.15; y = center_y+0.4+0.07 + 0.07;
	cout<<x<<","<<y<<","<<z_1+0.001<<","<<red<<","<<green<<","<<blue<<endl;
	x = -center_x + 0.35; y = center_y+0.4+0.07+0.5 - 0.07;
	cout<<x<<","<<y<<","<<z_1-0.1+0.02<<","<<red<<","<<green<<","<<blue<<endl;
	y = center_y+0.4+0.07 + 0.07;
	cout<<x<<","<<y<<","<<z_1+0.001<<","<<red<<","<<green<<","<<blue<<endl;

	x = -center_x + 0.35; y = center_y+0.4+0.07+0.5 - 0.07;
	cout<<x<<","<<y<<","<<z_2+0.1-0.02<<","<<red<<","<<green<<","<<blue<<endl;
	x = 0.05;
	cout<<x<<","<<y<<","<<z_2+0.1-0.02<<","<<red<<","<<green<<","<<blue<<endl;
	y = center_y+0.4+0.07 + 0.07;
	cout<<x<<","<<y<<","<<z_2-0.001<<","<<red<<","<<green<<","<<blue<<endl;

	x = -center_x + 0.35; y = center_y+0.4+0.07+0.5 - 0.07;
	cout<<x<<","<<y<<","<<z_2+0.1-0.02<<","<<red<<","<<green<<","<<blue<<endl;
	x = 0.05; y = center_y+0.4+0.07 + 0.07;
	cout<<x<<","<<y<<","<<z_2-0.001<<","<<red<<","<<green<<","<<blue<<endl;
	x = -center_x + 0.35;
	cout<<x<<","<<y<<","<<z_2-0.001<<","<<red<<","<<green<<","<<blue<<endl;

	x = -center_x + 0.15; y = center_y+0.4+0.07 + 0.07;
	cout<<x<<","<<y<<","<<z_2-0.001<<","<<red<<","<<green<<","<<blue<<endl;
	x = -center_x + 0.35; y = center_y+0.4+0.07+0.5 - 0.07;
	cout<<x<<","<<y<<","<<z_2+0.1-0.02<<","<<red<<","<<green<<","<<blue<<endl;
	y = center_y+0.4+0.07 + 0.07;
	cout<<x<<","<<y<<","<<z_2-0.001<<","<<red<<","<<green<<","<<blue<<endl;

	// front side glass
	x = 0.1; y = center_y+0.4+0.07+0.5 - 0.07;
	cout<<x<<","<<y<<","<<z_1-0.1+0.02<<","<<red<<","<<green<<","<<blue<<endl;
	x = 0.425;
	cout<<x<<","<<y<<","<<z_1-0.1+0.02<<","<<red<<","<<green<<","<<blue<<endl;
	y = center_y+0.4+0.07 + 0.07;
	cout<<x<<","<<y<<","<<z_1+0.001<<","<<red<<","<<green<<","<<blue<<endl;

	x = 0.1; y = center_y+0.4+0.07+0.5 - 0.07;
	cout<<x<<","<<y<<","<<z_1-0.1+0.02<<","<<red<<","<<green<<","<<blue<<endl;
	x = 0.425; y = center_y+0.4+0.07 + 0.07;
	cout<<x<<","<<y<<","<<z_1+0.001<<","<<red<<","<<green<<","<<blue<<endl;
	x = 0.1;
	cout<<x<<","<<y<<","<<z_1+0.001<<","<<red<<","<<green<<","<<blue<<endl;

	x = 0.425; y = center_y+0.4+0.07+0.5 - 0.07;
	cout<<x<<","<<y<<","<<z_1-0.1+0.02<<","<<red<<","<<green<<","<<blue<<endl;
	x = 0.625; y = center_y+0.4+0.07 + 0.07;
	cout<<x<<","<<y<<","<<z_1+0.001<<","<<red<<","<<green<<","<<blue<<endl;
	x = 0.425;
	cout<<x<<","<<y<<","<<z_1+0.001<<","<<red<<","<<green<<","<<blue<<endl;

	x = 0.1; y = center_y+0.4+0.07+0.5 - 0.07;
	cout<<x<<","<<y<<","<<z_2+0.1-0.02<<","<<red<<","<<green<<","<<blue<<endl;
	x = 0.425;
	cout<<x<<","<<y<<","<<z_2+0.1-0.02<<","<<red<<","<<green<<","<<blue<<endl;
	y = center_y+0.4+0.07 + 0.07;
	cout<<x<<","<<y<<","<<z_2-0.001<<","<<red<<","<<green<<","<<blue<<endl;

	x = 0.1; y = center_y+0.4+0.07+0.5 - 0.07;
	cout<<x<<","<<y<<","<<z_2+0.1-0.02<<","<<red<<","<<green<<","<<blue<<endl;
	x = 0.425; y = center_y+0.4+0.07 + 0.07;
	cout<<x<<","<<y<<","<<z_2-0.001<<","<<red<<","<<green<<","<<blue<<endl;
	x = 0.1;
	cout<<x<<","<<y<<","<<z_2-0.001<<","<<red<<","<<green<<","<<blue<<endl;

	x = 0.425; y = center_y+0.4+0.07+0.5 - 0.07;
	cout<<x<<","<<y<<","<<z_2+0.1-0.02<<","<<red<<","<<green<<","<<blue<<endl;
	x = 0.625; y = center_y+0.4+0.07 + 0.07;
	cout<<x<<","<<y<<","<<z_2-0.001<<","<<red<<","<<green<<","<<blue<<endl;
	x = 0.425;
	cout<<x<<","<<y<<","<<z_2-0.001<<","<<red<<","<<green<<","<<blue<<endl;


	// lights
	// front lights
	red = 0.69; green = 0.78; blue = 0.2;
	x = center_x+0.3+r+0.3+0.001; y = center_y+0.4-0.05;
	cout<<x<<","<<y<<","<<z_1-0.05-0.02<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<x<<","<<y<<","<<z_1-0.05-0.02-0.2<<","<<red<<","<<green<<","<<blue<<endl;
	y = center_y+0.2;
	cout<<x<<","<<y<<","<<z_1-0.05-0.02-0.2<<","<<red<<","<<green<<","<<blue<<endl;

	y = center_y+0.4-0.05;
	cout<<x<<","<<y<<","<<z_1-0.05-0.02<<","<<red<<","<<green<<","<<blue<<endl;
	y = center_y+0.2;
	cout<<x<<","<<y<<","<<z_1-0.05-0.02-0.2<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<x<<","<<y<<","<<z_1-0.05-0.02<<","<<red<<","<<green<<","<<blue<<endl;

	x = center_x+0.3+r+0.3+0.001; y = center_y+0.4-0.05;
	cout<<x<<","<<y<<","<<z_2+0.05+0.02<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<x<<","<<y<<","<<z_2+0.05+0.02+0.2<<","<<red<<","<<green<<","<<blue<<endl;
	y = center_y+0.2;
	cout<<x<<","<<y<<","<<z_2+0.05+0.02+0.2<<","<<red<<","<<green<<","<<blue<<endl;

	y = center_y+0.4-0.05;
	cout<<x<<","<<y<<","<<z_2+0.05+0.02<<","<<red<<","<<green<<","<<blue<<endl;
	y = center_y+0.2;
	cout<<x<<","<<y<<","<<z_2+0.05+0.02+0.2<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<x<<","<<y<<","<<z_2+0.05+0.02<<","<<red<<","<<green<<","<<blue<<endl;

	return 0;
}