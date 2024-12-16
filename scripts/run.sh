#!/bin/bash

cd ..

# Step 1: Create a Build Directory
echo "Creating build directory..."
mkdir -p build

# Step 2: Navigate to the Build Directory
echo "Navigating to the build directory..."
cd build

# Step 3: Generate Build Files with CMake
echo "Generating build files with CMake..."
cmake ..

# Step 4: Compile the Project
echo "Compiling the project with make..."
make

# Step 5: Run the Executable
echo "Running the executable..."
./mailman
