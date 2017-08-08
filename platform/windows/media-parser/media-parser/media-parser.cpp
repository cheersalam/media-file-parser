// media-parser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "media-parser-interface.h"
#include <iostream>
#include <windows.h>

typedef IMediaParserInterface* (__cdecl *mediaparser_factory)();

int main()
{
    // Load the DLL
    HINSTANCE dll_handle = ::LoadLibrary(TEXT("media-parser-lib.dll"));
    if (!dll_handle) {
        std::cerr << "Unable to load DLL!\n";
        return 1;
    }

    // Get the function from the DLL
    mediaparser_factory factory_func = reinterpret_cast<mediaparser_factory>(
        ::GetProcAddress(dll_handle, "create_MediaParserInterface"));
    if (!factory_func) {
        std::cerr << "Unable to load create_MediaParserInterface from DLL!\n";
        ::FreeLibrary(dll_handle);
        return 1;
    }

    IMediaParserInterface *media_parser_interface = factory_func();
    media_parser_interface->ParserMp4File("input1.mp4");
    media_parser_interface->PrintAtomTree();
    media_parser_interface->CreateNewMp4File("out1.mp4");
    media_parser_interface->ReleaseMp4Atoms();
    return 0;
}

