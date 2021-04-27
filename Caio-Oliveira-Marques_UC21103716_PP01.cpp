//Nome completo: Caio Oliveira Marques Matr�cula: UC21103716 Curso: Ci�ncias da Computa��o
 
 
// Dicas que eu segui do livro "C�digo Limpo":
// - Nome de vari�veis pronunci�veis e que revelam seu prop�sito;
// - Nome de fun��es que deixa claro o seus objetivos;
// - Identa��o;
// - Dividir o c�digo entre fun��es e cada uma com seu papel definido;
 // - Coment�rios que tentam explicar o c�digo.
 
#include<stdio.h>  //Importando biblioteca b�sica do C
#include<locale.h> // Importando uma biblioteca com a fun��o para mudar a formata��o para os padr�es brasileiros
#include <stdlib.h> // Importando uma biblioteca com a fun��o system()

// Declarando as fun��es que vou utilizar durante o projeto:
// Pelo nome das fun��es fica bem claro qual � o objetivo delas (uma das dicas de nomea��o que apliquei do livro "C�digo Limpo":
int solicitaSessoes();
char perguntaSexo();
char* perguntaNomeDoFilme(char nomeDoFilme[]);
int perguntaQuantidadePessoas();
int perguntaIdade();
void registraFilme();
char perguntaSeDesejaContinuar();
void apresentaInformacoesIniciais(char nomeDoFilme[], int quantidadeDeMasculinos, int quantidadeDeFemininas);
void imprimeQuantidadePessoasClassificadasPorIdade(int quantidadeCriancas, int quantidadeAdolescentes, 
	int quantidadeAdultos, int quantidadeIdosos);
void apresentaQuantidadeHomensEMulheres(int maioresDeIdadeMasculinos, int maioresDeIdadeFemininas);

// fun��o principal (por onde o algoritmo vai come�ar):
int main(){ 
	// Trocar as formata��es de dados para os padr�es que usamos no Brasil.
	setlocale(LC_ALL, "Portuguese"); 
	
	// Reservando um espa�o na mem�ria de um char para guardar se o usu�rio deseja ou n�o continuar registrando filmes
	char desejaContinuar; 
	do{
		// aqui chama-se o m�todo que efetivamente cadastra um filme.
		registraFilme();
		// atribuindo um valor pra vari�vel "desejaContinuar" declarada anteriormente, como o retorno da fun��o 
		// "perguntaSeDesejaContinuar".
		desejaContinuar = perguntaSeDesejaContinuar();
		//fun��o que limpa a tela:
		system("CLS"); 
	// se a vari�vel "desejaContinuar" tiver como valor 'S', o la�o continua, caso contr�rio, a execu��o para e
	// o programa fecha.
	} while(desejaContinuar == 'S'); 
	
	printf("Fim do programa.");
}

// Essa fun��o vai perguntar e devolver 'S' se o usu�rio quer continuar registrando filmes ou 'N' se o usu�rio n�o
// quer continuar registrando filmes:
char perguntaSeDesejaContinuar(){
	char desejaContinuar;
	while(true){
		// O c�digo abaixo pergunta se o usu�rio deseja continuar registrando filmes (funcionalidade nova que eu implementei)
		// para o usu�rio e o armazena na vari�vel "desejaContinuar" declarada anteriormente.
		printf("Deseja continuar (S -> sim, N -> n�o): ");
		scanf("%c", &desejaContinuar);
		fflush(stdin);
		// se o valor que o usu�rio digitar est� entre os valores aceitados (S ou N) o la�o se interrompe
		if(desejaContinuar == 'S' || desejaContinuar == 'N') break; 
		// caso o contr�rio, uma mensagem de erro � exibida ao usu�rio e a execu��o do la�o continua
		else printf("Valor inv�lido, digite outro valor...\n");
	}
	 // a fun��o retorna um char com os valores S ou N
	return desejaContinuar;
}

