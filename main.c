#include <stdio.h>
#include <stdlib.h>

# define LSH_BUFFER_SIZE 1024

char *lsh_read_line(void){
	// Creo un buffer donde almacenar el input del usuario, por defecto 1024 caracteres.
	size_t buffer_size = LSH_BUFFER_SIZE;
	char *buffer = malloc(sizeof(char) * buffer_size);
	int position = 0;
	int c;

	if(!buffer){
		printf("Error in memory allocation...\n");
		exit(EXIT_FAILURE); // Nota: exit() finaliza el programa, en este caso es más seguro
	}

	
	// Leo caracter a caracter el input del usuario realizando las siguientes comprobaciones:
	// 	- Si el caracter es "\n" (salto de línea) o EOF (End Of File), insertará el caracter valor nulo en esa posición y finalizará la lectura.
	// 	- Si se excede el buffer, le sumo al buffer el valor inicial, reasigno el nuevo tamaño en memoria y sigo con la iteración.
	// 	- En caso de cualquier caracter distinto a \n o EOF, lo inserta en la posición indicada y la incrementa para la próxima iteración.
	while(1){
		c = getchar();

		if(c == '\n' || c == EOF){
			buffer = '\0';
			printf("EOF detected...\n");
			return buffer;
		}

		buffer[position] = c;
		position++;

		if(position >= buffer_size){
			buffer_size += LSH_BUFFER_SIZE;
			realloc(buffer, buffer_size);
		}

		if(!buffer){
			printf("Error in memory reallocation\n");
			free(buffer);
			exit(EXIT_FAILURE); 
		}
	}	
}

void lsh_loop(void){
	char *line;
	char **args;
	int status=1;

	while(status){
		printf("-> ");
		line = lsh_read_line();
		printf("Reading line..\n");
		// args = lsh_split_line(line);
		// printf("Reading args...")
		// status = lsh_execute_line();
	}
	
	free(args);
	free(line);
	printf("Line & Args cleaned...\n");
}

int main(){
	// Load config files, if any
	
	// Loop command
	lsh_loop();

	// Necessary shutdown/cleanup

	return 0;
}
