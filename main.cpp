#include "main.h"

char RubiksCube::getColorLetter(COLOR color) {
    switch (color) {
        case COLOR::WHITE:
            return 'W';
        case COLOR::GREEN:
            return 'G';
        case COLOR::RED:
            return 'R';
        case COLOR::BLUE:
            return 'B';
        case COLOR::ORANGE:
            return 'O';
        case COLOR::YELLOW:
            return 'Y';
    }
}

string RubiksCube::getMove(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return "L";
        case MOVE::LPrime:
            return "L'";
        case MOVE::L2:
            return "L2";
        case MOVE::R:
            return "R";
        case MOVE::RPrime:
            return "R'";
        case MOVE::R2:
            return "R2";
        case MOVE::U:
            return "U";
        case MOVE::UPrime:
            return "U'";
        case MOVE::U2:
            return "U2";
        case MOVE::D:
            return "D";
        case MOVE::DPrime:
            return "D'";
        case MOVE::D2:
            return "D2";
        case MOVE::F:
            return "F";
        case MOVE::FPrime:
            return "F'";
        case MOVE::F2:
            return "F2";
        case MOVE::B:
            return "B";
        case MOVE::BPrime:
            return "B'";
        case MOVE::B2:
            return "B2";
    }
}

RubiksCube &RubiksCube::move(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return this->l();
        case MOVE::LPrime:  
            return this->lPrime();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->r();
        case MOVE::RPrime:
            return this->rPrime();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->u();
        case MOVE::UPrime:
            return this->uPrime();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->d();
        case MOVE::DPrime:
            return this->dPrime();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->f();
        case MOVE::FPrime:
            return this->fPrime();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->b();
        case MOVE::BPrime:
            return this->bPrime();
        case MOVE::B2:
            return this->b2();
    }
}

RubiksCube &RubiksCube::invert(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return this->lPrime();
        case MOVE::LPrime:
            return this->l();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->rPrime();
        case MOVE::RPrime:
            return this->r();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->uPrime();
        case MOVE::UPrime:
            return this->u();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->dPrime();
        case MOVE::DPrime:
            return this->d();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->fPrime();
        case MOVE::FPrime:
            return this->f();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->bPrime();
        case MOVE::BPrime:
            return this->b();
        case MOVE::B2:
            return this->b2();
    }
}

void RubiksCube::print() const {
    for (int i = 0; i < 3; i++) {
        cout << "      ";
        for (int j = 0; j < 3; j++) {
            cout << getColorLetter(getColor(FACE::UP, i, j)) << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << getColorLetter(getColor(FACE::LEFT, i, j)) << " ";
        }
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << getColorLetter(getColor(FACE::FRONT, i, j)) << " ";
        }
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << getColorLetter(getColor(FACE::RIGHT, i, j)) << " ";
        }
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << getColorLetter(getColor(FACE::BACK, i, j)) << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++) {
        cout << "      ";
        for (int j = 0; j < 3; j++) {
            cout << getColorLetter(getColor(FACE::DOWN, i, j)) << " ";
        }
        cout << endl;
    }
}

vector<RubiksCube::MOVE> RubiksCube:: randomShuffleCube (unsigned int times){
    vector<RubiksCube::MOVE> moves;
    srand(time(0));
    for (int i = 0; i < times; i++){
        unsigned int move = rand() % 18;
        moves.push_back(static_cast<RubiksCube::MOVE>(move));
        this->move(static_cast<RubiksCube::MOVE>(move));
    } 
    return moves;
}