
#include "day10.h"
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>
#include <algorithm>
#include <array>
#include <iostream>

using namespace AOC23;

Day10::Day10(std::string fname){
    this->ReadFromFile(fname);
}

void prnt_point(point_t p){
    std::cout << p.y << ", " << p.x << std::endl;
}

void print_dir(dir_t d){
    switch (d){
    case LEFT:
        std::cout << "LEFT";
        break;
    case RIGHT:
        std::cout << "RIGHT";
        break;
    case UP:
        std::cout << "UP";
        break;
    case DOWN:
        std::cout << "DOWN";
        break;
    case STARTING:
        std::cout << "START";
        break;
    case NONE:
        std::cout << "NONE";
        break;
    
    default:
        break;
    }
}
dir_t Day10::ValidMove(point_t pos, dir_t towards, dir_t from){
    char c;
    switch (towards){
    case LEFT:
        if(pos.x <= 0) return NONE;
        c = CharAt(pos.x - 1, pos.y);
        std::cout << "l: " << c << std::endl;
        if('-' == c) return LEFT;
        if(from==LEFT && 'L' == c) return UP;
        if(from==LEFT && 'F' == c) return DOWN;
        break;
        //return c == '-' || c == 'L' || c == 'F' || c=='S';
    case RIGHT:
        if(pos.x + 1 >= lines.at(pos.y).size()) return NONE;
        c = CharAt(pos.x + 1, pos.y);
        std::cout << "r: " << c << std::endl;
        if('-' == c) return RIGHT;
        if(from==RIGHT && 'J' == c) return UP;
        if(from==RIGHT && '7' == c) return DOWN;
        //return c == '-' || c == 'J' || c == '7' || c=='S';
        break;
    case DOWN:
        if(pos.y + 1  >=  lines.size()) return NONE;
        c = CharAt(pos.x, pos.y+1);
        std::cout << "d: " << c << std::endl;
        if('|' == c) return DOWN;
        if(from==DOWN && 'L' == c) return RIGHT;
        if(from==DOWN && 'J' == c) return LEFT;
        //return c == '|' || c == 'L' || c == 'J' || c=='S';
        break;
    case UP:
        if(pos.y <= 0) return NONE;
        c = CharAt(pos.x, pos.y-1);
        std::cout << "u: " << c << std::endl;
        if('|' == c) return UP;
        if(from == UP && '7' == c) return LEFT;
        if(from == UP && 'F' == c) return RIGHT;
        //return c == '|' || c == 'J' || c == 'L' || c=='S';
        break;
    default:
        return NONE;
    }
    if (c=='S') return STARTING;
    return NONE;
}
char Day10::CharAt(point_t pos){
    return lines.at(pos.y).at(pos.x);
}
char Day10::CharAt(size_t x, size_t y){
    return lines.at(y).at(x);
}

dir_t Day10::NextMove(point_t pos, dir_t from)
{
    std::cout << "Last went "; print_dir(from); std::cout << std::endl;
    //dir_t froms[4] = {UP, DOWN, LEFT, RIGHT};
    //for(int i=0; i<4; i++){
    //std::cout << "chcking " << froms[i] << std::endl;
    dir_t ne;
    switch(from){
    case RIGHT:
        std::cout << "Check R" << std::endl;
        ne = ValidMove(pos, RIGHT, from); if (ne!=NONE) return ne;
        std::cout << "Check D" << std::endl;
        ne = ValidMove(pos, DOWN, from); if (ne!=NONE) return ne;
        std::cout << "Check U" << std::endl;
        ne = ValidMove(pos, UP, from); if (ne!=NONE) return ne;
        /*
        if (ValidMove(pos, RIGHT)) return RIGHT;
        if (ValidMove(pos, DOWN)) return DOWN;
        if (ValidMove(pos, UP)) return UP;
        */
        break;
    case LEFT:
        std::cout << "Check L" << std::endl;
        ne = ValidMove(pos, LEFT, from); if (ne!=NONE) return ne;
        std::cout << "Check D" << std::endl;
        ne = ValidMove(pos, DOWN, from); if (ne!=NONE) return ne;
        std::cout << "Check U" << std::endl;
        ne = ValidMove(pos, UP, from); if (ne!=NONE) return ne;
        /*
        if (ValidMove(pos, LEFT)) return LEFT;
        if (ValidMove(pos, DOWN)) return DOWN;
        if (ValidMove(pos, UP)) return UP;
        */
        break;
    case DOWN:
        std::cout << "Check R" << std::endl;
        ne = ValidMove(pos, RIGHT, from); if (ne!=NONE) return ne;
        std::cout << "Check D" << std::endl;
        ne = ValidMove(pos, DOWN, from); if (ne!=NONE) return ne;
        std::cout << "Check L" << std::endl;
        ne = ValidMove(pos, LEFT, from); if (ne!=NONE) return ne;
        /*
        if (ValidMove(pos, RIGHT)) return RIGHT;
        if (ValidMove(pos, DOWN)) return DOWN;
        if (ValidMove(pos, LEFT)) return LEFT;
        */
        break;
    case UP:
        std::cout << "Check R" << std::endl;
        ne = ValidMove(pos, RIGHT, from); if (ne!=NONE) return ne;
        std::cout << "Check L" << std::endl;
        ne = ValidMove(pos, LEFT, from); if (ne!=NONE) return ne;
        std::cout << "Check U" << std::endl;
        ne = ValidMove(pos, UP, from); if (ne!=NONE) return ne;
        /*
        if (ValidMove(pos, RIGHT)) return RIGHT;
        if (ValidMove(pos, UP)) return UP;
        if (ValidMove(pos, LEFT)) return LEFT;
        */
        break;
    case STARTING:
        std::cout << "Check R" << std::endl;
        ne = ValidMove(pos, RIGHT, from); if (ne!=NONE) return ne;
        std::cout << "Check D" << std::endl;
        ne = ValidMove(pos, DOWN, from); if (ne!=NONE) return ne;
        std::cout << "Check U" << std::endl;
        ne = ValidMove(pos, UP, from); if (ne!=NONE) return ne;
        std::cout << "Check L" << std::endl;
        ne = ValidMove(pos, LEFT, from); if (ne!=NONE) return ne;
        /*
        if (ValidMove(pos, RIGHT)) return RIGHT;
        if (ValidMove(pos, DOWN)) return DOWN;
        if (ValidMove(pos, LEFT)) return LEFT;
        if (ValidMove(pos, UP)) return UP;
        */
       break;
    }
    
    //}
    return NONE;
}
struct Node{
    public:
    struct Node *prev;
    struct Node *next;
    point_t pos;
};

