#include<stdio.h>

char* my_strcat(char *dest, char *src); 
char* my_strncat(char *dest, char *src, size_t n);

int main() {
	char a[] = "ji";
	char b[] = "ll";
	
	char c[20] = "";
	char d[] = "abcdefg";
	
	//returns g, not a copy of it
	/*
	char *j = strcat(a, b);
	printf("%p %p\n", j, a);
	*/
	
	//printf("%s\n", my_strncat(a, b, 2));
	//printf("%s\n", my_strncat(c, d, 4));
	//printf("%s\n", my_strncat(b, a, 0));
	//printf("%s\n", my_strncat(d, c, 3));
	
	//printf("%s\n", my_strcat(i, o));
	printf("%s\n", my_strcat(a, b));
	printf("%s\n", my_strcat(a, b));
	printf("%s\n", my_strcat(d, c));
	printf("%s\n", my_strcat(d, c));

	printf("\n\nOBSERVATIONS\n");
	
	char g[] = "ji";
	char h[] = "ll";

	/*
	strcat appends the second string to the first string and returns a pointer to
	the first string

	the first string is modified
	*/
	printf("%s\n", strcat(g, h));
	printf("%s\n", strcat(h, g));
	printf("%p and %p are the same\n", g, strcat(g, h));


	char i[2];
	i[0] = 'p';
	i[1] = 'i';

	char j[] = "hello";

	/*
	strings should be null terminated, else unexpected results may occur
	*/
	printf("%s\n", strcat(j, i));


	char k[] = "boi";
	char l[] = "gurl";

	/*
	strncat takes another arg for the bytes to copy
	*/
	printf("%s\n", strncat(k, l, 2));

	/*
	It will still stop at any \0 found in src (the second arg)
	*/
	printf("%s\n", strncat(l, k, 10000));
	
	
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
