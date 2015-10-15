#include "Exception.h"

void my_new_handler()
{
	throw NoMem();
}

new_handler Old_Handler = std::set_new_handler(my_new_handler);