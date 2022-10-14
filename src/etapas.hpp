#ifndef ETAPAS_HPP
#define ETAPAS_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

void menu();

void tokenizar(string text, unordered_map<string, vector<int>> *mapa, int linha, unordered_map<string, vector<int>> *classe);

void tokenizar_etapaII(string text, unordered_map<int, vector<string>> *mapa, int linha);

void etapaI(unordered_map<string, vector<int>> *mapa_d, unordered_map<string, vector<int>> *classe);

void etapaII(unordered_map<string, vector<int>> *mapa_d, unordered_map<string, vector<int>> *classe);

void etapaIII(unordered_map<string, vector<int>> *mapa_d, unordered_map<int, vector<string>> *mapa_t_reduzido_permutacao, unordered_map<string, vector<int>> *classe);

void permutacao(unordered_map<int, vector<string>> *mapa_t_reduzido_permutacao,vector <string> vaux, int linha);

void split(string split, vector<string> *guardarValorSplit);

void intersecao(vector <int> intersecaoUm, vector <int> intersecaoDois, vector <int> *ResultadoFinal);

#endif
