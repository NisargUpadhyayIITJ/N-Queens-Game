# N-Queens Visualizer Project

This project is a visualizer for the N-Queens problem. It allows users to visualize all possible solutions for the N-Queens problem on an `n x n` chessboard.
The site is live:-  [N-Queens Game](https://nisargupadhyayiitj.github.io/N-Queens-Game/index.html)

## How to Run the Project

Follow these steps to run the project locally:

### Step 1: Download the ZIP File
1. Download the ZIP file containing the project source code from the provided link or repository.
2. Extract the contents of the ZIP file to your preferred directory.

### Step 2: Open the Project
1. Navigate to the folder where you extracted the files.
2. Locate the `index.html` file.

### Step 3: Run the Project
1. Open the `index.html` file in any modern web browser (Google Chrome, Firefox, Microsoft Edge, etc.).
2. You will see the visualizer interface, where you can input the number of queens and see the possible board arrangements.

## Important Notes

- **Do not delete or modify any files** in the extracted folder as this could break the functionality of the project.
- Ensure that all files, including `.css`, `.js`, and `assets` (if any), are in the same folder as the `index.html` file.

## Project Overview

This project visualizes all the possible solutions of the N-Queens problem for different board sizes. The N-Queens problem is a famous combinatorial problem where you must place `n` queens on an `n x n` chessboard such that no two queens threaten each other.

### Features

- **Input Board Size**: You can specify the size of the chessboard (number of queens) between 1 and 8.
- **Visualizer**: See all possible valid arrangements of queens on the board.
- **Speed Control**: Adjust the speed of the visualization using the slider.

### Technology Used

- **C++ with Emscripten**: The core logic for solving the N-Queens problem is implemented in C++. Emscripten is used to compile the C++ code into WebAssembly, enabling it to run in the browser.
- **JavaScript**: JavaScript is utilized to connect the WebAssembly code with the visualization and user interface.

### Enjoy solving the N-Queens problem visually! 🎮

