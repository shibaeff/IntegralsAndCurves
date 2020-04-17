To obtain the Makefile install cmake:
`sudo apt-get install cmake`

and run:

`cmake -DUSEBISEC=OFF` - in this case Newton's method will be used to solve equations

`cmake -DUSEBISEC=ON`   - in this case bisection method will be used to solve equations

Finally, run make:

`make all` - this will be build the entire project.

`./curves -h` - to get help about CLI options

`make clean` - to clean the build

Good luck! 

