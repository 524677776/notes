#include <stdio.h>
#include <stdarg.h> //va_list, va_start, va_arg, va_end..

void func(int n, ...)
{
	const char *val;
	
	va_list ap;
	va_start(ap,n);
	while(n--){
			val = va_arg(ap, const char*);
  			fputs(val, stdout);
	}
	va_end(ap);
}

int main()
{
	func(2, "hello","world");
	return 0;
}
