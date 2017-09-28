#include<stdio.h>

char* my_strcat(char *dest, char *src); 
char* my_strncat(char *dest, char *src, size_t n);

int main() {
	char g[] = "ji";
	char h[] = "ll";
	
	char i[20] = "";
	char o[] = "abcdefg";
	
	//returns g, not a copy of it
	/*
	char *j = strcat(g, h);
	printf("%p %p\n", j, g);
	*/
	
	//printf("%s\n", my_strncat(g, h, 2));
	//printf("%s\n", my_strncat(i, o, 4));
	//printf("%s\n", my_strncat(h, g, 0));
	//printf("%s\n", my_strncat(o, i, 3));
	
	//printf("%s\n", my_strcat(i, o));
	printf("%s\n", my_strcat(g, h));
	printf("%s\n", my_strcat(g, h));
	printf("%s\n", my_strcat(o, i));
	printf("%s\n", my_strcat(o, i));

	return 0;
}

/*
dest is required to have enough space for the resulting string
otherwise, may have unexpected behavior

both strings should be null terminated, otherwise undesired behavior
may result
*/
char* my_strncat(char *dest, char *src, size_t n) {
	char *temp = dest;
	
	//iterates until it reaches \0
	while (*(temp++));
	temp--;
	
	//size_t is never negative, so it's a bad idea use n > 0
	for (n += 1; n > 1; n--) {
		//stop if terminator is reached
		if (!*src) break;
		
		*(temp++) = *(src++);
	}
	*temp = 0;
	
	return dest;
}

/*
same as above, but using all of src by default
*/
char* my_strcat(char *dest, char *src) {
	//we want to use the whole string, so count the length
	char *temp = src;
	while(*(temp++));
	
	//minus 1 cuz we did temp++ (overshot by one)
	return my_strncat(dest, src, temp - src - 1);
}
