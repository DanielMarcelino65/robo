#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Coordenadas{
	int x;
	int y;

    Coordenadas(int a, int b)
    {
        a = x;
        b = y;
    }
};

/*bool operator==(Coordenadas a, Coordenadas b)
{
	if(a.x == b.x && a.y == b.y)
	{
		return true;
	}
	else
	{
		false;
	}
}*/

bool operator==(int a, Coordenadas b)
{
	if(a == b.x || a == b.y)
	{
		return true;
	}
	else
	{
		false;
	}
}

int main()
{
	//Posição inicial do carro
    vector<Coordenadas> coordenadas;
    Coordenadas carro(8, 4);
    Coordenadas saida(1, 4);

    int posOgX = 8;
    int posOgY = 4;

	//Posição do final do labirinto
	
	//Labirinto
	string lab[10][10];

    int contador = 1;


    int i = 0;
    /*int memoria = 0;
    int caminhoX[];
    int caminhoY[];*/
	
	//Conta quantas vezes o carro vai para cada direção
    int contadorE = 0;
    int contadorD = 0;
    int contadorF = 0;
    int contadorT = 0;
	
	//Verifica se o carro andou para os lados sem necessidade
    int verificarE = 0;
    int verificarD = 0;
    int verificarF = 0;
    int verificarT = 0;
	
	//Direção em que o carro andou
    bool foiDireita = false;
    bool foiEsquerda = false;
    bool foiFrente = false;
    bool foiTras = false;
    int verificar = 0;
	
	//Direções possiveis para o carro
    bool podeEsquerda = true;
    bool podeDireita = true;
    bool podeFrente = true;

    bool caminhoFrente = false;
    bool caminhoDireita = false;
    bool caminhoEsquerda = false;
    bool caminhoTras = false;

    bool caminhoAlt = false;
	
	//Variaveis para manter o loop/pausar o programa
    int loop = 54;
    int loop2 = 55;
    char lixo;	
	
	//Primeira corrida
	//Geração da matriz
    while(loop == 54)
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(i == 0 || i == 10-1 || j == 0 || j == 10-1)
                {
                    lab[i][j] = "*";
                }
                else
                {
                    lab[i][j] = " ";
                }
            }
        }
        
        //Labirinto/Caminho
        for(int i = 4; i <= 8; i++)
        {
            lab[8][i] = ".";
        }
        
        for(int i = 8; i >= 4; i--)
        {
            lab[i][8] = ".";
        }

        for(int i = 8; i >= 6; i--)
        {
            lab[4][i] = ".";
        }

        for(int i = 4; i <= 6; i++)
        {
            lab[i][6] = ".";
        }
        
        for(int i = 8; i >= 1; i--)
        {
            lab[6][i] = ".";
        }
        
        for(int i = 6; i >= 3; i--)
        {
            lab[i][4] = ".";
        }

        for(int i = 6; i >= 3; i--)
        {

            lab[i][1] = ".";
        }

        for(int i = 2; i <= 4; i++)
        {
            lab[3][i] = ".";
        }

        for(int i = 3; i >= 2; i--)
        {
            lab[i][4] = ".";
        }
        
        lab[saida.x][saida.y] = "#"; //Ponto final
        lab[carro.x][carro.y] = "C"; //Icone do carro

		//Printa o labirinto
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                cout << lab[i][j] << " ";
            }
            cout << endl;
        }
		
		//Quando o carro chega no final, ele quebra o loop
        if(carro.x == saida.x && carro.y == saida.y)
        {
        	if(coordenadas.size() > 0)
        	{
        		cout << "Carro encontrou outros possiveis caminhos" << endl;
        		cout << "Pressione qualquer tecla para continuar: ";
        		cin >> lixo;
        		carro.x = posOgX;
        		carro.y = posOgY;
                caminhoAlt = true;
        		system("clear || cls");
			}
            else
            {
                break;
            }
        }

        if(lab[carro.x][carro.y-1] == "." && lab[carro.x-1][carro.y] == "." && foiDireita == false && caminhoAlt == false)
        {
            coordenadas.push_back(Coordenadas(carro.x, carro.y));
        }

        if(carro.x == coordenadas[coordenadas.size()-1] && carro.y == coordenadas[coordenadas.size()-1] && caminhoAlt == true)
        {
            carro.x--;
        }
        
        if(lab[carro.x][carro.y-1] != " " && lab[carro.x][carro.y-1] != "*" && podeEsquerda == true) //Carro vai para esquerda
        {
            carro.y--;
            if(foiDireita == true) //Se o carro for para a esquerda logo após ir para a direita, ele subtrai 1 do contadorD
            {
                contadorD -= 1;
            }
            else
            {
                contadorE += 1;
            }
            
            //Carro foi para esquerda
            foiEsquerda = true;
            foiFrente = false;
            foiTras = false;
        }
        else
        {
            if(lab[carro.x-1][carro.y] != " " && lab[carro.x-1][carro.y] != "*" && podeFrente == true) //Se nao der, o carro vai para frente
            {
                carro.x--;
                podeEsquerda = true;
                if(foiTras == true) //Se o carro for para frente logo após ir para tras, ele subtrai 1 do contadorT
                {
                    contadorT -= 1;
                }
                else
                {
                    contadorF += 1;
                }
                
                //Carro foi para frente
                foiFrente = true;
                foiDireita = false;
                foiEsquerda = false;
            }
            else
            {
                if(lab[carro.x][carro.y+1] != " " && lab[carro.x][carro.y+1] != "*" && podeDireita == true) //Se nao der, o carro vai para direita
                {
                    carro.y++;
                    podeFrente = true;
                    podeEsquerda = false;
                    if(foiEsquerda == true) //Se o carro for para a direita logo após ir para a esquerda, ele subtrai 1 do contadorE
                    {
                         contadorE -= 1;
                    }
                    else
                    {
                        contadorD += 1;
                    }
                    
                    //Carro foi para esquerda
                    foiDireita = true;
                    foiFrente = false;
                    foiTras = false;
                }
                else
                {
                    if(lab[carro.x+1][carro.y] != " " && lab[carro.x+1][carro.y] != "*") //Se nao der, o carro vai para tras
                    {
                        carro.x++;
                        podeEsquerda = false;
                        podeFrente = false;
                        podeDireita = true;
                        if(foiFrente == true) //Se o carro for para tras logo após ir para frente, ele subtrai 1 do contadorF
                        {
                            contadorF -= 1;
                        }
                        else
                        {
                            contadorT += 1;
                        }
                        
                        //Carro foi para tras
                        foiTras = true;
                        foiDireita = false;
                        foiEsquerda = false;
                        
                    }
                    else
                    {
                        if(lab[carro.x][carro.y+contador] != "." && lab[carro.x+contador][carro.y] != "." && lab[carro.x-contador][carro.y] != ".") //Se o carro encontrar um caminho fechado no lado direito, ele da um "giro" e volta
                        {
                            carro.y--;
                            contador++;
                            podeEsquerda = false;
                            podeFrente = false;
                            podeDireita = false;
                            if(foiDireita == true)
                            {
                                contadorD -= 1;
                            }
                            else
                            {
                                contadorE += 1;
                            }
                            foiEsquerda = true;
                            foiFrente = false;
                            foiTras = false;
                        }
                    }
                }
            }
        }

        cout << endl;
        cout << endl;
        cout << "Caminhos alternativos: " << coordenadas.size() << endl;
        //cout << "Caminho x: " << caminhoX[i] << "\nCaminho y: " << caminhoY[i] << endl;
        cout << "Pressione qualquer botao para continuar: ";
        cin >> lixo;

        system("clear || cls");
    }

    cout << endl;
    cout << endl;
    cout << "Carro chegou ao final" << endl;
    cout << "Pressione qualquer botao para a segunda corrida: ";
    cin >> lixo;
	
	
	//Segunda corrida
    carro.x = 8;
    carro.y = 4;

    podeEsquerda = true;
    podeDireita = true;
    podeFrente = true;

    while(loop2 == 55)
    {
        system("clear || cls");

        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(i == 0 || i == 10-1 || j == 0 || j == 10-1)
                {
                    lab[i][j] = "*";
                }
                else
                {
                    lab[i][j] = " ";
                }
            }
        }
        
        for(int i = 4; i <= 8; i++)
        {
            lab[8][i] = ".";
        }
        
        for(int i = 8; i >= 4; i--)
        {
            lab[i][8] = ".";
        }

        for(int i = 8; i >= 6; i--)
        {
            lab[4][i] = ".";
        }

        for(int i = 4; i <= 6; i++)
        {
            lab[i][6] = ".";
        }
        
        for(int i = 8; i >= 1; i--)
        {
            lab[6][i] = ".";
        }
        
        for(int i = 6; i >= 3; i--)
        {
            lab[i][4] = ".";
        }

        for(int i = 6; i >= 3; i--)
        {
            
            lab[i][1] = ".";
        }

        for(int i = 2; i <= 4; i++)
        {
            lab[3][i] = ".";
        }

        for(int i = 3; i >= 2; i--)
        {
            lab[i][4] = ".";
        }
        
        lab[saida.x][saida.y] = "#";
        
        lab[carro.x][carro.y] = "C";

        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                cout << lab[i][j] << " ";
            }
            cout << endl;
        }

        if(carro.x == saida.x && carro.y == saida.y)
        {
            break;
        }

        if(lab[carro.x][carro.y-1] != " " && lab[carro.x][carro.y-1] != "*" && podeEsquerda == true && contadorE > 0) //Carro vai para esquerda
        {
            carro.y--;
            contadorE--;
        }
        else if(lab[carro.x-1][carro.y] != " " && lab[carro.x-1][carro.y] != "*" && podeFrente == true && contadorF > 0) //Carro vai para frente
        {
            carro.x--;
            contadorF--;
            podeEsquerda = true;
        }
        else if(lab[carro.x][carro.y+1] != " " && lab[carro.x][carro.y+1] != "*" && podeDireita == true && contadorD > 0) //Carro vai para direita
        {
            carro.y++;
            contadorD--;
            podeEsquerda = false;
            podeFrente = true;
        }
        else if(lab[carro.x+1][carro.y] != " " && lab[carro.x+1][carro.y] != "*" && contadorT > 0) //Carro vai para tras
        {
            carro.x++;
            contadorT--;
            podeDireita = true;
            podeEsquerda = false;
            podeFrente = false;
        }

        cout << endl;
        cout << endl;
        cout << "Pressione qualquer botao para continuar: ";
        cin >> lixo; 
    }
    cout << endl;
    cout << endl;
    cout << "Carro chegou ao final" << endl;
	
    return 0;
}
