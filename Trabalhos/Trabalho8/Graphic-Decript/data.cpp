#include "data.h"

void Data::getAlphabetFromMessage(){

}
bool Data::loadFreqOrig(string path){

    return true;
}

string Data::dencriptMessage(){
    stringstream returnData;
    if(_alphabet.size()>0){
        for (size_t i = 0; i < _freqList.size(); i++)
        {
            if (i<_alphabet.size())
                _freqList.at(i).second = _alphabet.at(i);
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
    }else{
        return _dataStr.str();
    }

}
bool Data::loadAlphabet(string data){

    stringstream s;
    s << data;


    string tmp;
    while (getline(s, tmp))
    {
        _alphabet.push_back(atoi(tmp.c_str()));
    }
    return true;
}
void Data::loadMessage(string data){

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
       }
   }
}
void Data::shiftAlphabet(){
    for(size_t i= 0;i<_alphabet.size();i++){
        _alphabet.at(i) = _alphabet.at(i) + _shift;
    }
}
Data::Data()
{
    vector<pair<size_t,size_t>> a(256);
    _freqList = a;
    _shift = 0;
}
