fastcsv: src/*.c
	gcc -std=c99 -o bin/fastcsv src/*.c

clean:
	rm -rf bin/*