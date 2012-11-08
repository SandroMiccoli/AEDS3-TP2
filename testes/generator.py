#!/usr/bin/python
# -*- coding: latin-1 -*-


#Gera um arquivo teste para TP2 - AEDS3
#Argumentos:
#1- Quantidade de palavras
#2- Quantidade de concatenações em cada palavra impressa

import sys
import random


dicio = open('testes/dictionary.txt','r')
n = int(sys.argv[1]) 
k = int(sys.argv[2]) 
words=dicio.readlines()
dicio.close()

for i in range(len(words)):
	words[i]=words[i].replace('\n','')
	words[i]=words[i].replace('\r','')
	words[i]=words[i].lower()

words=random.sample(words,n*k)

for j in range(n):
	words[j] = ''.join(words[j:k+j])
	del words[j+1:k+j]

print(n)
for word in words:
	print(word)
