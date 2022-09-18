#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <vector>

#define TAM 5 

using namespace std;

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

int main(void){
	unordered_map<string, vector<int>> mapa_d;
	cout << "Etapa I: " << endl;
	etapaI(&mapa_d);
	cout << endl << "Etapa II: " << endl;
	etapaII(&mapa_d);
	return 0;
}

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
			saux.assign(*it_vec).append("->").append(*it_segundo);
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
				saux.assign(*it_vec).append("->").append(*it_segundo).append("->").append(*it_terceiro);
				v.push_back(saux);
			}			
		}
	}
	mapa_t_reduzido_permutacao->insert({linha, v});
}
