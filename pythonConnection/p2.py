a = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'e', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

def convert(character):
    for i in range(len(a)):
        if a[i]==character:
            return i

def ord(character, x):
    shift = x
    x=shift%27
    val = convert(character) + x
    if val > 25:
        val = val - 27
        return val
    else:
        return val

p = ord('c', -2)

print(a[p])



