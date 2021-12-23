![ScreenShot of the fetch](cat-fetch.png)

# cat-fetch
A cute, minimal fetch made in C [as my first C program]
Also Victor Mono is the recomened font for the cat art.

# Building
To build, you can either use the `install.sh` script, or use `gcc` (make sure you are in the same folder as the file!):

```
gcc cat_fetch.c -o cat-fetch
```
To use this without writing the path to the compiled binary every time, you can move it to `/bin/` using `sudo`:
```
sudo mv cat-fetch /bin/
```

after that, you can run catfetch with `cat-fetch` or whatever your compiled binary name was.

# Config

to config it, just modify and rebuild the program. Use the `install.sh` script to make things faster.


# TODO

- [x] add color support
- [ ] merge with watts version
- [ ] fix DWM bug
- [ ] Add more cats with a `--random` flag option
