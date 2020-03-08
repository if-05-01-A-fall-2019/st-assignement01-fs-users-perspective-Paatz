#include <stdio.h>
#include <fcntl.h> 
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define COPYMODE 0644


int main (int argc, char const * argv[]){
	int source;
	int copy;
	
	source = open(argv[1], O_RDONLY);
	copy = open(argv[2], O_CREAT | O_WRONLY, COPYMODE);

	ssize_t in, out;
	char buffer[256];

	while((in = read(source,&buffer,256)) > 0){
		out= write(copy, &buffer, (ssize_t) in);
	}
	
	close(source);
	close(copy);
	return 0;
}
