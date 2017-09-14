#include "kenobet.h"
#include "funcoesaux.h"

// Construtor
KenoBet::KenoBet( unsigned int _maxNumSpots ) {
    this->m_maxSpots = _maxNumSpots;
}


// Funções Get
float KenoBet::getWage() const {
    return m_wage;
}


vector<int> KenoBet::getSpots() const {
	return m_spots;
}

vector<int> KenoBet::getHits(const std::vector<int> &_hits) const {
    
	vector<int> Pontos_acertados;

	for (int i = 0; i < 20; i++) {

		for (auto j (0u) ; j < m_spots.size(); j++) {

			if(_hits[i] == m_spots[j]) {
				Pontos_acertados.push_back(_hits[i]);
			}
		}
	}
		
	return Pontos_acertados;
}

// Funções set
bool KenoBet::setWage(float _wage) {
	this->m_wage = _wage;
	return m_wage;
}


// Métodos
std::size_t KenoBet::numChosen() const {
    return m_spots.size();
}

void KenoBet::reset() {
    m_spots.clear();
}

	
bool KenoBet::addNumber(int _spot)	{
    
    if(_spot >= 1 && _spot <= 80 && !No_Array(_spot, m_spots )) {
        
        m_spots.push_back(_spot);
        return true;
    }
    
    else {
        return false;
	}	
}
