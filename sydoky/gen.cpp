#include "gen.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
gen::gen()
{
}
class pole
{
int p[9][9];
public:
void in(int i,int j,int z){p[i][j]=z;}
int out(int i,int j){return p[i][j];}
};
pole g(int slognost)
{int r=60;pole pol;
    if(slognost==0){r=81-(30+rand()%5);};
    if(slognost==1){r=81-(25+rand()%5);};
    if(slognost==2){r=81-(20+rand()%5);};
    int i[9][9]={1,2,3,4,5,6,7,8,9,
               4,5,6,7,8,9,1,2,3,
               7,8,9,1,2,3,4,5,6,
               2,3,4,5,6,7,8,9,1,
               5,6,7,8,9,1,2,3,4,
               8,9,1,2,3,4,5,6,7,
               3,4,5,6,7,8,9,1,2,
               6,7,8,9,1,2,3,4,5,
               9,1,2,3,4,5,6,7,8
              };

int k11=rand() % 3;
int k12=rand() % 3;
int k21=rand() % 3;
int k22=rand() % 3;
for(int j=0;j<3;j++)
{for (int z=0;z<9;z++)
    {int k=i[j+k11*3][z];
     i[j+k11*3][z]=i[j+k12*3][z];
     i[j+k12*3][z]=k;};

};
for(int j=0;j<3;j++)
{for (int z=0;z<9;z++)
{int k=i[z][j+k21*3];
 i[z][j+k21*3]=i[z][j+k22*3];
 i[z][j+k22*3]=k;};
}
for(int j=0;j<3;j++)
{int k31=rand() % 3;
 int k32=rand() % 3;
    for (int z=0;z<9;z++)
{int k=i[z][j*3+k31];
 i[z][j*3+k31]=i[z][j*3+k32];
 i[z][j*3+k32]=k;};
}
for(int j=0;j<3;j++)
{int k31=rand() % 3;
 int k32=rand() % 3;
    for (int z=0;z<9;z++)
{int k=i[j*3+k31][z];
 i[j*3+k31][z]=i[j*3+k32][z];
 i[j*3+k32][z]=k;};
}
int e=0;
while(e<r)
{int u=rand()%81;
if(i[u/9][u%9]!=0)
{e++;
 i[u/9][u%9]=0;};
};
for(int j=0;j<9;j++)
{for(int z=0;z<9;z++)
    {pol.in(j,z,i[j][z]);}
}
    return pol;
}


bool check(pole pol)
{int i[9][9];
    for(int j=0;j<9;j++)
    {for(int z=0;z<9;z++)
        {i[j][z]=pol.out(j,z);}
    }

    for(int j=0;j<9;j++)
    {bool b[9]={0,0,0,0,0,0,0,0,0};
        for(int z=0;z<9;z++)
        {if(i[j][z]>0)
            {
             if(b[i[j][z]-1]>0)
               {b[i[j][z]-1]=1;}else{return 0;};
            }
            else{return 0;};
        }

    }
return 1;
}

