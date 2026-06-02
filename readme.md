# SDL3 CMake Project Template
This is a basic 'hello world' SDL3 cmake project.

## Building this project
This project uses the cmake build system, this is a cross-platform build system with wide support outside of the Microsoft ecosystem. Many of the FOSS projects, such as OBS Studio and SDL are developed with this build system. You can view these on their github pages.

### Windows
On windows, the path of least resistance is to install visual studio community edition, along with the C++ tools (and cmake support). You can then open the cmake project from the file menu (I don't know of a way to open an existing cmake project from the launcher - sorry). 

There is a step by step guide I wrote for security. You can find it in the [COMP280 Resources](http://fal.fosslab.uk/comp280/unreal/sec_pt1/). Ignore the bit about the adventure game in the guide.

### Linux/CLI
If you have a cmake CLI, toolchain and compiler setup. You can use modern cmake commands to build this project:

```bash
cmake -B build/ -S .
cmake --build build
```

Another option is to use CLion, you can get free Educational licences while you are a student. If you've used pycharm, it's pycharm for C++.

## Dealing with dependencies
CMake has reasonably good dependency resolution support if setup correctly, and it takes a lot of the headache out of dealing with dependency management.

## Linux
For most linux distrubtions, the common way to install the cmake library, `packagename` would be:

In an ideal world, you would use the package manager provided by your distrubtion to manage your dependeicies:

On Fedora: `sudo dnf install pkgconfig(packagename)`
On Debian/Ubuntu: `sudo apt install libpackagename-dev`

You can integrate 3rd party package managers (eg, conan), but please don't. It makes life a pain for maintaining distrubtion packages (not that it's likely you'll want to package your project). If you're especially adventurous you can set up vcpkg on linux and the project will try to download libraries like in visual studio given the correct environment variables for vcpkg are set.

## Windows
On windows, you should use vcpkg, you can configure this as a standard user (ie, no admin rights). This project contains the code needed to bootstrap this into the project. Follow [Joseph's guide](http://fal.fosslab.uk/comp290/workshops/00_vcpkg/) on how to do this.

On windows: `vcpkg install packagename:x64-windows`

## Mac
On Mac, you can use the linux style cmake cli pipeline to generate the binary just like on linux. You will need brew to install the dependencies.

Mac: `brew install cmake sdl3 sdl3_image`

And the same build command works as with linux:
```bash
cmake -B build/ -S .
cmake --build build
```

Although if you want to work with xcode and have run through all the setup correctly you can generate an Xcode project with the following command that you can then open from the build folder:

```bash
cmake -G Xcode -B build/ -S .
```

## Tips for Usage
In this version of the template repo you will see some additional changes from the repo it's forked from. Firstly the sdl3 and sdl3-image libraries are linked by default. Secondly some quality of life tweaks have been added.

### SDL3 linkage
sdl3 and sdl3-image libraries have been included and linked for you in CMakeLists.txt if you are using vcpkg it should "just work" as these libraries are supported in the package repository. Otherwise if you're on linux you may need to run one of the following:

On Fedora: `sudo dnf install pkgconfig(sdl3) pkgconfig(sdl3-image)`
On Debian/Ubuntu: `sudo apt install libsdl3-dev libsdl3-image-dev`
On Mac: `brew install sdl3 sdl3_image`

### `data/` and automatic asset copying
To add support for binary assets used in your code without encouraging you to commit your builds, a step to copy all of the files in `data/` to the binary output location has been added to the `CMakeLists.txt`. Please place images and other binary assets in this directory. They will be accessible to your executable via a relative path at runtime.

E.g, `data/image.png` should be available at `./image.png` when running the project executable from its build folder.
