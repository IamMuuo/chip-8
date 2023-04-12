# Chip 8 Emulator 🕹️

Welcome to the Chip 8 Emulator! This repo contains everything you need to play classic Chip 8 games on your computer. Our emulator is built using CMake 🏗️ and the SDL2 library 🎨, which provide a powerful and flexible framework for graphics and audio programming.

## Getting Started 🚀

To get started, follow the instructions below.

### Prerequisites 🧰

To use our emulator, you will need the following software installed on your computer:

- CMake (version 3.13 or later) 🏭
- SDL2 library (version 2.0 or later) 🎭

If you don't have these tools installed, don't worry - we'll walk you through the installation process.

### Installing 💻

To install the emulator, follow these steps:

1. Clone the repo to your local machine 🖥️:

```bash
git clone https://github.com/IamMuuo/chip-8.git
```


2. Navigate to the repo directory using the command line 🕵️‍♀️:


```bash
cd chip-8
```


3. Create a build directory and navigate to it 🛠️:

```bash
mkdir build
cd build
```


4. Generate build files using CMake 🛠️:


```
cmake ..
```


This will generate the necessary build files based on the CMakeLists.txt file.

5. Build the emulator by running 🏗️:


```bash
make
```


This will compile the emulator and generate an executable file.

### Running 🏃‍♀️

To run the emulator, execute the following command from the `build` directory:

```bash
./chip-8 <path_to_rom_file>
```


Replace `<path_to_rom_file>` with the path to the Chip 8 ROM file you want to play.

For example:

```bash
./chip-8 ../roms/tetris.ch8
```


This will launch the emulator and load the specified ROM file.

## Controls 🎮

The Chip 8 emulator uses the following keyboard controls:

| Keyboard Key | Emulator Key |
|--------------|--------------|
| 1 | 1 |
| 2 | 2 |
| 3 | 3 |
| 4 | C |
| Q | 4 |
| W | 5 |
| E | 6 |
| R | D |
| A | 7 |
| S | 8 |
| D | 9 |
| F | E |
| Z | A |
| X | 0 |
| C | B |
| V | F |

## Contributing 🤝

Contributions are welcome! If you find a bug or have a feature request, please open an issue or submit a pull request. We are always looking for ways to improve our emulator and make it more accessible to everyone.

## License 📜

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments 🙏

This project was inspired by the love of classic video games and the desire to relive the nostalgia of childhood memories. We would like to extend our special thanks to the SDL 2.0 library 🎨 for providing an easy-to-use interface for graphics and audio programming, as well as the CMake community 🏭 for developing such a powerful and flexible build system. Without these tools, this project would not have been possible.
