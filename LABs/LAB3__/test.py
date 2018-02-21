eq = "4+4=23"

for l in eq:
    if ((ord(l) >= 40) and (ord(l) <= 47)) or (ord(l) == 94) or (ord(l) == 61):
        print(l)

for l in eq:
    if ((ord(l) >= 48) and (ord(l) <= 57)):
        print(l)
