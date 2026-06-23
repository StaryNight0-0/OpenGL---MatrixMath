
<img width="700" height="70" alt="OpenGL_Matrix_Math(1)" src="https://github.com/user-attachments/assets/05587269-0102-415a-9904-a81a55fcc5b1" />



![Static Badge](https://img.shields.io/badge/C%2B%2B-red)                ![Static Badge](https://img.shields.io/badge/OpenGL-red)            ![Static Badge](https://img.shields.io/badge/CMake-red)       ![Static Badge](https://img.shields.io/badge/SDL2-red)

A Brief overview of the usage of OpenGL matrices.

<img width="750" height="422" alt="giphy" src="https://github.com/user-attachments/assets/13513396-9629-4288-a47a-40942845636b" />

Designed using NVIM and Linux , not fully tested on Windows.

## Tech Stack 💻
- C++
- SDL2 (``` SDL2::SDL2```)
- OpenGL 4.6
- GLM Library
- glad
- Dear ImGui
- CMake





## Usage 🔧

1. Install from GitHub.
2. Once installed, configure the file using the CMake lists available in the build. ```(Cmake ..)``` on Linux.
3. SDL2 must be installed on your system for this to work appropiately ```(Sudo apt install libsdl2-dev)``` on Ubuntu.
4. Then to run the application use ``` ./Caboodle ``` .
   
## Key Features
- The code will have comments along with is so the user is able to understand what is happening and can modify and too it if they want to.
 - This code is built to be modified so the user can understand some more about matrices and their uses within vertex and fragment shaders. It also grants an insight into some basic OpenGL conecpts and functions.
 - If you wish to modify the code, please bare in mind all of the code relates back to the ``` MainLoop.cpp ``` . Individual code pieces such as window can be found in their respective files such as ``` Window.cpp ```  where you will be able to view variables such as ``` screenWidth ```  and ``` screenHeight ``` .
## Example
  <img width="640" height="480" alt="codesnip1" src="https://github.com/user-attachments/assets/d723b971-a383-4394-bf8c-edbdd3e04e75" />

## Lessons Learned 🎓
I decided to take on this project to learn some more lower level ideas when it comes to programming. I have taken a more  proactive approach to how I organise my C++ projects aswell as learning some low level maths. I feel this can add to my arsenal when it comes to gameplay programming as I understand the systems in which I work with everyday.

There is also the use of memory to take into account using buffers and uniform variables. Both of the shaders are also made custom using GLSL. I also got hands on experience with using CMake which was a completely new venture for me. 

















