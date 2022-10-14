#include "etapas.hpp"
#define TAM 5 

void menu(){
    int opcao, sair = 0;
	
    unordered_map<string, vector<int>> mapa_d;
	unordered_map<int, vector<string>> mapa_t_reduzido_permutacao;

    while(sair != 1){
        
        cout << endl;

        cout << "================" << endl;
        cout << "      Menu     " << endl;
        cout << "================" << endl;
        
        cout << endl; 

        cout << "1) Etapa 1" << endl;
        cout << "2) Etapa 2" << endl;
		cout << "3) Etapa 3" << endl;
        cout << "0) Sair" << endl;
        
        cout << endl;
        
        cout << "Selecione uma opção: ";
        cin >> opcao;

        switch (opcao){
        case 1:
            system("clear");
            cout << "Etapa I: " << endl;
            etapaI(&mapa_d);
            break;

        case 2:
			etapaI(&mapa_d);
            system("clear");
            cout << endl << "Etapa II: " << endl;
            etapaII(&mapa_d);
            break;

		case 3:
            system("clear");
            cout << endl << "Etapa III: " << endl;
			etapaIII(&mapa_d, &mapa_t_reduzido_permutacao);
			break;

        case 0:
			etapaI(&mapa_d);
			etapaII(&mapa_d);
            system("clear");
            sair = 1;
            break;

        default:
            break;
        }
    }
}

void tokenizar(string text, unordered_map<string, vector<int>> *mapa, int linha){
	char del = ',';

	stringstream str(text);
	string token;
	vector<int> v;
	unordered_map<string, vector<int>>::iterator nome;
	int aux = 1;
	int col = 1;

	while (getline(str, token, del)){
		if(aux++ < TAM){
			token.insert(0,to_string(col++).append(","));		
		}
		nome = mapa->find(token);
		if(nome != mapa->end()){
			nome->second.push_back(linha);
		}else{
			v.clear();
			v.push_back(linha);
			mapa->insert({token, v});
		}
	}
}

void tokenizar_etapaII(string text, unordered_map<int, vector<string>> *mapa, int linha){
	char del = ',';

	stringstream str(text);
	string token;
	vector<string> v;
	int aux = 1;
	int col = 1;

	while (getline(str, token, del)){
		if(aux++ < TAM){
			token.insert(0,to_string(col++).append(","));		
			v.push_back(token);
		}
	}
	mapa->insert({linha, v});
}

void etapaI(unordered_map<string, vector<int>> *mapa_d);
void etapaII(unordered_map<string, vector<int>> *mapa_d);
void permutacao(unordered_map<int, vector<string>> *mapa_t_reduzido_permutacao,vector <string> vaux, int linha);

void etapaI(unordered_map<string, vector<int>> *mapa_d){
	string path = "DT/D.csv";
	int contadorLinha = 1;

	ifstream myfile(path);
	string line;

	if (myfile.is_open()) {
		while (getline(myfile, line)){
			tokenizar(line, mapa_d, contadorLinha++);
		}
		myfile.close();
	} else cout << "Nao foi possivel abrir o arquivo" << endl;

	unordered_map<string, vector<int>>::iterator it;

	for(it=mapa_d->begin(); it != mapa_d->end(); ++it){
		cout << it->first << endl << "-> ";
		for(int coluna:it->second){
			cout << coluna << " ";
		}
		cout << endl;
	}
}

void etapaII(unordered_map<string, vector<int>> *mapa_d){
	string path = "DT/T.csv";
	unordered_map<int, vector<string>> mapa_t;
	unordered_map<int, vector<string>> mapa_t_reduzido;
	unordered_map<int, vector<string>> mapa_t_reduzido_permutacao;
	int contadorLinha = 1;

	ifstream myfile(path);
	string line;

	if (myfile.is_open()) {
		while (getline(myfile, line)){
			tokenizar_etapaII(line, &mapa_t, contadorLinha++);
		}
		myfile.close();
	} else cout << "Nao foi possivel abrir o arquivo" << endl;

	unordered_map<int, vector<string>>::iterator it;
	unordered_map<string, vector<int>>::iterator it_d;

	vector<string> v2;
	
	for(it=mapa_t.begin(); it != mapa_t.end(); ++it){
		v2.clear();
		for(auto coluna:it->second){
			it_d = mapa_d->find(coluna);
			if(it_d != mapa_d->end()){
				v2.push_back(coluna);
			}
		}
		mapa_t_reduzido.insert({it->first, v2});
	}
	
	for(it=mapa_t_reduzido.begin(); it != mapa_t_reduzido.end(); ++it){
		cout << it->first << endl << "-> ";
		for(auto coluna:it->second){
			cout << coluna << " ";
		}
		cout << endl;
	}

	for(it=mapa_t_reduzido.begin(); it != mapa_t_reduzido.end(); ++it){
		permutacao(&mapa_t_reduzido_permutacao, it->second, it->first);
	}

	for(it=mapa_t_reduzido_permutacao.begin(); it != mapa_t_reduzido_permutacao.end(); ++it){
		cout << it->first << endl << "-> ";
		for(auto coluna:it->second){
			cout << coluna << endl;
		}
		cout << endl;
	}

	etapaIII(mapa_d, &mapa_t_reduzido_permutacao);
}

