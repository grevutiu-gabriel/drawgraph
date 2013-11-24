#include <png++/png.hpp>
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <math.h>


 
int main(int nNumberofArgs, char *pszArgs[]) {
  const char *filename;
  filename=pszArgs[1];
  double xd,yd;
  double xshow,yshow;
  double numarx, numary;
  double rezultat;
  
  png::image< png::rgb_pixel > image(filename);
  std::cout<<"inaltimea imagini: "<<image.get_height()<<"\n";
  std::cout<<"lungimea imagini: "<<image.get_width()<<"\n";
  //for (size_t y = 0; y < image.get_height(); ++y) {
    //for (size_t x = 0; x < image.get_width(); ++x) {
  for (size_t y = 0; y < image.get_height(); ++y) {
	numary=0;	
	for (int i=0;i<5;++i) {	
	yd=numary+y;
	yshow=round(yd);
	}
    for (size_t x = 0; x < image.get_width(); ++x) {
	numarx=0;
	for (int i=0; i<5; ++i) {
		numarx+=0.2;
		xd=numarx+x;
		xshow=round(xd);
		
		//std::cout<<"Valoare lui x este: "<<xshow<<" Valoare lui y este: "<<yshow<<"\n";
		//std::cout<<"x : "<<xshow<<" y : "<<yshow<<"\n";

		//numar+=1;
  //if(((x*x*x-y)%60) <= 35) image[y][x] = png::rgb_pixel(0, numar, numar);
  //if(((x+y)%60) <= x+y) image[y][x] = png::rgb_pixel(0, 0, 0);
  //if (((x+y)%60) <= 35) image[y][x] = png::rgb_pixel(0, 255, 0);
  //if (yshow==round(xd*xd)) {image[yshow][xshow] = png::rgb_pixel(0, 255, 0); std::cout<<"egal"<<"\n";}
  
  //else std::cout<<"neegal"<<"\n";
  rezultat=xd*xd;
  printf("valoare xd este %.2lf\n", xd);
  printf("round of  %4.2lf is  %.2lf\n", rezultat, round(rezultat));
  //std::cout<<rezultat<<"\n";
  if (yshow==rezultat) image[yshow][xshow] = png::rgb_pixel(0, 255, 0);
		}
    }
    
  }
 
 image.write(filename);
}
