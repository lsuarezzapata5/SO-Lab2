//so;3,4;2

/* strtok example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="3.0;3,4;2-aaaaa";  //"so" "3,4" "2"
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str,"-;");
/*  while (pch != NULL)
  {
    printf ("%s\n",pch);
    strcpy(md , pch)
    
    sscanf(pch, "%f", )
    
    pch = strtok (NULL, "-;");
  }*/
  
  strcpy(md->nombre , pch);
  pch = strtok (NULL, "-;");
  md->nota = atof(pch);
  
  pch = strtok (NULL, "-;");
  md->cred = atoi(pch);
  
  return 0;
}

