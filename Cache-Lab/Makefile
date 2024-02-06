SRC := src

cache: $(SRC)/cache.cpp
	g++ --std=c++14 -Wall -Wextra -Wconversion -o $@ $<

.PHONY: build
build: cache

.PHONY: clean 
clean:
	@rm -rf *.o *out cache