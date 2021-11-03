with open('./source.bin','rb+') as f:
    with open('./source_dec.bin','wb+') as ff:
        s = list(f.read())
        for i in range(len(s)):
            s[i] = s[i] ^ 65
        ff.write(bytes(s))