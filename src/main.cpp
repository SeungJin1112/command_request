#include "../include/context.h"

int main() 
{
	TargetLoginImpl *test = new TargetLoginImpl();

	test->Login(SSH_MODE);

	return 0;
}