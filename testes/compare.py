#!/usr/bin/python
# -*- coding: latin-1 -*-


#Compara duas saidas 
#Argumentos:
#1- Arquivo Saida PD
#2- Arquivo Saida Guloso

import sys

fin=open(sys.argv[1],"r")
n_pd=fin.readlines()
fin.close()
fin=open(sys.argv[2],"r")
n_guloso=fin.readlines()
fin.close()

count=0
for i in range(len(n_pd)):
	if (int(n_pd[i]) == 0):
		print (float(n_guloso[i])*100)
	else:
		print round(float(n_guloso[i])*100/float(n_pd[i]),2)-100
		



