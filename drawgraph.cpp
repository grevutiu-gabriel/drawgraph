#include <png++/png.hpp>
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;


 
int main(int nNumberofArgs, char *pszArgs[]) {
  const char *filename;
  filename=pszArgs[1];
  double xd,yd;
  double xshow,yshow;
  double numarx, numary;
  double rezultat;
  
  png::image< png::rgb_pixel > image(filename);
  cout<<"inaltimea imagini: "<<image.get_height()<<"\n";
  cout<<"lungimea imagini: "<<image.get_width()<<"\n";
  //for (size_t y = 0; y < image.get_height(); ++y) {
    //for (size_t x = 0; x < image.get_width(); ++x) {
  for (size_t y = 0; y < image.get_height(); ++y) {
	numary=0;	
	for (int i=0;i<10;++i) {
	numary+=0.1;
	yd=numary+y;
	yshow=round(yd);
	
    for (size_t x = 0; x < image.get_width(); ++x) {
	numarx=0;
	for (int i=0; i<10; ++i) {
		numarx+=0.1;
		xd=numarx+x;
		xshow=round(xd);
		
		//std::cout<<"Valoare lui x este: "<<xshow<<" Valoare lui y este: "<<yshow<<"\n";
		//std::cout<<"x : "<<xshow<<" y : "<<yshow<<"\n";

		//numar+=1;
  //if(((x*x*x-y)%60) <= 35) image[y][x] = png::rgb_pixel(0, numar, numar);
  //if(((x+y)%60) <= x+y) image[y][x] = png::rgb_pixel(0, 0, 0);
  //if (((x+y)%60) <= 35) image[y][x] = png::rgb_pixel(0, 255, 0);
  
  rezultat=xd*xd;
  //printf("valoarea xd este %.2lf; valoarea xd patrat este %.2lf; valoarea rotunjita xd patrat %.2lf; valoare yd %.2lf\n", xd, rezultat, round(yd));
  //printf("round of  %4.2lf is  %.2lf\n", rezultat, round(rezultat));
  //cout<<rezultat<<"\n";
  //if (yshow==round(rezultat)) image[yshow][xshow] = png::rgb_pixel(0, 255, 0);
  if (round(xd*xd)>=image.get_height()) return(0); //limiteaza valoarea produsului xd*xd la valoarea inaltimii imaginii 
  if (yshow==round(xd*xd)) {image[yshow][xshow] = png::rgb_pixel(0, 255, 0); printf("valoarea xd este %.2lf; valoarea xd patrat este %.2lf; valoarea rotunjita xd patrat %.2lf; valoare yd %.2lf; egal\n", xd, rezultat, round(rezultat), round(yd));}
  else printf("valoarea xd este %.2lf; valoarea xd patrat este %.2lf; valoarea rotunjita xd patrat %.2lf; valoare yd %.2lf; diferit\n", xd, rezultat, round(rezultat), round(yd));
  
  /*if (yshow==round(xd*xd)) {image[yshow][xshow] = png::rgb_pixel(0, 255, 0); cout<<"egal"<<"\n";}
  else cout<<"diferit"<<"\n";*/
		}
    }
   }
    
  }
 
 image.write(filename);
}
