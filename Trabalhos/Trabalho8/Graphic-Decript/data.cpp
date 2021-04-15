#include "data.h"

void Data::getAlphabetFromMessage(){

}
bool Data::loadFreqOrig(string path){

    return true;
}

string Data::dencriptMessage(){
    stringstream returnData;
    for (size_t i = 0; i < _freqList.size(); i++)
    {
        if (_alphabet.at(i))
            _freqList.at(i).second = _alphabet.at(i) + _shift;
        else
            _freqList.at(i).second = _freqList.at(i).first;
    }

    for (char ch : _dataStr.str())
    {
        for (size_t i = 0; i < _freqList.size(); i++)
        {

            if ((size_t)ch == (_freqList.at(i).first))
            {
                returnData << (char)_freqList.at(i).second;
                break;
            }
        }
    }
    return returnData.str();


}
bool Data::loadAlphabet(string data){

    stringstream s;
    s << data;


    string tmp;
    int cont = 0;
    while (s >> tmp)
    {
        int ch = stoi(tmp.c_str());
        _alphabet.at(cont) = ch;
        cont++;
    }
    return true;
}
void Data::loadMessage(string data){
    _dataStr.str("");
    vector<pair<size_t,size_t>> a(256);
    _freqList = a;

    _dataStr << data;
    loadFrequency();
}
bool ordenaLista(const pair<size_t, size_t> &a, const pair<size_t, size_t> &b)
{

    return a.second > b.second;
}
void Data::loadFrequency(){
   for (size_t i = 0; i < 256; i++)
   {
       _freqList.at(i).first = i;
       _freqList.at(i).second = 0;
   }

   for (char ch : _dataStr.str())
       _freqList.at(ch).second++;

   stable_sort(_freqList.begin(), _freqList.end(), ordenaLista);

   for (size_t i = 0; i < _freqList.size(); i++)
   {
       if (_freqList.at(i).second == 0)
       {
           _freqList.erase(_freqList.begin() + i, _freqList.end());
           _alphabet.erase(_alphabet.begin() + i, _alphabet.end());
       }
   }
}

Data::Data()
{
    vector<pair<size_t,size_t>> a(256);
    _freqList = a;
    vector<size_t> b(256);
    _alphabet = b;
    _shift = 0;
}
