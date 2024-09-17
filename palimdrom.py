def palimdromo(txt: str) -> bool:
    txt = txt.replace(' ','').lower()
    return txt == txt[::-1]

text_1 = 'anita lava la tina'
text_2 = 'segundo'

print(text_1, '=', palimdromo(text_1))
print(text_2, '=', palimdromo(text_2))