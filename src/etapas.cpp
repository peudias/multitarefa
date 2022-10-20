#include "etapas.hpp"
#define TAM 5

unordered_map<string, unordered_map<string, int>> cache;


void menu() {
	int opcao, sair = 0;

	unordered_map<string, vector<int>> mapa_d;
	unordered_map<string, vector<int>> classe;
	unordered_map<int, vector<string>> mapa_t_reduzido_permutacao;

	etapaI(&mapa_d, &classe);
	etapaII(&mapa_d, &classe);//etapa2 chama a 3 e a 3 chama a 4
}

void tokenizar(string text, unordered_map<string, vector<int>> *mapa, int linha, unordered_map<string, vector<int>> *classe) {
	char del = ',';

	stringstream str(text);
	string token;
	vector<int> v;
	unordered_map<string, vector<int>>::iterator nome;
	int aux = 1;
	int col = 1;

	while (getline(str, token, del)) {
		if (aux++ < TAM) {
			token.insert(0, to_string(col++).append(","));
			nome = mapa->find(token);
			if (nome != mapa->end()) {
				nome->second.push_back(linha);
			} else {
				v.clear();
				v.push_back(linha);
				mapa->insert({ token, v });
			}
		} else {
			nome = classe->find(token);
			if (nome != classe->end()) {
				nome->second.push_back(linha);
			} else {
				v.clear();
				v.push_back(linha);
				classe->insert({ token, v });
			}
		}
		//cout << token << endl;
	}
}

void tokenizar_etapaII(string text, unordered_map<int, vector<string>> *mapa, int linha) {
	char del = ',';

	stringstream str(text);
	string token;
	vector<string> v;
	int aux = 1;
	int col = 1;

	while (getline(str, token, del)) {
		if (aux++ < TAM) {
			token.insert(0, to_string(col++).append(","));
			v.push_back(token);
		}
	}
	mapa->insert({ linha, v });

}

void etapaI(unordered_map<string, vector<int>> *mapa_d);
void etapaII(unordered_map<string, vector<int>> *mapa_d);
void permutacao(unordered_map<int, vector<string>> *mapa_t_reduzido_permutacao, vector <string> vaux, int linha);

void etapaI(unordered_map<string, vector<int>> *mapa_d, unordered_map<string, vector<int>> *classe) {
	string path = "DT/D.csv";
	int contadorLinha = 1;

	ifstream myfile(path);
	string line;

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			tokenizar(line, mapa_d, contadorLinha++, classe);
		}
		myfile.close();
	} else cout << "Nao foi possivel abrir o arquivo" << endl;

	unordered_map<string, vector<int>>::iterator it;

	for (it = classe->begin(); it != classe->end(); ++it) {
		//cout << it->first << endl << "-> ";
		for (int coluna : it->second) {
			//cout << coluna << " ";
		}
		//cout << endl;
	}
}

void etapaII(unordered_map<string, vector<int>> *mapa_d, unordered_map<string, vector<int>> *classe) {
	string path = "DT/T.csv";
	unordered_map<int, vector<string>> mapa_t;
	unordered_map<int, vector<string>> mapa_t_reduzido;
	unordered_map<int, vector<string>> mapa_t_reduzido_permutacao;
	int contadorLinha = 1;

	ifstream myfile(path);
	string line;

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			tokenizar_etapaII(line, &mapa_t, contadorLinha++);
		}
		myfile.close();
	} else cout << "Nao foi possivel abrir o arquivo" << endl;

	unordered_map<int, vector<string>>::iterator it;
	unordered_map<string, vector<int>>::iterator it_d;

	vector<string> v2;

	for (it = mapa_t.begin(); it != mapa_t.end(); ++it) {
		v2.clear();
		for (auto coluna : it->second) {
			it_d = mapa_d->find(coluna);
			if (it_d != mapa_d->end()) {
				v2.push_back(coluna);
			}
		}
		mapa_t_reduzido.insert({ it->first, v2 });
	}

	//reduzido
	/*for(it=mapa_t_reduzido.begin(); it != mapa_t_reduzido.end(); ++it){
		cout << it->first << endl << "-> ";
		for(auto coluna:it->second){
			cout << coluna << " ";
		}
		cout << endl;
	}*/

	for (it = mapa_t_reduzido.begin(); it != mapa_t_reduzido.end(); ++it) {
		permutacao(&mapa_t_reduzido_permutacao, it->second, it->first);
	}

	for (it = mapa_t_reduzido_permutacao.begin(); it != mapa_t_reduzido_permutacao.end(); ++it) {
		//cout << it->first << endl << "-> ";
		for (auto coluna : it->second) {
			//cout << coluna << endl;
		}
		//cout << endl;
	}

	etapaIII(mapa_d, &mapa_t_reduzido_permutacao, classe);
}

