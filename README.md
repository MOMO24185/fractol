# fractol

## Overview
`fractol` is a dynamic fractal image generation software featuring three built-in fractal types: Mandelbrot, Julia, and Flame. It offers an engaging, interactive experience that allows users to explore these mathematical wonders through real-time visualization and manipulation.

## Features
- **Fractal Types:**
  - Mandelbrot set
  - Julia set
  - Flame fractals
- **Interactivity:**
  - Real-time zooming and panning
  - Color customization
  - Parameter adjustment for Julia set coefficients
- **Cross-Platform Support:**
  - Designed to work on multiple platforms, including Linux and macOS.

## How It Works
The program:
1. **Initializes Fractal Data:**
   - Loads fractal parameters and screen resolution settings.
2. **Generates Fractals:**
   - Uses mathematical algorithms to compute fractal visuals for the specified type.
3. **Interactive Features:**
   - Responds to user input (e.g., mouse and keyboard) for zooming, moving, and parameter tuning.
4. **Real-Time Rendering:**
   - Renders fractals dynamically, offering instant visual feedback for user interactions.

## Usage
### Compilation
Compile the program using the `Makefile`:
```bash
make
```

### Running the Program
Execute the program with the following syntax:
```bash
./fractol <fractal_type>
```

#### Supported Fractal Types:
- `mandelbrot`
- `julia`
- `flame`

#### Example:
```bash
./fractol mandelbrot
```

### Interactive Controls
- **View Menu:** Press H to view controls.

## Key Concepts
### Fractals
Fractals are infinitely complex mathematical shapes, created by repeating a simple process over and over in an ongoing feedback loop. They are visual representations of equations that exhibit self-similarity across different scales.

### Mandelbrot Set
A set of complex numbers that produce a connected and infinitely detailed shape when visualized.

### Julia Set
Derived from the Mandelbrot set, these fractals vary based on user-defined parameters, creating a vast array of possible designs.

### Flame Fractals
A type of iterated fractal that uses nonlinear equations to create intricate, flame-like patterns.

## Dependencies
- **MinilibX (mlx):** A simple and lightweight graphics library.
- **libft:** Custom helper functions.

## License
This project is released under the MIT License.

