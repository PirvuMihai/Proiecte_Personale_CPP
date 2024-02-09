#include <iostream>

using namespace std;

class Player {
private:
    char alegere;
    char** tabela;
    int status;
public:

    void setAlegere(char alegere) {
        this->alegere = alegere;
    }

    char getAlegere() {
        return this->alegere;
    }
    
    Player() {
        this->status = 0;
        this->alegere = NULL;
        if (this->tabela != NULL)
            delete[]this->tabela;
        this->tabela = new char*[7];
        for (int i = 0; i < 7; i++) {
            this->tabela[i] = new char[5];
                for (int j = 0; j < 5; j++) {
                    this->tabela[i][j] = NULL;
                }
        }
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 5; j++) {
                if (i % 2 == 1 && j % 2 == 1)
                    this->tabela[i][j] = '|';
                if (i % 2 == 0 && j!=4)
                    this->tabela[i][j] = '-';
            }

        }
    }

    void afisareTabela() {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 5; j++)
                cout << this->tabela[i][j] << " ";
            cout << endl;
        }
    }

    void start() {
        mutare(this->alegere);
    }

    void mutare(char alegere){
        int a, b;
        cout << "Unde doriti sa plasati simbolul dumneavoastra?";
        cout << endl << "a=";
        cin >> a;
        while (a < 1 || a>3) {
            cout << "Introduceti o valoare intre 1 si 3!";
            cin >> a;
        }
        cout << endl << "b=";
        cin >> b;
        while (b < 1 || b>3) {
            cout << "Introduceti o valoare intre 1 si 3!";
            cin >> b;
        }
        if(tabela[2 * (a - 1) + 1][2 * (b - 1)]==NULL)
            tabela[2 * (a - 1) + 1][2 * (b - 1)] = alegere;
        else {
            cout<<"Acea sectiune a tabelei a fost deja ocupata!";
        }
        afisareTabela();
        status = checkWinCondition();
        if (status == 1) {
            cout << "Jucatorul cu simbolul " << alegere << " a castigat!";     
            felicitari();
        }
        int cnt = 0;
        for (int i = 0; i < 7; i++)
            for (int j = 0; j < 5; j++)
                if (tabela[i][j] == NULL)
                    cnt = 1;
        if(cnt==1)
            schimbaJucator(alegere);
        else {
            cout << "Jocul a luat sfarsit, este egalitate.";
            end();
        }
    }

    void end() {
        string raspuns;
        cout << "Doriti sa mai jucati? Da/Nu";
        cin >> raspuns;
        while (raspuns != "Da" && raspuns != "Nu") {
            cout << "Va rugam introduceti un raspuns sub forma Da/Nu";
            cin >> raspuns;
        }
        if (raspuns == "Nu")
            exit(0);
        else
            run();
    }

    void felicitari() {
        cout << endl << "Felicitari";
        end();
    }

    void schimbaJucator(char alegere) {
        if (alegere == 'X')
            mutare('0');
        else
            mutare('X');
    }

    int checkWinCondition() {
        for (int i = 1; i < 7; i=i+2) {
            if ((tabela[i][0] == 'X' || tabela[i][0]=='O') && (tabela[i][2] == 'X' || tabela[i][2] == '0') && (tabela[i][4] == 'X' || tabela[i][4] == '0'))
                return 1;
        }
        for (int j = 0; j < 5; j=j+2)
            if ((tabela[1][j] == tabela[3][j] && tabela[1][j] == tabela[5][j]) && (tabela[1][j] =='X' || tabela[3][j]=='0'))
                return 1;
        if ((tabela[1][0] == tabela[3][2] && tabela[1][0] == tabela[5][4]) && (tabela[1][0] == 'X' || tabela[1][0] == '0'))
            return 1;
        if ((tabela[5][0] == tabela[3][2] && tabela[5][0] == tabela[1][4]) && (tabela[1][4] == 'X' || tabela[1][4] == '0'))
            return 1;
        return 0;
    }

    void run() {
        Player player1;
        Player player2;
        cin >> player1;
        if (player1.getAlegere() == 'X')
            player2.setAlegere('0');
        else
            player2.setAlegere('X');
        cout << player1.getAlegere();
        cout << player2.getAlegere();
        cout << endl;
        player1.afisareTabela();
        cout << "Cine doriti sa inceapa? X/0?";
        char a1;
        cin >> a1;
        while (a1 != 'X' && a1 != '0') {
            cout << "Va rugam introduceti X/0.";
            cin >> a1;
        }
        if (player1.getAlegere() == a1)
            player1.start();
        else
            player2.start();
    }

    friend istream& operator>>(istream& in, Player& p) {
        cout << "Doriti sa jucati cu X sau cu 0?";
        in >> p.alegere;
        while (p.alegere != 'X' && p.alegere != '0') {
            cout << "Va rog, alegeti X sau 0.";
            in >> p.alegere;
        }
        return in;
    }
};

int main()
{
    Player player1;
    Player player2;
    player1.run();
}

