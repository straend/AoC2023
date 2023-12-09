
#include "day7.h"
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>
#include <algorithm>
#include <array>
#include <iostream>
#include <cstring>
#include <numeric>
#include <map>

using namespace AOC23;

Day7::Day7(std::string fname){
    this->ReadFromFile(fname);
}

void print_card(int c){
    if (c && c < 10) { std::cout << c; return; }
    switch (c)
    {
    case 0:
        std::cout << 'J';
        break;
    case 10:
        std::cout << 'T';
        break;
    case 11:
        std::cout << 'J';
        break;
    case 12:
        std::cout << 'Q';
        break;
    case 13:
        std::cout << 'K';
        break;
    case 14:
        std::cout << 'A';
        break;
    }
}

int char_to_cardval(char ch, bool jokers=false){
    int res = 0;
    switch (ch)
    {
    //case '0':
    //    res=0;
    //    break;
    //case '1':
    //    res=1;
    //    break;
    case '2':
        res=2;
        break;
    case '3':
        res=3;
        break;
    case '4':
        res=4;
        break;
    case '5':
        res=5;
        break;
    case '6':
        res=6;
        break;
    case '7':
        res=7;
        break;
    case '8':
        res=8;
        break;
    case '9':
        res=9;
        break;
    case 'T':
        res=10;
        break;
    case 'J':
        res=jokers?0:11;
        break;
    case 'Q':
        res=12;
        break;
    case 'K':
        res=13;
        break;
    case 'A':
        res=14;
        break;
    default:
        break;
    }
    return res;
}

void print_handvalue(handvalue_t t)
{
    switch (t)
    {
    case HIGH:
        std::cout << "HIGH";
        break;
    
    case PAIR:
        std::cout << "PAIR";
        break;
    
    case TWOPAIR:
        std::cout << "TWOPAIR";
        break;
    
    case THREES:
        std::cout << "THREES";
        break;
    
    case FULLHOUSE:
        std::cout << "FULLHOUSE";
        break;
    
    case FOURS:
        std::cout << "FOURS";
        break;
    
    case FIVES:
        std::cout << "FIVES";
        break;
    default:
        break;
    }
}
handvalue_t Hand::for_cards(int cards[5], bool jokers)
{
    handvalue_t ret = HIGH;
    int values[15] = {0};

    std::vector<std::pair<int, int>> vals(15, std::pair(0,0));

    std::cout << std::endl;;
    for(int i=0;i<5;i++){
        print_card(cards[i]);
        values[cards[i]] += 1;
    
        vals.at(cards[i]).first = cards[i];
        
        vals.at(cards[i]).second += 1;
    }
    std::cout << std::endl;;
    std::sort(vals.begin(), vals.end(), [](std::pair<int, int> &l, std::pair<int,int> &r){return l.second > r.second;});

    int trees = 0;
    int pairs = 0;
    int joks = values[0];
    for(auto &p:vals){
        if (p.second==0) break;
        std::cout << p.first << ": " << p.second << std::endl;
        
        if (jokers && p.first == 11) { std::cout<<"SKIP JOKER"<<std::endl;continue;}
        if(joks + p.second == 5) {ret=FIVES; goto RETSTATE;}
        if(joks + p.second == 4) {ret=FOURS; goto RETSTATE;}
        if(joks + p.second == 3) {trees +=1; joks -= 3-p.second; p.second-=3; break;}
    }
    HANDLE_PAIRS:
    for(auto &p:vals){
        if (jokers && p.first == 11) { std::cout<<"SKIP JOKER"<<std::endl;continue;}
        
        if(joks + p.second >= 2) {
            std::cout <<"PAIR of " << p.first <<std::endl;
            pairs +=1; 
            joks -= 2-p.second;
            p.second-=2;
        }
    }
    if(pairs && trees) {ret=FULLHOUSE; goto RETSTATE;}
    if (trees) {ret=THREES; goto RETSTATE;}
    if (pairs == 2) {ret=TWOPAIR; goto RETSTATE;}
    if (pairs) {ret=PAIR; goto RETSTATE;}
RETSTATE:
    std::cout << "re: ";
    print_handvalue(ret);
    std::cout << std::endl;
    return ret;
}

Hand::Hand(char l[5], bool jokers)
{
    char *ptr=l;
    cards[0] = char_to_cardval(*ptr++, jokers);
    cards[1] = char_to_cardval(*ptr++, jokers);
    cards[2] = char_to_cardval(*ptr++, jokers);
    cards[3] = char_to_cardval(*ptr++, jokers);
    cards[4] = char_to_cardval(*ptr, jokers);
    value = for_cards(cards, jokers);
}
Hand::Hand(std::string &line, bool jokers)
{
    char *cstr = new char[line.length() + 1];
    strcpy(cstr, line.c_str());
    char *ptr = strtok(cstr, " ");
    
    cards[0] = char_to_cardval(*ptr++, jokers);
    cards[1] = char_to_cardval(*ptr++, jokers);
    cards[2] = char_to_cardval(*ptr++, jokers);
    cards[3] = char_to_cardval(*ptr++, jokers);
    cards[4] = char_to_cardval(*ptr, jokers);

    ptr = strtok(NULL, " ");
    bid = atoi(ptr);
    value = for_cards(cards, jokers);
};

int Day7::Part1(){
    int sum = 0;
    for (auto & line : this->lines) {
        AOC23::Hand h(line, false);
        hands.push_back(h);
    }

    std::sort(hands.begin(), hands.end(), [](Hand &h1, Hand &h2){
        bool res = false;
        if(h1.value < h2.value ){
            res = true;
        } else if (h1.value > h2.value){
            res = false;
        } else {
            for(int i=0; i<5; i++){
                if(h1.cards[i] == h2.cards[i]) continue;
                res = h1.cards[i] < h2.cards[i];
                break;
            }
        }
        return res;
    });
    int i=1;
    for(auto &h : hands){
        sum += h.bid * i;
        i++;
    }
    return sum;
}


unsigned long long Day7::Part2(){
    long long sum = 0;
    hands.clear();
    for (auto & line : this->lines) {
        AOC23::Hand h(line, true);
        hands.push_back(h);
    }

    std::sort(hands.begin(), hands.end(), [](Hand &h1, Hand &h2){
        bool res = true;
        if (h1.value == h2.value) {
            for(int i=0; i<5; i++){
                if(h1.cards[i] == h2.cards[i]) continue;
                res = h1.cards[i] < h2.cards[i];
                break;
            }
        } else if(h1.value > h2.value ){
            res = false;
        }
        return res;
    });
    
    int i=1;
    for(auto &h : hands){
        sum += (h.bid * i);
        //std::cout << h.value << "\t"<<h.bid <<"\t"<< i << std::endl;
        //std::cout << "\t";
        for (int i=0; i< 5; i++){
        //    print_card(h.cards[i]);
        }
        //std::cout << std::endl;

        i++;
    }
    //std::cout << sum << std::endl;
    return sum;
}
