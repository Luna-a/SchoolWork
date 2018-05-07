
all:
	g++ -std=c++11 des.cpp -o des
	./des -i input -k 133457799bbcdff1 -iv 133457799bbcdff1 -e
	./des -i CIPHER.txt -k 133457799bbcdff1 -iv 133457799bbcdff1 -d
