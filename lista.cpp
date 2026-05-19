#include "headers.h"
#include "lista.h"

Lista::Lista(unsigned int capInput){
    cap = capInput + 100;
    total = 0; Cn = 0; Mn = 0;

    listaDePessoas = new (nothrow) Pessoa[cap];

    if(!listaDePessoas){
        cout << "Memória insuficiente!" << endl;
        exit(1);
    }
}

Lista::~Lista(){
    delete[] listaDePessoas;
}

void Lista::InserirRapido(string nome, string rg){
    if (total < cap) {
        listaDePessoas[total].Setnome((char*)nome.c_str());
        listaDePessoas[total].SetRG((char*)rg.c_str());
        
        total++;
        Mn += 2;
    } 
    else 
        cout << "Erro: Lista cheia!" << endl;
}

void Lista::InserirNoFinal()
{
    ZerarMetricas();
    string nome, rg;
    cout << "Nome: "; cin >> nome;
    cout << "RG: "; cin >> rg;

    InserirRapido(nome, rg);
    ExibirMetricas();
}

void Lista::InserirNoComeço()
{
    ZerarMetricas();
    if (total >= cap) {
        cout << "Lista cheia!" << endl;
        return;
    }

    string nome, rg;
    cout << "Nome: "; cin >> nome;
    cout << "RG: "; cin >> rg;

    for(int i = total; i > 0; i--){
        listaDePessoas[i] = listaDePessoas[i-1];
        Mn++;
    }

    listaDePessoas[0].Setnome((char*)nome.c_str());
    listaDePessoas[0].SetRG((char*)rg.c_str());
    Mn += 2; 
    total++;

    ExibirMetricas();
}

void Lista::InserirNoMeio()
{
    ZerarMetricas();
    if (total >= cap) {
        cout << "Lista cheia!" << endl;
        return;
    }

    string nome, rg;
    int pos;
    cout << "Nome: "; cin >> nome;
    cout << "RG: "; cin >> rg;
    cout << "Em qual posiçao (humana) vai ser colocado? "; cin >> pos;
    pos--;

    if(pos < 0 || pos > total){
        cout << "Posição Inválida"<< endl;
        return;
    }
    
    for(int i = total; i > pos ; i--){
        listaDePessoas[i] = listaDePessoas[i-1];
        Mn++;
    }
    
    listaDePessoas[pos].Setnome((char*)nome.c_str());
    listaDePessoas[pos].SetRG((char*)rg.c_str());
    Mn += 2;
    total++;

    ExibirMetricas();
}

void Lista::RemoverDoFim(){
    ZerarMetricas();
    total--;
    Mn++;
    ExibirMetricas();
}

void Lista::RemoverDoComeço(){
    ZerarMetricas();
    for(int i = 0; i < total - 1; i++){
        listaDePessoas[i] = listaDePessoas[i+1];
        Mn++;
    }
    total--;
    ExibirMetricas();
}

void Lista::RemoverDoMeio(){
    ZerarMetricas();
    int pos;
    cout << "De qual posição (humana) deve ser retirado? "; cin >> pos;
    pos--;

    if (pos < 0 || pos >= total) {
        cout << "Erro: Posição inválida!" << endl;
        return;
    }

    for(int i = pos; i < total - 1; i++){
        listaDePessoas[i] = listaDePessoas[i+1];
        Mn++;
    }
    total--;
    ExibirMetricas();
}

void Lista::SalvaLista(){
    ZerarMetricas();
    string nomearquivo;
    cout << "Nome do novo arquivo: "; cin >> nomearquivo;
    ofstream arquivo(nomearquivo);

    if (!arquivo.is_open()) {
        cout << "Erro ao criar o arquivo!" << endl;
        return;
    }

    for(int i = 0; i < total; i++){
        arquivo << listaDePessoas[i].Getnome() << "," << listaDePessoas[i].GetRG() << "\n";
    }
    arquivo.close();
    cout << "Dados salvos!" << endl;
    ExibirMetricas();
}

void Lista::ProcuraRG(){
    ZerarMetricas();
    string cpf;
    int encontrou = 0;
    cout << "CPF para busca: "; cin >> cpf;

    for(int i = 0; i < total; i++){
        Cn++;
        if(string(listaDePessoas[i].GetRG()) == cpf){
            cout << "Encontrado: " << listaDePessoas[i].Getnome() << endl;
            encontrou++;
            break;
        }
    }

    if(!encontrou) cout << "CPF não encontrado." << endl;
    ExibirMetricas();
}

void Lista::Imprimir() {
    ZerarMetricas();


    for(int i = 0; i < total; i++) {
        cout << i + 1 << ": " << listaDePessoas[i].Getnome() << " | " << listaDePessoas[i].GetRG() << endl;
    }
    ExibirMetricas();
}

void Lista::ExibirMetricas() {
    cout << "\n>>> [Analise de Desempenho]" << endl;
    cout << ">>> Comparacoes C(n): " << Cn << endl;
    cout << ">>> Movimentacoes M(n): " << Mn << endl;
    cout << "--------------------------" << endl;
}

void Lista :: SelectionSort(){
    ZerarMetricas();
    int menor;
    Pessoa aux;

    for(int i=0; i<total-1;i++){
        menor = i;
        for(int j=i+1;j<total-1;j++){
            if((stoull(string(listaDePessoas[j].GetRG())))<(stoull(string(listaDePessoas[menor].GetRG())))){
            menor = j;
            Cn++;
            }
        }
        aux = listaDePessoas[i];
        listaDePessoas[i]=listaDePessoas[menor];
        listaDePessoas[menor]=aux;
        Mn+=3;
    }
    ExibirMetricas();
}

