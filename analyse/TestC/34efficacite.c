#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *fctRLE(char chaine[]) {

  // Afin de réaliser des tests, j'ai fait en sorte d'avoir un chronomètre dans mon programme. 
  // Sur VSCode, les "CLOCK_MONOTONIC" peuvent montrer des erreurs, 
  // mais lancer le programme fonctionne quand même et montre des temps qui semblent réalistes (plus rapide que Java).

  // struct timespec start_time, end_time;
  // long time_taken;

  // clock_gettime(CLOCK_MONOTONIC, &start_time);


  int len = strlen(chaine);
  if (len == 0) {
    return "";
  }

  char *result = malloc(sizeof(char) * len * 2 + 1);
  if (!result) {
    return NULL; 
  }
  result[0] = '\0';

  char tempoLettre = chaine[0];
  int tempoNb = 1;
  char *ptr = result;

  for (int i = 1; i < len; i++) {
    if (chaine[i] == tempoLettre && tempoNb < 9) {
      tempoNb++;
    } else {
      ptr+=sprintf(ptr, "%d%c", tempoNb, tempoLettre);
      tempoLettre = chaine[i];
      tempoNb = 1;
    }
  }
  ptr += sprintf(ptr, "%d%c", tempoNb, tempoLettre);

  result = realloc(result, ptr - result + 1);
  if (!result) {
    return NULL; 
  }

  
  // clock_gettime(CLOCK_MONOTONIC, &end_time);

  // time_taken = (end_time.tv_sec - start_time.tv_sec) * 1e9 + (end_time.tv_nsec - start_time.tv_nsec);
  // printf("Temps pris : %ld nanosecondes\n", time_taken);

  return result;
}


int main(void) {
  char *texte = "J'efffffectue un petit test afin de determiner la longueur d'un message d'exactement 100 caracteres.";

  char *compressed = fctRLE(texte);

  if (strlen(texte)>100){ // Si le texte est trop long, on affiche seulement les 100 premiers caractères
    
    printf("Pas compresse : ");
    for (int i = 0; i < 100; i++){
      printf("%c", texte[i]);
    }
    
    printf("\nCompresse : ");
    for (int i = 0; i < 100; i++){
      printf("%c", compressed[i]);
    }

  } else{
    printf("Pas compresse : %s\n",texte);
    printf("Compresse : %s\n",compressed);
  }


  // Afin de faire des tests sur des fichiers plus gros, j'ai fait en sorte de prendre des fichiers .txt
  // Si vous voulez faire la même chose, commentez le début, décommentez la suite, 
  // remplacez le chemin du fichier par un fichier texte rempli par vos soins. 

  // Le test sera fait plusieurs fois car l'ordinateur peut avoir fait des opérations d'autres programmes entre temps.

  // FILE *filePointer;
  // filePointer = fopen("sae2024-2-02-MaximePbn/src/main/ressource/long.txt", "r");
  // if (filePointer == NULL) {
  //   perror("Erreur d'ouverture de fichier");
  //   return 1;
  // }

  // fseek(filePointer, 0, SEEK_END);
  // const long fileSize = ftell(filePointer);

  // rewind(filePointer);

  // char *fileText = malloc(fileSize + 1);
  // fileText[0]='\0';

  // fread(fileText, 1, fileSize, filePointer);

  // fclose(filePointer);

  // fileText[fileSize] = '\0';

  // for(int i=0;i<15;i++){
  //   fctRLE(fileText);
  // }
}