## Commands used


    permissions:                  chmod u=...,o=...,g=... [file]
    change time (soft link):      touch -h -t YYMMDDHHmmss [path/to/link]
    create Symbolic Links:        ln -s [file-direc] [link]
    create hard Links:            ln [file] [link]
    archive:                      tar -cf archive.tar files_or_directory

> [!WARNING]
> Hard Links cannot link to directories
> 
> If the original file or directory is deleted or moved,
>
> the symbolic link will be broken
>
> the data remains accessible through the hard link(s)
