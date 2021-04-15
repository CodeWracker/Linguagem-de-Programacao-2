#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#define NDEBUG 1
using namespace std;
class Data
{
private:
    vector<char> _alphabet;
    stringstream _dataStr;
    vector<pair<size_t,size_t>> _freqList;
    int _shift;

private:
    void loadFrequency();


public:
    void setShift(int s){_shift = s;
                        shiftAlphabet();}
    bool loadAlphabet(string data);
    void loadMessage(string data);
    string getMessage(){return _dataStr.str();}
    string getFrequency(){
        stringstream s;
        for(size_t i = 0; i<_freqList.size();i++){
            s<< (char)_freqList.at(i).first<< " - ";
            if(i<_alphabet.size()){
                s<< _alphabet.at(i);
            }
            s<<endl;
        }
        return s.str();
    }

public:
    void getAlphabetFromMessage();
    bool loadFreqOrig(string path);
    string dencriptMessage();
    void shiftAlphabet();

public:
    Data();
};

#endif // DATA_H
