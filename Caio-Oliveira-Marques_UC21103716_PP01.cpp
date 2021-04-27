//Nome completo: Caio Oliveira Marques Matrícula: UC21103716 Curso: Ciências da Computação
 
 
// Dicas que eu segui do livro "Código Limpo":
// - Nome de variáveis pronunciáveis e que revelam seu propósito;
// - Nome de funções que deixa claro o seus objetivos;
// - Identação;
// - Dividir o código entre funções e cada uma com seu papel definido;
 // - Comentários que tentam explicar o código.
 
#include<stdio.h>  //Importando biblioteca básica do C
#include<locale.h> // Importando uma biblioteca com a função para mudar a formatação para os padrões brasileiros
#include <stdlib.h> // Importando uma biblioteca com a função system()

// Declarando as funções que vou utilizar durante o projeto:
// Pelo nome das funções fica bem claro qual é o objetivo delas (uma das dicas de nomeação que apliquei do livro "Código Limpo":
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

// função principal (por onde o algoritmo vai começar):
int main(){ 
	// Trocar as formatações de dados para os padrões que usamos no Brasil.
	setlocale(LC_ALL, "Portuguese"); 
	
	// Reservando um espaço na memória de um char para guardar se o usuário deseja ou não continuar registrando filmes
	char desejaContinuar; 
	do{
		// aqui chama-se o método que efetivamente cadastra um filme.
		registraFilme();
		// atribuindo um valor pra variável "desejaContinuar" declarada anteriormente, como o retorno da função 
		// "perguntaSeDesejaContinuar".
		desejaContinuar = perguntaSeDesejaContinuar();
		//função que limpa a tela:
		system("CLS"); 
	// se a variável "desejaContinuar" tiver como valor 'S', o laço continua, caso contrário, a execução para e
	// o programa fecha.
	} while(desejaContinuar == 'S'); 
	
	printf("Fim do programa.");
}

// Essa função vai perguntar e devolver 'S' se o usuário quer continuar registrando filmes ou 'N' se o usuário não
// quer continuar registrando filmes:
char perguntaSeDesejaContinuar(){
	char desejaContinuar;
	while(true){
		// O código abaixo pergunta se o usuário deseja continuar registrando filmes (funcionalidade nova que eu implementei)
		// para o usuário e o armazena na variável "desejaContinuar" declarada anteriormente.
		printf("Deseja continuar (S -> sim, N -> não): ");
		scanf("%c", &desejaContinuar);
		fflush(stdin);
		// se o valor que o usuário digitar está entre os valores aceitados (S ou N) o laço se interrompe
		if(desejaContinuar == 'S' || desejaContinuar == 'N') break; 
		// caso o contrário, uma mensagem de erro é exibida ao usuário e a execução do laço continua
		else printf("Valor inválido, digite outro valor...\n");
	}
	 // a função retorna um char com os valores S ou N
	return desejaContinuar;
}

