void free_mem(char *line, char **args){
	free(line);
	free(args);
}

void lsh_loop(void){
	char *line;
	char **args;
	int status=1;

	while(status){
		printf("-> ");
		line = lsh_read_line();
		printf("Reading line..");
		args = lsh_split_line(line);
		printf("Reading args...")
		status = lsh_execute_line();
	}

	free_mem(line, args);
	printf("Line & Args cleaned...");
}

int main(){
	// Load config files, if any
	
	// Loop command
	lsh.loop();

	// Necessary shutdown/cleanup

	return 0;
}
