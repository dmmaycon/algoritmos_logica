/*
* EXERCICIO DA MATERIA DE ALGORITMO E LOGICA DE PROGRAMAÇÃO II
* Apresentar um menu utilizando estrutura STRUCT
* Autor: Academico Maycon de Moraes - Curso de Análise e Desenvolvimento de Sistemas
* Faculdade Unicesumar Curitiba
* Data: 21/11/2016
*/

/*
* Desenvolver um algoritmo que armazene a estrutura dos seguintes
* campos e referemte a uma banda (código, nome, gênero e quantidade
* de instrumentos) grave em arquivo de forma ordenada
*/

#include <fstream>
#include<iostream>
#include<conio.h>
using namespace std;

//prototipo das funcoes
void novaBanda();
void imprimirBandas();
void menu();
void gravaArquivos();

//controle do vetor da struct
static int controle = 0;


//struct 
struct Banda{
	int cod;
	char nome[100];
	char genero[100];
	int quant_instrumento;
};


//inicializa o struct
struct Banda vet_banda[10];


main(){
	setlocale(LC_ALL, "Portuguese");
    system("color a");

	menu();
}


void novaBanda(){
	system("cls");
	cout << "Digite o código da banda\n"; cin >> vet_banda[controle].cod;
	fflush(stdin);
	cout << "Digite o nome da banda\n"; cin.getline(vet_banda[controle].nome, 100);
	fflush(stdin);
	cout << "Digite o gênero da banda\n"; cin.getline(vet_banda[controle].genero, 100);
	fflush(stdin);
	cout << "Digite a quantidade de instrumentos da banda\n"; cin >> vet_banda[controle].quant_instrumento;
	fflush(stdin);
	system("cls");
	cout << "\nDados gravados com sucesso!";
	
	controle++;
}

void imprimirBandas(){
	system("cls");
	cout << "--------------------***-----------------------\n";
	for(int x = 0; x < controle; x++){
		cout << "Código da banda: " << vet_banda[x].cod << "\n";
		cout << "Nome da banda: " << vet_banda[x].nome << "\n";
		cout << "Gênero da banda: " << vet_banda[x].genero << "\n";
		cout << "Quantidade de instrumentos: " << vet_banda[x].quant_instrumento << "\n";
		cout << "--------------------***-----------------------\n";
	}
	getch();
}


void menu(){
	int op;
	do {
		system("cls");
	
		cout << "Digite [ 1 ] para cadastrar nova banda\n";
		cout << "Digite [ 2 ] para mostrar as bandas cadastradas\n";
		cout << "Digite [ 3 ] para gravar no arquivo de texto\n";
		cout << "Digite [ 4 ] para sair do programa\n";
		cin >> op;
		
		switch (op){
			case 1:
				novaBanda();
			break;
			case 2:
				imprimirBandas();
			break;
			case 3:
				gravaArquivos();
				cout << "Arquivo gravado com sucesso!\n";
			break;
			case 4:
				system("cls");
				cout << "O programa foi finalizado!";
			break;
			default:
				cout << "Opção inválida!\n";
				cout << "Tecle ENTER!";
				getch();
		}
		
	}while(op != 4);	

}

void gravaArquivos()
{
 ofstream fgrava("bandas.txt");
 
 	fgrava << "--------------------***-----------------------\n";
	for(int x = 0; x < controle; x++){
		fgrava << "Código da banda: "  << vet_banda[x].cod << "\n";
		fgrava << "Nome da banda: "   << vet_banda[x].nome << "\n";
		fgrava << "Gênero da banda: "   << vet_banda[x].genero << "\n";
		fgrava << "Quantidade de instrumentos: " <<  vet_banda[x].quant_instrumento << "\n";
		fgrava << "--------------------***-----------------------\n";
	}
	
}

