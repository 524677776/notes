#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <new>

class NoMem
{
public:
	NoMem(){}
};

class OutOfBounds
{
public:
	OutOfBounds(){};

};

#endif // !__EXCEPTION_H__
