def any_lowercase1(s):
    for c in s:
        if c.islower():
            return True
        else:
            return False

x=any_lowercase1('IIeee')
print(x)