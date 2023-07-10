#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

using namespace std;

#include "./soundSnake.class.h"

int main(int argc, char *argv[]){
	SoundSnake ss;
	if(!ss.initSimpleSpeaker(argv[0])){
		printf("FAiled to setup speaker.\n");
		return 1;
	}

	int fd = open("./test.wav", O_RDONLY);
	if(fd <= 0){
		printf("failed to open test file.\n");
		ss.freeDevice();
		return 1;
	}

	struct stat st;
	stat("./test.wav", &st);
	char *buff = (char *)malloc(st.st_size);

	printf("Buffer Size : %ld\n", (long)st.st_size);
	if(read(fd, buff, st.st_size) <= 0){
		printf("failed to read test file.\n");
		close(fd);
		ss.freeDevice();
		return 1;
	}else{
		close(fd);
	}

	printf("Trying to play audio...");
	if(!ss.playSimpleAudio(buff, (int)st.st_size)){
		printf("Failed.\n");
	}else{
		printf("Success\n");
	}

	ss.freeDevice();
	return 0;
}
