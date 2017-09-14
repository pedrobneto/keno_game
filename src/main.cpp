#include "kenobet.h"
#include "funcoesaux.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
       
    string linha;
	string betfile;
    ifstream aposta;
    KenoBet Jogada;
    int rodadas = 0;
    float floatvar = 0;
    int intvar = 0;
    
   // Leitura dos dados do arquivo
   
    if(argc == 1) {
        cout << "\nVocê não especificou o arquivo a ser lido, tente novamente.\n\n";
        return EXIT_FAILURE;
    }

    betfile = argv[1];
    
    aposta.open(betfile);

    if(!aposta.is_open()) {
        cout << "\nArquivo no pôde ser lido, tente novamente.\n";
        return EXIT_FAILURE;
    }
    
    //Vector de um vector com os possiveis valores ganhos
    vector<vector<float>> ganhosPorAposta = {
			{0,3},
			{0,1,9},
			{0,1,2,16},
			{0,0.5,2,6,12},
			{0,0.5,1,3,15,50},
			{0,0.5,1,2,3,30,75},
			{0,0.5,0.5,1,6,12,36,100},
			{0,0.5,0.5,1,3,6,19,90,720},
			{0,0.5,0.5,1,2,4,8,20,80,1200},
			{0,0,0.5,1,2,3,5,10,30,600,1800},
			{0,0,0.5,1,1,2,6,15,25,180,1000,3000},
			{0,0,0,0.5,1,2,4,24,72,250,500,2000,4000},
			{0,0,0,0.5,0.5,3,4,5,20,80,240,500,3000,6000},
			{0,0,0,0.5,0.5,2,3,5,12,50,150,500,1000,2000,7500},
			{0,0,0,0.5,0.5,1,2,5,15,50,150,300,600,1200,2500,10000}
		};
    
    
    cout << ">>> Arquivo aberto com sucesso... Preparando-se para ler o arquivo aposta --> " << betfile << " <--" <<endl;


	// Lê as linhas do arquivo e verifica se contém algum erro

	bool booleano = true;

    while(!aposta.eof() && booleano) {
		getline(aposta, linha);
		
		if(linha.length() > 0) {
			stringstream a_stream(linha);
			
			while(!a_stream.eof()) {	
				
			    
				if(a_stream >> floatvar && floatvar > 0) {
					
					Jogada.setWage(floatvar);
					booleano = false;
					break;
				}
			}
		}
	}
    booleano = true;
	while(!aposta.eof() && booleano) {
		
		getline(aposta, linha);
		
		if(linha.length() > 0)	{
						
			stringstream b_stream(linha);
			while(!b_stream.eof()) {
							
				
				if(b_stream >> intvar && intvar > 0) {
								
					rodadas = intvar;
					booleano = false;
					break;
				}
			}
		}
	}
	
	booleano = true;
	
	while(!aposta.eof() && booleano) {
	
    	getline(aposta, linha);
    	
    	if(linha.length() > 0) {
    	    stringstream f_stream(linha);
    		
    		int i = 0;
       	    while(!f_stream.eof() && (f_stream >> intvar) && i < 15) {
	            if(Jogada.addNumber(intvar)) {
                	i++;
	            }
        	}
    	}
	}
	
	
	
	// Mecânica do jogo
	
	float Aposta_rodada = Jogada.getWage() / rodadas;
	
	vector <int> PlayerSpots = Jogada.getSpots();
	quicksort(PlayerSpots, 0, PlayerSpots.size() -1);

	cout << fixed << setprecision(2);
	cout << "--------------------------------------------------" << endl;
	cout << ">>> Aposta lida com sucesso" << endl;
	cout << "Você está apostando um total de R$" << Jogada.getWage() << " reais." << endl;
	cout << "Indo para um total de " << rodadas << " rodadas, apostando R$" << Aposta_rodada << " por rodada." << endl;
	cout << "\nSua aposta tem " << PlayerSpots.size() << " números. Eles são: [ ";
	
	for(auto i (0u) ; i < PlayerSpots.size() ; i++) cout << PlayerSpots[i] << " ";
	
	cout << "]" << endl;
	
	cout << fixed << setprecision(1);
	cout << "-------+---------" << endl;
	cout << "Acertos | Pagamento" << endl;
	cout << "-------+---------" << endl;
	for(auto i (0u) ; i <= PlayerSpots.size() ; i++)
	cout << i << "       |  " << ganhosPorAposta[PlayerSpots.size() - 1][i] << endl;
	
	vector<int> hits;
	srand((int) time(NULL)); // seed randomizer
	vector<int> Acertos;
	float pag_na_rodada = Aposta_rodada;
	float balanco_final = Jogada.getWage();
	cout << fixed << setprecision(2);
	
	// Roda pelo número de rodadas.
	for(auto i (0) ; i < rodadas ; i++) {
		 
		cout << "\n--------------------------------------------------\n" << endl;
		cout << "Essa é a rodada #" << i+1 << " de " << rodadas << " , e sua aposta é R$" << Aposta_rodada << ". Boa Sorte!" << endl;
		
		for (auto i(0u); i < 20; ++i) {
			do {
				intvar = randomInt(1, 80);
			} while(No_Array(intvar, hits));
			
			hits.push_back(intvar);
		}
		
		quicksort(hits, 0, hits.size() - 1);
		Acertos = Jogada.getHits(hits);
		cout << "Os hits foram: [ ";
		for(auto i (0u) ; i < hits.size() ; i++) cout << hits[i] << " ";
		cout << "]" << endl;
		hits.clear();
		
		
		cout << "Você acertou o(s) seguinte(s) número(s): [ ";
		for(auto i(0u) ; i < Acertos.size() ; i++) cout << Acertos[i] << " ";
		cout << "], um total de " << Acertos.size() << " acertos de " << PlayerSpots.size() << "." << endl;
		
		cout << "A taxa de pagamento é: " << ganhosPorAposta[PlayerSpots.size() - 1][Acertos.size()];
		
		pag_na_rodada = Aposta_rodada * ganhosPorAposta[PlayerSpots.size() - 1][Acertos.size()];
		
		
		cout << ", então você sai da rodada com: R$" << pag_na_rodada << endl;
		balanco_final = pag_na_rodada == 0 ? balanco_final - Aposta_rodada : balanco_final + pag_na_rodada - Aposta_rodada;
		cout << "Seu dinheiro no momento é: R$" << balanco_final << " reais." << endl;
		
		
	}
	cout << "--------------------------------------------------" << endl;
	cout << ">>> Fim das rodadas!" << endl;
	cout << "===== RESUMO DO JOGO =====" << endl;
	cout << ">>> Você gastou nesse jogo um total de R$" << Jogada.getWage() << " reais." << endl;
	balanco_final > Jogada.getWage() ? cout << "Uhuuul, você ganhou R$" << balanco_final - Jogada.getWage() << " reais." << endl : cout << "Que pena, você perdeu R$" << Jogada.getWage() - balanco_final << " reais." << endl;
	cout << "Você está saindo do jogo com: R$" << balanco_final << " reais." << endl << "Te vejo na próxima." << endl;
	
	return 0;
}
