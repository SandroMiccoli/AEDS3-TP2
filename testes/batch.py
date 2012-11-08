#!/usr/bin/python
# -*- coding: latin-1 -*-

# Comando utilizado posteriormente para obter nome do arquivo e apenas o tempo de execução
#
# $ head -1 * | awk -F'user' '{print $1}'

import sys,os,random

entpd = 'entrada/pd/'
entg = 'entrada/g/'
saipd = 'saida/pd/'
saig = 'saida/g/'
comp = 'comp/'
script = './testes/generator.py '
arqAppend = ' >> '
arqNew = ' > '
tppd = './tp2pd '
tpg = './tp2g '
compare = './testes/compare.py '


i = int(sys.argv[1]) # numero de palavras
c = int(sys.argv[2]) # quantidade de concatenações

teste = script+str(i)+' '+str(c)

arqEnt= 'ent'+str(i)+str(c)+'.txt'
arqSai= 'sai'+str(i)+str(c)+'.txt'
arqCmp= 'cmp'+str(i)+str(c)+'.txt'

os.system(teste+arqNew+entpd+arqEnt)	# gera entrada pro pd
os.system('cp '+entpd+arqEnt+' '+entg+arqEnt)
#os.system(teste+arqNew+entg+arqEnt) 	# gera entrada pro g ERRADO

print "Comandos executados"

print teste

os.system(tppd+'pd/'+arqEnt+' pd/'+arqSai) 	# executa pd
print tppd+arqEnt+' pd/'+arqSai

os.system(tpg+'g/'+arqEnt+' g/'+arqSai)		# executa g
print tpg+arqEnt+' g/'+arqSai

os.system(compare+saipd+arqSai+' '+saig+arqSai+arqNew+comp+arqCmp)		# executa compare
print compare+saipd+arqSai+' '+saig+arqSai+arqNew+comp+arqCmp


#os.system('./tp0 '+arqEnt+' '+arqSai)
#os.system('/usr/bin/./time -o '+tempo+arqTmp+tp+arqEnt+' '+arqSai)
print "\nArquivos entrada"
os.system('ls '+entpd)
os.system('ls '+entg)
print "\nArquivos saida"
os.system('ls '+saipd)
os.system('ls '+saig)
print "\nArquivos de comparacao"
os.system('ls '+comp)
