//Header Guard
#pragma once

#ifndef SSH_REQUEST_H
#define SSH_REQUEST_H

#include <libssh/libssh.h>

#include "../include/abstract_classes.h" 

class SSHLogin : public AdvancedLogin
{
public:
	void SSHConnection(std::map<std::string, std::string>& mpLogin) override;
	void SSHDisConnection(std::map<std::string, std::string>& mpLogin) override {};
	void GetLocalAccount() override {};

private:
	ssh_session m_sshSession;
};

#endif // SSH_REQUEST_H