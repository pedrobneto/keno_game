#ifndef _KENOBET_H
#define _KENOBET_H

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class KenoBet {
    public:
        explicit KenoBet( unsigned int _maxNumSpots = 15 );
        bool addNumber( int _spot );
        bool setWage( float _wage );
        void reset();
        float getWage() const;
        vector<int> getSpots() const;
        vector<int> getHits(const std::vector<int> &_hits) const;
        size_t numChosen() const;
    
    private:
        vector <int> m_spots;   // As apostas do jogador
        float m_wage; 
        unsigned int m_maxSpots;
};

#endif