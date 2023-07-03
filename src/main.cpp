#include "../include/stdafx.h"
#include "../include/abstract_classes.h"

int main(int argc, char** argv)
{
	std::vector<std::string> vtArgs;
	std::map<std::string, std::string> mpArgs;
	LOGIN_MODE mode = NO_MODE;

	for (int i = 0; i < argc; i++) 
		vtArgs.push_back(std::string(argv[i]));

	for (int i = 0; i < vtArgs.size(); i++)
	{
		if (vtArgs[i].compare("-h") == 0 && (i + 1) < argc) 
			mpArgs.insert(std::make_pair("HOST", vtArgs[i + 1]));
		if (vtArgs[i].compare("-u") == 0 && (i + 1) < argc) 
			mpArgs.insert(std::make_pair("USER", vtArgs[i + 1]));
		if (vtArgs[i].compare("-pw") == 0 && (i + 1) < argc) 
			mpArgs.insert(std::make_pair("PASSWORD", vtArgs[i + 1]));
		if (vtArgs[i].compare("-key") == 0 && (i + 1) < argc)
			mpArgs.insert(std::make_pair("PRIVATE_KEY_PATH", vtArgs[i + 1]));
		if (vtArgs[i].compare("-mode") == 0 && (i + 1) < argc)
			mpArgs.insert(std::make_pair("LOGIN_MODE", vtArgs[i + 1]));
	}

	if (mpArgs["LOGIN_MODE"].empty())
	{
		return;
	}
	else
	{
		if (mpArgs["LOGIN_MODE"].compare("SSH_MODE") == 0)
			mode = SSH_MODE;
		if (mpArgs["LOGIN_MODE"].compare("CMD_WIN_MODE") == 0)
			mode = CMD_WIN_MODE;
		if (mpArgs["LOGIN_MODE"].compare("CMD_UNIX_MODE") == 0)
			mode = CMD_UNIX_MODE;
	}

	TargetLoginImpl *loginImpl = new TargetLoginImpl();

	if (mode == SSH_MODE)
	{
		//Login
	}
	else
	{
		loginImpl->Login(mode);
	}

	return 0;
}