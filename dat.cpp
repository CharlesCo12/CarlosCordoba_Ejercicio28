#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void lineal(int nmax, float delta_x,float delta_t, string filename);

int main(){
    lineal(201,0.01,0.5,"datos.dat");
    return 0;
}

void lineal(int nmax, float delta_x, float delta_t, string filename){  
  double x=0;
  double n=(delta_t*200)/(delta_x*delta_x*900*2700);  
  ofstream outfile;
  outfile.open(filename);
  float T[nmax][nmax]={0};
    
  for(int i=0;i<nmax;i++){
      for(int j=0;j<nmax;j++){          
          T[i][j]=300;
      }
  }  
    
  for(int i=80;i<=120;i++){
      T[i][0]=500;
  }
    
  for(int j=0;j<nmax-1;j++)
    {
      for(int i=1;i<nmax-1;i++)
      {
          T[i][j+1]=T[i][j]+n*(T[i+1][j]+T[i-1][j]-2*T[i][j]);
      }      
    }
    
  for(int j=0;j<nmax;j++)
  {
      for(int i=0;i<nmax;i++)
      {
          outfile << T[i][j] << " ";
          if(i==nmax-1){outfile<<endl;}
      } 
  }  
  outfile.close();
}