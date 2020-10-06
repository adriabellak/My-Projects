# Proyecto Integrador
# Adriana Abella Kuri
# A01329591

def show_tablero(tablero):
    print("  0 1 2 3 4 5")
    for e in range(6):
        print(str(e), end=" ")
        for f in range(6):
            print(tablero[e][f],end=" ")
        print(end='\n')
    


import random

# lista inicial
nums = [0]*36
for b in range(0,18):
    d = chr(64+b+1)
    nums[b]=d
    nums[b+18]=d

# random shuffle
random.shuffle(nums)

# creación de matriz
renglon0 = [0]*6
renglon1 = [0]*6
renglon2 = [0]*6
renglon3 = [0]*6
renglon4 = [0]*6
renglon5 = [0]*6

for c in range (0,36):
    if c>=0 and c<6:
        renglon0[c] = nums[c]
    elif c>=6 and c<12:
        renglon1[c-6] = nums[c]
    elif c>=12 and c<18:
        renglon2[c-12] = nums[c]
    elif c>=18 and c<24:
        renglon3[c-18] = nums[c]
    elif c>=24 and c<30:
        renglon4[c-24] = nums[c]
    elif c>=30 and c<36:
        renglon5[c-30] = nums[c]

matrix = [renglon0, renglon1, renglon2, renglon3, renglon4, renglon5]

tablero = [['-']*6,['-']*6,['-']*6,['-']*6,['-']*6,['-']*6]

# mostrar tablero
show_tablero(tablero)
    
# comenzar a jugar
contador = 1
juego = True
puntos1 = 0
puntos2 = 0

while juego==True:
    j=0
    x1=10
    y1=10
    x2=10
    y2=10
    if contador%2!=0:
        print("Turno de jugador 1.")
    else:
        print("Turno de jugador 2.")
    while x1==x2 and y1==y2:
        while (x1>5 or y1>5 or x1<0 or y1<0) or tablero[x1][y1]!='-':
            x1=int(input("Renglón de la primera carta: "))
            y1=int(input("Columna de la primera carta: "))
        print("Valor de la carta: ", end=matrix[x1][y1])
        print(end='\n')
        while (x2>5 or y2>5 or x2<0 or y2<0) or tablero[x2][y2]!='-':
            x2=int(input("Renglón de la segunda carta: "))
            y2=int(input("Columna de la segunda carta: "))
        print("Valor de la carta: ", end=matrix[x2][y2])
        print(end='\n')
    if matrix[x1][y1]==matrix[x2][y2]:
        tablero[x1][y1]=matrix[x1][y1]
        tablero[x2][y2]=matrix[x2][y2]
        if contador%2!=0:
            puntos1=puntos1+1
        else:
            puntos2=puntos2+1
            
    show_tablero(tablero)
        
    for g in range(6):
        for h in range(6):
            if tablero[g][h]=='-':
                j=j+1
    if j==0:
        juego=False
    else:
        print("¿Continuar juego? s=sí, n=no.")
        si_no=input()
        if si_no=='s':
            juego=True
        elif si_no=='n':
            juego=False
    if juego==False:
        print("Juego terminado.")
        print("Puntaje del jugador 1: ", end=str(puntos1))
        print(end='\n')
        print("Puntaje del jugador 2: ", end=str(puntos2))
        print(end='\n')
        if puntos1>puntos2:
            print("Ganador: Jugador 1")
        elif puntos2>puntos1:
            print("Ganador: Jugador 2")
        elif puntos1==puntos2:
            print("¡Empate!")
    contador=contador+1
