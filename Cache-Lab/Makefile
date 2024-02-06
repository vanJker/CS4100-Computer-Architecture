SRC  := src
OBJ  := cache
PLOT := plot

block_size := 4 8 16 32 64 128
cache_size := 1 2 4 8 16 32 64 128 256 512
associativity := 1 2 4 8

$(OBJ): $(SRC)/cache.cpp
	g++ --std=c++14 -Wall -Wextra -Wconversion -o $@ $<

# fix the associativity on 1
$(PLOT)/block.txt: $(OBJ)
	@echo -n "" > $@
	@for bsz in $(block_size); do \
		echo -n $$bsz >> $@; \
		for csz in $(cache_size); do \
			./$(OBJ) -f testcase/Trace.txt -p $@ -a 1 -b $$bsz -c $$csz -s; \
		done; \
		echo "" >> $@; \
	done

# fix the block size on 32
$(PLOT)/way.txt: $(OBJ)
	@echo -n "" > $@
	@for assoc in $(associativity); do \
		echo -n $$assoc >> $@; \
		echo -n "-way" >> $@; \
		for csz in $(cache_size); do \
			./$(OBJ) -f testcase/Trace.txt -p $@ -b 32 -a $$assoc -c $$csz -s; \
		done; \
		echo "" >> $@; \
	done

.PHONY: plot
plot: $(PLOT)/block.txt $(PLOT)/way.txt $(PLOT)/block.gp $(PLOT)/way.gp
	@cd ./plot && gnuplot block.gp && gnuplot way.gp

.PHONY: build
build: cache

.PHONY: clean 
clean:
	@rm -rf *.o *out $(OBJ) $(PLOT)/*.txt $(PLOT)/*.png