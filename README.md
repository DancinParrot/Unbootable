# Unbootable
Simple MBR wiper that overwrites the first 512 bytes of the root drive, and thus, preventing the computer from booting.

# Compilation
To compile the project into a single executable, do the following:
```Bash
# Compile manifest into object file
i686-w64-mingw32-windres --input manifest.rc --output manifest.o

# Compile to 32-bit exe
i686-w64-mingw32-gcc -std=c++11 main.c manifest.o -o unbootable.exe -s -lws2_32 -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc
```

# Features
As of now, the program is really simple, which also means that it can be easily detected by AVs/EDRs. Though, maybe I'll test out some obfuscation techniques in the future.

# Known Issues
- Program crashes on Win 7 x86, though will still overwrite MBR

# Credits
The following resources were of great help to me:  
[Python and Malware: Writing a simple wiper malware](https://0x00sec.org/t/python-and-malware-writing-a-simple-wiper-malware/31652)
[Malware Development – Welcome to the Dark Side: Part 2-1](https://niiconsulting.com/checkmate/2018/02/malware-development-welcome-dark-side-part-2-1/)