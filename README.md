
# Final project of the course "Foundation of Software Engineering" 
## Team 5

This project is about finding the smallest possible square the pieces can be arranged in and prints it out.
Possible input:
```
...#
...#
...#
...#

....
....
....
####

.###
...#
....
....

....
..##
.##.
....
```
Output:
```
ABBBB
ACCC.
A..C.
ADD..
DD...
```


## Usage

Clone the project: `git clone https://github.com/warchiba/final_fse.git`\
Compile using the command: `cd final_fse && make`\
Then run the program with the command: `./fillit samples/input_file`\

### Dockerfile
You can also build docker image and run project inside it.\
`docker build .`\
`docker run -it <dicker_image_name> /bin/bash`\
`./fillit samples/input_file`\
If you have problems - try to do `make fclean && make fclean -C libft/`

