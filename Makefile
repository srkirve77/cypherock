mnemonic_to_entropy:
	gcc -fPIC -c bip39.c
	gcc -shared -o libbip39.so bip39.o
	gcc -L/home/srkirve77/Downloads/trezor-firmware-82c0c403677a14bde56c1a6b440a46593a57267d/crypto -Wl,-rpath=/home/srkirve77/Downloads/trezor-firmware-82c0c403677a14bde56c1a6b440a46593a57267d/crypto main.c -lbip39  -lmemzero -lrand -lpbkdf2 -lsha2 -lhmac  -g
	./a.out