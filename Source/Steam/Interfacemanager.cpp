/*
    Initial author: Convery
    Started: 2017-4-3
    License: MIT
*/

#include "Steam.h"
#include <unordered_map>
#include <map>
#include "Interfaces/All.h"
#include "Interfacemanager.h"

constexpr const char *Steamdllname = sizeof(size_t) == sizeof(uint64_t) ? "steam_api64.dll" : "steam_api.dll";

// The interfaces we support.
std::unordered_map<std::string, eInterfaceType> Interfacestore;
std::unordered_map<eInterfaceType /* Type */, void * /* Interface */> Interfacemap;
std::unordered_map<std::string /* Name */, void * /* Interface */> Interfacenames;

void Setmapbyname(eInterfaceType Type, std::string Name)
{
    Interfacemap[Type] = Interfacemanager::Fetchinterface(Name);
}

void Scanfile(std::FILE *Filehandle)
{
 
    std::vector<std::string> Scanwords = 
    {
        "STEAMAPPS_INTERFACE_VERSION0",
        "STEAMHTTP_INTERFACE_VERSION0",
        "STEAMREMOTESTORAGE_INTERFACE_VERSION0",
        "STEAMSCREENSHOTS_INTERFACE_VERSION0",
        "STEAMUSERSTATS_INTERFACE_VERSION0",
        "SteamClient0",
        "SteamContentServer0",
        "SteamFriends0",
        "SteamGameServer0",
        "SteamGameServerStats0",
        "SteamMatchMaking0",
        "SteamMatchMakingServers0",
        "SteamNetworking0",
        "SteamUtils0",
    };
	std::map<std::string, std::string> Replacementwords =
    {
        { "STEAMAPPS_INTERFACE_VERSION0", "SteamApps0"},
        { "STEAMHTTP_INTERFACE_VERSION0", "SteamHTTP0" },
        { "STEAMREMOTESTORAGE_INTERFACE_VERSION0", "SteamRemotestorage0" },
        { "STEAMSCREENSHOTS_INTERFACE_VERSION0", "SteamScreenshots0" },
        { "STEAMUSERSTATS_INTERFACE_VERSION0", "SteamUserstats0" },
        { "SteamMatchMakingServers0", "SteamMatchamkingservers0" },
        { "SteamUtils0", "SteamUtilities0" },
    };
    
    std::fseek(Filehandle, 0, SEEK_END);
    auto Filesize = std::ftell(Filehandle);
    std::fseek(Filehandle, 0, SEEK_SET);

    auto Buffer = std::make_unique<char[]>(Filesize);
    std::fread(Buffer.get(), Filesize, 1, Filehandle);

    for (uint64_t i = 0; i < Filesize; ++i)
    {
        if (Buffer[i] != 'S') continue;

        for (auto &Item : Scanwords)
        {
			if (std::strstr((Buffer.get() + i), Item.c_str()))
			{
				auto interfaceName = Replacementwords.find(Item);
				if (interfaceName == Replacementwords.end()) {
					auto it = Interfacestore.find((Buffer.get() + i));
					if (it != Interfacestore.end()) {
						Setmapbyname(it->second, (Buffer.get() + i));
					}
				}
				else {
					std::string b;

					b.append( interfaceName->second.c_str() );
					b.append( Buffer.get() + i + interfaceName->first.size() );
	
					auto it = Interfacestore.find(b);
					if (it != Interfacestore.end()) {
						Setmapbyname(it->second, b);
					}
				}
            }
        }
    }
}

void Interfacemanager::Initialize()
{
    // Check for a cache file.
	//TODO: when do we even initialize this?
    {
        const char *Cachename = "./Plugins/Platformwrapper/Steam_Interfacecache";
        std::FILE *Filehandle = std::fopen(Cachename, "rt");
        if (Filehandle)
        {
            char InputString[1024]{};
            while (fgets(InputString, 1024, Filehandle))
            {
                #define Checktype(Interfacename, Type)          \
                if(std::strstr(InputString, Interfacename))     \
                { Setmapbyname(Type, InputString); continue; }  \

                // Add by type.
                Checktype("SteamUGC0", STEAM_UGC);
                Checktype("SteamApps0", STEAM_APPS);
                Checktype("SteamUser0", STEAM_USER);
                Checktype("SteamHTTP0", STEAM_HTTP);
                Checktype("SteamMusic0", STEAM_MUSIC);
                Checktype("SteamVideo0", STEAM_VIDEO);
                Checktype("SteamClient0", STEAM_CLIENT);
                Checktype("SteamUtilities0", STEAM_UTILS);
                Checktype("SteamFriends0", STEAM_FRIENDS);
                Checktype("SteamApplist0", STEAM_APPLIST);
                Checktype("SteamInventory0", STEAM_INVENTORY);
                Checktype("SteamUserstats0", STEAM_USERSTATS);
                Checktype("SteamController0", STEAM_CONTROLLER);
                Checktype("SteamGameserver0", STEAM_GAMESERVER);
                Checktype("SteamNetworking0", STEAM_NETWORKING);
                Checktype("SteamHTMLSurface0", STEAM_HTMLSURFACE);
                Checktype("SteamMusicremote0", STEAM_MUSICREMOTE);
                Checktype("SteamScreenshots0", STEAM_SCREENSHOTS);
                Checktype("SteamMatchmaking0", STEAM_MATCHMAKING);
                Checktype("SteamRemotestorage0", STEAM_REMOTESTORAGE);
                Checktype("SteamContentServer0", STEAM_CONTENTSERVER);
                Checktype("SteamUnifiedmessages0", STEAM_UNIFIEDMESSAGES);
                Checktype("SteamGameserverStats0", STEAM_GAMESERVERSTATS);
                Checktype("SteamMatchamkingservers0", STEAM_MATCHMAKINGSERVERS);
                Checktype("SteamMasterserverUpdater0", STEAM_MASTERSERVERUPDATER);
            }

            fclose(Filehandle);
            return;
        }
    }
    
    {
		// Check for a backup file, in the case of devs compiling as a steam_api replacement.
        std::string Backupname = std::string(Steamdllname) + ".bak";
        std::FILE *Filehandle = std::fopen(Backupname.c_str(), "rb");
		// Try to open main steam_api.dll
        if(!Filehandle) Filehandle = std::fopen(Steamdllname, "rb");
        if (!Filehandle)
        {
            InfoPrint("No interfaces could be loaded, contact the developers.");
            InfoPrint("The Platformwrapper will use the latest version of interfaces as a hail Mary.");
            return;
        }

        Scanfile(Filehandle);
        std::fclose(Filehandle);
    }
}
void *Interfacemanager::Fetchinterface(std::string Name)
{
    auto Result = Interfacenames.find(Name);
    if (Result != Interfacenames.end()) return Result->second;

    DebugPrint(va("%s had no interface with the name \"%s\"", __FUNCTION__, Name.c_str()).c_str());
    return nullptr;
}

void *Interfacemanager::Fetchinterface(eInterfaceType Type)
{
	// Return the interface by name if available.
	auto Result = Interfacemap.find(Type);
	if (Result != Interfacemap.end()) return Result->second;

	DebugPrint(va("%s had no interface for the type %i", __FUNCTION__, Type).c_str());
	return nullptr;
}

void Interfacemanager::Addinterface(eInterfaceType Type, std::string Name, void *Interface)
{
	Interfacestore[Name] = Type;
    Interfacenames[Name] = Interface;
}
