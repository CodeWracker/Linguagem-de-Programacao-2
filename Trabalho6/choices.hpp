#ifndef CHOICES_HPP
#define CHOICES_HPP
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include "Monstro/Monstro.hpp"
#include "Pessoa/Pessoa.hpp"
#include "Item/Item.hpp"
using namespace std;

void showData(Pessoa &mercador, Pessoa &heroi, vector<Monstro *> &monsterList);
void upgradeStatus(Pessoa &mercador, Pessoa &heroi, vector<Monstro *> &monsterList);
void openStore(Pessoa &mercador, Pessoa &heroi, vector<Monstro *> &monsterList);
void hunt(Pessoa &mercador, Pessoa &heroi, vector<Monstro *> &monsterList);
#endif
