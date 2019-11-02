
# YA_asteroids

## How to launch on local machine

1. Install MinGW
2. Copy SDL2, SDL2_image, SDL2_ttf development files to MinGW (be careful - there are two almost the same folders)
3. That's all

## Performance

Windows 10, Dell XPS 13, Intel Core i7-8550U, 16GB RAM, UHD Graphics 620

    - 2 objects in the Space, Max FPS: 663 on laptop screen: Full HD (without vsync)
    - 10000 objects in the Space, Avg FPS: 53, Min FPS: 47 on LG monitor screen: 4K

### Run from console

```bash
C:\Workspace\asteroids\debug>cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug && make -j 4 && asteroids.exe
```

#### Author

Linkedin: [https://www.linkedin.com/in/slawektuleja/](https://www.linkedin.com/in/slawektuleja/)

#### License

You can use this software freely in any project free or commercial however except all files placed in 'resources' folder