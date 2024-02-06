set title "Block size = 32 (byte)"
set xlabel "Associativity"
set ylabel "miss rate (%)"
set term png font "Noto Sans CJK TC,12"
set output "way.png"
set key right

plot \
"way.txt" using 2:xtic(1) with linespoints linewidth 2 title "1KB", \
"way.txt" using 3:xtic(1) with linespoints linewidth 2 title "2KB", \
"way.txt" using 4:xtic(1) with linespoints linewidth 2 title "8KB", \
"way.txt" using 5:xtic(1) with linespoints linewidth 2 title "16KB", \
"way.txt" using 6:xtic(1) with linespoints linewidth 2 title "32KB", \
"way.txt" using 7:xtic(1) with linespoints linewidth 2 title "64KB", \
"way.txt" using 8:xtic(1) with linespoints linewidth 2 title "128KB", \
"way.txt" using 9:xtic(1) with linespoints linewidth 2 title "256KB", \
"way.txt" using 10:xtic(1) with linespoints linewidth 2 title "512KB"