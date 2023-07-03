#ifndef ABSTRACT_CLASSES_H
#define ABSTRACT_CLASSES_H

enum LOGIN_MODE
{
    NO_MODE,
    SSH_MODE,
    CMD_WIN_MODE,
    CMD_UNIX_MODE,
};

class TargetLogin
{
public:
    virtual void Login(int mode, std::map<std::string, std::string>& mpLogin) = 0;
};

class AdvancedLogin
{
public:
    virtual void SSHConnection(std::map<std::string, std::string>& mpLogin) = 0;
    virtual void SSHDisConnection(std::map<std::string, std::string>& mpLogin) = 0;
    virtual void GetLocalAccount() = 0; //cmd는 로그인하지 않음. 현재 로그인중인 계정 정보를 가져오면 된다.
};

class AdapterLogin : public TargetLogin
{
public:
    AdapterLogin(int mode);

    void Login(int mode, std::map<std::string, std::string>& mpLogin) override;

private:
    AdvancedLogin* m_advancedLogin;
};

class TargetLoginImpl 
{
public:
    void Login(int mode,
        std::string host = "",
        std::string user = "",
        std::string pw = "",
        std::string keyPath = "");

    void Login(int mode, std::map<std::string, std::string>& mpLogin);

private:
    AdapterLogin* m_adapterLogin;

    int m_mode;
    std::map<std::string, std::string> m_mpLogin;
};

class TargetCommand
{
public:
    virtual void Command(TargetLoginImpl& login, std::string cmd) = 0;
};

#endif // ABSTRACT_CLASSES_H