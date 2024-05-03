#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct entry
{
    string cognome;
    string nome;
    string telFisso;
    string telMobile;
};


vector<entry> Rubrica;

/*

  _____  _      _____                                _
 |  __ \| |    / ____|     /\                       | |
 | |__) | |   | |         /  \   __ _  ___ _ __   __| | __ _
 |  ___/| |   | |        / /\ \ / _` |/ _ \ '_ \ / _` |/ _` |
 | |    | |___| |____   / ____ \ (_| |  __/ | | | (_| | (_| |
 |_|    |______\_____| /_/    \_\__, |\___|_| |_|\__,_|\__,_|
                                 __/ |
                                |___/
*/

int getInput() {
    int input = 0;
    do {
        system("CLS");
        cout
            << "                                                                " << "\n"
            << "  _____  _      _____                                _          " << "\n"
            << " |  __ \\| |    / ____|     /\\                       | |         " << "\n"
            << " | |__) | |   | |         /  \\   __ _  ___ _ __   __| | __ _    " << "\n"
            << " |  ___/| |   | |        / /\\ \\ / _` |/ _ \\ '_ \\ / _` |/ _` |   " << "\n"
            << " | |    | |___| |____   / ____ \\ (_| |  __/ | | | (_| | (_| |   " << "\n"
            << " |_|    |______\\_____| /_/    \\_\\__, |\\___|_| |_|\\__,_|\\__,_|   " << "\n"
            << "                                 __/ |                          " << "\n"
            << "                                |___/                           " << "\n";
        cout
            << "1) Inserisci voce\n"
            << "2) Cerca voce\n"
            << "3) Stampa voce su file\n"
            << "4) Cancella voce\n"
            << "5) Stampa rubrica\n"
            << "6) Crea backup\n"
            << "7) Ripristina rubrica\n"
            << "8) Ordina rubrica\n"
            << "9) Esci\n";
        cin >> input;
    } while (input < 1 || input > 9);
    return input;
}

void AddEntry() {
    system("CLS");
    entry thisEntry;
    cout << "Inserisci nome: ";
    cin >> thisEntry.nome;
    cout << "Inserisci cognome: ";
    cin >> thisEntry.cognome;
    cout << "Inserisci numero di telefono fisso: ";
    cin >> thisEntry.telFisso;
    cout << "Insersci numero di telefono (Mobile): ";
    cin >> thisEntry.telMobile;

    Rubrica.push_back(thisEntry);
    system("CLS");
}

void GetEntry() {
    int inp;
    do {
        system("CLS");
        cout << "In base a cosa vuoi cercare?\n" << "1 - Nome || 2 - Cognome || 3 - Telefono fisso || 4 - Telefono mobile || 5 - Indice" << endl;
        cin >> inp;
    } while (inp < 1 || inp > 5);

    string search;
    cout << "Inserisci il valore da cercare: ";
    cin >> search;


    int index = -1;
    switch (inp)
    {
    case 1:
        for (int i = 0; i < Rubrica.size(); i++) {
            if (Rubrica.at(i).nome == search) {
                index = i;
                break;
            }
        }
        break;
    case 2:
        for (int i = 0; i < Rubrica.size(); i++) {
            if (Rubrica.at(i).cognome == search) {
                index = i;
                break;
            }
        }
        break;
    case 3:
        for (int i = 0; i < Rubrica.size(); i++) {
            if (Rubrica.at(i).telFisso == search) {
                index = i;
                break;
            }
        }
        break;
    case 4:
        for (int i = 0; i < Rubrica.size(); i++) {
            if (Rubrica.at(i).telMobile == search) {
                index = i;
                break;
            }
        }
    case 5:
        index = stoi(search) - 1;
        break;
    }


    if (index == -1) {
        cout << "Voce non trovata!\n";
        system("PAUSE");
        system("CLS");
        return;
    }

    cout
        << "La voce richiesta e' la seguente\n"
        << "Nome e Cognome: " << Rubrica.at(index).nome << " " << Rubrica.at(index).cognome << endl
        << "Telefono fisso: " << Rubrica.at(index).telFisso << endl
        << "Telefono mobile: " << Rubrica.at(index).telMobile << endl;
    system("PAUSE");
}


