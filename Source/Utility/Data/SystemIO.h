/*
    Initial author: Convery (tcn@ayria.se)
    Started: 07-08-2017
    License: MIT
    Notes:
        [Insert some line about how this is a utility for
        new developers to get up and running quickly; not
        just me being too lazy to use stdio             ]
*/

#pragma once

#include "../../Stdinclude.h"

// Open a file on disk and do IO.
inline std::string Readfile(std::string Path)
{
    std::FILE *Filehandle = std::fopen(Path.c_str(), "rb");
    if (!Filehandle) return "";

    std::fseek(Filehandle, 0, SEEK_END);
    auto Length = std::ftell(Filehandle);
    std::fseek(Filehandle, 0, SEEK_SET);

    auto Buffer = std::make_unique<char[]>(Length);
    std::fread(Buffer.get(), Length, 1, Filehandle);
    std::fclose(Filehandle);

    return std::string(Buffer.get(), Length);
}
inline bool Writefile(std::string Path, std::string Buffer)
{
    std::FILE *Filehandle = std::fopen(Path.c_str(), "wb");
    if (!Filehandle) return false;

    std::fwrite(Buffer.data(), Buffer.size(), 1, Filehandle);
    std::fclose(Filehandle);
    return true;
}
inline bool Fileexists(std::string Path)
{
    std::FILE *Filehandle = std::fopen(Path.c_str(), "rb");
    if (!Filehandle) return false;
    std::fclose(Filehandle);
    return true;
}

// Open a pipe and do IO.
inline std::string Readpipe(std::string Path)
{
    #if defined(_WIN32)
    std::FILE *Pipehandle = _popen(Path.c_str(), "rt");
    if (!Pipehandle) return "";
    #else
    std::FILE *Pipehandle = popen(Path.c_str(), "rt");
    if (!Pipehandle) return "";
    #endif

    std::string Result;
    auto Buffer = std::make_unique<char[]>(2048);
    while (std::fgets(Buffer.get(), 2048, Pipehandle))
    {
        Result += Buffer.get();
    }

    #if defined(_WIN32)
    _pclose(Pipehandle);
    #else
    pclose(Pipehandle);
    #endif

    return Result;
}
inline bool Writepipe(std::string Path, std::string Buffer)
{
    #if defined(_WIN32)
    std::FILE *Pipehandle = _popen(Path.c_str(), "wt");
    if (!Pipehandle) return false;
    #else
    std::FILE *Pipehandle = popen(Path.c_str(), "wt");
    if (!Pipehandle) return false;
    #endif

    std::fputs(Buffer.c_str(), Pipehandle);

    #if defined(_WIN32)
    _pclose(Pipehandle);
    #else
    pclose(Pipehandle);
    #endif

    return true;
}