class Point {
public:
    int x;
    int y;
    Point& operator+=(const Point& rhs){
        return *this;
    }
    friend Point operator+(Point lhs, const Point& rhs){
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        return lhs;
    }
    bool operator==(const Point &rhs){
        return x == rhs.x && y == rhs.y;
    }
};

const Point pDown{.x=0, .y=1};
const Point pUp{.x=0, .y=-1};
const Point pRigt{.x=1, .y=0};
const Point pLeft{.x=-1, .y=0};

std::ostream& operator<<(std::ostream &out, Point const& data) {
    out << "y: " << data.y << " x: " << data.x;
    return out;
}
std::vector<struct Node> nodes;

Point speed_from_char_and_dir(char c, Point dir){
    switch (c){
    case '-':
        
        break;
    
    default:
        break;
    }
    return dir;
}
struct around {
    char right;
    char left;
    char up;
    char down;
};

int Day10::Part1(){
    Point s = {0};
    int distance = 0;
    for (auto & line : this->lines) {
        s.x = line.find('S');
        if (s.x!=std::string::npos) break;
        s.y++;
    }
    int loop = 0;
    Point now(s.x, s.y);
    Point speed = {0};
    char l = 'S';
    char c;
    bool complete = false;
    while(!complete && ++loop ){
        c = CharAt(now.x, now.y);
        //std::cout << "At: " << now << " '" <<c <<"' came from " << l << std::endl;
        if(c=='S'){
            auto &line = lines.at(now.y);
            
            struct around ar = {
                .right = now.x +1 < line.size() ? CharAt(now.x+1, now.y):'.',
                .left = now.x > 0 ? CharAt(now.x-1, now.y):'.',
                .up = now.y > 0 ? CharAt(now.x, now.y-1):'.',
                .down = now.y +1 < lines.size() ? CharAt(now.x, now.y+1):'.'
            };
            // @TODO: add starting points to left, down and up
            if (ar.right == '-' || ar.right =='7' || ar.right == 'J'){
                //std::cout << "START RIGHT >" << std::endl;
                speed.x = 1;
                if(ar.right == 'J'){
                    speed.y = -1;
                } else if (ar.right == '7'){
                    speed.y = 1;
                }
            }
            if(l!='S'){
                complete = true;
                speed.x = 0;
                speed.y = 0;
            }
        } else if ((c=='-' && speed.y == 0)|| (c=='|' && speed.x == 0)){
            // Speed keeps the same
            
        } else if (c=='J'){
            // Coming from left
            if(l=='-'||l=='L') speed=pUp;
            // Coming from up
            else if(l=='|'||l=='7') speed=pLeft;
            // going right, go up, else go down
            else if (l=='F') speed = speed.x==1?pUp:pLeft;

        } else if (c=='7'){
            if(l == '-'||l=='F') speed=pDown;
            else if (l=='|'||l=='J') speed=pLeft;
            
            // going right: go down else go left
            else if (l=='L') speed = speed.x==1?pDown:pLeft;
                
        } else if (c=='F'){
            if(l=='|'||l=='L') speed=pRigt;
            else if(l=='-'||l=='7') speed=pDown;
            
            // going up: go right, else go down
            else if(l=='J') speed = speed.y==-1?pRigt:pDown;

        } else if (c=='L'){
            if(l=='-'||l=='J') speed=pUp;
            else if(l=='|'||l=='F') speed=pRigt;
            
            // if going left: go up, else go right
            else if(l=='7') speed = speed.x==-1?pUp:pRigt;
        }
        l = c;
        now = speed + now;
        //std::cout << "go: " << speed<<std::endl;
    }
    if (loop%2!=0) loop--;

    return loop/2;
}

unsigned long long Day10::Part2(){
    int sum = 0;
    for (auto & line : this->lines) {
        
    }
    return sum;
}
