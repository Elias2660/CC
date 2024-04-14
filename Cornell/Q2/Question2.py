braille = {"a": 1, "b": 2, "c":2,"d":3,"e":2,"f":3,"g":4,"h":3,"i":2,"j":3,"k":2,"l":3,"m":3,"n":4,"o":3,"p":4,"q":5,"r":4,"s":3,"t":4,"u":3,"v":4,"w":4,"x":4,"y":5,"z":4}
out = 0
for s in input():
    out += braille[s]
print(out)