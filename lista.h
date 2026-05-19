#include "headers.h"
#include "pessoa.h"
#pragma once

class Lista {

    Pessoa* listaDePessoas;
    unsigned int cap,total;

    public:

    unsigned long long Cn,Mn;

    Lista(unsigned int cap);
    ~Lista();
    void ZerarMetricas(){Cn=0;Mn=0;}
    void InserirRapido(string nome,string rg);
    void InserirNoFinal();
    void InserirNoComeço();
    void InserirNoMeio();
    void RemoverDoFim();
    void RemoverDoComeço();
    void RemoverDoMeio();
    void SalvaLista();
    void ProcuraRG();
    void Imprimir();
    void ExibirMetricas();
    void SelectionSort();
    void InsertionSort();
    void BubbleSort();
    void ShellSort();
    void QuickSort(int inicio =-1, int fim =-1);
    void MergeSort(int inicio = -1, int fim = -1);
    void BuscaBinaria();
};