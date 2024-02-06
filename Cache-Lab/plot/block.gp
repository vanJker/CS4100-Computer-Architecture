set title "Associativity = 1 (direct map cache)"
set xlabel "Block size (byte)"
set ylabel "miss rate (%)"
set term png font "Noto Sans CJK TC,12"
set output "block.png"
set key right

plot \
"block.txt" using 2:xtic(1) with linespoints linewidth 2 title "1KB", \
"block.txt" using 3:xtic(1) with linespoints linewidth 2 title "2KB", \
"block.txt" using 4:xtic(1) with linespoints linewidth 2 title "8KB", \
"block.txt" using 5:xtic(1) with linespoints linewidth 2 title "16KB", \
"block.txt" using 6:xtic(1) with linespoints linewidth 2 title "32KB", \
"block.txt" using 7:xtic(1) with linespoints linewidth 2 title "64KB", \
"block.txt" using 8:xtic(1) with linespoints linewidth 2 title "128KB", \
"block.txt" using 9:xtic(1) with linespoints linewidth 2 title "256KB", \
"block.txt" using 10:xtic(1) with linespoints linewidth 2 title "512KB"