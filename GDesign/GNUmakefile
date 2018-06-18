ACC=g++
IDIR =./include
LIB=./output/lib
RELEASE=./output/release
PKGNAME=Sample_GDesign

all: 
	if [ ! -d /home/johnliu/dev/Sample/GDesign/output/lib ];then \
		mkdir -p output/lib; \
	fi
	$(ACC) -g -c GDesign.cpp -o ./output/lib/GDesign.o

	if [ ! -d "./output/release" ]; then \
		mkdir -p output/release; \
		mkdir -p output/release/$(PKGNAME)/DEBIAN; \
	fi
	$(ACC)  -g GDesign.cpp -o ./output/release/GDesign
	scp installbuilder/control ./output/release/$(PKGNAME)/DEBIAN
	scp ./output/release/GDesign ./output/release/$(PKGNAME)
	dpkg-deb -b ./output/release/$(PKGNAME) ./output/release/$(PKGNAME).deb
install:
	sudo dpkg -i ./output/release/$(PKGNAME).deb
	
.PHONY: clean
clean:
	rm -rf ./output
