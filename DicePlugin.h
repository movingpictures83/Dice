#ifndef DICEPLUGIN_H
#define DICEPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class DicePlugin : public Plugin
{
public: 
 std::string toString() {return "Dice";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;

};

#endif
