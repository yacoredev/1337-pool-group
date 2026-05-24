`git ls-files -o -i --exclude-standard`

        #!/bin/sh
        👉 Tells the system to run the script using sh (shell).

        git ls-files
        👉 Lists files known by Git.

        --others
        👉 Shows files not tracked by Git.

        --ignored
        👉 Shows files that Git ignores (from .gitignore).

        --exclude-standard
        👉 Uses the default ignore rules
        (.gitignore, global ignore, etc.)

        ✅ Meaning of the whole command:
        👉 Show all ignored files in the repository.
        
        git status --ignored        //test ignored files
       
        give script permission execute         chmod +x