// Essa função deve registrar um filme e fornecer dados sobre as pessoas que o assistiu
void registraFilme(){
	
	//   Reservando espaços na memória para guardar a quantidade de pessoas segundo a classificação 
	// (crianças, adolescentes, adultos e idosos)
	int quantidadeCriancas = 0; 
	int quantidadeAdolescentes = 0;
	int quantidadeAdultos = 0;
	int quantidadeIdosos = 0;
	
	// as variáveis abaixo contém a quantidade de pessoas do sexo masculino e pessoas do sexo feminino
	int quantidadeDeMasculinos = 0;
	int quantidadeDeFemininas = 0;
	
	// as variáveis abaixo contém a quantidade de pessoas do sexo feminino maiores de idade e as pessoas do sexo masculino
	// maiores de idade.
	int mulheres = 0;
	int homens = 0;
	
	// Inicializa uma variável chamada nomeDoFilme que será alterada na função pergunta nome do filme e receberá o nome do
	//filme fornecido pelo usuário.
	char nomeDoFilme[100] = "string";
	perguntaNomeDoFilme(nomeDoFilme);
	// chama a função que solicita quantas sessões o filme vai ter, como não foi explicitado nada para
	// fazer com esse informação, eu não armazenei em nenhuma variável
	solicitaSessoes(); 
	
	// chama a função que pergunta para o usuário quantas pessoas 
	// assistiram ao filme e armazena na variável "quantidadePessoas";
	int quantidadePessoas = perguntaQuantidadePessoas(); 
	
	for(int i = 0; i < quantidadePessoas; i++){ // para cada pessoa que assistiu ao filme faça:
		
		char sexo = perguntaSexo(); //pergunta o sexo dessa pessoa e armazena na variável "sexo"
		int idade = perguntaIdade(); //pergunta a idade dessa pessoa e armazena na variável "idade"
		bool ehMaiorDeIdade = idade >= 18;
		
		// se a idade da pessoa analisada é maior ou igual a 13, 
		// a quantidade de crianças aumenta um
		if(idade <= 13) quantidadeCriancas++; 
			//lógica similar se aplica para as outras classificações
			else if(idade <= 17) quantidadeAdolescentes++;
				else if(idade <= 64) quantidadeAdultos++;
					// se não é nenhuma das classificações acima então a idade é maior que 64 e
					// portanto é idoso.
					else quantidadeIdosos++; 

		//se o usuário for masculino, a quantidade de usuários masculinos aumenta um e se o usuário for feminino, a
		// quantidade de usuários femininos aumenta um.
		if(sexo == 'M') quantidadeDeMasculinos++;
			else quantidadeDeFemininas++;
		
		// se a idade for maior que 18 e for do sexo masculino,
		// a variável que conta os maiores de idade masculinos aumenta um e se a idade for maior que 18 e for do sexo 
		// feminino, a variável que conta os maiores de idade femininos aumenta em um;
		
		if(ehMaiorDeIdade && sexo == 'M') homens++; 
		if(ehMaiorDeIdade && sexo == 'F') mulheres++;
		
	}

	system("CLS"); // essa função limpa a tela 
	
	// as funções seguintes imprimem para o usuário o nome do filme e as variáveis contadas no algoritmo (a quantidade 
	//de pessoas do sexo masculino e do sexo feminino e a quantidade de crianças, adolescentes, adultos e idosos)
	
	apresentaInformacoesIniciais(nomeDoFilme, quantidadeDeMasculinos, quantidadeDeFemininas);
	imprimeQuantidadePessoasClassificadasPorIdade(quantidadeCriancas, quantidadeAdolescentes, quantidadeAdultos,
		quantidadeIdosos);
	
	system("PAUSE"); 
	system("CLS"); 
	
	apresentaQuantidadeHomensEMulheres(homens, mulheres);
}

// Função que imprime na tela a quantidade de pessoas maiores de idade que assistiram ao filme segundo seu sexo.
void apresentaQuantidadeHomensEMulheres(int homens, int mulheres){
	printf("Mulheres maiores de idade que assistiram ao filme: %i\n",mulheres);
	printf("Homens maiores de idade que assistiram ao filme: %i\n\n", homens);	
}

// Função que imprime na tela a quantidade de pessoas que assistiram ao filme segundo suas classificações baseadas na idade.
void imprimeQuantidadePessoasClassificadasPorIdade(int quantidadeCriancas, int quantidadeAdolescentes, 
	int quantidadeAdultos, int quantidadeIdosos){
	printf("---------------------------\n");
	printf("Crianças: %i\n", quantidadeCriancas);
	printf("Adolescentes: %i\n", quantidadeAdolescentes);
	printf("Adultos: %i\n", quantidadeAdultos);
	printf("Idosos: %i\n", quantidadeIdosos);	
	printf("---------------------------\n");
}

// Função que imprime na tela as seguintes informações: nome do filme, quantidade de pessoas do sexo masculino 
//e quantidade de pessoas do sexo feminino que assistiram ao filme
void apresentaInformacoesIniciais(char nomeDoFilme[], int quantidadeDeMasculinos, int quantidadeDeFemininas){
	printf("---------------------------\n");
	printf("Nome do filme: %s", nomeDoFilme);
	printf("A quantidade de pessoas do sexo masculino que viram o filme é: %i\n", quantidadeDeMasculinos);
	printf("A quantidade de pessoas do sexo feminino que viram o filme é: %i\n\n\n", quantidadeDeFemininas);
}

