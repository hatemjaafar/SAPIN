#include<stdio.h>

int    	nb_etoile(int size,int nb_ligne);
void	affiche(int nb,int nb_et,int nb_ligne);
void	affiche_espace(int k);
void	affiche_etoile(int l);
void	sapin (int size);
/*
**fonction de calcul de nombre d'etoile 
*/

int	nb_etoile(size,nb_ligne)
{
  int i;
  int j;
  int cpt_etoile;
  
  cpt_etoile=1;
  i=1;
  j=1;
  
  while (i<=size)
    {
      while(j<nb_ligne)
	{
	  cpt_etoile=cpt_etoile+2;
	  j=j+1;
	}
      j = 1;
      i=i+1;
      nb_ligne=nb_ligne+1;
      
      cpt_etoile=cpt_etoile-2*(i/2);	  
    }
  cpt_etoile=cpt_etoile+2*(i/2);
  return (cpt_etoile);
}
/*
**fonction affichage des esapces & etoiles du sapin
*/
void	 affiche (int size,int nb_et,int nb_ligne)
{
  int nb_esp;
  int cpt;
  int j;
  int i;
  
  nb_esp=(nb_et/2);
  cpt=0;
  j=0;
  i=1;
  nb_et=1;
  
  while (i<=size)
    {
      while(j<nb_ligne)
	{
	  cpt=nb_esp;
	  affiche_espace(cpt);
	  cpt=nb_et;
	  affiche_etoile(cpt);
	  j=j+1;
	  write(1,"\n",1);
	  nb_esp=nb_esp-1;
	  nb_et=nb_et+2;
	  
	}
      i=i+1;
      j=0;
      nb_ligne=nb_ligne+1;
      if (i<3)
	{
	  nb_esp=nb_esp+2;
	  nb_et=nb_et-4;
	}
      else 
	{
	  nb_esp=nb_esp+i/2+1;
	  nb_et=nb_et-2-2*(i/2);
	}   
    }	
}
/*
**fonction pour afficher les espaces 
*/
void	 affiche_espace(int k)
{
  while(k>0)
    {
      write(1," ",1);
      k=k-1;
    }
}

/*
**afficher le nombre de pipe
*/

void	 affiche_pipe(size,nb_et)
{
  int i;
  int j;
  int nb_pipe;
  
  i=0;
  j=0;
  nb_pipe=0;
  
  if (size%2==0)
    nb_pipe=size+1;
  else
    nb_pipe=size;
  while (i<size)
    {
      affiche_espace((nb_et/2)-size/2);
      while (j<nb_pipe)
	{
	  write(1,"|",1);
	  j=j+1;
	}
      j=0;
      i=i+1;
      write (1,"\n",1);
    }
}

void	 affiche_etoile(int l)
{
  while (l>0)
    {
      write(1,"*",1);
      l=l-1;
    }
}

void	 sapin (int size)
{
  int nb_et;
  int nb_ligne;
  
  nb_ligne=4;
  nb_et=nb_etoile(size,nb_ligne);
  affiche(size,nb_et,nb_ligne);
  affiche_pipe(size,nb_et);
}


int	main(int arc,char** arv)
{
  int size;
  int nb_et;
 
  if (arv[1])
    {  size=atoi(arv[1]);
      sapin (size);
    } 
  
  return 0;
}

