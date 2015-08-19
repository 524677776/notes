#include <stdio.h>
#include <string.h>

int main()
{
	char const * str = "the differ from puts and fputs";
	
	puts(str);
	fputs(str, stdout);
	
	return 0;	
}
