#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int is_background(char input[500], int strlen){
	int i;
	int ans = -1; // if there is no & sign at the end
	for(i = strlen - 1; i >= 0; i--){
		if(input[i] == '&'){
			ans = i + 1;
			break;
		}
	}
	return ans;
}

int main(){

	char input[500];
	while(fgets(input, sizeof(input), stdin)){
		if(strncmp(input, "exit", 4) == 0){
			break;
		}
		if(strncmp(input, "get pid", 7) == 0){
			printf("pid: %d\n", getpid());
			continue;
		}
		int input_size = strlen(input);
		// running program at background
		if((input_size = is_background(input, input_size)) != -1){
			pid_t pid = fork();
			// if we are in child process
			if(pid == 0){
				char * args[15];
				int i;
				for(i = 0; i < 15; i++){
					args[i] = malloc(sizeof(char) * 50);
					args[i] = NULL;
				}
				// extract arguments of program from input string
				int j = 0, y = 0;
				char c[15][50];
				for(i = 0; i < input_size; i++, y++){
					if(input[i] == ' '){
						c[j][y] = '\0';
						args[j] = &c[j][0];
						y = -1;
						j++;
						continue;
					}
					c[j][y] = input[i];
				}
				// execute program
				char * env_args[] = { NULL };
				if(execve(args[0], args, env_args) != -1){
					exit(EXIT_SUCCESS);
				}
				else{
					perror("execve error");
					exit(EXIT_FAILURE);
				}
			}
		} else{
			system(input);
		}
		fflush(stdin);
	}

	return 0;
}
