

#include "headers.h"
#include "pessoa.h"
#include "lista.h"


void Imprimir();
void subMenuInserir(Lista &minhaLista);
void subMenuOrdenar(Lista &minhalista);
void subMenuRemover(Lista &minhaLista);
void SalvaLista();


void Menuprincipal(Lista &minhaLista){
    int opcao;
    do {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1.Inserir"<<endl<<
                 "2.Remover"<<endl<< 
                 "3.Imprimir"<<endl<< 
                 "4.Ordenar"<<endl<<
                 "5.Salva"<<endl<<
                 "6.procurar pelo CPF"<<endl <<
                 "7.Busca Binaria"<<endl<<
                 "8.sair"<<endl ;
        cin >> opcao;

        switch(opcao) {
            case 1: subMenuInserir(minhaLista); break;
            case 2: subMenuRemover(minhaLista); break;
            case 3: minhaLista.Imprimir(); break;
            case 4: subMenuOrdenar(minhaLista); break;
            case 5: minhaLista.SalvaLista(); break;
            case 6: minhaLista.ProcuraRG(); break;
            case 7: minhaLista.BuscaBinaria(); break;
        }
    } while(opcao != 8);
}

void subMenuInserir(Lista &minhaLista) {

    int escolha;
        cout << "1.Inicio"<<endl<<
                "2.fim"<<endl<< 
                "3.meio"<<endl<< 
                "4.voltar"<<endl ;

    cin >> escolha;
    
    if(escolha == 1) minhaLista.InserirNoComeço();
    else if(escolha == 2) minhaLista.InserirNoFinal();
    else if(escolha == 3) minhaLista.InserirNoMeio();
}

void subMenuRemover(Lista &minhaLista) {
    int escolha;
    cout << "1.Inicio"<<endl<<
            "2.fim"<<endl<< 
            "3.meio"<<endl<< 
            "4.voltar"<<endl ;
    cin >> escolha;
    
    if(escolha == 1) minhaLista.RemoverDoComeço();
    else if(escolha == 2) minhaLista.RemoverDoFim();
    else if(escolha == 3) minhaLista.RemoverDoMeio();
}

void subMenuOrdenar(Lista &minhaLista) {
    int escolha;
    cout << "1.Selection"<<endl<<
            "2.Insertion"<<endl<< 
            "3.Bubble"<<endl<< 
            "4.Shell"<<endl<<
            "5.Quick"<<endl<<
            "6.merge"<<endl<<
            "7.sair"<<endl;
    cin >> escolha;
    
    if(escolha == 1) minhaLista.SelectionSort();
    else if(escolha == 2) minhaLista.InsertionSort();
    else if(escolha == 3) minhaLista.BubbleSort();
    else if(escolha == 4) minhaLista.ShellSort();
    else if(escolha == 5) minhaLista.QuickSort();
    else if(escolha ==6) minhaLista.MergeSort();
}