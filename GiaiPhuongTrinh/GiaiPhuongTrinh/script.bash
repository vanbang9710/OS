cd C || exit
ls
gcc -o PhuongTrinhBac1.o -c PhuongTrinhBac1.cpp
ls
gcc -o GiaiPhuongTrinh.o -c GiaiPhuongTrinh.cpp
ls
gcc -o giaipt GiaiPhuongTrinh.o PhuongTrinhBac1.o
ls
./giaipt
2
6

#1 result
# [vanba@oralinux C]$ cd ..
# [vanba@oralinux ~]$ cd C
# [vanba@oralinux C]$ ls
# GiaiPhuongTrinh.cpp  GiaiPhuongTrinh.o  giaipt  PhuongTrinhBac1.cpp  PhuongTrinhBac1.o  PhuongTrinh.h
# [vanba@oralinux C]$ gcc -o PhuongTrinhBac1.o -c PhuongTrinhBac1.cpp
# [vanba@oralinux C]$ ls
# GiaiPhuongTrinh.cpp  GiaiPhuongTrinh.o  giaipt  PhuongTrinhBac1.cpp  PhuongTrinhBac1.o  PhuongTrinh.h
# [vanba@oralinux C]$ gcc -o GiaiPhuongTrinh.o -c GiaiPhuongTrinh.cpp
# [vanba@oralinux C]$ ls
# GiaiPhuongTrinh.cpp  GiaiPhuongTrinh.o  giaipt  PhuongTrinhBac1.cpp  PhuongTrinhBac1.o  PhuongTrinh.h
# [vanba@oralinux C]$ gcc -o giaipt GiaiPhuongTrinh.o PhuongTrinhBac1.o
# [vanba@oralinux C]$ ls
# GiaiPhuongTrinh.cpp  GiaiPhuongTrinh.o  giaipt  PhuongTrinhBac1.cpp  PhuongTrinhBac1.o  PhuongTrinh.h
# [vanba@oralinux C]$ ./giaipt
# Please enter a=Please enter b=one result, -3.000000[vanba@oralinux C]$

cat Makefile
make
make clean
ls
make

make clean
make
./giaipt
2
6

make clean
make
./srtf