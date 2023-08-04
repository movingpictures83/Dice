#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "DicePlugin.h"

void DicePlugin::input(std::string file) {
 inputfile = file;
}

void DicePlugin::run() {

}

void DicePlugin::output(std::string file) {
   std::string command = "export OLDPATH=${PATH}; ";
   command += "export PATH=${CONDA_HOME}/bin/:${PATH}; ";
   command += "eval \"$(conda shell.bash hook)\"; ";
   command += "conda activate qiime2-2021.4; ";
   command += "qiime diversity beta --i-table "+inputfile+" --p-metric dice --o-distance-matrix "+file+"; unzip -jo "+file+" -d "+PluginManager::prefix()+"; ";
   command += "conda deactivate; ";
   command += "export PATH=${OLDPATH}";
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<DicePlugin> DicePluginProxy = PluginProxy<DicePlugin>("Dice", PluginManager::getInstance());
