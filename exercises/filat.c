#include <stdio.h>
#include <fcntl.h> 
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char checkType(struct stat attributes);
int main(int argc, char const *argv[]) {
  struct stat attributes;
  int s = lstat(argv[1], &attributes);
    printf("File Type         | %d\n", checkType(attributes));
    printf("Access privileges | %hu\n", attributes.st_mode); //%hu short int
    printf("inode-Number      | %llu\n", attributes.st_ino); //unsigned long int
    printf("Device numbers    | %d\n", attributes.st_dev);
    printf("Links count       | %hu\n", attributes.st_nlink); //unsigned
    printf("UID               | %u\n", attributes.st_uid);
    printf("GID               | %u\n", attributes.st_gid);
    printf("File size         | %lld\n", attributes.st_size); //long long int
    printf("Last access       | %ld\n", attributes.st_atime); //decimal
    printf("Last modification | %ld\n", attributes.st_mtime);
    printf("Last inode change | %ld\n", attributes.st_ctime);
  return 0;
}
char checkType(struct stat attributes){
  if (attributes.st_mode & S_IFREG) {
    return '-';
  }
  else if (attributes.st_mode & S_IFDIR) {
    return 'd';
  }
  else if (attributes.st_mode & S_IFCHR) {
    return 'c';
  }
  else if (attributes.st_mode & S_IFBLK) {
    return 'b';
  }
  else if (attributes.st_mode & S_IFSOCK) {
    return 's';
  }
  return ' ';
}
