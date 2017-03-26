.386
.model flat, stdcall
option casemap: none

.code

DllEntry proc hInst: dword, reason: dword, reserved1: dword
DllEntry endp

EnumerateLoadedModules proc a1:dword, a2:dword, a3:dword
EnumerateLoadedModules endp

EnumerateLoadedModules64 proc a1:dword, a2:dword, a3:dword
EnumerateLoadedModules64 endp

ExtensionApiVersion proc
ExtensionApiVersion endp

FindDebugInfoFile proc a1:dword, a2:dword, a3:dword
FindDebugInfoFile endp

FindDebugInfoFileEx proc a1:dword, a2:dword, a3:dword, a4:dword, a5:dword
FindDebugInfoFileEx endp 

FindExecutableImage proc a1:dword, a2:dword, a3:dword
FindExecutableImage endp

FindExecutableImageEx proc a1:dword, a2:dword, a3:dword, a4:dword, a5:dword
FindExecutableImageEx endp

FindFileInSearchPath proc a1:dword, a2:dword, a3:dword, a4:dword, a5:dword, a6:dword, a7:dword
FindFileInSearchPath endp

GetTimestampForLoadedLibrary proc a1:dword
GetTimestampForLoadedLibrary endp

ImageDirectoryEntryToData proc a1:dword, a2:dword, a3:dword, a4:dword
ImageDirectoryEntryToData endp

ImageDirectoryEntryToDataEx proc a1:dword, a2:dword, a3:dword, a4:dword, a5:dword
ImageDirectoryEntryToDataEx endp

ImageNtHeader proc a1:dword
ImageNtHeader endp

ImageRvaToSection proc a1:dword, a2:dword, a3:dword
ImageRvaToSection endp

ImageRvaToVa proc a1:dword, a2:dword, a3:dword, a4:dword
ImageRvaToVa endp

ImagehlpApiVersion proc
ImagehlpApiVersion endp 

ImagehlpApiVersionEx proc a1:dword
ImagehlpApiVersionEx endp

MakeSureDirectoryPathExists proc a1:dword
MakeSureDirectoryPathExists endp

MapDebugInformation proc a1:dword, a2:dword, a3:dword
MapDebugInformation endp

SearchTreeForFile proc a1:dword, a2:dword, a3:dword
SearchTreeForFile endp

StackWalk proc a1:dword, a2:dword, a3:dword, a4:dword, a5:dword, a6:dword, a7:dword, a8:dword, a9:dword
StackWalk endp

StackWalk64 proc a1:dword, a2:dword, a3:dword, a4:dword, a5:dword, a6:dword, a7:dword, a8:dword, a9:dword
StackWalk64 endp

SymCleanup proc a1:dword
SymCleanup endp

SymEnumerateModules proc a1:dword, a2:dword, a3:dword
SymEnumerateModules endp

SymEnumerateModules64 proc a1:dword, a2:dword, a3:dword
SymEnumerateModules64 endp

SymEnumerateSymbols proc a1:dword, a2:dword, a3:dword, a4:dword
SymEnumerateSymbols endp

SymEnumerateSymbols64 proc a1:dword, a2:dword, a3:dword, a4:dword
SymEnumerateSymbols64 endp

SymEnumerateSymbolsW proc a1:dword, a2:dword, a3:dword, a4:dword
SymEnumerateSymbolsW endp

SymEnumerateSymbolsW64 proc a1:dword, a2:dword, a3:dword, a4:dword
SymEnumerateSymbolsW64 endp

SymFunctionTableAccess proc a1:dword, a2:dword
SymFunctionTableAccess endp

SymFunctionTableAccess64 proc a1:dword, a2:dword
SymFunctionTableAccess64 endp

SymGetLineFromAddr proc a1:dword, a2:dword, a3:dword, a4:dword
SymGetLineFromAddr endp

SymGetLineFromAddr64 proc a1:dword, a2:dword, a3:dword, a4:dword
SymGetLineFromAddr64 endp

SymGetLineFromName proc a1:dword, a2:dword, a3:dword, a4:dword, a5:dword, a6:dword
SymGetLineFromName endp

SymGetLineFromName64 proc a1:dword, a2:dword, a3:dword, a4:dword, a5:dword, a6:dword
SymGetLineFromName64 endp

SymGetLineNext proc a1:dword, a2:dword
SymGetLineNext endp

SymGetLineNext64 proc a1:dword, a2:dword
SymGetLineNext64 endp

