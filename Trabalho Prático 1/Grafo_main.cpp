#include <iostream>
#include <windows.h>
#include "Grafo_Funcoes.cpp"
 
using namespace std;
 
int main() 
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
    Principal* principal = new Principal();

    int resposta = 0, direcionado = 0;
    int origem, destino, peso, quantidade_vertice;
    int vertice, x, y;

    do
    {
        system("cls");
        principal->menu_principal();
        cout << "\n - Digite o que deseja fazer: ";
        cin >> resposta;
        
        switch (resposta) 
        {
            case 1:
                system("cls");
                principal->importa_arquivo();
                break;
                
            case 2:
                system("cls");
                cout << "\n O grafo é direcionado? 1-(Sim) 2-(Não): ";
                cin >> direcionado;

                if (direcionado == 1) 
                {
                    principal->setDirecionado(true);
                } 
                else if (direcionado == 2)
                {
                    principal->setDirecionado(false);
                }

                cout << "\n Digite a quantidade de vértices: ";
                cin >> quantidade_vertice;

                principal->cria_grafo_vazio(quantidade_vertice);
                principal->cria_vertice();
                break;
                
            case 3:
                system("cls");
                principal->matriz_impressao();
                system("pause");
                break;
                
            case 4:
                system("cls");
                cout << "\n Digite a origem do vértice: ";
                cin >> origem;
                cout << "\n Digite o destino do vértice: ";
                cin >> destino;

                if (principal->consulta_vertice(origem, destino)) 
                {
                    cout << "\n Os vértices " << origem << " e " << destino << " são adjacentes!" << endl;
                } 
                else 
                {
                    cout << "\n Os vértices " << origem << " e " << destino << " não são adjacentes!" << endl;
                }
                system("pause");
                break;
                
            case 5:
                system("cls");

                if (direcionado == true)
                {
                    cout << "\n Digite a origem do vértice: ";
                    cin >> origem;
                    cout << "\n Digite o destino do vértice: ";
                    cin >> destino;
                    cout << "\n Digite o peso do vértice: ";
                    cin >> peso;
                }
                else
                {
                    cout << "\n Digite a origem do vértice: ";
                    cin >> origem;
                    cout << "\n Digite o destino do vértice: ";
                    cin >> destino;
                }

                principal->inseri_aresta(origem, destino, peso);
                break;
                
            case 6:
                system("cls");
                cout << "\n Digite a origem do vertice: ";
                cin >> origem;
                cout << "\n Digite o destino do vertice: ";
                cin >> destino;

                principal->remove_aresta(origem, destino);
                break;
                
            case 7:
                system("cls");
                cout << "\n Digite o vértice que deseja editar: ";
                cin >> vertice;
                cout << "\n Digite a nova coordenada do eixo X: ";
                cin >> x;
                cout << "\n Digite a nova coordenada do eixo Y: ";
                cin >> y;

                principal->edita_coordenada(vertice, x, y);
                break;
                
            case 8:
                system("cls");
                cout << "\n Digite a origem: ";
                cin >> origem;
                cout << "\n O primeiro adjacente é: " << principal->consulta_primeiro_adj(origem) << endl;
                system("pause");
                break;
                
            case 9:
                system("cls");
                cout << "\n Digite o vértice: ";
                cin >> vertice;
                cout << "\n Digite a origem: ";
                cin >> origem;
                cout << "\n O proximo adjacente é: " << principal->consulta_proximo_adj(vertice, origem) << endl;
                system("pause");
                break;
                
            case 10:
                system("cls");
                cout << "\n Digite a origem: ";
                cin >> origem;

                principal->consulta_lista(origem);
                cout << endl;
                system("pause");
                break;
                
            case 11:
                system("cls");
                principal->exporta_arquivo();
                break;

            case 0:
                cout << "\n Saindo...";
                Sleep(2000);
                system("cls");
                return 0;
            break;
                
            default:
                cout << "\n Nenhuma função corresponde a esse comando! Tente Novamente!";
        }
    } while (resposta != 0);
 
 
  cout << endl;
  return 0;
}