// Essa função vai perguntar e devolver a quantidade de sessões do filme
int solicitaSessoes(){
	int sessoes;
	while(true){
		// O código abaixo pergunta quantas sessões terão esse filme
		// para o usuário e o armazena na variável "sessoes" declarada anteriormente.

		printf("Digite a quantidade de sessões para esse filme: "); 
		scanf("%i", &sessoes);

		// caso o número informado seja igual a 2 então o número informado é válido e sai do laço
		// caso contrário o algoritmo informa o usuário que o valor digitado é inválido e solicita novamente.
		if(sessoes == 2) break; 
			else printf("Valor digitado é inválido, digite outro valor...\n");
	}
	// retorna o dado da variável "sessoes" declarada anteriormente
	return sessoes;
}

// Essa função vai perguntar e devolver o número de pessoas que assistiram o filme.
int perguntaQuantidadePessoas(){ 
	// reservando um espaço na memória de um inteiro para armazenar a quantidade de pessoas que assistiram ao filme
	int quantidadePessoas;
	while(true){
		// O código abaixo pergunta quantas pessoas assistiram o filme
		// para o usuário e o armazena na variável "quantidadePessoas" declarada anteriormente.
		printf("Digite a quantidade de pessoas que irão assistir ao filme: ");
		scanf("%i", &quantidadePessoas);
		fflush(stdin);
		
		// caso o número informado seja igual ou maior que 10 então o número informado é válido e sai do laço
		// caso contrário o algoritmo informa o usuário que o valor digitado é inválido e solicita novamente.
		if(quantidadePessoas >= 10) break; 
			else printf("Valor digitado é inválido, digite outro valor...\n");
		
	}
	// retorna o dado da variável "quantidadePessoas" declarada anteriormente
	return quantidadePessoas;
}

// Essa função vai perguntar e devolver o sexo de uma pessoa que assistiu ao filme.
char perguntaSexo(){
	// reservando o espaço de um char na memória
	char sexo;
	while(true){
		// O código abaixo pergunta o sexo para o usuário e o armazena na variável "sexo" declarada anteriormente.
		printf("Digite o seu sexo (M -> masculino, F -> feminino): ");
		scanf("%c", &sexo);
		fflush(stdin);
		
		// caso o valor seja válido (sexo seja M ou F), o laço quebra, caso contrário, o algoritmo informa ao
		// usuário que o valor informado é inválido e pede novamente o dado.
		if(sexo == 'M' || sexo == 'F') break;
			else printf("Sexo inválido, digite outro valor...\n");
	}
	// retorna o dado da variável "sexo" declarada anteriormente
	return sexo;
}

// Essa função vai perguntar e devolver a idade de uma pessoa que assistiu ao filme
int perguntaIdade(){
	int idade;
	while(true){
		// O código abaixo pergunta a idade para o usuário e o armazena na variável "idade" declarada anteriormente.
		printf("Digite a idade: ");
		scanf("%i", &idade);
		fflush(stdin);
		
		// caso o valor passado pelo usuário seja válido (idade é maior ou igual a 3 e menor ou igual a 100), o laço quebra, 
		// caso contrário, o algoritmo informa ao usuário que o valor informado é inválido e pede novamente o dado.
		if(idade >= 3 && idade <= 100) break;
			else printf("Valor da idade inválido, digite outro valor...\n");
	}
	// retorna o dado da variável "idade" declarada anteriormente
	return idade; 
}

char* perguntaNomeDoFilme(char nomeDoFilme[]){	
	while(true){
		//dentro desse laço perguntamos pro usuário o nome do filme, e se o nome for "vazio" exibimos
		//uma mensagem de erro para o usuário e continuamos o laço, caso o contrário, o laço se interrompe 
		//e o valor do nome do filme é válido.
		printf("Digite o nome do filme: ");
		fgets(nomeDoFilme, 100, stdin);
		if(nomeDoFilme == "vazio") printf("Nome do filme inválido, digite outro valor...\n");
			else break;
	}
	return nomeDoFilme;
}
