Installation
------------

Below are installation instructions for various operating systems. Use the set of instructions that
best applies to you. If your operating system is missing from the list, see 'Generic Instructions'
at the bottom for help.

If you can supply instructions for an operating system that is not listed here, please email me or
submit a pull request updating this document.

#### Ubuntu/Debian/Mint Linux

```
sudo apt-get update
sudo apt-get install lib32ncurses5-dev lib32ncursesw5-dev
git clone https://github.com/GLUG-REVA/welcome.git
cd ./welcome
make
sudo make install
```

#### Fedora Linux

```
sudo dnf update --refresh
sudo dnf install ncurses-devel
git clone https://github.com/GLUG-REVA/welcome.git
cd ./welcome
make
sudo make install
```

#### Redhat/Cent OS Linux

```
sudo yum update
sudo yum install ncurses-devel
git clone https://github.com/GLUG-REVA/welcome.git
cd ./welcome
make
sudo make install
```

#### Arch Linux

```
sudo pacman -Sy
sudo pacman -S ncurses
git clone https://github.com/GLUG-REVA/welcome.git
cd ./welcome
make
sudo make install
```

From source:
```
sudo zypper ref
sudo zypper in ncurses-devel
git clone https://github.com/GLUG-REVA/welcome.git
cd ./welcome
make
sudo make install
```

#### Generic Instructions

First, make sure you have the ncurses header installed:
```
ls /usr/include | grep ncurses.h
```
Also make sure you have the ncurses library for wide character support:
```
ls /usr/lib | grep libncursesw.so
```
If either file is missing, you may need to install the ncurses and/or ncursesw library. All linux
distributions should have these available from their package manager. Usually they are both included
in a single package named something along the lines of 'ncurses'. However, on some distrubutions, such
as Ubuntu, you need to install them as separate packages. For example:
```
sudo apt-get update
sudo apt-get install lib32ncurses5-dev lib32ncursesw5-dev
```
Use your package manager to search for the "ncurses" package. Install
it. If you see two different packages for "ncurses" and "ncursesw", install them both (as shown above
in the Ubuntu example).

Next, download and build the standalone executable:
```
git clone https://github.com/GLUG-REVA/welcome.git
cd ./welcome
make
sudo make install
```

[Back to README](README.md)
