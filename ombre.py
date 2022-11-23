clefs = (1, 2, 3)
vals = ('un', 'deux', 'trois')
print(vals[-1])
print({clef:vals[-i] for clef in clefs for i in range(1, len(vals) + 1)})

for clef in clefs:
    for i in range(1, len(vals) + 1):
        clef:vals[-i]