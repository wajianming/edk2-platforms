python build_bios.py -p SMCIx12SPW -t GCC5 -d
cp $PWD/../../../Build/WhitleyOpenBoardPkg/DEBUG_GCC5/FV/SMCIX12SPW.fd ~/WILSONCITYRVP.bin
sha256sum ~/WILSONCITYRVP.bin