void Lista :: BubbleSort(){
    ZerarMetricas();
    bool trocou;
    Pessoa aux;

    for (int i = 0;i<total-1;i++){
        trocou = false;
        for(int j = 0; j < total-1-i;j++){
            if((stoull(string(listaDePessoas[j].GetRG())))>(stoull(string(listaDePessoas[j+1].GetRG())))){
                aux = listaDePessoas[j];
                listaDePessoas[j]=listaDePessoas[j+1];
                listaDePessoas[j+1]=aux;
                trocou= true;
                Cn++;
                Mn+=3;
            }

        }
        if(!trocou) break;
    }
    ExibirMetricas();
}
void Lista :: InsertionSort(){
    ZerarMetricas();
    Pessoa key;
    for(int i = 1; i<total;i++){
        key =listaDePessoas[i];Mn++;
        int j = i-1;
        for(j;j>=0 && (stoull(string(listaDePessoas[j].GetRG()))) > (stoull(string(key.GetRG())));j--){
            listaDePessoas[j+1]=listaDePessoas[j];
            Cn++;Mn++;
        }
        listaDePessoas[j+1]=key;Mn++;

    }
    ExibirMetricas();
}
void Lista:: ShellSort(){
    ZerarMetricas();
    Pessoa aux;
    for(int gap = total/2;gap>0;gap /=2){
        for(int i= gap ; i <total ; i++){
            aux = listaDePessoas[i];Mn++;
            int j;
            for(j=i;j>=gap && (stoull(string(listaDePessoas[j-gap].GetRG()))) > (stoull(string(aux.GetRG()))); j-=gap){
                listaDePessoas[j] = listaDePessoas[j-gap];
                Mn++;Cn++;
            }
            listaDePessoas[j] = aux;Mn++;
        }
    }

    ExibirMetricas();
}
void Lista::QuickSort(int inicio, int fim) {
    if (inicio == -1 && fim == -1) {
        ZerarMetricas();
        if (total <= 1) { ExibirMetricas(); return; }
        inicio = 0;
        fim = total - 1;
    }

    if (inicio < fim) {
        Pessoa pivo = listaDePessoas[inicio + (fim - inicio) / 2];
        unsigned long long rgPivo = stoull(string(pivo.GetRG()));
        Mn++;

        int i = inicio - 1;
        int j = fim + 1;

        while (true) {
            do {
                i++;
                Cn++;
            } while (stoull(string(listaDePessoas[i].GetRG())) < rgPivo);

            do {
                j--;
                Cn++;
            } while (stoull(string(listaDePessoas[j].GetRG())) > rgPivo);

            if (i >= j) break;

            Pessoa aux = listaDePessoas[i];
            listaDePessoas[i] = listaDePessoas[j];
            listaDePessoas[j] = aux;
            Mn += 3;
        }
        
        int pivoIndice = j;

        QuickSort(inicio, pivoIndice);
        QuickSort(pivoIndice + 1, fim);
    }

    if (inicio == 0 && fim == total - 1) {
        ExibirMetricas();
    }
}


void Lista::MergeSort(int inicio, int fim) {
    if (inicio == -1 && fim == -1) {
        ZerarMetricas();
        if (total <= 1) { ExibirMetricas(); return; }
        inicio = 0;
        fim = total - 1;
    }

    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        
        MergeSort(inicio, meio);
        MergeSort(meio + 1, fim);
        
        int n1 = meio - inicio + 1;
        int n2 = fim - meio;

        Pessoa* L = new Pessoa[n1];
        Pessoa* R = new Pessoa[n2];

        for (int i = 0; i < n1; i++) {
            L[i] = listaDePessoas[inicio + i];
            Mn++;
        }
        for (int j = 0; j < n2; j++) {
            R[j] = listaDePessoas[meio + 1 + j];
            Mn++;
        }

        int i = 0, j = 0, k = inicio;
        while (i < n1 && j < n2) {
            Cn++;
            if (stoull(string(L[i].GetRG())) <= stoull(string(R[j].GetRG()))) {
                listaDePessoas[k] = L[i];
                i++;
            } else {
                listaDePessoas[k] = R[j];
                j++;
            }
            Mn++;
            k++;
        }

        while (i < n1) {
            listaDePessoas[k] = L[i];
            i++; k++; Mn++;
        }
        while (j < n2) {
            listaDePessoas[k] = R[j];
            j++; k++; Mn++;
        }

        delete[] L;
        delete[] R;
    }

    if (inicio == 0 && fim == total - 1) {
        ExibirMetricas();
    }
}

void Lista :: BuscaBinaria(){
    
    ZerarMetricas();

    long long rg;
    bool encontrou = false;
    int inicio = 0,fim = total-1;
    cout<<"qual RG vc quer encontrar?";cin >> rg;

    while(inicio <= fim && !encontrou){

        int meio = inicio + (fim - inicio) / 2;
        long long rgMeio = stoull(string(listaDePessoas[meio].GetRG()));
        if(rg > rgMeio){
                inicio = meio+1;
                Cn++;
        }
        else if(rg < rgMeio){
                fim = meio-1;
                Cn++;
        }
        else if(rg == rgMeio){
            cout<< "ENCONTRADO:"<<listaDePessoas[meio].Getnome()<<endl;
            encontrou = true;
            Cn++;
        }
    }

    ExibirMetricas();
}