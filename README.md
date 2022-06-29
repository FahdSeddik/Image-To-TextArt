# Image-To-TextArt
 C++ program that converts an image into ASCII characters written in a .txt file.

Written using OpenCV. Check out [Video-to-ASCII-on-Console](https://github.com/FahdSeddik/Video-to-ASCII-on-Console) project that follows from this one.

## Examples
![](https://github.com/FahdSeddik/Image-To-TextArt/blob/main/Screenshots/1.png)  
## 
  
![](https://github.com/FahdSeddik/Image-To-TextArt/blob/main/Screenshots/2.png)


  
## Process  
#### 1- Converted ASCII characters into fixed sized images numbered with their ASCII code  
Images can be found in the ASCII Chars folder
#### 2- Wrote a script to assign a value to each ASCII character  
This value is based on how many black pixels are present in each character  
The values are then written in a .txt file (this program was run only once)  
Program and file can be found in ASCII VALUES folder  
#### 3- Main  
To read the given image and the values text file then assign each set of pixels a specific ASCII character  
that is then written in an output file.  

