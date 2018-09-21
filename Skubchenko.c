#include <stdio.h> 
#include <math.h> 

float h,m,g,R; 

void f0(float *Q,float *N,float *xn,float *yn,float *un,float *vn) 
{ 
	float xold,yold;
*Q=m*(g*(*yn)-(*un)*(*un)-(*vn)*(*vn))/R;
if ((*Q)>=0) *N=*Q; else *N = 0;
xold=*xn;
yold=*yn;
*xn=xold+h*(*un); 
*yn=yold+h*(*vn); 
*un=*un+h*(*N*xold/R);
*vn=*vn+h*(*N*yold/R-m*g);
return; 
} 

int main(void) 
{ 
float Q,N,xn=0.173648178f,yn=0.984807753f,un=0.098480775f,vn=-0.017364818f;
FILE*f; 
int i; 
float ti, te, tend=10.0f, dt=1.0f; 

char fs[] = "%e %e %e %e\n"; 
char fs1[] = "%e\t %e\t %e\n"; 

f = fopen("C:\\Users\\Viktor\\Documents\\Visual Studio 2012\\Projects\\Скубченко 3 этап\\params.txt", "r"); 
i = fscanf(f, "%f", &h); while(fgetc(f) != '\n'); 
i = fscanf(f, "%f", &m); while(fgetc(f) != '\n'); 
i = fscanf(f, "%f", &g); while(fgetc(f) != '\n'); 
i = fscanf(f, "%f", &R);
fclose(f); 

f=fopen("solution.txt", "w"); 
ti = 0.0f; 
i = fprintf(f, fs, ti, xn, yn); 

while(ti < tend) 
{ 
te = ti + dt; 
while(ti < te) 
{ 
ti = ti + h; 
f0(&Q, &N, &xn, &yn, &un, &vn); 
i = fprintf(f, fs1, ti, xn, yn); 
} 
} 
fclose(f); 
}
