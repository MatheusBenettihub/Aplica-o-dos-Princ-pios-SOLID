#include <iostream>
#include <string>

class Saudacao {
public:
    virtual ~Saudacao() {}
    virtual std::string saudar() = 0;
};

class SaudacaoFormal : public Saudacao {
public:
    std::string saudar() override {
        return "Boa noite, senhor.";
    }
};

class SaudacaoCasual : public Saudacao {
public:
    std::string saudar() override {
        return "E ai, cara?";
    }
};

class SaudacaoIntima : public Saudacao {
public:
    std::string saudar() override {
        return "Ola, querido(a)!";
    }
};

class SaudacaoPadrao : public Saudacao {
public:
    std::string saudar() override {
        return "Ola.";
    }
};

class Saudador {
private:
    Saudacao* saudacao;

public:
    Saudador(Saudacao* saudacao) : saudacao(saudacao) {}

    std::string saudar() {
        return saudacao->saudar();
    }
};

int main() {
    SaudacaoFormal formal;
    SaudacaoCasual casual;
    SaudacaoIntima intima;
    SaudacaoPadrao padrao;

    Saudador s1(&formal);
    std::cout << s1.saudar() << std::endl;

    Saudador s2(&casual);
    std::cout << s2.saudar() << std::endl;

    Saudador s3(&intima);
    std::cout << s3.saudar() << std::endl;

    Saudador s4(&padrao);
    std::cout << s4.saudar() << std::endl;

    return 0;
}
