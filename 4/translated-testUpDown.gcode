(Scribbled version of /tmp/ink_ext_XXXXXX.svgJGANL0 @ 3500.00)
( unicorn.py --tab=plotter_setup --pen-up-angle=50 --pen-down-angle=30 --start-delay=150 --stop-delay=150 --xy-feedrate=3500 --z-feedrate=150 --z-height=0 --finished-height=0 --register-pen=true --x-home=0 --y-home=0 --num-copies=1 --continuous=false --pause-on-layer-change=false /tmp/ink_ext_XXXXXX.svgJGANL0 )
(G28 X Home the X axes)
(G28 Y Home the Y axes)
G21 (metric ftw)
G90 (absolute mode)
G92 X0.00 Y0.00 Z0.00 (you are here)

(M400 finish all movement)
G1 Z-0.1 F65 (pen down)
G4 P0.15 (wait 150ms)
G1 Z0.4 F65 (pen up)
G4 P0.15 (wait 150ms)
(M18 disengage drives)
M01 (Was registration test successful?)
(M17 engage drives if YES, and continue)

(Polyline consisting of 1 segments.)
G1 X14.67 Y22.46 F3500.00
(M400 finish all movement)
G1 Z-0.1 F65 (pen down)
G4 P0.15 (wait 150ms)
G1 X14.67 Y3.60 F3500.00
(M400 finish all movement)
G1 Z0.4 F65 (pen up)
G4 P0.15 (wait 150ms)

(Polyline consisting of 1 segments.)
G1 X25.41 Y22.72 F3500.00
(M400 finish all movement)
G1 Z-0.1 F65 (pen down)
G4 P0.15 (wait 150ms)
G1 X24.89 Y3.60 F3500.00
(M400 finish all movement)
G1 Z0.4 F65 (pen up)
G4 P0.15 (wait 150ms)


(end of print job)
(M400 finish all movement)
G1 Z0.4 F65 (pen up)
G4 P0.15 (wait 150ms)
G1 X0 Y0 F3500.00
G1 Z0.00 F150.00 (go up to finished level)
G1 X0.00 Y0.00 F3500.00 (go home)
(M18 drives off)
G1 Z0.4 F65 (pen up)
