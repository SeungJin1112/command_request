#include "../include/ssh_request.h"

enum SSH_FREE_LEVEL
{
	SSH_FREE = 0x01,
	SSH_DISCONNECT,
	SSH_CHANNEL_FREE,
	SSH_CHANNEL_CLOSE,
	SSH_CHANNEL_EOF
};

void SSHLogin::SSHConnection(std::map<std::string, std::string>& mpLogin)
{
	m_sshSession = ssh_new();

	if (m_sshSession == NULL)
		return;

	ssh_options_set(m_sshSession, SSH_OPTIONS_HOST, mpLogin["HOST"].c_str());
	ssh_options_set(m_sshSession, SSH_OPTIONS_USER, mpLogin["USER"].c_str());

	if (!mpLogin["PRIVATE_KEY_PATH"].empty())
	{
		if (ssh_options_set(m_sshSession, SSH_OPTIONS_IDENTITY, mpLogin["PRIVATE_KEY_PATH"].c_str()) < 0)
		{
			ssh_free(m_sshSession);
			return;
		}
	}

	if (ssh_connect(m_sshSession) == SSH_OK)
	{
		if (!mpLogin["PRIVATE_KEY_PATH"].empty())
		{
		}
		else if (!mpLogin["PASSWORD"].empty())
		{

		}
		else
		{
			ssh_disconnect(m_sshSession);
			ssh_free(m_sshSession);
		}
		return;
	}
	else
	{
		ssh_free(m_sshSession);
		return;
	}
}
