/*
CURSO: SUP TEC EM ANÁLISE E DESENVOLVIMENTO E SISTEMAS
DISCLIPINA: PIM IV
UNIP - UNIVERSIDADE PAULISTA
AUTORES: LUCAS LUCHI NUNES
                 ROBERT PEREIRA
                 TAINARA KIOKO MOTIZUKI
*/

// {bibliotecas.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>



// Struct data. Utilizado para calcular idade dos pacientes.
typedef struct data DATA;
struct data
{
	int dia;
	int mes;
	int ano;
};

// Struct local
typedef struct local LOCAL;
struct local
{
	char rua[30];
	char n[10];
	char bairro[20];
	char cidade[20];
	char estado[10];
	char cep[10];
};

// Struct paciente
typedef struct paciente PACIENTE;
struct paciente
{
	char nome[40];
	char cpf[20];
	char telefone[20];
	LOCAL endereco;
	DATA nasc;
	char email[40];
	DATA diagnostico;
	char comorbidades[60];
};

// Criando tipo booleno.
typedef enum boolean bool;
enum boolean
{
   true = 1, false = 0
};

void SetCursorPosition(int XPos, int YPos)
{
	COORD coord;
	coord.X = XPos;
	coord.Y = YPos;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int fileExists(const char *filename)
{
	FILE * file;
	if (file = fopen(filename, "r"))
	{
		fclose(file);
		return 1;
	}

	return 0;
}

int main()
{
	unsigned int cp = 1252;
	unsigned int cpin = GetConsoleCP();
	unsigned int cpout = GetConsoleOutputCP();

	SetConsoleCP(cp);
	SetConsoleOutputCP(cp);

	if (fileExists("Users.txt") == 0)
	{
		FILE * Users;
		Users = fopen("Users.txt", "w");
		fclose(Users);
	}

	int opcao = 0;
	int podeEntrar = 0;
	int confirma = 0;

	//{ Página inicial, tela de login ou cadastro
	do {
		system("cls");
		printf("\n  ====================  CADASTRO DE PACIENTES (COVID-19)  ====================");
		printf("\n  ============================================================================");
		printf("\n                                                                                                                                                                             ");
		printf("\n                           ***** BEM-VINDO(A)! *****                                                                                                      ");
		printf("\n                                                                                                                                                                             ");
		printf("\n                                                                                                                                                                             ");
		printf("\n                           1 - FAZER LOGIN                                                                                                                          ");
		printf("\n                           2 - CADASTRAR NOVO USUÁRIO                                                                                                    ");
		printf("\n                                                                                                                                                                              ");
		printf("\n                           0 - SAIR                                                                                                                                       ");
		printf("\n                                                                                                                                                                              ");
		printf("\n                                                                                                                                                                              ");
		printf("\n  ============================================================================");
		printf("\n\n  > Escolha uma opção: ");
		scanf("%i", &opcao);
	//}
		switch (opcao)
		{
			case 1:
				{
					// Página de Login
					do {
						char login[15];
						char senha[15];

						system("cls");
		                printf("\n  ====================  CADASTRO DE PACIENTES (COVID-19)  ====================");
                        printf("\n  ============================================================================");
		                printf("\n                                                                                                                                                                             ");
		                printf("\n                           ***** BEM-VINDO(A)! *****                                                                                                         ");
		                printf("\n                                                                                                                                                                             ");
                        printf("\n                           POR FAVOR, INSIRA SEUS DADOS DE ACESSO:                                                                                 ");
                        printf("\n                                                                                                                                                                             ");
                        printf("\n                           LOGIN:                                                                                                                                         ");
		                printf("\n                                                                                                                                                                              ");
		                printf("\n                           SENHA:                                                                                                                                        ");
		                printf("\n                                                                                                                                                                              ");
		                printf("\n                                                                                                                                                                              ");
		                printf("\n  ============================================================================");

						SetCursorPosition(33, 13);
						scanf("%s", &login);

						SetCursorPosition(33, 17);

						int pass = 0;

						do {
							senha[pass] = getch();

							if (senha[pass] != '\r' && senha[pass] != '\b')
							{
								printf("*");
							}

							if (senha[pass] == '\b' && pass >= 1)
							{
								pass -= 2;
								SetCursorPosition(33 + pass, 17);
								printf(" ");
								SetCursorPosition(33 + pass, 17);
							}

							pass++;

						}

						while (senha[pass - 1] != '\r');

						senha[pass - 1] = '\0';

						SetCursorPosition(0, 20);

						FILE * Users;
						Users = fopen("Users.txt", "r");

						char usuario[15];
						char senhaCorreta[15];
						int encontrouUsuario = 0;

						while (fgets(usuario, sizeof(usuario), Users) != NULL)
						{
							if (strstr(usuario, login) != NULL)
							{
								encontrouUsuario = 1;
								fscanf(Users, "%[^\n]", senhaCorreta);
							}
						}

						fclose(Users);

						if (encontrouUsuario == 1)
						{
							if (strstr(senha, senhaCorreta) != NULL)
							{
								podeEntrar = 1;
							}
							else
							{
								printf(" > Senha incorreta! Pressione ENTER para tentar novamente.");
								podeEntrar = 0;
								getch();
                            }
						}
						else
						{
							printf(" > Usuário não encontrado! Pressione ENTER para tentar novamente.");
							podeEntrar = 0;
							getch();
						}
					}

					while (podeEntrar != 1);

					// Checagem de arquivos
					if (fileExists("ListaDePacientes.txt") == 0)
					{
						FILE * ListaDePacientes;
						ListaDePacientes = fopen("ListaDePacientes.txt", "w");
						fclose(ListaDePacientes);
					}

					if (fileExists("GrupoDeRisco.txt") == 0)
					{
						FILE * GrupoDeRisco;
						GrupoDeRisco = fopen("GrupoDeRisco.txt", "w");
						fclose(GrupoDeRisco);
					}

					if (fileExists("GrupoSemRisco.txt") == 0)
					{
						FILE * GrupoSemRisco;
						GrupoSemRisco = fopen("GrupoSemRisco.txt", "w");
						fclose(GrupoSemRisco);
					}

					// Menu Principal
					do {
						system("cls");
		                printf("\n  ====================  CADASTRO DE PACIENTES (COVID-19)  ====================");
                        printf("\n  ============================================================================");
		                printf("\n                                                                                                                                                                                                             ");
		                printf("\n                       ***** MENU PRINCIPAL *****                                                                                                                                      ");
		                printf("\n                                                                                                                                                                                                             ");
                        printf("\n                     1 - CONSULTAR TODOS OS PACIENTES                                                                                                                   ");
                        printf("\n                     2 - CONSULTAR PACIENTES (GRUPO DE RISCO)                                                                                                     ");
                        printf("\n                     3 - CONSULTAR PACIENTES (GRUPO SEM RISCO)                                                                                                   ");
                        printf("\n                     4 - CADASTRAR NOVO PACIENTE                                                                                                                            ");
		                printf("\n                                                                                                                                                                                                             ");
		                printf("\n                     0 - SAIR                                                                                                                                                                     ");
		                printf("\n                                                                                                                                                                                                             ");
		                printf("\n                                                                                                                                                                                                             ");
		                printf("\n  ============================================================================");
						printf("\n\n  > Escolha uma opção: ");
						scanf("%i", &opcao);

						switch (opcao)
						{
							// Consulta de todos os pacientes
							case 1:
								{int dia, mes, ano;
									system("cls");
									printf("\n====================  CONSULTA DE PACIENTES  ====================");
									printf("\n\n\n\n");

									FILE * ListaDePacientes;
									ListaDePacientes = fopen("ListaDePacientes.txt", "r");

									if (ListaDePacientes == NULL)
									{
										printf(" > Não foi possível abrir arquivo. Pressione ENTER para voltar ao menu principal.");
										break;
									}

									char pacientesGeral[1500];

									int quantidadePacientes = 0;

									while (fgets(pacientesGeral, 1500, ListaDePacientes) != NULL)
									{
									    quantidadePacientes++;
										printf("%s", pacientesGeral);
									}

									if(quantidadePacientes == 0){
                                        printf(" > Não há pacientes cadastrados! Pressione ENTER para voltar ao menu principal.");
									}

									fclose(ListaDePacientes);
									getch();

									break;
								}

                            // Consulta de pacientes do grupo de risco
							case 2:
								{
									system("cls");
									printf("\n====================  CONSULTA DE PACIENTES (GRUPO DE RISCO)  ====================");
									printf("\n\n\n\n");

									FILE * GrupoDeRisco;
									GrupoDeRisco = fopen("GrupoDeRisco.txt", "r");

									if (GrupoDeRisco == NULL)
									{
										printf(" > Não foi possível abrir arquivo. Pressione ENTER para voltar ao menu principal.");
										break;
									}

									char pacientesRisco[1500];
                                    int quantidadePacientes = 0;

									while (fgets(pacientesRisco, 1500, GrupoDeRisco) != NULL)
									{
										quantidadePacientes++;
										printf("%s", pacientesRisco);
									}

									if(quantidadePacientes == 0)
                                        {
                                        printf(" > Não há pacientes cadastrados! Pressione ENTER para voltar ao menu principal.");
									    }

									fclose(GrupoDeRisco);
									getch();

									break;
								}

								// Consulta de pacientes do grupo sem risco
							case 3:
								{
									system("cls");
									printf("\n====================  CONSULTA DE PACIENTES (GRUPO SEM RISCO)  ====================");
									printf("\n\n\n\n");

									FILE * GrupoSemRisco;
									GrupoSemRisco = fopen("GrupoSemRisco.txt", "r");

									if (GrupoSemRisco == NULL)
									{
										printf(" > Não foi possível abrir arquivo. Pressione ENTER para voltar ao menu principal.");
										break;
									}

									char pacientesSemRisco[1500];
                                    int quantidadePacientes = 0;

									while (fgets(pacientesSemRisco, 1500, GrupoSemRisco) != NULL)
									{
										quantidadePacientes++;
										printf("%s", pacientesSemRisco);
									}

									if(quantidadePacientes == 0){
                                        printf(" > Não há pacientes cadastrados! Pressione ENTER para voltar ao menu principal.");
									}

									fclose(GrupoSemRisco);
									getch();

									break;
								}

                            // Cadastro de pacientes
							case 4:
								{
									PACIENTE novoPaciente;
									int salvarCadastro = 0;
									int anoAtual = 2022;
									int idade;
									int dia, mes, ano;
									bool possuiComorbidade;
									char branco[15] = "NAO POSSUI";

									do {
                                            char temp;
                                            system("cls");
                                            printf("\n  ====================  CADASTRO DE PACIENTES (COVID-19)  ====================");
                                            printf("\n  ============================================================================");
                                            printf("\n                                                                                                                                                                             ");
                                            printf("\n                     ***** CADASTRO DE NOVO PACIENTE *****                                                                                        ");
                                            printf("\n                                                                                                                                                                             ");
                                            printf("\n  NOME:                                       CPF:                                                                                                                     ");
                                            printf("\n                                                                                                                                                                             ");
                                            printf("\n  TELEFONE:                                 DATA DE NASCIMENTO (DD/MM/AAAA):                                                                   ");
                                            printf("\n                                                                                                                                                                              ");
                                            printf("\n  RUA:                           Nº:                 BAIRRO:                                                                                                         ");
                                            printf("\n                                                                                                                                                                              ");
                                            printf("\n  CIDADE:                     ESTADO:         CEP:                                                                                                                ");
                                            printf("\n                                                                                                                                                                              ");
                                            printf("\n  E-MAIL:                                    DATA DO DIAGNÓSTICO (DD/MM/AAAA):                                                                    ");
                                            printf("\n                                                                                                                                                                              ");
                                            printf("\n  POSSUI COMORBIDADE? (1 = SIM; 2 = NÃO):                                                                                                             ");
                                            printf("\n                                                                                                                                                                              ");
                                            printf("\n  ============================================================================");
                                            printf("\n\n   > Registre nos campos acima os dados do paciente.");

                                            SetCursorPosition(8, 9);
                                            scanf("%c", &temp);
                                            scanf("%[^\n]", &novoPaciente.nome);

                                            SetCursorPosition(51, 9);
                                            scanf("%c", &temp);
                                            scanf("%[^\n]", &novoPaciente.cpf);

                                            SetCursorPosition(13, 13);
                                            scanf("%c", &temp);
                                            scanf("%[^\n]", &novoPaciente.telefone);

                                            SetCursorPosition(77, 13);
                                            scanf("%d%*c%d%*c%d", &dia, &mes, &ano);
                                            novoPaciente.nasc.dia = dia;
                                            novoPaciente.nasc.mes = mes;
                                            novoPaciente.nasc.ano = ano;

                                            SetCursorPosition(7, 17);
                                            scanf("%c", &temp);
                                            scanf("%[^\n]", &novoPaciente.endereco.rua);

                                            SetCursorPosition(37, 17);
                                            scanf("%c", &temp);
                                            scanf("%[^\n]", &novoPaciente.endereco.n);

                                            SetCursorPosition(61, 17);
                                            scanf("%c", &temp);
                                            scanf("%[^\n]", &novoPaciente.endereco.bairro);

                                            SetCursorPosition(10, 21);
                                            scanf("%c", &temp);
                                            scanf("%[^\n]", &novoPaciente.endereco.cidade);

                                            SetCursorPosition(38, 21);
                                            scanf("%c", &temp);
                                            scanf("%[^\n]", &novoPaciente.endereco.estado);

                                            SetCursorPosition(51, 21);
                                            scanf("%c", &temp);
                                            scanf("%[^\n]", &novoPaciente.endereco.cep);

                                            SetCursorPosition(10, 25);
                                            scanf("%c", &temp);
                                            scanf("%[^\n]", &novoPaciente.email);

                                            SetCursorPosition(79, 25);
                                            scanf("%d%*c%d%*c%d", &dia, &mes, &ano);
                                            novoPaciente.diagnostico.dia = dia;
                                            novoPaciente.diagnostico.mes = mes;
                                            novoPaciente.diagnostico.ano = ano;

                                            SetCursorPosition(42, 29);
                                            scanf("%i", &opcao);
                                            switch(opcao)
                                            {
                                            case 1:
                                                printf("\n  COMORBIDADE: ");
                                                SetCursorPosition(15, 31);
                                                scanf("%c", &temp);
                                                gets(novoPaciente.comorbidades);
                                                possuiComorbidade = true;
                                                break;
                                            case 2:
                                                possuiComorbidade = false;
                                                break;
                                            default:
                                                {
                                                    printf("\n\n Opção inválida!");
                                                    getch();
                                                    break;
                                            }
                                            break;
										}

										SetCursorPosition(1, 37);
										printf("                                                                               ");
										SetCursorPosition(1, 37);
										printf("  > Deseja salvar este cadastro? (1 = SIM; 0 = NÃO): ");
										SetCursorPosition(53, 37);
										scanf("%i", &salvarCadastro);

									}

									while (salvarCadastro != 1);

//{ Lista geral
									FILE * ListaDePacientes;
									ListaDePacientes = fopen("ListaDePacientes.txt", "a");

                                    {
                                        fprintf(ListaDePacientes, "NOME: %s\n", novoPaciente.nome);
                                        fprintf(ListaDePacientes, "CPF: %s\n", novoPaciente.cpf);
                                        fprintf(ListaDePacientes, "TELEFONE: %s\n", novoPaciente.telefone);
                                        fprintf(ListaDePacientes, "ENDEREÇO: %s, nº %s\n", novoPaciente.endereco.rua, novoPaciente.endereco.n);
                                        fprintf(ListaDePacientes, "BAIRRO: %s\n", novoPaciente.endereco.bairro);
                                        fprintf(ListaDePacientes, "CIDADE: %s - %s\n", novoPaciente.endereco.cidade, novoPaciente.endereco.estado);
                                        fprintf(ListaDePacientes, "CEP: %s\n", novoPaciente.endereco.cep);
                                        fprintf(ListaDePacientes, "DATA DE NASCIMENTO: %i / %i / %i\n", novoPaciente.nasc.dia, novoPaciente.nasc.mes, novoPaciente.nasc.ano);

                                        idade = anoAtual - novoPaciente.nasc.ano;

                                        fprintf(ListaDePacientes, "IDADE: %i\n", idade);
                                        fprintf(ListaDePacientes, "E-MAIL: %s\n", novoPaciente.email);
                                        fprintf(ListaDePacientes, "DATA DO DIAGNÓSTICO: %i / %i / %i\n", novoPaciente.diagnostico.dia, novoPaciente.diagnostico.mes, novoPaciente.diagnostico.ano);

                                       if (!possuiComorbidade)
                                        {
                                            fprintf(ListaDePacientes, "COMORBIDADES: %s\n\n\n", branco);
                                        }
                                        else
                                        {
                                            fprintf(ListaDePacientes, "COMORBIDADES: %s\n\n\n", novoPaciente.comorbidades);
                                        }

                                    }

									fclose(ListaDePacientes);
									//}

//{Lista de grupo de risco
									FILE * GrupoDeRisco;
									GrupoDeRisco = fopen("GrupoDeRisco.txt", "a");

									if (idade >= 65 || possuiComorbidade)
									{
                                        /*
                                        fprintf(GrupoDeRisco, "NOME: %s\n", novoPaciente.nome);
                                        fprintf(GrupoDeRisco, "CPF: %s\n", novoPaciente.cpf);
                                        fprintf(GrupoDeRisco, "DATA DE NASCIMENTO: %i / %i / %i\n", novoPaciente.nasc.dia, novoPaciente.nasc.mes, novoPaciente.nasc.ano);

                                        dade = anoAtual - novoPaciente.nasc.ano;

                                        fprintf(GrupoDeRisco, "TELEFONE: %s\n", novoPaciente.telefone);
                                        fprintf(GrupoDeRisco, "ENDEREÇO: %s, nº %s\n", novoPaciente.endereco.rua, novoPaciente.endereco.n);
                                        fprintf(GrupoDeRisco, "BAIRRO: %s\n", novoPaciente.endereco.bairro);
                                        fprintf(GrupoDeRisco, "CIDADE: %s - %s\n", novoPaciente.endereco.cidade, novoPaciente.endereco.estado);
                                        fprintf(GrupoDeRisco, "E-MAIL: %s\n", novoPaciente.email);
                                        fprintf(GrupoDeRisco, "DATA DO DIAGNÓSTICO: %i / %i / %i\n", novoPaciente.diagnostico.dia, novoPaciente.diagnostico.mes, novoPaciente.diagnostico.ano);

                                        if (!possuiComorbidade)
                                        {
                                            fprintf(GrupoDeRisco, "COMORBIDADES: %s\n\n\n", branco);
                                        }
                                        else
                                        {
                                            fprintf(GrupoDeRisco, "COMORBIDADES: %s\n\n\n", novoPaciente.comorbidades);
                                        }
                                        */

                                        fprintf(GrupoDeRisco, "CEP: %s\n", novoPaciente.endereco.cep);
                                        fprintf(GrupoDeRisco, "IDADE: %i\n\n\n", idade);

									}

									fclose(GrupoDeRisco);
									//}

//{Lista grupos em risco
									FILE * GrupoSemRisco;
									GrupoSemRisco = fopen("GrupoSemRisco.txt", "a");

									if (idade < 65 && !possuiComorbidade)
									{
                                        fprintf(GrupoSemRisco, "NOME: %s\n", novoPaciente.nome);
                                        fprintf(GrupoSemRisco, "CPF: %s\n", novoPaciente.cpf);
                                        fprintf(GrupoSemRisco, "TELEFONE: %s\n", novoPaciente.telefone);
                                        fprintf(GrupoSemRisco, "ENDEREÇO: %s, nº %s\n", novoPaciente.endereco.rua, novoPaciente.endereco.n);
                                        fprintf(GrupoSemRisco, "BAIRRO: %s\n", novoPaciente.endereco.bairro);
                                        fprintf(GrupoSemRisco, "CIDADE: %s - %s\n", novoPaciente.endereco.cidade, novoPaciente.endereco.estado);
                                        fprintf(GrupoSemRisco, "CEP: %s\n", novoPaciente.endereco.cep);
                                        fprintf(GrupoSemRisco, "DATA DE NASCIMENTO: %i / %i / %i\n", novoPaciente.nasc.dia, novoPaciente.nasc.mes, novoPaciente.nasc.ano);

                                        idade = anoAtual - novoPaciente.nasc.ano;

                                        fprintf(GrupoSemRisco, "IDADE: %i\n", idade);
                                        fprintf(GrupoSemRisco, "E-MAIL: %s\n", novoPaciente.email);
                                        fprintf(GrupoSemRisco, "DATA DO DIAGNÓSTICO: %i / %i / %i\n", novoPaciente.diagnostico.dia, novoPaciente.diagnostico.mes, novoPaciente.diagnostico.ano);
                                        fprintf(GrupoSemRisco, "COMORBIDADES: %s\n\n\n", branco);
									}

									fclose(GrupoSemRisco);
									//}
                                    possuiComorbidade = false;
									break;
								}

							case 0:
								{
									break;
								}

							default:
								{
									printf("\n\n Opção inválida! Pressione ENTER para tentar novamente.");
									getch();
									break;
								}
						}
					}

					while (opcao != 0);
					break;
				}

            // Criação de usuário
			case 2:
				{
					char novoLogin[15];
					char novaSenha[15];

					    system("cls");
		                printf("\n  ====================  CADASTRO DE PACIENTES (COVID-19)  ====================");
                        printf("\n  ============================================================================");
		                printf("\n                                                                                                                                                                             ");
		                printf("\n                           ***** CRIAÇÃO DE USUÁRIO *****                                                                                                ");
		                printf("\n                                                                                                                                                                             ");
                        printf("\n                           POR FAVOR, INSIRA SEUS DADOS DE ACESSO:                                                                                 ");
                        printf("\n                                                                                                                                                                             ");
                        printf("\n                           LOGIN:                                                                                                                                         ");
		                printf("\n                                                                                                                                                                              ");
		                printf("\n                           SENHA:                                                                                                                                         ");
		                printf("\n                                                                                                                                                                               ");
		                printf("\n                                                                                                                                                                               ");
		                printf("\n  ============================================================================");

					SetCursorPosition(34, 13);
					scanf("%s", &novoLogin);

					SetCursorPosition(34, 17);

					int p = 0;

					do {
						novaSenha[p] = getch();

						if (novaSenha[p] != '\r' && novaSenha[p] != '\b')
						{
							printf("*");
						}

						if (novaSenha[p] == '\b' && p >= 1)
						{
							p -= 2;
							SetCursorPosition(29 + p, 10);
							printf(" ");
							SetCursorPosition(29 + p, 10);
						}

						p++;

					}

					while (novaSenha[p - 1] != '\r');

					novaSenha[p - 1] = '\0';

					SetCursorPosition(0, 20);

					FILE * Users;
					Users = fopen("Users.txt", "r");
					char usuario[15];
					int salvarUsuario = 1;
					while (fgets(usuario, sizeof(usuario), Users) != NULL)
					{
						if (strstr(usuario, novoLogin) != NULL)
						{
							salvarUsuario = 0;
							printf(" > Usuário já cadastrado! Pressione ENTER para voltar.");
							getch();
						}
					}

					fclose(Users);

					if (salvarUsuario == 1)
					{
						FILE * Users;
						Users = fopen("Users.txt", "a");
						fprintf(Users, "%s\n", novoLogin);
						fprintf(Users, "%s\n", novaSenha);
						fclose(Users);

						printf("  > Usuário cadastrado com sucesso! Pressione ENTER para continuar.");
						getch();
					}

					break;
				}

			case 0:
				{
					break;
				}

			default:
				{
					printf("\n\n > Opção inválida! Pressione ENTER para voltar.");
					getch(); // Interrompe a execução até alguma tecla ser clicada.
					break;
				}
		}
	}
	while (opcao != 0);

	SetConsoleCP(cpin);
	SetConsoleOutputCP(cpout);

	return 0;
}
