#include <iostream>
#include <string>

class Notificador {
public:
    virtual ~Notificador() {}
    virtual std::string gerarAlertaMeteorologico(std::string condicoesClimaticas) = 0;
};

class EnviadorDeEmail : public Notificador {
public:
    std::string gerarAlertaMeteorologico(std::string condicoesClimaticas) override {
        return "O tempo esta " + condicoesClimaticas;
    }
};

class Telefone : public Notificador {
public:
    std::string gerarAlertaMeteorologico(std::string condicoesClimaticas) override {
        return "O tempo esta " + condicoesClimaticas;
    }
};

class MonitorDoClima {
public:
    std::string condicoesAtuais;
    Notificador* notificador;

    MonitorDoClima(Notificador* notificador) : notificador(notificador) {}

    void definirCondicoesAtuais(std::string descricaoDoClima) {
        condicoesAtuais = descricaoDoClima;
        std::string alerta = notificador->gerarAlertaMeteorologico(descricaoDoClima);
        std::cout << alerta;
    }
};

int main() {
    Telefone telefone;
    std::cout << "Definindo para chuvoso: ";
    MonitorDoClima monitorChuva(&telefone);
    monitorChuva.definirCondicoesAtuais("chuvoso");
    std::cout << std::endl;

    EnviadorDeEmail email;
    std::cout << "Definindo para ensolarado: ";
    MonitorDoClima monitorSol(&email);
    monitorSol.definirCondicoesAtuais("ensolarado");
    std::cout << std::endl;

    return 0;
}
