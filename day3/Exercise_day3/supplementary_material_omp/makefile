#######################################################################	

all: 	1.BS.cpp.exec 2.dot_prod.cpp.exec 3.normalize_vec.cpp.exec \
	4.serial_pi.cpp.exec 

#######################################################################	


## Example 1
1.BS.cpp.exec: BS.cpp
	g++ BS.cpp -fopenmp -o 1.BS.cpp.exec

## Example 2
2.dot_prod.cpp.exec: dot_prod.cpp
	g++ dot_prod.cpp -fopenmp -o 2.dot_prod.cpp.exec	
	
## Example 3
3.normalize_vec.cpp.exec: normalize_vec.cpp
	g++ normalize_vec.cpp -fopenmp -o 3.normalize_vec.cpp.exec		
	
## Example 4
4.serial_pi.cpp.exec: serial_pi.cpp
	g++ serial_pi.cpp -fopenmp -o 4.serial_pi.cpp.exec
	
clean :
	rm -f *.exec
