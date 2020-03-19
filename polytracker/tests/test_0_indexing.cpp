#include <fcntl.h> 
#include <stdio.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h> 

int main() {
	int fd = open("./test_data.txt", O_RDONLY);
	if (fd == -1) {
		printf("Could not open file!\n"); 
	}	
	else {
		printf("Opened file!\n"); 
		char buff[2048];
		//Read first byte, this should ALWAYS be instrumented by normal dfsan
		int bytes_read = read(fd, buff, 1); 
		char a = buff[0]; 
		//make new label some how 
		a = a + 1;
		close(fd); 
	}
	
	return 0;
}
