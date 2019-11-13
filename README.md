
# YA_asteroids

![s1](screenshots/s1.png)

## How to launch on local machine

0. Install cmake
1. Install MinGW (make, g++)
2. Download SDL2-devel-x.x.x-mingw.tar.gz from [https://www.libsdl.org/download-2.0.php](https://www.libsdl.org/download-2.0.php) and copy SDL2, SDL2_image, SDL2_ttf development files to MinGW
3. That's all


### Current status

- [x] Spaceships (spaceship 1 keys: W, A, D, SPACE and spaceship 2 keys: UP, LEFT, RIGHT, ENTER)
- [x] Bullets
- [ ] Collisions
- [x] Debug info
- [ ] Extra weapons
- [ ] Extra effects  

### Run from console

```bash
C:\Workspace\asteroids\debug>cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug && make -j 4 && asteroids.exe
```

#### Author

Linkedin: [https://www.linkedin.com/in/slawektuleja/](https://www.linkedin.com/in/slawektuleja/)

#### License

You can use this software freely in any free or commercial project except files placed in 'resources' folder
