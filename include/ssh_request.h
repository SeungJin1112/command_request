//Header Guard
#pragma once

#ifndef SSH_REQUEST_H
#define SSH_REQUEST_H

#include <libssh/libssh.h>

#include "abstract_classes.h"

// Use Pattern
// * Adapter Pattern 

class AdvancedSSHRequest
{
public:
    virtual void SET() = 0;
    
};

#endif // SSH_REQUEST_H