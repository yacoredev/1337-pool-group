## Commands used
    git log --format="%H" -n5

    git log            Shows the commit history.
    --format='%H'      Shows only the full commit hash (ID) for each commit.
    -n5                Limits the output to 5 commits.

### Useful Placeholders

%H        Full commit hash

%h	Abbreviated commit hash

%an	Author name

%ae	Author email

%ad	Author date (honors the --date option)

%cn	Committer name

%cd	Committer date

%s	Subject (commit message title)

%b	Body (full commit message body)

%n	Newline
