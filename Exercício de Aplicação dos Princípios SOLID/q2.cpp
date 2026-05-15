#include <iostream>
#include <string>

class Ave {
public:
    virtual ~Ave() {}
    virtual void trocarPenas() = 0;
};

class AveVoadora : public Ave {
public:
    virtual void voar() = 0;
};

class Aguia : public AveVoadora {
public:
    std::string localizacaoAtual;
    int numeroDePenas;

    Aguia(int contagemInicialPenas) : numeroDePenas(contagemInicialPenas) {}

    void voar() override {
        localizacaoAtual = "no ar";
        std::cout << "Aguia esta voando. Localizacao: " << localizacaoAtual << std::endl;
    }

    void trocarPenas() override {
        numeroDePenas -= 1;
        std::cout << "Aguia trocando penas. Penas: " << numeroDePenas << std::endl;
    }
};

class Pinguim : public Ave {
public:
    std::string localizacaoAtual;
    int numeroDePenas;

    Pinguim(int contagemInicialPenas) : numeroDePenas(contagemInicialPenas) {}

    void trocarPenas() override {
        numeroDePenas -= 1;
        std::cout << "Pinguim trocando penas. Penas: " << numeroDePenas << std::endl;
    }

    void nadar() {
        localizacaoAtual = "na agua";
        std::cout << "Pinguim esta nadando. Localizacao: " << localizacaoAtual << std::endl;
    }
};

int main() {
    Aguia aguia(100);
    aguia.voar();
    aguia.trocarPenas();

    std::cout << "---" << std::endl;

    Pinguim pinguim(50);
    pinguim.nadar();
    pinguim.trocarPenas();

    return 0;
}
