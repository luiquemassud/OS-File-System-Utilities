#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h> 
#include <stdio.h>        


// 1. Stat: Write your own version of the command line program stat, which simply calls
// the stat() system call on a given file or directory. Print out file size, number of blocks
// allocated, reference (link) count, file permissions, and file inode. 
  
//   struct stat {
//                dev_t     st_dev;         //* ID of device containing file 
//                ino_t     st_ino;         //* Inode number 
//                mode_t    st_mode;        //* File type and mode 
//                nlink_t   st_nlink;       //* Number of hard links 
//                uid_t     st_uid;         //* User ID of owner 
//                gid_t     st_gid;         //* Group ID of owner 
//                dev_t     st_rdev;        //* Device ID (if special file) 
//                off_t     st_size;        //* Total size, in bytes 
//                blksize_t st_blksize;     //* Block size for filesystem I/O 
//                blkcnt_t  st_blocks;      //* Number of 512B blocks allocated 


//int stat(const char *pathname, struct stat *statbuf);


int main(int argc, char **argv){

  struct stat dirstat;
  stat(argv[1],&dirstat);

  printf("File to be analyzed: %s\n", (argv[1]));
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
  printf("\nFile inode: %llu\n",dirstat.st_ino);

}
