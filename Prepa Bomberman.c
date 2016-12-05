#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#define arriba 72
#define abajo 80 
#define derecha 77
#define izquierda 75

struct bomba{
	int px,py,act;
	int cont;
};

struct jugador{
	int px,py,vida,gano;
	struct bomba bomb;
};

void llenar(int m[11][11])
{
	int i,j;
	
	for(i=0;i<11;i++)
	{
		for(j=0;j<11;j++)
		{
			if(i==0||j==0||j==10||i==10)
			{
				m[i][j]=219;
			}
			else
			{
				if(i%2==0&&j%2==0)
				{
					m[i][j]=219;
				}
				else
				{
					m[i][j]=32;
				}
			}
		}
	}
}

void imprimir(int m[11][11])
{
	int i,j;
	
	for(i=0;i<11;i++)
	{
		printf("\n");
		for(j=0;j<11;j++)
		{
			printf("%c",m[i][j]);
		}
	}
}

void ponercaja(int m[11][11])
{
	int x,i,j,rep;
	
	for(x=0;x<50;x++)
	{
		do
		{
			rep=0;
			i=rand()%9+1;
			j=rand()%9+1;
			if(j==1&&i<3)
			{
				rep=1;
			}
			if(i==1&&j<3)
			{
				rep=1;
			}
			if(j==9&&i>7)
			{
				rep=1;
			}
			if(i==9&&j>7)
			{
				rep=1;
			}
			if(m[i][j]!=32)
			{
				rep=1;
			}
			
		}while(rep==1);
		m[i][j]=4;
	}
}