// Essa fun��o deve registrar um filme e fornecer dados sobre as pessoas que o assistiu
void registraFilme(){
	
	//   Reservando espa�os na mem�ria para guardar a quantidade de pessoas segundo a classifica��o 
	// (crian�as, adolescentes, adultos e idosos)
	int quantidadeCriancas = 0; 
	int quantidadeAdolescentes = 0;
	int quantidadeAdultos = 0;
	int quantidadeIdosos = 0;
	
	// as vari�veis abaixo cont�m a quantidade de pessoas do sexo masculino e pessoas do sexo feminino
	int quantidadeDeMasculinos = 0;
	int quantidadeDeFemininas = 0;
	
	// as vari�veis abaixo cont�m a quantidade de pessoas do sexo feminino maiores de idade e as pessoas do sexo masculino
	// maiores de idade.
	int mulheres = 0;
	int homens = 0;
	
	// Inicializa uma vari�vel chamada nomeDoFilme que ser� alterada na fun��o pergunta nome do filme e receber� o nome do
	//filme fornecido pelo usu�rio.
	char nomeDoFilme[100] = "string";
	perguntaNomeDoFilme(nomeDoFilme);
	// chama a fun��o que solicita quantas sess�es o filme vai ter, como n�o foi explicitado nada para
	// fazer com esse informa��o, eu n�o armazenei em nenhuma vari�vel
	solicitaSessoes(); 
	
	// chama a fun��o que pergunta para o usu�rio quantas pessoas 
	// assistiram ao filme e armazena na vari�vel "quantidadePessoas";
	int quantidadePessoas = perguntaQuantidadePessoas(); 
	
	for(int i = 0; i < quantidadePessoas; i++){ // para cada pessoa que assistiu ao filme fa�a:
		
		char sexo = perguntaSexo(); //pergunta o sexo dessa pessoa e armazena na vari�vel "sexo"
		int idade = perguntaIdade(); //pergunta a idade dessa pessoa e armazena na vari�vel "idade"
		bool ehMaiorDeIdade = idade >= 18;
		
		// se a idade da pessoa analisada � maior ou igual a 13, 
		// a quantidade de crian�as aumenta um
		if(idade <= 13) quantidadeCriancas++; 
			//l�gica similar se aplica para as outras classifica��es
			else if(idade <= 17) quantidadeAdolescentes++;
				else if(idade <= 64) quantidadeAdultos++;
					// se n�o � nenhuma das classifica��es acima ent�o a idade � maior que 64 e
					// portanto � idoso.
					else quantidadeIdosos++; 

		//se o usu�rio for masculino, a quantidade de usu�rios masculinos aumenta um e se o usu�rio for feminino, a
		// quantidade de usu�rios femininos aumenta um.
		if(sexo == 'M') quantidadeDeMasculinos++;
			else quantidadeDeFemininas++;
		
		// se a idade for maior que 18 e for do sexo masculino,
		// a vari�vel que conta os maiores de idade masculinos aumenta um e se a idade for maior que 18 e for do sexo 
		// feminino, a vari�vel que conta os maiores de idade femininos aumenta em um;
		
		if(ehMaiorDeIdade && sexo == 'M') homens++; 
		if(ehMaiorDeIdade && sexo == 'F') mulheres++;
		
	}

	system("CLS"); // essa fun��o limpa a tela 
	
	// as fun��es seguintes imprimem para o usu�rio o nome do filme e as vari�veis contadas no algoritmo (a quantidade 
	//de pessoas do sexo masculino e do sexo feminino e a quantidade de crian�as, adolescentes, adultos e idosos)
	
	apresentaInformacoesIniciais(nomeDoFilme, quantidadeDeMasculinos, quantidadeDeFemininas);
	imprimeQuantidadePessoasClassificadasPorIdade(quantidadeCriancas, quantidadeAdolescentes, quantidadeAdultos,
		quantidadeIdosos);
	
	system("PAUSE"); 
	system("CLS"); 
	
	apresentaQuantidadeHomensEMulheres(homens, mulheres);
}

// Fun��o que imprime na tela a quantidade de pessoas maiores de idade que assistiram ao filme segundo seu sexo.
void apresentaQuantidadeHomensEMulheres(int homens, int mulheres){
	printf("Mulheres maiores de idade que assistiram ao filme: %i\n",mulheres);
	printf("Homens maiores de idade que assistiram ao filme: %i\n\n", homens);	
}

// Fun��o que imprime na tela a quantidade de pessoas que assistiram ao filme segundo suas classifica��es baseadas na idade.
void imprimeQuantidadePessoasClassificadasPorIdade(int quantidadeCriancas, int quantidadeAdolescentes, 
	int quantidadeAdultos, int quantidadeIdosos){
	printf("---------------------------\n");
	printf("Crian�as: %i\n", quantidadeCriancas);
	printf("Adolescentes: %i\n", quantidadeAdolescentes);
	printf("Adultos: %i\n", quantidadeAdultos);
	printf("Idosos: %i\n", quantidadeIdosos);	
	printf("---------------------------\n");
}

// Fun��o que imprime na tela as seguintes informa��es: nome do filme, quantidade de pessoas do sexo masculino 
//e quantidade de pessoas do sexo feminino que assistiram ao filme
void apresentaInformacoesIniciais(char nomeDoFilme[], int quantidadeDeMasculinos, int quantidadeDeFemininas){
	printf("---------------------------\n");
	printf("Nome do filme: %s", nomeDoFilme);
	printf("A quantidade de pessoas do sexo masculino que viram o filme �: %i\n", quantidadeDeMasculinos);
	printf("A quantidade de pessoas do sexo feminino que viram o filme �: %i\n\n\n", quantidadeDeFemininas);
}

