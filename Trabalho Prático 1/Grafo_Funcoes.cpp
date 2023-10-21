#include <iostream>
#include <vector>
#include <fstream>
#include "Grafo.hpp"

using namespace std;

class Principal
{
    private:
    vector<vector<int>> matriz;
    int quantidade_vertice;
    int quantidade_aresta;
    bool direcionado;
    vector<Vertice> vetor;

    public:
    void menu_principal()
    {
        cout << "\n ======================================";
        cout << "\n|    1. Importar Grafo Pronto          |";
        cout << "\n ======================================";
        cout << "\n|    2. Criar Grafo Vazio              |";
        cout << "\n ======================================";
        cout << "\n|    3. Exibir Matriz Adjacente        |";
        cout << "\n ======================================";
        cout << "\n|    4. Consultar Vertice Adjacente    |";
        cout << "\n ======================================";
        cout << "\n|    5. Inserir Novas Arestas          |";
        cout << "\n ======================================";
        cout << "\n|    6. Remover Arestas Existentes     |";
        cout << "\n ======================================";
        cout << "\n|    7. Editar Coordenadas dos Vértices|";
        cout << "\n ======================================";
        cout << "\n|    8. Consultar Primeiro Adjacente   |";
        cout << "\n ======================================";
        cout << "\n|    9. Consultar Proximo Adjacente    |";
        cout << "\n ======================================";
        cout << "\n|   10. Consultar Lista de Adjacentes  |";
        cout << "\n ======================================";
        cout << "\n|   11. Exportar Grafo                 |";
        cout << "\n ======================================";
        cout << "\n|    0. Sair                           |";
        cout << "\n ======================================" << endl;
    }

    void importa_arquivo()
    {
        string nome_arquivo;

        cout << "\n Digite o nome do arquivo: ";
        cin >> nome_arquivo;

        ifstream arquivo(nome_arquivo);

        if (arquivo.is_open())
        {
            string linha;
            arquivo >> linha;
            direcionado = !(linha.compare("false") == 0);

            arquivo >> quantidade_vertice;
            cria_grafo_vazio(quantidade_vertice);

            for (int i = 0; i < quantidade_vertice; i++) 
            {
                int a, b, c;
                arquivo >> a >> b >> c;
                Vertice vertice(a, b, c);
                vetor[a] = vertice;
            }

            arquivo >> quantidade_aresta;

            for (int i = 0; i < quantidade_aresta; i++) 
            {
                int origem, destino, peso;

                arquivo >> origem >> destino >> peso;
                inseri_aresta(origem, destino, peso);
            }

            arquivo.close();
            cout << "\n Arquivo importado com sucesso!";
            Sleep(2000);
        } 
        else 
        {
            cout << "\n Não foi possivel ler o arquivo!" << endl;
        }
    }

    void inseri_aresta(int origem, int destino, int peso) 
    {
        if (matriz[origem][destino] == -1) 
        {
            matriz[origem][destino] = peso;

            if (!direcionado) 
            {
                matriz[destino][origem] = peso;
            }

            quantidade_aresta++;
        }
    }

    void remove_aresta(int origem, int destino) 
    {
        if (matriz[origem][destino] != -1) 
        {
            matriz[origem][destino] = -1;

            if (!direcionado) 
            {
                matriz[destino][origem] = -1;
            }
            
            quantidade_aresta--;
        }
    }

    void matriz_reset() 
    {
        for (int i = 0; i < quantidade_vertice; i++) 
        {
            for (int j = 0; j < quantidade_vertice; j++) 
            {
                matriz[i][j] = -1;
            }
        }
    }

    void cria_grafo_vazio(int quantidade_vertice) 
    {
        this->quantidade_vertice = quantidade_vertice;
        vetor.resize(quantidade_vertice);
        matriz.resize(quantidade_vertice, vector<int>(quantidade_vertice, -1));
        matriz_reset();
    }

    void matriz_impressao() 
    {
        for (int i = 0; i < quantidade_vertice; i++) 
        {
            for (int j = 0; j < quantidade_vertice; j++) 
            {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool consulta_vertice(int origem, int destino) 
    {
        if (matriz[origem][destino] != -1) 
        {
            return true;
        }
        return false;
    }

    void edita_coordenada(int vertice, int x, int y) 
    {
        vetor[vertice].setX(x);
        vetor[vertice].setY(y);
    }

    int consulta_primeiro_adj(int origem) 
    {
        for (int i = 0; i < quantidade_vertice; i++) 
        {
            if (matriz[origem][i] != -1) 
            {
                return i;
            }
        }
        return -1;
    }

    int consulta_proximo_adj(int vertice, int origem) 
    {
        bool encontrado = false;

        for (int i = origem + 1; i < quantidade_vertice; i++) 
        {
            if (matriz[vertice][i] > -1) 
            {
                encontrado = true;
                return i;
            }
        }
        return -1;
    }

    void consulta_lista(int origem) 
    {
        cout << "\n Os vértices adjacentes são: ";

        for (int i = 0; i < quantidade_vertice; i++) 
        {
            if (matriz[origem][i] != -1) 
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    void exporta_arquivo() 
    {
        string nome_arquivo;
        cout << "\n Digite o nome do arquivo: ";
        cin >> nome_arquivo;

        ofstream arquivo(nome_arquivo);

        if (arquivo.is_open()) 
        {
            if (direcionado) 
            {
                arquivo << "true" << endl;
            } 
            else 
            {
                arquivo << "false" << endl;
            }

            arquivo << quantidade_vertice << endl;

            for (int i = 0; i < quantidade_vertice; i++) 
            {
                Vertice vertice = vetor[i];
                arquivo << vertice.getId() << " " << vertice.getX() << " " << vertice.getY() << endl;
            }

            if (direcionado) 
            {
                arquivo << quantidade_aresta << endl;
            } 
            else 
            {
                arquivo << quantidade_aresta * 2 << endl;
            }

            for (int i = 0; i < quantidade_vertice; i++) 
            {
                for (int j = 0; j < quantidade_vertice; j++) 
                {
                    if (matriz[i][j] != -1) 
                    {
                        arquivo << i << " " << j << " " << matriz[i][j] << endl;
                    }
                }
            }

            arquivo.close();
            cout << "\n Arquivo exportado com sucesso!";
            Sleep(2000);
        } 
        else 
        {
            cout << "\n Não foi possivel criar o arquivo!" << endl;
        }
    }

    void cria_vertice() 
    {
        int x, y;

        for (int i = 0; i < quantidade_vertice; i++) 
        {
            cout << "\n Digite a coordenada X do vértice: ";
            cin >> x;
            cout << "\n Digite a coordenada Y do vértice: ";
            cin >> y;

            vetor[i] = Vertice(i, x, y);
        }
    }

    int getquantidade_vertice() 
    {
        return quantidade_vertice;
    }

    void setquantidade_vertice(int quantidade_vertice) 
    {
        this->quantidade_vertice = quantidade_vertice;
    }

    int getquantidade_aresta() 
    {
        return quantidade_aresta;
    }

    void setquantidade_aresta(int quantidade_aresta) 
    {
        this->quantidade_aresta = quantidade_aresta;
    }

    bool isDirecionado() 
    {
        return direcionado;
    }

    void setDirecionado(bool direcionado) 
    {
        this->direcionado = direcionado;
    }
};
        
