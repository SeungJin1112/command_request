//Header Guard
#pragma once

#ifndef ABSTRACT_CLASSES_H
#define ABSTRACT_CLASSES_H

#include <iostream>
#include <map>

#ifdef _WIN32
#include <Windows.h>
#else
#endif


enum mode
{
    SSH_MODE = 0x01,
    LOCAL_CMD_WIN_MODE,
    LOCAL_CMD_UNIX_MODE,
    REMOTE_CMD_WIN_MODE,
    REMOTE_CMD_UNIX_MODE
};

/*
* std::map<std::string, std::string> mpLogin
* HOST
* PORT
* USER
* PASSWORD
* PRIVATE_KEY_PATH
*/

class TargetLogin
{
public:
    virtual void Login(int mode, std::map<std::string, std::string> mpLogin) = 0;
};

class TargetCommand
{
public:
    virtual void Command(int binaryNumber, TargetLogin& login, std::string cmd) = 0;
};

#endif // ABSTRACT_CLASSES_H