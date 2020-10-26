
strin = input("string to convert ")
inter = int(input("interval "))

def convert(strin, inter):
    finalval = ""
    for i in range(len(strin)):
        if (strin[i].isupper()):
            x = ord(strin[i]) + inter-65
            x = x%26
            finalval = finalval + chr(x + 65)
        else:
            y = ord(strin[i]) + inter-97
            y = y%26
            finalval = finalval + chr(y + 97)
    return finalval

o=convert(strin, inter)
print(o)