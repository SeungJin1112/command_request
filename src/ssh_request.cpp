#include "../include/abstract_classes.h"
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
		ssh_options_set(m_sshSession, SSH_OPTIONS_IDENTITY, mpLogin["PRIVATE_KEY_PATH"].c_str());

	if (ssh_connect(m_sshSession) == SSH_OK)
	{
		if (!mpLogin["PRIVATE_KEY_PATH"].empty())
		{
			if (ssh_userauth_publickey_auto(m_sshSession, NULL, NULL) == SSH_AUTH_SUCCESS)
				return;
		}
		else if (!mpLogin["PASSWORD"].empty())
		{
			if (ssh_userauth_password(m_sshSession, NULL, mpLogin["PASSWORD"].c_str())
				== SSH_AUTH_SUCCESS)
				return;
		}

		ssh_disconnect(m_sshSession);
		ssh_free(m_sshSession);
		return;
	}

	ssh_free(m_sshSession);
	return;
}