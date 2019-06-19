#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>   
#include <dirent.h>  
#include <string.h>  
#include <stdio.h>

/*
2. List Files: Write a program that lists files in the given directory. When called without
any arguments, the program should just print the file names. When invoked with the -l
flag, the program should print out information about each file, such as the owner, group,
permissions, and other information obtained from the stat() system call. The program
should take one additional argument, which is the directory to read, e.g., myls -l
directory. If no directory is given, the program should just use the current working
directory.
Useful interfaces: stat(), opendir(), readdir(), getcwd(). 
*/
  


void printDetails(char *name){
  //func to print all details from specified place
  struct stat dirstat;
  stat(name,&dirstat);
  printf("File to be analyzed: %s\n", (name));
  printf("File Size: %lld\n",dirstat.st_size);
  printf("Number of blocks allocated: %lld\n",dirstat.st_blocks);
  printf("Reference link count: %d\n",dirstat.st_nlink);
  printf("File Permissions: ");
  if (S_ISDIR(dirstat.st_mode)){
    printf("Directory - ");
  }
  if (dirstat.st_mode & S_IRUSR){
    printf("read permission, owner - ");
  } 
  if (S_IWUSR & dirstat.st_mode){
    printf("write permission, owner - ");
  } 
  if (dirstat.st_mode & S_IXUSR){
    printf("execute/search permission, owner - ");
  } 
  if (dirstat.st_mode & S_IRGRP){
    printf("read permission, group - ");
  } 
  if (dirstat.st_mode & S_IWGRP){
    printf("write permission, group - ");
  } 
  if (dirstat.st_mode & S_IXGRP){
    printf("execute/search permission, group - ");
  } 
  if (dirstat.st_mode & S_IROTH){
    printf("read permission, others - ");
  } 
  if (dirstat.st_mode & S_IWOTH){
    printf("write permission, others - ");
  } 
  if (dirstat.st_mode & S_IXOTH){
    printf("execute/search permission, others - ");
  } 
  if (dirstat.st_mode & S_ISUID){
    printf("set-user-ID on execution - ");
  }
  if (dirstat.st_mode & S_ISGID){
    printf("set-group-ID on execution - ");
  } 
  if (dirstat.st_mode & S_ISVTX){
    printf("on directories, restricted deletion flag - ");
  } 
  printf("\nFile inode: %llu\n\n\n",dirstat.st_ino);
  //permissions were taken from man page
}
int main(int argc, char **argv){
//variable declarations
  DIR *direct;
  direct = opendir(".");

  if (argc > 1){
    if (strcmp(argv[1], "-l") != 0){
      direct = opendir(argv[1]);
    } else if (argc > 2){
      if (strcmp(argv[2], "-l") != 0){
        direct = opendir(argv[2]);
      } 
    }
  } 

  struct dirent *strdir;
  strdir = readdir(direct);
  // if (strcmp(argv[1], "-l")){
  //   printf("-%s-\n", argv[1]);
  // }
  while (strdir != NULL){
    // printf("%s\n", argv[1]);
    // printf("%d\n", strcmp(argv[1], "-l"));
    if (argc > 1){
      //checking if print detail needed
      if (strcmp(argv[1], "-l") == 0){
        printDetails(strdir->d_name);
      } else if (argc > 2){
        if (strcmp(argv[2], "-l") == 0){
          printDetails(strdir->d_name);
        }
      } else {
      printf("%s\n", strdir->d_name);
      }
    } else {
      printf("%s\n", strdir->d_name);
    }
    strdir = readdir(direct);
  }
  closedir(direct);
}
