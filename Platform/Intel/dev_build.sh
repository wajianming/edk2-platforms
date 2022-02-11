python build_bios.py -p WilsonCityRvp -t GCC5 -d
cp $PWD/../../../Build/WhitleyOpenBoardPkg/DEBUG_GCC5/FV/WILSONCITYRVP.fd ~/WILSONCITYRVP.bin
sha256sum ~/WILSONCITYRVP.bin