void GetEntryInFile() {
    int inp;
    do {
        system("CLS");
        cout << "In base a cosa vuoi cercare?\n" << "1 - Nome || 2 - Cognome || 3 - Telefono fisso || 4 - Telefono mobile || 5 - Indice" << endl;
        cin >> inp;
    } while (inp < 1 || inp > 5);

    string search;
    cout << "Inserisci il valore da cercare: ";
    cin >> search;


    int index = -1;
    switch (inp)
    {
    case 1:
        for (int i = 0; i < Rubrica.size(); i++) {
            if (Rubrica.at(i).nome == search) {
                index = i;
                break;
            }
        }
        break;
    case 2:
        for (int i = 0; i < Rubrica.size(); i++) {
            if (Rubrica.at(i).cognome == search) {
                index = i;
                break;
            }
        }
        break;
    case 3:
        for (int i = 0; i < Rubrica.size(); i++) {
            if (Rubrica.at(i).telFisso == search) {
                index = i;
                break;
            }
        }
        break;
    case 4:
        for (int i = 0; i < Rubrica.size(); i++) {
            if (Rubrica.at(i).telMobile == search) {
                index = i;
                break;
            }
        }
    case 5:
        index = stoi(search) - 1;
        break;
    }


    if (index == -1) {
        cout << "Voce non trovata!\n";
        system("PAUSE");
        system("CLS");
        return;
    }
    string stringtxt = "voce" + to_string(index) + ".txt";
    string text = "Nome e cognome: " + Rubrica.at(index).nome + " " + Rubrica.at(index).cognome + "\nTelefono fisso: " + Rubrica.at(index).telFisso + "\nTelefono mobile: " + Rubrica.at(index).telMobile + "\n";

    ofstream file(stringtxt);
    file << text;
    file.close();
}

void DeleteEntry() {
    int inp;
    do {
        system("CLS");
        cout << "Inserisci la voce da cancellare: ";
        cin >> inp;
    } while (inp < 1 || inp >= Rubrica.size());
    inp--;
    swap(Rubrica.at(inp), Rubrica.at(Rubrica.size() - 1));
    Rubrica.pop_back();
    while (inp < Rubrica.size() - 1) {
        swap(Rubrica.at(inp), Rubrica.at(inp + 1)); // Non dovrebbe mai andare in overflow grazie alla Rubrica.size() - 1
        inp++;
    }
}

void PrintAllEntries() {
    system("CLS");
    for (int i = 0; i < Rubrica.size(); i++) {
        cout
            << "Voce " << i+1 << ":\n"
            << "    Nome e cognome: " << Rubrica.at(i).nome << " " << Rubrica.at(i).cognome << "\n"
            << "    Telefono fisso: " << Rubrica.at(i).telFisso << "\n"
            << "    Telefono mobile: " << Rubrica.at(i).telMobile << "\n";
    }
    system("PAUSE");
}

void CreateBackup() {
    string filename = "Backup.txt";
    ofstream file(filename, ios::trunc);

    for (int i = 0; i < Rubrica.size(); i++) {
        string thisParse = Rubrica.at(i).nome + "-" + Rubrica.at(i).cognome + "-" + Rubrica.at(i).telFisso + "-" + Rubrica.at(i).telMobile + "\n";
        file << thisParse;
    }
}



// Formato nel backup file
// NOME-COGNOME-NUMEROFISSO-NUMEROMOBILE

// Che bel parser :D
void RestoreData() {
    string filename = "Backup.txt";
    ifstream file(filename);
    string buff = "";
    int index = 0;

    entry clearEntry = { 
        "",
        "",
        "",
        "",
    };
    Rubrica.clear();
    while (getline(file, buff)) {
        Rubrica.push_back(clearEntry);
        string temp;
        for (int i = 0, item = 0; i < buff.length(); i++) {
            if (buff[i] == '-') {
                switch (item)
                {
                    case 0:
                        Rubrica.at(index).nome = temp;
                        temp = "";
                        break;
                    case 1:
                        Rubrica.at(index).cognome = temp;
                        temp = "";
                        break;
                    case 2:
                        Rubrica.at(index).telFisso = temp;
                        temp = "";
                        break;
                    case 3: 
                        Rubrica.at(index).telMobile = temp;
                        temp = "";
                        break;
                }
                item++;
                continue;
            }
            temp = temp + buff[i];
        }
        index++;
    }
}

void OrderBySurname() {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < Rubrica.size() - 1; i++) {
            if (Rubrica.at(i).cognome < Rubrica.at(i+1).cognome) {
                swap(Rubrica.at(i), Rubrica.at(i + 1));
                swapped = true;
            }
        }
    } while (swapped); 
}

void ExitQuestion(int& input, bool hasSaved) {
    system("CLS");
    char np;
    (hasSaved) ? cout << "Sei sicuro di voler uscire? (S/N): " : cout << "Sei sicuro di voler uscire?\nNon hai ancora fatto il backup della rubrica! (S/N): ";
    cin >> np;
    if(np == 'N') {
        input = 0;
    }

}

int main() {
    int input;
    bool hasSaved = false;
    do {
        input = getInput();
        switch (input)
        {
        case 1:
            AddEntry();
            break;
        case 2:
            GetEntry();
            break;
        case 3:
            GetEntryInFile();
            break;
        case 4:
            DeleteEntry();
            break;
        case 5:
            PrintAllEntries();
            break;
        case 6:
            CreateBackup();
            hasSaved = true;
            break;
        case 7:
            RestoreData();
            break;
        case 8:
            OrderBySurname();
            break;
        case 9:
            ExitQuestion(input, hasSaved);
        }
    } while (input != 9);
    return 0;
}