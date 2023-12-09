
#include "day2.h"
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>
#include <algorithm>
#include <array>
#include <iostream>
#include <ranges>
#include <string_view>
#include <iomanip>
#include <cstring>
#include <sstream>

using namespace AOC23;

Day2::Day2(std::string fname){
    this->ReadFromFile(fname);
    for (auto & line : this->lines) {
        auto game = CubeGame(line);
        this->games.push_back(game);
     }

}

bool CubeGame::validThrows(int red, int green, int blue){
    int valid = std::count_if(this->throws.begin(), this->throws.end(),
        [red, green, blue](const GameThrow g) {return g.red <=red && g.green <= green && g.blue <= blue; }
    );
    return valid == this->throws.size();
    
}
int CubeGame::powerCubes(){
    GameThrow max_red = *max_element(this->throws.begin(), this->throws.end(),
        [](GameThrow &l, GameThrow &r){return l.red<r.red;});
    GameThrow max_green = *max_element(this->throws.begin(), this->throws.end(),
        [](GameThrow &l, GameThrow &r){return l.green<r.green;});
    GameThrow max_blue = *max_element(this->throws.begin(), this->throws.end(),
        [](GameThrow &l, GameThrow &r){return l.blue<r.blue;});
    
    return max_red.red * max_green.green * max_blue.blue;

}

CubeGame::CubeGame(const std::string source)
{
    
    char *cstr = new char[source.length()+1];
    strcpy(cstr, source.c_str());
    char *ptr = strtok(cstr, ":");
    while(ptr != NULL){
        char key[10];
        int val;
        int res = sscanf(ptr, "%s %d", &key, &val);
        if (res == 2){
            id = val;
        } else {
            int v[3];
            char s[3][20];
            int red=0, green=0, blue=0;
            int res2 = sscanf(ptr, " %d %s %d %s %d %s", &v[0], &s[0], &v[1], &s[1], &v[2], &s[2]);
            for (int c=0; c<res2/2; c++){
                if (strstr(s[c], "red")!=NULL ) red=v[c];
                else if (strstr(s[c], "green")!=NULL ) green=v[c];
                else if (strstr(s[c], "blue")!=NULL ) blue=v[c];
            }
            this->throws.push_back(GameThrow(red, green, blue));
        }
        ptr = strtok(NULL, ";");

    }
    delete [] cstr;
};

int Day2::Part1(){
    int sum = 0;

    auto valid_games = this->games | std::views::filter([](CubeGame g){ return g.validThrows(12,13,14); });

    for (CubeGame &game : valid_games){
        sum+=game.id;
    }
    
    return sum;
}

unsigned long long Day2::Part2(){
    int sum = 0;
    for (CubeGame &game : this->games){
        sum += game.powerCubes();
    }
    return sum;
}
