#include "../include/stdafx.h" 
#include "../include/abstract_classes.h"
#include "../include/ssh_request.h"

AdapterLogin::AdapterLogin(int mode)
{
    switch (mode)
    {
    case SSH_MODE:
        m_advancedLogin = new SSHLogin();
        break;
    case CMD_WIN_MODE:
        break;
    case CMD_UNIX_MODE:
        break;
    default:
        break;
    }
}

void AdapterLogin::Login(int mode, std::map<std::string, std::string>& mpLogin)
{
    switch (mode)
    {
    case SSH_MODE:
        m_advancedLogin->SSHConnection(mpLogin);
        break;
    case CMD_WIN_MODE:
    case CMD_UNIX_MODE:
        m_advancedLogin->GetLocalAccount();
        break;
    default:
        break;
    }
}

void TargetLoginImpl::Login(int mode, 
    std::string host,
    std::string user,
    std::string pw,
    std::string keyPath)
{
    if (mode == 0)
        return;
    else
        m_mode = mode;

    if (!host.empty())
        m_mpLogin.insert(std::make_pair("HOST", host));
    if (!user.empty())
        m_mpLogin.insert(std::make_pair("USER", user));
    if (!pw.empty())
        m_mpLogin.insert(std::make_pair("PASSWORD", pw));
    if (!keyPath.empty())
        m_mpLogin.insert(std::make_pair("PRIVATE_KEY_PATH", keyPath));

    m_adapterLogin = new AdapterLogin(m_mode);
    m_adapterLogin->Login(m_mode, m_mpLogin);
}

void TargetLoginImpl::Login(int mode, std::map<std::string, std::string>& mpLogin)
{
    if (mode == 0 && mpLogin.empty())
    {
        return;
    }
    else
    {
        m_mode = mode;
        m_mpLogin = mpLogin;
    }

    m_adapterLogin = new AdapterLogin(m_mode);
    m_adapterLogin->Login(m_mode, m_mpLogin);
}