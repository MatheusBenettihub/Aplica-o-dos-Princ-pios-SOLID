#include <iostream>
#include <string>
#include <vector>

class Tabuleiro {
public:
    std::vector<std::string> posicoes;

    Tabuleiro() {
        for (int i = 0; i < 9; ++i) {
            this->posicoes.push_back(std::to_string(i));
        }
    }

    std::vector<std::string> primeiraLinha() {
        return { posicoes[0], posicoes[1], posicoes[2] };
    }

    std::vector<std::string> segundaLinha() {
        return { posicoes[3], posicoes[4], posicoes[5] };
    }

    std::vector<std::string> terceiraLinha() {
        return { posicoes[6], posicoes[7], posicoes[8] };
    }
};

class ExibidorDeTabuleiro {
public:
    void exibir(const Tabuleiro& tabuleiro) {
        const auto& p = tabuleiro.posicoes;
        std::cout << p[0] << " | " << p[1] << " | " << p[2] << "\n"
                  << p[3] << " | " << p[4] << " | " << p[5] << "\n"
                  << p[6] << " | " << p[7] << " | " << p[8] << std::endl;
    }
};

int main() {
    Tabuleiro tabuleiro;
    ExibidorDeTabuleiro exibidor;
    exibidor.exibir(tabuleiro);
    return 0;
}
