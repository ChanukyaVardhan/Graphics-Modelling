#include<iostream>
#include<cmath>

using namespace std;

int main(){

double center_x=-1.0,center_y=-0.3,center_z=0.0,red=0.3,green=0.2,blue=0.5;

double r=0.05,theta=3;
red=0.5,green=0.5,blue=0.5;

for (int i = 0; i < 360; i+=theta)
{
	cout<<center_x+0.6<<","<<center_y+0.7<<","<<center_z-0.3<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+0.6+r*cos(i*M_PI/180)<<","<<center_y+0.7<<","<<center_z-0.3+r*sin(i*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+0.6+r*cos((i+theta)*M_PI/180)<<","<<center_y+0.7<<","<<center_z-0.3+r*sin((i+theta)*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;

	cout<<center_x+0.6<<","<<center_y+1.0<<","<<center_z-0.3<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+0.6+r*cos(i*M_PI/180)<<","<<center_y+1.0<<","<<center_z-0.3+r*sin(i*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+0.6+r*cos((i+theta)*M_PI/180)<<","<<center_y+1.0<<","<<center_z-0.3+r*sin((i+theta)*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;

	cout<<center_x+0.6+r*cos(i*M_PI/180)<<","<<center_y+0.7<<","<<center_z-0.3+r*sin(i*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+0.6+r*cos((i+theta)*M_PI/180)<<","<<center_y+0.7<<","<<center_z-0.3+r*sin((i+theta)*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+0.6+r*cos(i*M_PI/180)<<","<<center_y+1.0<<","<<center_z-0.3+r*sin(i*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;

	cout<<center_x+0.6+r*cos((i+theta)*M_PI/180)<<","<<center_y+0.7<<","<<center_z-0.3+r*sin((i+theta)*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+0.6+r*cos(i*M_PI/180)<<","<<center_y+1.0<<","<<center_z-0.3+r*sin(i*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+0.6+r*cos((i+theta)*M_PI/180)<<","<<center_y+1.0<<","<<center_z-0.3+r*sin((i+theta)*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;

}

for (int i = 0; i < 360; i+=theta)
{
	cout<<center_x+0.9<<","<<center_y+0.7<<","<<center_z-0.3<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+0.9+r*cos(i*M_PI/180)<<","<<center_y+0.7<<","<<center_z-0.3+r*sin(i*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+0.9+r*cos((i+theta)*M_PI/180)<<","<<center_y+0.7<<","<<center_z-0.3+r*sin((i+theta)*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;

	cout<<center_x+0.9<<","<<center_y+1.0<<","<<center_z-0.3<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+0.9+r*cos(i*M_PI/180)<<","<<center_y+1.0<<","<<center_z-0.3+r*sin(i*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+0.9+r*cos((i+theta)*M_PI/180)<<","<<center_y+1.0<<","<<center_z-0.3+r*sin((i+theta)*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;

	cout<<center_x+0.9+r*cos(i*M_PI/180)<<","<<center_y+0.7<<","<<center_z-0.3+r*sin(i*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+0.9+r*cos((i+theta)*M_PI/180)<<","<<center_y+0.7<<","<<center_z-0.3+r*sin((i+theta)*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+0.9+r*cos(i*M_PI/180)<<","<<center_y+1.0<<","<<center_z-0.3+r*sin(i*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;

	cout<<center_x+0.9+r*cos((i+theta)*M_PI/180)<<","<<center_y+0.7<<","<<center_z-0.3+r*sin((i+theta)*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+0.9+r*cos(i*M_PI/180)<<","<<center_y+1.0<<","<<center_z-0.3+r*sin(i*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+0.9+r*cos((i+theta)*M_PI/180)<<","<<center_y+1.0<<","<<center_z-0.3+r*sin((i+theta)*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;

}

for (int i = 0; i < 360; i+=theta)
{
	cout<<center_x+1.2<<","<<center_y+0.7<<","<<center_z-0.3<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+1.2+r*cos(i*M_PI/180)<<","<<center_y+0.7<<","<<center_z-0.3+r*sin(i*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+1.2+r*cos((i+theta)*M_PI/180)<<","<<center_y+0.7<<","<<center_z-0.3+r*sin((i+theta)*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;

	cout<<center_x+1.2<<","<<center_y+1.0<<","<<center_z-0.3<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+1.2+r*cos(i*M_PI/180)<<","<<center_y+1.0<<","<<center_z-0.3+r*sin(i*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+1.2+r*cos((i+theta)*M_PI/180)<<","<<center_y+1.0<<","<<center_z-0.3+r*sin((i+theta)*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;

	cout<<center_x+1.2+r*cos(i*M_PI/180)<<","<<center_y+0.7<<","<<center_z-0.3+r*sin(i*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+1.2+r*cos((i+theta)*M_PI/180)<<","<<center_y+0.7<<","<<center_z-0.3+r*sin((i+theta)*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+1.2+r*cos(i*M_PI/180)<<","<<center_y+1.0<<","<<center_z-0.3+r*sin(i*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;

	cout<<center_x+1.2+r*cos((i+theta)*M_PI/180)<<","<<center_y+0.7<<","<<center_z-0.3+r*sin((i+theta)*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+1.2+r*cos(i*M_PI/180)<<","<<center_y+1.0<<","<<center_z-0.3+r*sin(i*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;
	cout<<center_x+1.2+r*cos((i+theta)*M_PI/180)<<","<<center_y+1.0<<","<<center_z-0.3+r*sin((i+theta)*M_PI/180)<<","<<red<<","<<green<<","<<blue<<endl;

}
return 0;
}