void permutacao(unordered_map<int, vector<string>> *mapa_t_reduzido_permutacao, vector <string> vaux, int linha) {

	string saux = "";
	vector <string> v;

	vector <string> ::iterator it_vec;

	for (it_vec = vaux.begin(); it_vec != vaux.end(); ++it_vec) {
		saux.assign(*it_vec);
		v.push_back(saux);
	}

	vector<string>::iterator it_segundo;
	vector<string>::iterator it_aux;

	for (it_vec = vaux.begin(); it_vec != vaux.end(); ++it_vec) {
		it_aux = it_vec;
		++it_aux;
		for (it_segundo = it_aux; it_segundo != vaux.end(); ++it_segundo) {
			saux.assign(*it_vec).append("-").append(*it_segundo);
			v.push_back(saux);
		}
	}

	vector<string>::iterator it_terceiro;

	for (it_vec = vaux.begin(); it_vec != vaux.end(); ++it_vec) {
		it_aux = it_vec;
		++it_aux;
		for (it_segundo = it_aux; it_segundo != vaux.end(); ++it_segundo) {
			it_aux = it_segundo;
			++it_aux;
			for (it_terceiro = it_aux; it_terceiro != vaux.end(); ++it_terceiro) {
				saux.assign(*it_vec).append("-").append(*it_segundo).append("-").append(*it_terceiro);
				v.push_back(saux);
			}
		}
	}
	mapa_t_reduzido_permutacao->insert({ linha, v });
}

void etapaIII(unordered_map<string, vector<int>> *mapa_d, unordered_map<int, vector<string>> *mapa_t_reduzido_permutacao, unordered_map<string, vector<int>> *classe) {
	unordered_map<int, vector<string>>::iterator it;
	//vector<string> guardarValorSplit;

	unordered_map<string, vector<int>>::iterator itMapaD;
	unordered_map<string, int> classeAux;
	unordered_map<int, unordered_map<string, int>> resultado;
	unordered_map<int, unordered_map<string, int>>::iterator itResultado;
	unordered_map<string, int>::iterator itResultado2;
	vector <int> ResultadoFinal;
	//unordered_map<string, vector<int>>::iterator itClasse;

	for (itMapaD = classe->begin(); itMapaD != classe->end(); ++itMapaD) {
		classeAux.insert({ itMapaD->first, 0 });
	}

	for (it = mapa_t_reduzido_permutacao->begin(); it != mapa_t_reduzido_permutacao->end(); ++it) {
		resultado.insert({ it->first, classeAux });
		itResultado = resultado.find(it->first);
		ResultadoFinal.clear();

		for (auto coluna : it->second) {
			//etapa4 pesquisa na cache
			etapaIV(coluna, mapa_d, classe, &ResultadoFinal, &itResultado->second, classeAux);
		}
	}

	string guardarClasse;

	for (itResultado = resultado.begin(); itResultado != resultado.end(); ++itResultado) {
		cout << itResultado->first << endl;
		int quemMaior = -1;
		for (itResultado2 = itResultado->second.begin(); itResultado2 != itResultado->second.end(); ++itResultado2) {
			if (itResultado2->second > quemMaior) {
				quemMaior = itResultado2->second;
				guardarClasse = itResultado2->first;
			}
			cout << itResultado2->first << " " << itResultado2->second << endl;
		}
		cout << endl;
		cout << " ==== " << guardarClasse << endl << endl;
		cout << " ------------------- " << endl;
	}
}

