#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>   
#include <dirent.h>  
#include <string.h>  
#include <stdio.h>
#define MAX 10000  

/*
4. Recursive Search: Write a program that prints out the names of each file and directory
in the file system tree, starting at a given point in the tree. For example, when run without
arguments, the program should start with the current working directory and print its
contents, as well as the contents of any sub-directories, etc., until the entire tree, root at
the CWD, is printed. If given a single argument (of a directory name), use that as the root
of the tree instead.
Useful interfaces: you figure it out. 
*/
void explore(char *name){
  DIR *direct;
  //init variables
  direct = opendir(name);
  struct stat dirstat;
  char directories[MAX];
  struct dirent *strdir;

  
  strdir = readdir(direct);
  //starting the while to check for files
  while (strdir != NULL){
    //this cmp is because i had an infinite loop while finding . and ..
    if (strcmp(strdir->d_name, ".") != 0 && strcmp(strdir->d_name, "..") != 0){ 
      printf("%s\n", strdir->d_name);
      stat(strdir->d_name,&dirstat);
      if (S_ISDIR(dirstat.st_mode)){
        strcpy(directories, name);
        strcat(directories, "/");
        strcat(directories, strdir->d_name);
        printf("%sdirect:\n", directories);
        explore(directories);
      }
    }
    strdir = readdir(direct); 
  }
  closedir(direct);
  printf("%s\n", name);
}

int main(int argc, char **argv){

  //char *getcwd(char *buffer, size_t size);
  DIR *direct;
  char *name;
  int count=0;

  if (argc > 1){
    name = argv[1];
  }  else {
    name = ".";
  }

  direct = opendir(name);
  struct stat dirstat;
  printf("Files: \n");
  
  char directories[MAX];
  struct dirent *strdir;

  
  strdir = readdir(direct);
  while (strdir != NULL){
    if (strcmp(strdir->d_name, ".") != 0 && strcmp(strdir->d_name, "..") != 0){ 
      printf("%s\n", strdir->d_name);
      stat(strdir->d_name,&dirstat);
      if (S_ISDIR(dirstat.st_mode)){
        strcpy(directories, name);
        strcat(directories, "/");
        strcat(directories, strdir->d_name);
        printf("%sdirect:\n", directories);
        explore(directories);
      }
    }
    strdir = readdir(direct); 
  }
  closedir(direct);
  printf("%s\n", name);

  // while (count > 0){
  //   opendir(directories[count]);
  //   strdir = readdir(direct);
  //   while (strdir != NULL){
  //     printf("%s\n", strdir->d_name);
  //     stat(strdir->d_name,&dirstat);
  //     if (S_ISDIR(dirstat.st_mode)){
  //       strcpy(directories[count-1], name);
  //       strcat(directories[count-1], "/");
  //       strcat(directories[count-1], strdir->d_name);
  //       count++;
  //     }
  //     strdir = readdir(direct);
  //   }
  //   closedir(direct);
  //   count--;
  // }
  

}
