all: clean compile run

compile: 210104004239.c
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc 210104004239.c -c -lm
	@gcc 210104004239.o -lm

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./a.out
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f *.out
	@rm -f coefficients.txt
	@rm -f graph.txt
