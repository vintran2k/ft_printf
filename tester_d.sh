chmod +x d.py
./d.py > main_d.c

#Enleve le # de la ligne de commande suivante si tu veux que le script compile tes .c
gcc -Wall -Wextra *.c -o prog && ./prog
