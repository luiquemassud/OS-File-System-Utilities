#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>   
#include <dirent.h>  
#include <string.h>    
#include <stdlib.h>
#include <stdio.h>

/*
3. Tail: Write a program that prints out the last few lines of a file. The program should be
efficient, in that it seeks to near the end of the file, reads in a block of data, and then goes
backwards until it finds the requested number of lines; at this point, it should print out
those lines from beginning to the end of the file. To invoke the program, one should type:
mytail -n file, where n is the number of lines at the end of the file to print.
Useful interfaces: stat(), lseek(), open(), read(), close(). 
*/
  

int main(int argc, char **argv){

  //char *getcwd(char *buffer, size_t size);
  DIR *direct;
  direct = opendir(".");
  int n = 0, lines = 0, i;
  FILE *file;

  char c, *name;
  

  //check if we have a - in the 1st or second argv
  if (argc > 1){
    if (argv[1][0] == '-'){
      char *str;
      str = argv[1];
      str++;
      n = atoi(str);
    } else {
      name = argv[1];
      file = fopen(argv[1],"r");
    }
    if (argc > 2){
      if (argv[2][0] == '-'){
        char *str;
        str = argv[2];
        str++;
        n = atoi(str);
      } else {
        name = argv[2];
        file = fopen(argv[2],"r");
      }
    }
  } 
  //iter through file to count lines
  while (!feof(file)){
    c = fgetc(file);
    if(c == '\n'){
      lines++; 
    }
  }
  // printf("%d\n", lines);
  fclose(file);
  file = fopen(name, "r");

  i=0;
  //iter to get to the part where we need to print
// printf("%d\n", lines-n);
  while (i < lines-n){
    c = fgetc(file);
    if(c == '\n'){
      i++;
    }
  }
  //prints until file is over
  while (1==1){
    c = fgetc(file);
    if (!feof(file)){
      printf("%c", c);  
    } else {
      break;
    } 
  }
  printf("\n");
  fclose(file);
}
