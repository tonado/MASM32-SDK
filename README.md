# MASM32-SDK
The Microsoft Assembler (commonly known as MASM) is an industrial software development tool that has been maintained and updated for over 30 years by a major operating system vendor. It has never been softened or compromised into a consumer friendly tool and is designed to be used by professional programmers for operating system level code and high performance object modules, executable files and dynamic link libraries.

The MASM32 SDK is an independent project that is designed to ease the entry of experienced programmers into the field of assembler language programming. It is a complex and demanding form of programming that requires high coding precision and a good understanding of both the Intel mnemonics and x86 processor architecture as it is utilised by the Windows operating system environment but for the effort, it offers flexibility and performance that is beyond the best of compilers when a high enough level of expertise is reached.

## Description 
The MASM32 SDK version 11 is a working development environment for programmers who are interested in either learning or writing 32 bit Microsoft assembler (MASM). The installation is an automated process that installs the correct directory tree structure on the local drive of your choice.

Note that MASM32 will not install on a network drive. MASM32 comes with its own runtime library written fully in assembler and an extensive range of macros for improved high level emulation and faster development. It builds its own IMPORT libraries for the Windows API functions and supplies its own include files for a very large number of API functions.

The default editor in MASM32 has been fully recoded from scratch in MASM and it is smaller, faster and more powerful with two (2) separate scripting engines, a legacy version to maintain backwards compatibility of existing scripts and a completely new one that is much faster and more powerful than its predecessor.

New CHM documentation and a wider range of "Create New" project types directly supported by the new script engine from the editor place a wider range of project types at your fingertips. There is also a new format PLUGIN system for the default editor as well as the old one for backwards compatibility.

## UNICODE Support
The MASM32 SDK has a completely new include file system that supports either ASCII or UNICODE by the inclusion of an equate, `__UNICODE__` . Two new macro systems support UNICODE text that can be used in much the same manner as embedded ASCII text.

## DEP Compatibility
The MASM32 SDK has been rebuilt to ensure it is fully compatible with the Data Execution Prevention safety feature in later versions of Windows.

## OS Version
The MASM32 SDK requires Win2000 or higher Windows versions. The Installation is not designed to run on Win9x or ME.

## Features
1. The most up to date version of Ray Filiatreault's floating point library and tutorial.
2. A completely new dedicated time and date library written by Greg Lyon.
3. The MASM32 library with over 200 procedures for writing general purpose high performance code.
4. A new dynamic array system for variable length string and binary data with both a macro and procedural interface.
5. The include files and libraries have been upgraded to include VISTA / Win7 with additional equates and structures.
6. A specialised linker, resource compiler and assembler from Pelle's tool set with working examples.
7. An extensive range of example code ranging from simple examples to more complex code design.
8. Prebuilt scripts in the editor for creating working templates for assembler projects.
9. A very easy to use console interface for developing algorithms, test code and experimental ideas in code.
More ......

## Target Users
The MASM32 SDK is targeted at experienced programmers who are familiar with writing software in 32 bit versions of Windows using the API interface and who are familiar with at least some direct mnemonic programming in assembler. It is not well suited for beginner programmers due to the advanced technical nature of programming in assembler and beginners are advised to start with a compiler first to learn basic concepts like addressing, programming logic, control flow and similar.

## Help Files
The help file system has been upgraded to CHM format so that MASM32 can be used on Windows versions that no longer support Winhelp help files.

## Application
MASM is routinely capable of building complete executable files, dynamic link libraries and separate object modules and libraries to use with the Microsoft Visual C development environment as well as MASM. It is an esoteric tool that is not for the faint of heart and it is reasonably complex to master but in skilled hands it has performance that is beyond the best of modern compilers when properly written which makes it useful for performance critical tasks.

## Things To Get
For both space and copyright reasons the MASM32 SDK does not include reference material from either the Intel Corporation or the Microsoft Corporation but both make the best comprehensive reference material available as free downloads. With the Intel Corporation you would obtain the PIV set of manuals or later for compete mnemonic and architecture reference and with the Microsoft Corporation you can either use their online MSDN reference or download an appropriate PLATFORMSDK or its successor for you own version of Windows. If you can still find it it is useful to have the very old WIN32.HLP file on yur computer even if you have to download the Winhelp engine to use it on OS versions like Vista as it is a lot faster to load than the later CHM format help files and works with the F1 help key system built into the default editor.

## Warning
Not for the faint of heart. If MASM is beyond you, take up server side scripting.

