#!/bin/sh
chmod 777 Playgame.sh
echo "1 -> Two Player Tic Tac Toe"
echo "other Single Player Tic Tac Toe"
read ch
if [ $ch != "1" ]
then
	python tictactoe.py
else
	gcc tic_tac_2player.c
	./a.out
fi