void etapaIV(string key,
	unordered_map<string, vector<int>> *mapa_d,
	unordered_map<string, vector<int>> *classe,
	vector <int> *ResultadoFinal,
	unordered_map<string, int> *auxiliar,
	unordered_map<string, int> classeAux) {

	unordered_map<string, unordered_map<string, int>>::iterator itCache;

	itCache = cache.find(key);
	if (itCache != cache.end()) {
		unordered_map<string, int> ValorCache = itCache->second;
		unordered_map<string, int>::iterator itValorCache;
		unordered_map<string, int>::iterator itAuxiliar;

		for (itValorCache = ValorCache.begin(); itValorCache != ValorCache.end(); ++itValorCache) {
			itAuxiliar = auxiliar->find(itValorCache->first);
			itAuxiliar->second += itValorCache->second;
		}
	} else {
		cache.insert({ key,classeAux });
		itCache = cache.find(key);
		operacao(key, mapa_d, classe, ResultadoFinal, auxiliar, &itCache->second);
	}
}

void operacao(string coluna,
	unordered_map<string, vector<int>> *mapa_d,
	unordered_map<string, vector<int>> *classe,
	vector <int> *ResultadoFinal,
	unordered_map<string, int> *auxiliar,
	unordered_map<string, int> *valorCache) {

	vector<string> guardarValorSplit;
	unordered_map<string, vector<int>>::iterator itMapaD;
	unordered_map<string, vector<int>>::iterator itClasse;
	unordered_map<string, int>::iterator itResultado2;
	unordered_map<string, int > ::iterator itValorCache;

	guardarValorSplit.clear();
	split(coluna, &guardarValorSplit);

	if (guardarValorSplit.size() == 1) {
		itMapaD = mapa_d->find(coluna);
		if (itMapaD != mapa_d->end()) {
			for (itClasse = classe->begin(); itClasse != classe->end(); ++itClasse) {
				intersecao(itMapaD->second, itClasse->second, ResultadoFinal);
				itResultado2 = auxiliar->find(itClasse->first);
				itResultado2->second += ResultadoFinal->size();

				itValorCache = valorCache->find(itClasse->first);
				itValorCache->second += ResultadoFinal->size();
			}
		}
	} else {
		vector<string>::iterator itSplit;
		vector<int> resultIntersecao;
		vector<int> aux1;
		vector<int> aux2;
		itSplit = guardarValorSplit.begin();
		aux1 = mapa_d->find(guardarValorSplit.at(0))->second;
		++itSplit;
		resultIntersecao.resize(guardarValorSplit.size());

		while (resultIntersecao.size() > 1) {
			aux2 = mapa_d->find(*itSplit)->second;
			++itSplit;
			aux1.clear();
			aux2.clear();
			resultIntersecao.clear();
			intersecao(aux1, aux2, &resultIntersecao);
			aux1.assign(resultIntersecao.begin(), resultIntersecao.end());
		}
		if (resultIntersecao.size() > 0) {
			itMapaD = mapa_d->find(coluna);
			if (itMapaD != mapa_d->end()) {
				unordered_map<string, vector<int>>::iterator itClasse;

				for (itClasse = classe->begin(); itClasse != classe->end(); ++itClasse) {
					intersecao(itMapaD->second, itClasse->second, ResultadoFinal);
					itResultado2 = auxiliar->find(itClasse->first);
					itResultado2->second += ResultadoFinal->size();

					itValorCache = valorCache->find(itClasse->first);
					itValorCache->second += ResultadoFinal->size();
				}
			}
		}
	}
}

void split(string split, vector<string> *guardarValorSplit) {
	char del = '-';

	stringstream str(split);
	string token;
	vector<int> v;
	unordered_map<string, vector<int>>::iterator nome;
	int aux = 1;
	int col = 1;

	while (getline(str, token, del)) {
		guardarValorSplit->push_back(token);
	}
}

void intersecao(vector <int> intersecaoUm, vector <int> intersecaoDois, vector <int> *ResultadoFinal) {
	vector<int>::iterator it;
	ResultadoFinal->resize(intersecaoUm.size() + intersecaoDois.size());

	it = set_intersection(intersecaoUm.begin(), intersecaoUm.end(), intersecaoDois.begin(),
		intersecaoDois.end(), ResultadoFinal->begin());

	ResultadoFinal->resize(it - ResultadoFinal->begin());
}
