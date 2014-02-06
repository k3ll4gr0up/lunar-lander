#!/bin/sh
echo 
echo 
curl -O ftp://ftp.gnu.org/gnu/ncurses/ncurses-5.9.tar.gz
tar -xzvf ncurses-5.9.tar.gz
cd ./ncurses-5.9
./configure --prefix=/usr/local --without-cxx --without-cxx-binding --without-ada --without-progs --without-curses-h --with-shared --without-debug --enable-widec --enable-const --enable-ext-colors --enable-sigwinch --enable-wgetch-events && make
echo 
echo 
echo Now you need to type in your password:
echo 
sudo make install
cd ..
rm -rf ncurses*
echo 
echo Done.
echo Now type in 'make' to continue!
