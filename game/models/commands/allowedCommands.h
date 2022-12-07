#include <string>
#include <unordered_map>

const static std::unordered_map<std::string,int> allowedCommands{
        {"animal",0},
        {"kill",1},
        {"food",2},
        {"feed",3},
        {"feedid",4},
        {"nofood",5},
        {"empty",6},
        {"see",7},
        {"info",8},
        {"n",9},
        {"anim",10},
        {"visanim",11},
        {"store",12},
        {"restore",13},
        {"load",14},
        {"slide",15},
        {"killid",16}
};