#include "ModuleConfig.h"

#include "Log.h"
#include "SystemConfig.h"

ModuleConfig::ModuleConfig(const std::string& filename)
: filename(filename)
{

}

bool ModuleConfig::Load()
{
    if (config.SetSource(SYSCONFDIR + filename))
    {
        return OnLoad();
    }
    else
    {
        sLog.outError(std::string("Failed to open configuration file" + filename).c_str());
        return false;
    }
}