SymGetLinePrev proc a1:dword, a2:dword
SymGetLinePrev endp

SymGetLinePrev64 proc a1:dword, a2:dword
SymGetLinePrev64 endp

SymGetModuleBase proc a1:dword, a2:dword
SymGetModuleBase endp

SymGetModuleBase64 proc a1:dword, a2:dword
SymGetModuleBase64 endp

SymGetModuleInfo proc a1:dword, a2:dword, a3:dword
SymGetModuleInfo endp

SymGetModuleInfo64 proc a1:dword, a2:dword, a3:dword
SymGetModuleInfo64 endp

SymGetModuleInfoEx proc a1:dword, a2:dword, a3:dword, a4:dword, a5:dword, a6:dword, a7:dword
SymGetModuleInfoEx endp

SymGetModuleInfoEx64 proc a1:dword, a2:dword, a3:dword, a4:dword, a5:dword, a6:dword, a7:dword
SymGetModuleInfoEx64 endp

SymGetModuleInfoW proc a1:dword, a2:dword, a3:dword
SymGetModuleInfoW endp

SymGetModuleInfoW64 proc a1:dword, a2:dword, a3:dword
SymGetModuleInfoW64 endp

SymGetOptions proc
SymGetOptions endp

SymGetSearchPath proc a1:dword, a2:dword, a3:dword
SymGetSearchPath endp

SymGetSymFromAddr proc a1:dword, a2:dword, a3:dword, a4:dword
SymGetSymFromAddr endp

SymGetSymFromAddr64 proc a1:dword, a2:dword, a3:dword, a4:dword
SymGetSymFromAddr64 endp

SymGetSymFromName proc a1:dword, a2:dword, a3:dword
SymGetSymFromName endp

SymGetSymFromName64 proc a1:dword, a2:dword, a3:dword
SymGetSymFromName64 endp

SymGetSymNext proc a1:dword, a2:dword
SymGetSymNext endp

SymGetSymNext64 proc a1:dword, a2:dword
SymGetSymNext64 endp

SymGetSymPrev proc a1:dword, a2:dword
SymGetSymPrev endp

SymGetSymPrev64 proc a1:dword, a2:dword
SymGetSymPrev64 endp

SymGetSymbolInfo proc a1:dword, a2:dword, a3:dword, a4:dword, a5:dword, a6:dword, a7:dword
SymGetSymbolInfo endp

SymGetSymbolInfo64 proc a1:dword, a2:dword, a3:dword, a4:dword, a5:dword, a6:dword, a7:dword
SymGetSymbolInfo64 endp

SymInitialize proc a1:dword, a2:dword, a3:dword
SymInitialize endp

SymLoadModule proc a1:dword, a2:dword, a3:dword, a4:dword, a5:dword, a6:dword
SymLoadModule endp

SymLoadModule64 proc a1:dword, a2:dword, a3:dword, a4:dword, a5:dword, a6:dword
SymLoadModule64 endp

SymMatchFileName proc a1:dword, a2:dword, a3:dword, a4:dword
SymMatchFileName endp

SymRegisterCallback proc a1:dword, a2:dword, a3:dword
SymRegisterCallback endp

SymRegisterCallback64 proc a1:dword, a2:dword, a3:dword
SymRegisterCallback64 endp

SymRegisterFunctionEntryCallback proc a1:dword, a2:dword, a3:dword
SymRegisterFunctionEntryCallback endp

SymRegisterFunctionEntryCallback64 proc a1:dword, a2:dword, a3:dword
SymRegisterFunctionEntryCallback64 endp

SymSetOptions proc a1:dword
SymSetOptions endp

SymSetSearchPath proc a1:dword, a2:dword
SymSetSearchPath endp

SymUnDName proc a1:dword, a2:dword, a3:dword
SymUnDName endp

SymUnDName64 proc a1:dword, a2:dword, a3:dword
SymUnDName64 endp

SymUnloadModule proc a1:dword, a2:dword
SymUnloadModule endp

SymUnloadModule64 proc a1:dword, a2:dword
SymUnloadModule64 endp

UnDecorateSymbolName proc a1:dword, a2:dword, a3:dword, a4:dword
UnDecorateSymbolName endp

UnmapDebugInformation proc a1:dword
UnmapDebugInformation endp

WinDbgExtensionDllInit proc
WinDbgExtensionDllInit endp

sym proc
sym endp

end DllEntry