void permutacao(unordered_map<int, vector<string>> *mapa_t_reduzido_permutacao,vector <string> vaux, int linha){

	string saux = "";
	vector <string> v;

	vector <string> :: iterator it_vec;

	for(it_vec=vaux.begin(); it_vec != vaux.end(); ++it_vec){
			saux.assign(*it_vec);
			v.push_back(saux);
	}
	
	vector<string>::iterator it_segundo;
	vector<string>::iterator it_aux;

	for(it_vec=vaux.begin(); it_vec != vaux.end(); ++it_vec){
		it_aux = it_vec;
		++it_aux;
		for(it_segundo=it_aux; it_segundo != vaux.end(); ++it_segundo){
			saux.assign(*it_vec).append("-").append(*it_segundo);
			v.push_back(saux);
		}
	}

	vector<string>::iterator it_terceiro;

	for(it_vec=vaux.begin(); it_vec != vaux.end(); ++it_vec){
		it_aux = it_vec;
		++it_aux;
		for(it_segundo=it_aux; it_segundo != vaux.end(); ++it_segundo){
			it_aux = it_segundo;
			++it_aux;
			for(it_terceiro=it_aux; it_terceiro != vaux.end(); ++it_terceiro){
				saux.assign(*it_vec).append("-").append(*it_segundo).append("-").append(*it_terceiro);
				v.push_back(saux);
			}			
		}
	}
	mapa_t_reduzido_permutacao->insert({linha, v});
}

void etapaIII(unordered_map<string, vector<int>> *mapa_d, unordered_map<int, vector<string>> *mapa_t_reduzido_permutacao){
	unordered_map<int, vector<string>>::iterator it;
	vector<string> guardarValorSplit;

	unordered_map<string, vector<int>>::iterator itMapaD; 

	for(it=mapa_t_reduzido_permutacao->begin(); it != mapa_t_reduzido_permutacao->end(); ++it){
		for(auto coluna:it->second){
			guardarValorSplit.clear();
			split(coluna, &guardarValorSplit);
			
			if(guardarValorSplit.size() == 1){
				itMapaD = mapa_d->find(coluna);
				if(itMapaD != mapa_d->end()){
				
				}
  			}else{
				vector<string>::iterator itSplit;
				vector<int> resultIntersecao;
				vector<int> aux1;
				vector<int> aux2;
				itSplit = guardarValorSplit.begin();
				aux1 = mapa_d->find(guardarValorSplit.at(0))->second;
				++itSplit;
				resultIntersecao.resize(guardarValorSplit.size());
				
				while(resultIntersecao.size() > 1){
					aux2 = mapa_d->find(*itSplit)->second;
					++itSplit;
					intersecao(aux1, aux2, &resultIntersecao);
					aux1.clear();
					aux2.clear();
					aux1.assign(resultIntersecao.begin(),resultIntersecao.end());
					resultIntersecao.clear();
				}
			}
		}
	}
}

/**
 * @brief 
 * 
 * @param split 
 * @param guardarValorSplit 
 * 
 * falta pegar o resultado encontrado (coluna ou intersecao) e fazer a intersecao com a classe
 * pra depois verificar quem é o maior
 */

void split(string split, vector<string> *guardarValorSplit){
	char del = '-';

	stringstream str(split);
	string token;
	vector<int> v;
	unordered_map<string, vector<int>>::iterator nome;
	int aux = 1;
	int col = 1;

	while (getline(str, token, del)){
		guardarValorSplit->push_back(token);
	}
}

void intersecao(vector <int> intersecaoUm, vector <int> intersecaoDois, vector <int> *ResultadoFinal){
  vector<int>::iterator it;
  ResultadoFinal->resize(intersecaoUm.size() + intersecaoDois.size());
  
  it=set_intersection (intersecaoUm.begin(), intersecaoUm.end(), intersecaoDois.begin(), 
  intersecaoDois.end(), ResultadoFinal->begin());

  ResultadoFinal->resize(it-ResultadoFinal->begin());
}
