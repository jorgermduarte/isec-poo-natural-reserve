//
// Created by duarte on 10-11-2022.
//
#include "validateCommands.h"
#include "commands.h"

// for string delimiter
// https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

vector<string> getCommandArguments(string &command){
    vector<string> args = split(command," ");
    return args;
}

bool validateArgumentsSize(string &command){
    vector<string> args = split(command," ");
    if(args.size() > 3){
        return false;
    }else{
        return true;
    }
}

bool validateCommand(string &command){
    // validate the arguments size
    bool validArgumentsSize = validateArgumentsSize(command);
    if(!validArgumentsSize){
        return false;
    }

    // retrieve the arguments
    vector<string> arguments = getCommandArguments(command);

    //verify if the argument[0] (command type) exists on the map (allowed command)
    std::unordered_map<std::string,int>::const_iterator got = allowedCommands.find(arguments[0]);
    if(got == allowedCommands.end()){
        //we couldn't find any command available for the argument provided
        return false;
    }

    return true;
}
