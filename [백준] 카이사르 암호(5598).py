for ch in input():
    print(chr(ord('A')+(ord(ch)-ord('A')-3)%26),end='')