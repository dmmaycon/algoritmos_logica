/*
* EXERCICIO DA MATERIA DE ALGORITMO E LOGICA DE PROGRAMAÇÃO II
* Apresentar um menu utilizando estrutura STRUCT
* Autor: Academico Maycon de Moraes - Curso de Análise e Desenvolvimento de Sistemas
* Faculdade Unicesumar Curitiba
* Data: 27/10/2016
*/

#include<iostream>
#include<conio.h>
using namespace std;



// prototipos da funcoes 
void Menu();
void IncluiFuncionario();
void ConsultaFuncionario();
void exclui_funcionario();


// Tamananho do vetor da struct
static int controle_vet = 0;

//strutc do funcionario
struct Funcionario
{
	int matricula;
	char nome[50];
	char cidade[50];
	char uf[2];
	float salario;
	bool status; //se status ativo = true, se false então está excluido
		
};

//vetor do struct funcionario com o maximo de posições definidas pela MAX
struct Funcionario vet_funcionario[10];

int main()
{	
  setlocale(LC_ALL, "Portuguese");
   system("color a");
	Menu();
   
   
   
return 0;
}


//funcoes

// funcao incluir novo funcionario

void IncluiFuncionario()
{
		system("cls");
		cout << "Qual o número da matricula do funcionário ? \n"; 
		cin >> vet_funcionario[controle_vet].matricula;
		fflush(stdin);
		cout << "Qual o nome do funcionário ? \n";
		cin.getline(vet_funcionario[controle_vet].nome,50);
		fflush(stdin);
		cout << "Qual a cidade que funcionário reside ? \n";
		cin.getline(vet_funcionario[controle_vet].cidade,50); 
		fflush(stdin);
		cout << "Qual o UF desta cidade ? \n";
		cin >> vet_funcionario[controle_vet].uf;
		cout << "Qual o salario do funcionário ? \n"; 
		cin >> vet_funcionario[controle_vet].salario;
		fflush(stdin);
		vet_funcionario[controle_vet].status = true;
		
		controle_vet++; 
}

// funcao consultar

void ConsultaFuncionario()
{
	system("cls");
	cout << "----Lista de Funcionarios do cadastro----\n";
	for(int x = 0; x < controle_vet; x++){
		cout << "Número da Matricula --> " << vet_funcionario[x].matricula << "\n";
		cout << "Nome --> " << vet_funcionario[x].nome << "\n";
		cout << "Cidade --> " << vet_funcionario[x].cidade << "\n";
		cout << "UF --> " << vet_funcionario[x].uf << "\n";
		cout << "Salario --> " << vet_funcionario[x].salario << "\n";
		
		//verifica se o funcionario esta ativo ou inativo
		if(vet_funcionario[x].status == true){
			cout << "Funcionario ATIVO no cadastro!\n"; 
		}else{
			cout << "Funcionario EXCLUÍDO do cadastro!\n"; 
		}
		cout << "\n----------------------------------------------------------------\n";
	}
	cout << "----Fim da Lista de Funcionarios do cadastro----\n";
	cout << "----Digite ENTER para retornar ao menu----\n";
	getch();
}

//funcao excluir um funcionario

void exclui_funcionario(){
	system("cls");
	
	// recebe o valor do matricula a ser excluída
	int auxilia_exclusao;
	
	cout << "Digite o número da matricula do funcionario a ser excluído do cadastro\n";
	cin >> auxilia_exclusao;
	
	for(int x = 0; x < controle_vet; x++){
		//busca a matricula para excluir o funcionario
		if (vet_funcionario[x].matricula == auxilia_exclusao){
			// se a matricula for encontra o status recebe falso e na hora de mostrar exibe como excluido
			vet_funcionario[x].status = false;
			cout << "Cadastro excluido com sucesso!...\n";
		} else{
			cout << "Matricula informada não encontra no nosso cadastro!\n";
		}
		cout << "----Digite ENTER para retornar ao menu----\n";
		getch();
	}
	
}

// funcao ordena funcionario segundo tamanho da matricula
/*
void Ordena_funcionario()
{	
	system("cls");
	
	int auxiliar_ordena = 999999;
	struct Funcionario vet_ordenado[10];
	
	for(int x = 0; x < controle_vet; x++){
	
		if(auxiliar_ordena > vet_funcionario.matricula[x]){
			vet_ordenado[x].matricula = vet_funcionario.matricula[x];
			vet_ordenado[x].nome = vet_funcionario.nome[x];
			vet_ordenado[x].cidade = vet_funcionario.cidade[x];
			vet_ordenado[x].uf = vet_funcionario.uf[x];
			vet_ordenado[x].salario = vet_funcionario.salario[x];
			vet_ordenado[x].status = vet_funcionario.status[x];
		}
		auxiliar_ordena = vet_funcionario.matricula[x + 1];
	}
	
 
}
*/
//funcao menu

void Menu()
{
	bool condicao_menu = true;
	int resposta;
	
	
	
	do{
	//limpa a tela sempre que o menu é chamado
	system("cls");
	cout << "\n# ------------------------------------------------------------- #";
	cout << "\n#	Digite | 1 | para incluir um novo funcionário.          #";
	cout << "\n#	Digite | 2 | para consultar um funcionário.             #";
	cout << "\n#	Digite | 3 | para excluir um funcionário.               #";
	cout << "\n#	Digite | 4 | --função desabilitada-- 	                #";
	cout << "\n#	Digite | 5 | para sair do programa.                     #";
	cout << "\n# ------------------------------------------------------------- #\n";
	
	cin >> resposta;
	
	if(resposta == 5){
		condicao_menu = false;
	}else{
		
		switch (resposta){
			case 1:
				IncluiFuncionario();
			break;
			case 2:
				ConsultaFuncionario();
			break;
			case 3:
				exclui_funcionario();
			break;
			case 4:
				//chama funcao
			break;
			default:
				cout << "Opção digitada invalida...\n Digite qualquer tecla para voltar ao menu!\n";
				getch();
				system("cls");
				Menu();
		}
	}
	
	}while(condicao_menu != false);
	
}
