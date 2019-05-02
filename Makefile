plot.png: datos.dat plot.py
	python plot.py

%.dat : a.out
	./a.out

a.out: dat.cpp
	g++ dat.cpp

clear:
	rm -rf *.dat *.png *.out