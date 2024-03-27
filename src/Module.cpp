#include "Module.h"
#include "ModuleMgr.h"
#include "ModuleConfig.h"

namespace cmangos_module
{
    Module::Module(const std::string& name)
        : config(nullptr)
        , name(name)
    {
        sModuleMgr.RegisterModule(this);
    }

    Module::~Module()
    {
        delete config;
        config = nullptr;
    }

    void Module::LoadConfig()
    {
        config = CreateConfig();
        config->Load();
    }

    void Module::Initialize()
    {
        sLog.outString("Initializing %s module", name.c_str());
        OnInitialize();
    }
}