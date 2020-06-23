import sys

f2 = open(f"translated-{sys.argv[1]}", "w")
with open(sys.argv[1]) as 15 (wait 150ms)")
        elif "M400" in line f:
    for line in f.readlines():
        if "(pen up)" in line:
            f2.write("G1 Z0.4 F65 (pen up)")
        elif "(pen down)" in line:
            f2.write("G1 Z-0.1 F65 (pen down)")
        elif "wait 150ms" in line:
            f2.write("G4 P0.or "G28" in line or "M18" in line or "M17" in line:
            f2.write(f"({line.strip().replace('(', '').replace(')', '')})")
        else:
            f2.write(line.strip())
        f2.write('\n')
f2.close()