void jugar(int m[11][11],int *ganar)
{
	struct jugador j1,j2;
	char tecla=0;	
	
	j1.px=1; j1.py=1;
	j1.vida=3; j1.gano=0;
	j1.bomb.act=0;
	
	j2.px=9; j2.py=9;
	j2.vida=3; j2.gano=0;
	j2.bomb.act=0;
	
	m[j1.px][j1.py]=32;
	m[j2.px][j2.py]=32;
	
	while(tecla!='X')
	{
		if(kbhit())
		{
			tecla=toupper(getch());
		}
		m[j1.px][j1.py]=32;
		m[j2.px][j2.py]=32;
		
		if(tecla==arriba)
		{
			if(m[j1.px-1][j1.py]==32)
			{
				j1.px--;
			}
		}
		if(tecla==abajo)
		{
			if(m[j1.px+1][j1.py]==32)
			{
				j1.px++;
			}
		}
		if(tecla==derecha)
		{
			if(m[j1.px][j1.py+1]==32)
			{
				j1.py++;
			}
		}
		if(tecla==izquierda)
		{
			if(m[j1.px][j1.py-1]==32)
			{
				j1.py--;
			}
		}
		if(tecla=='W')
		{
			if(m[j2.px-1][j2.py]==32)
			{
				j2.px--;
			}
		}
		if(tecla=='S')
		{
			if(m[j2.px+1][j2.py]==32)
			{
				j2.px++;
			}
		}
		if(tecla=='D')
		{
			if(m[j2.px][j2.py+1]==32)
			{
				j2.py++;
			}
		}
		if(tecla=='A')
		{
			if(m[j2.px][j2.py-1]==32)
			{
				j2.py--;
			}
		}
		m[j1.px][j1.py]=1;
		m[j2.px][j2.py]=2;
		
		if(tecla==48)
		{
			if(j1.bomb.act==0)
			{
				j1.bomb.act=1;
				j1.bomb.px=j1.px;
				j1.bomb.py=j1.py;
				j1.bomb.cont=0;
			}
		}
		if(tecla==32)
		{
			if(j2.bomb.act==0)
			{
				j2.bomb.act=1;
				j2.bomb.px=j2.px;
				j2.bomb.py=j2.py;
				j2.bomb.cont=0;
			}
		}
		
		if(j1.bomb.act==1)
		{
			j1.bomb.cont++;
			if(j1.bomb.cont==30)
			{
				j1.bomb.act=0;
				m[j1.bomb.px][j1.bomb.py]=32;
				if(m[j1.bomb.px-1][j1.bomb.py]!=219) m[j1.bomb.px-1][j1.bomb.py]=32;
				if(m[j1.bomb.px+1][j1.bomb.py]!=219) m[j1.bomb.px+1][j1.bomb.py]=32;
				if(m[j1.bomb.px][j1.bomb.py-1]!=219) m[j1.bomb.px][j1.bomb.py-1]=32;
				if(m[j1.bomb.px][j1.bomb.py+1]!=219) m[j1.bomb.px][j1.bomb.py+1]=32;
			
		
		if(j1.bomb.px==j1.px)
		{
			if(j1.bomb.py==j1.py||j1.bomb.py-1==j1.px||j1.bomb.px+1==j1.px)
			{
				j1.vida--;
			}
		}
		else
		{
			if(j1.bomb.py==j1.py)
			{
				if(j1.bomb.px-1==j1.px||j1.bomb.px+1==j1.px)
				{
					j1.vida--;
				}
			}
		}
		
		if(j1.bomb.px==j2.px)
		{
			if(j1.bomb.py==j2.py||j1.bomb.py-1==j2.px||j1.bomb.px+1==j2.px)
			{
				j2.vida--;
			}
		}
		else
		{
			if(j1.bomb.py==j2.py)
			{
				if(j2.bomb.px-1==j2.px||j1.bomb.px+1==j2.px)
				{
					j2.vida--;
				}
			}
		}
		}
		}
		
		if(j2.bomb.act==1)
		{
			j2.bomb.cont++;
			if(j2.bomb.cont==30)
			{
				j2.bomb.act=0;
				m[j2.bomb.px][j2.bomb.py]=32;
				if(m[j2.bomb.px-1][j2.bomb.py]!=219) m[j2.bomb.px-1][j2.bomb.py]=32;
				if(m[j2.bomb.px+1][j2.bomb.py]!=219) m[j2.bomb.px+1][j2.bomb.py]=32;
				if(m[j2.bomb.px][j2.bomb.py-1]!=219) m[j2.bomb.px][j2.bomb.py-1]=32;
				if(m[j2.bomb.px][j2.bomb.py+1]!=219) m[j2.bomb.px][j2.bomb.py+1]=32;
			
		
		if(j2.bomb.px==j2.px)
		{
			if(j2.bomb.py==j2.py||j2.bomb.py-1==j2.px||j2.bomb.px+1==j2.px)
			{
				j2.vida--;
			}
		}
		else
		{
			if(j2.bomb.py==j2.py)
			{
				if(j2.bomb.px-1==j2.px||j2.bomb.px+1==j2.px)
				{
					j2.vida--;
				}
			}
		}
		
		if(j2.bomb.px==j1.px)
		{
			if(j2.bomb.py==j1.py||j2.bomb.py-1==j1.px||j2.bomb.px+1==j1.px)
			{
				j1.vida--;
			}
		}
		else
		{
			if(j2.bomb.py==j1.py)
			{
				if(j2.bomb.px-1==j1.px||j2.bomb.px+1==j1.px)
				{
					j1.vida--;
				}
			}
		}
		}
		}
		if(j1.vida==0)
		{
			*ganar=2;
			return;
		}
		if(j2.vida==0)
		{
			*ganar=1;
			return;
		}
		if(j1.bomb.act==1)
		{
			m[j1.bomb.px][j1.bomb.py]=3;
		}
		if(j2.bomb.act==1)
		{
			m[j2.bomb.px][j2.bomb.py]=3;
		}
		system("cls");
		imprimir(m);
		Sleep(100);
		tecla=0;
	}
}

int main()
{
	int m[11][11],ganar;
	
	srand(time(0));
	llenar(m);
	ponercaja(m);
	jugar(m,&ganar);
	imprimir(m);
}
