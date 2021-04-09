#include "Encript.hpp"
#include "Decript.hpp"
#include <stdlib.h>

void abrirArq(stringstream &dataStr, vector<pair<size_t, size_t>> &listaFreq, vector<char> &alfabeto, vector<char> &frequenciaOrig, vector<char> &shiftedAlpha, int &shift);
void takeAlphabet(stringstream &dataStr, vector<pair<size_t, size_t>> &listaFreq, vector<char> &alfabeto, vector<char> &frequenciaOrig, vector<char> &shiftedAlpha, int &shift);
void showShifts(stringstream &dataStr, vector<pair<size_t, size_t>> &listaFreq, vector<char> &alfabeto, vector<char> &frequenciaOrig, vector<char> &shiftedAlpha, int &shift);
void decrypt(stringstream &dataStr, vector<pair<size_t, size_t>> &listaFreq, vector<char> &alfabeto, vector<char> &frequenciaOrig, vector<char> &shiftedAlpha, int &shift);

void printShiftedALph(stringstream &dataStr, vector<pair<size_t, size_t>> &listaFreq, vector<char> &alfabeto, vector<char> &frequenciaOrig, vector<char> &shiftedAlpha, int &shift);
void changeShiftedAlpha(stringstream &dataStr, vector<pair<size_t, size_t>> &listaFreq, vector<char> &alfabeto, vector<char> &frequenciaOrig, vector<char> &shiftedAlpha, int &shift);
void loadShiftedAlpha(stringstream &dataStr, vector<pair<size_t, size_t>> &listaFreq, vector<char> &alfabeto, vector<char> &frequenciaOrig, vector<char> &shiftedAlpha, int &shift);