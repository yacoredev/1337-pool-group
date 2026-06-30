
<img src="https://github.com/Yacin-lab/Uses/blob/main/img/linux-ls-detail.jpg">

## Commands used

    list detail:          ls -l
    permissions:          chmod u=...,o=...,g=... [file]
    time:                 touch -t YYMMDDHHMMSS [file]
    archive:              tar -cf archive.tar files_or_directory

> [!NOTE]
> tar: tool used to group multiple files into one archive.
> -c (create): creates a new archive.
> -f (file): specifies the archive file name.

> [!TIP]
> To extract the contents of a tar archive while preserving original
>
> attributes (permissions, ownership, timestamps), use:
> 
> `tar -xpf archive.tar`
>
> `-x` → extract files
> 
> `-p` → preserve original permissions
> 
> `-f` → specify the archive file
