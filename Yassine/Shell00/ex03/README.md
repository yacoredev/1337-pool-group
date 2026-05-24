## SSH me!
- What is SSH

SSH means Secure Shell.
It is a way to connect to another remote machine (server) using the terminal in a secure way.
With SSH, you can work on a remote server as if you are using it directly.
In 42 pool, SSH is used to access school machines and work only with the terminal.


Permissions:

    chmod 700 ~/.ssh
    chmod 600 ~/.ssh/id_rsa
    chmod 644 ~/.ssh/id_rsa.pub

> [!NOTE]
> In 42 school, computers are shared, so your work is stored on remote servers.

    ssh-keygen -t rsa -b 4096 -C "Your_email@example.com"  //Create an SSH key
    ssh -T git@github.com                                  //Connect to a server. If everything is correct, you will connect without a password
