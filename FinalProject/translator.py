u1 = "ヲァィゥェォャュョッーアイウエオカキクケコサシスセソタチツテトナニヌネノハヒフヘホマミムメモヤユヨラリルレロワン"
u2 = 'カガキギクグケゲコゴサザシジスズセゼソゾタダチヂツヅテデトドハバヒビフブヘベホボ'
u3 = 'ハパヒピフプヘペホポ'

katakana_chart = "ァアィイゥウェエォオカガキギクグケゲコゴサザシジスズセゼソゾタダチヂッツヅテデトドナニヌネノハバパヒビピフブプヘベペホボポマミムメモャヤュユョヨラリルレロヮワヰヱヲンヴヵヶヽヾ"
hiragana_chart = "ぁあぃいぅうぇえぉおかがきぎくぐけげこごさざしじすずせぜそぞただちぢっつづてでとどなにぬねのはばぱひびぴふぶぷへべぺほぼぽまみむめもゃやゅゆょよらりるれろゎわゐゑをんゔゕゖゝゞ" 
hir2kat = str.maketrans(hiragana_chart, katakana_chart)

dic1 = {}
for (i, p) in zip(u1, range(0xA6, 0xDE)):
    dic1[i] = hex(p).replace('0x', r'\x')
flg = 0
wd = ''
for i in u2:
    flg = 1 - flg
    if flg == 1:
        wd = i
    else:
        dic1[i] = dic1[wd] + r'\xde'
flg = 0
wd = ''
for i in u3:
    flg = 1 - flg
    if flg == 1:
        wd = i
    else:
        dic1[i] = dic1[wd] + r'\xdf'

print(dic1)
while True:
    q = input().translate(hir2kat)
    ans = []
    for i in q:
        if i in dic1.keys():
            ans.append(dic1[i])
        else:
            ans.append(i)
    print(''.join(ans))