// Essa fun��o vai perguntar e devolver a quantidade de sess�es do filme
int solicitaSessoes(){
	int sessoes;
	while(true){
		// O c�digo abaixo pergunta quantas sess�es ter�o esse filme
		// para o usu�rio e o armazena na vari�vel "sessoes" declarada anteriormente.

		printf("Digite a quantidade de sess�es para esse filme: "); 
		scanf("%i", &sessoes);

		// caso o n�mero informado seja igual a 2 ent�o o n�mero informado � v�lido e sai do la�o
		// caso contr�rio o algoritmo informa o usu�rio que o valor digitado � inv�lido e solicita novamente.
		if(sessoes == 2) break; 
			else printf("Valor digitado � inv�lido, digite outro valor...\n");
	}
	// retorna o dado da vari�vel "sessoes" declarada anteriormente
	return sessoes;
}

// Essa fun��o vai perguntar e devolver o n�mero de pessoas que assistiram o filme.
int perguntaQuantidadePessoas(){ 
	// reservando um espa�o na mem�ria de um inteiro para armazenar a quantidade de pessoas que assistiram ao filme
	int quantidadePessoas;
	while(true){
		// O c�digo abaixo pergunta quantas pessoas assistiram o filme
		// para o usu�rio e o armazena na vari�vel "quantidadePessoas" declarada anteriormente.
		printf("Digite a quantidade de pessoas que ir�o assistir ao filme: ");
		scanf("%i", &quantidadePessoas);
		fflush(stdin);
		
		// caso o n�mero informado seja igual ou maior que 10 ent�o o n�mero informado � v�lido e sai do la�o
		// caso contr�rio o algoritmo informa o usu�rio que o valor digitado � inv�lido e solicita novamente.
		if(quantidadePessoas >= 10) break; 
			else printf("Valor digitado � inv�lido, digite outro valor...\n");
		
	}
	// retorna o dado da vari�vel "quantidadePessoas" declarada anteriormente
	return quantidadePessoas;
}

// Essa fun��o vai perguntar e devolver o sexo de uma pessoa que assistiu ao filme.
char perguntaSexo(){
	// reservando o espa�o de um char na mem�ria
	char sexo;
	while(true){
		// O c�digo abaixo pergunta o sexo para o usu�rio e o armazena na vari�vel "sexo" declarada anteriormente.
		printf("Digite o seu sexo (M -> masculino, F -> feminino): ");
		scanf("%c", &sexo);
		fflush(stdin);
		
		// caso o valor seja v�lido (sexo seja M ou F), o la�o quebra, caso contr�rio, o algoritmo informa ao
		// usu�rio que o valor informado � inv�lido e pede novamente o dado.
		if(sexo == 'M' || sexo == 'F') break;
			else printf("Sexo inv�lido, digite outro valor...\n");
	}
	// retorna o dado da vari�vel "sexo" declarada anteriormente
	return sexo;
}

// Essa fun��o vai perguntar e devolver a idade de uma pessoa que assistiu ao filme
int perguntaIdade(){
	int idade;
	while(true){
		// O c�digo abaixo pergunta a idade para o usu�rio e o armazena na vari�vel "idade" declarada anteriormente.
		printf("Digite a idade: ");
		scanf("%i", &idade);
		fflush(stdin);
		
		// caso o valor passado pelo usu�rio seja v�lido (idade � maior ou igual a 3 e menor ou igual a 100), o la�o quebra, 
		// caso contr�rio, o algoritmo informa ao usu�rio que o valor informado � inv�lido e pede novamente o dado.
		if(idade >= 3 && idade <= 100) break;
			else printf("Valor da idade inv�lido, digite outro valor...\n");
	}
	// retorna o dado da vari�vel "idade" declarada anteriormente
	return idade; 
}

char* perguntaNomeDoFilme(char nomeDoFilme[]){	
	while(true){
		//dentro desse la�o perguntamos pro usu�rio o nome do filme, e se o nome for "vazio" exibimos
		//uma mensagem de erro para o usu�rio e continuamos o la�o, caso o contr�rio, o la�o se interrompe 
		//e o valor do nome do filme � v�lido.
		printf("Digite o nome do filme: ");
		fgets(nomeDoFilme, 100, stdin);
		if(nomeDoFilme == "vazio") printf("Nome do filme inv�lido, digite outro valor...\n");
			else break;
	}
	return nomeDoFilme;
}
