# Mailman

## Description
CLI application to test and configure APIs by sending HTTP requests.

## Build and Run Instructions

Follow the steps below to build and run the project:

### 1. Create a Build Directory
```bash
mkdir build
```
This creates a new directory named `build` to keep the build files separate from the source code.

### 2. Navigate to the Build Directory
```bash
cd build
```
Switch to the `build` directory where the compilation will take place.

### 3. Generate Build Files with CMake
```bash
cmake ..
```
This generates the necessary build configuration files by invoking `CMake`. The `..` specifies the parent directory, where the `CMakeLists.txt` file is located.

### 4. Compile the Project
```bash
make
```
This compiles the source code using the generated build files and produces the final executable(s).

### 5. Run the Executable
```bash
./mailman
```
Executes the compiled program. Replace `mailman` with the actual name of the generated executable if different.

## Requirements
Ensure the following tools are installed on your system before running the build process:

- **CMake**: Used to generate the build configuration files.
- **Build Tools**: A compiler (e.g., `gcc` or `clang`) and `make` must be installed.

### Installing Dependencies
On a Debian-based system (e.g., Ubuntu), you can install these tools using:
```bash
sudo apt update
sudo apt install cmake build-essential
```

## Troubleshooting
If you encounter issues during the build process:
- Ensure all dependencies are installed and up-to-date.
- Verify that the `CMakeLists.txt` file is configured correctly.
- Check for error messages during the `cmake` or `make` steps for further debugging.

## License
This project is licensed under the [MIT License](./LICENSE).

## Author
- **Ansh Mehta**
- [GitHub Profile](https://github.com/anshmehta7x)
