#include <string.h>
#include <stdio.h>

int main()
{
	char str[50];
	strcpy(str, "this is string.h library function");
	puts(str);

	memset(str, '$', 7);
	puts(str);
	
	return 0;	
}
