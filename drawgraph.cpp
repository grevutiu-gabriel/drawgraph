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
  double xd,yd,valorinegative, valoripozitive;
  double xshow,yshow,xplot,yplot,xplotvertical,yplotvertical,xplotorizontal,yplotorizontal;
  double numarx, numary;
  double rezultat, rotunjit, rotunjitnegativ, rotunjitpozitiv;
  int xvar=0,  valoarefatadereferinta, rezultatnegativ, rezultatpozitiv;
  
  png::image< png::rgb_pixel > image(filename);
  cout<<"inaltimea imagini: "<<image.get_height()<<"\n";
  cout<<"lungimea imagini: "<<image.get_width()<<"\n";
  //for (size_t y = 0; y < image.get_height(); ++y) {
    //for (size_t x = 0; x < image.get_width(); ++x) {
  /*for (size_t y = 0; y < image.get_height(); ++y) {
	numary=0;	
	for (int i=0;i<50;++i) {
	numary+=0.02;
	yd=numary+y;
	yshow=round(yd);*/
	
	
    for (size_t x = xvar; x < image.get_width(); ++x) {
	numarx=0;
	for (int i=0; i<100; ++i) {
		numarx+=0.01;
		xd=numarx+x;
		xshow=round(xd);
		//if (xshow<image.get_width()/2) {valorinegative=image.get_width()/2-xshow;cout<<"Valoarea negativa este: "<<valorinegative<<endl;}
		//if (xshow>image.get_width()/2) {valoripozitive=image.get_width()/2+xshow;cout<<"Valoarea pozitiva este: "<<valoripozitive<<endl;}
		valorinegative=image.get_width()/2-xd;
		valoripozitive=image.get_width()/2+xd;

		//valoarefatadereferinta=xshow-image.get_width()/2;
		
		//cout<<"Valoare lui x este: "<<xshow<<" Valoare lui y este: "<<yshow<<"\n";
		//cout<<"x : "<<xshow<<" y : "<<yshow<<"\n";

		//numar+=1;
  //if(((x*x*x-y)%60) <= 35) image[y][x] = png::rgb_pixel(0, numar, numar);
  //if(((x+y)%60) <= x+y) image[y][x] = png::rgb_pixel(0, 0, 0);
  //if (((x+y)%60) <= 35) image[y][x] = png::rgb_pixel(0, 255, 0);
  
  rezultat=xd*xd;
  rotunjit=round(rezultat);
  rezultatnegativ=xd*xd;
  rezultatpozitiv=xd*xd;
  rotunjitnegativ=767-round(rezultatnegativ)-image.get_height()/2;
  rotunjitpozitiv=767-round(rezultatpozitiv)-image.get_height()/2;
  //printf("valoarea xd este %.2lf; valoarea xd patrat este %.2lf; valoarea rotunjita xd patrat %.2lf; valoare yd %.2lf\n", xd, rezultat, round(yd));
  //printf("round of  %4.2lf is  %.2lf\n", rezultat, round(rezultat));
  //cout<<rezultat<<"\n";
  
  //if (sqrt(yd)-1>xd) xvar=round(sqrt(yd))-1;
  //if (sqrt(yd)<(xd-1) || round(xd*xd)>image.get_height()+1) break; //limiteaza valoarea produsului xd*xd la valoarea inaltimii imaginii 
  //if (sqrt(yd)<round(xd) || round(xd*xd)>=image.get_height()) break; //limiteaza valoarea produsului xd*xd la valoarea inaltimii imaginii
  //if (round(xd*xd)>=image.get_height()) break; //limiteaza valoarea produsului xd*xd la valoarea inaltimii imaginii 
  //if (yshow==rotunjit) image[(unsigned long)yshow][(unsigned long)xshow] = png::rgb_pixel(0, 255, 0);
  //if (rotunjit>image.get_height()) break; //limiteaza valoarea produsului xd*xd la valoarea inaltimii imaginii
  //xplotorizontal=(image.get_width()/2+xshow && image.get_width()/2-xshow);
  xplotvertical=image.get_width()/2;//deseneaza linie orizontala
  yplotvertical=rotunjit;
  xplotorizontal=xshow;//deseneaza linie orizontala
  yplotorizontal=image.get_height()/2;//deseneaza linie orizontala
  
 if (1)/*xshow < image.get_width()*/
  {	
	image[yplotorizontal][xplotorizontal] = png::rgb_pixel(255, 255, 255);
	if (rotunjitnegativ < 768 && rotunjitnegativ>=0) image[rotunjitnegativ][(int)valorinegative]=png::rgb_pixel(255, 0, 0);
	if (rotunjitpozitiv < 768 && rotunjitnegativ>=0) image[rotunjitpozitiv][(int)valoripozitive]=png::rgb_pixel(255, 0, 0);
  }	
  else continue;

  if (xshow < image.get_height()) 
  {
	image[xshow][xplotvertical] = png::rgb_pixel(255, 255, 255);
  }
  else continue;
	//image[yplot][xplot] = png::rgb_pixel(0, 255, 0);
 
  //if (yplot < image.get_height())
//{image[yplot][xplot] = png::rgb_pixel(0, 255, 0); printf("valoarea xd este %.2lf; valoarea xd patrat este %.2lf; valoarea rotunjita xd patrat %.2lf; valoare yd %.2lf\n", xshow, rezultat, rotunjit, round(yd));}
 // else break;
 
 //if (yshow==rotunjit && yplot < image.get_height())
//{image[yplot][xplot] = png::rgb_pixel(0, 255, 0); printf("valoarea xd este %.2lf; valoarea xd patrat este %.2lf; valoarea rotunjita xd patrat %.2lf; valoare yd %.2lf; egal\n", xshow, rezultat, rotunjit, round(yd));}
  //else printf("valoarea xd este %.2lf; valoarea xd patrat este %.2lf; valoarea rotunjita xd patrat %.2lf; valoare yd %.2lf; diferit\n", xshow, rezultat, rotunjit, round(yd));
  
  /*if (yshow==round(xd*xd)) {image[yshow][xshow] = png::rgb_pixel(0, 255, 0); cout<<"egal"<<"\n";}
  else cout<<"diferit"<<"\n";*/
		}
    }
  // }
    
  //}
 
 image.write(filename);
}
