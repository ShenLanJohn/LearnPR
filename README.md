# LovelyDesign  [![Build Status](https://travis-ci.com/ColorfulTime/GeekDesign.svg?branch=master)](https://travis-ci.com/ColorfulTime/GeekDesign#)
For Learning CICD

### Additional Resources
- GBase
- Index

### Get GDesign
- Git clone
- make

### Release History

Platform | Release | Architecture | SSL   | Filename
-------- |-------- |------------  | ---   | --------
Linux    | Ubutnu18| x64          | 0.1.0 | GD


4 key concepts of docker:
Dockerfile, image, container, registry.


You can use [skip ci] or [ci skip] to skip the .CircleCI build.

#### 1. How to install cmake?
- sudo apt-get -Y install cmake
- or install specify one:
  
  sudo wget https://cmake.org/files/v3.11/cmake-3.11.4-Linux-x86_64.tar.gz
  
  tar xf cmake-3.11.4-Linux-x86_64.tar.gz
  
  export PATH="$(pwd)/cmake-3.11.4-Linux-x86_64/bin:$PATH" (you have to change ~./bashrc or /etc/environmetn if you want to change PATH permanantly)

#### 2. How to update /etc/environment by script?
https://stackoverflow.com/questions/26263249/how-to-modify-etc-environment-from-a-bash-script 

#!/bin/bash
sed -e 's|PATH="\(.*\)"|PATH="/opt/jdk1.6.0_45/bin:\1"|g' -i /etc/environment


#### 3. How to make 'sudo' preserve $PATH
https://unix.stackexchange.com/questions/83191/how-to-make-sudo-preserve-path
change path in /etc/sudoers


#### 4. About env and $PATH, sigle quotes and double quotes

single quotes and doube quotes: https://stackoverflow.com/questions/6697753/difference-between-single-and-double-quotes-in-bash

test data: "/foo4/foobar" + foobar is executalbe (chmon +x /foo4/foobar)

johnliu@Ubn1604G2:/root$ bash -c 'echo $PATH'

```/foo2:/foo1:/foo:/home/johnliu/dev/cmake-3.11.4-Linux-x86_64/bin:/opt/AAA/bin:/opt/jdk1.6.0_45/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games```

johnliu@Ubn1604G2:/root$ sudo bash -c 'echo $PATH'

```/foo4:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin```

johnliu@Ubn1604G2:/root$ sudo echo "$PATH"
```
/foo2:/foo1:/foo:/home/johnliu/dev/cmake-3.11.4-Linux-x86_64/bin:/opt/AAA/bin:/opt/jdk1.6.0_45/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
```
johnliu@Ubn1604G2:/root$ sudo echo '$PATH'
```
$PATH
```

johnliu@Ubn1604G2:/root$ sudo 'echo $PATH'
```
[sudo] password for johnliu:
sudo: echo $PATH: command not found
```
johnliu@Ubn1604G2:/root$ sudo "echo $PATH"
```
sudo: echo /foo2:/foo1:/foo:/home/johnliu/dev/cmake-3.11.4-Linux-x86_64/bin:/opt/AAA/bin:/opt/jdk1.6.0_45/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games: command not found
```

#### 5. [echo $PATH] VS [sudo echo $PATH]
##### root account's $PATH is from /etc/sudoers
##### general account johnliu's $PATH is from /etc/environment
#####  PLEASE use "env" and "sudo env" to check your PATH but not echo $PATH

Return result is same.

WHY??? 

take a look at "4.  About env and $PATH, sigle quotes and double quotes".  $PATH is variable, ehco $PATH will print out $PATH. 

format: sudo command

example 1: `sudo echo $PATH`: get $PATH under curent user ==> run echo under sudo

example 2: `echo $PATH`: get $PATH under curent user ==> run echo under current user

example 3: `sudo bash -c "echo $PATH"`: ==> run $PATH  dunder current user==> run  [echo "/foo2:/foo1:......."] as bash command under sudo

example 4: `sudo bash -c 'echo $PATH'`: ==> dont get $PATH, just run [echo $PATH] as bash command udner sudo

johnliu@Ubn1604G2:/root$ sudo echo $PATH
```
/foo2:/foo1:/foo:/home/johnliu/dev/cmake-3.11.4-Linux-x86_64/bin:/opt/AAA/bin:/opt/jdk1.6.0_45/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
```
johnliu@Ubn1604G2:/root$ echo $PATH
```
/foo2:/foo1:/foo:/home/johnliu/dev/cmake-3.11.4-Linux-x86_64/bin:/opt/AAA/bin:/opt/jdk1.6.0_45/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
```


### 6. [env] VS [sudo env] check PATH value
johnliu@Ubn1604G2:/root$ env
```
TERM=xterm
SHELL=/bin/bash
USER=johnliu
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
SUDO_USER=johnliu
SUDO_UID=1000
USERNAME=root
PATH=/foo2:/foo1:/foo:/home/johnliu/dev/cmake-3.11.4-Linux-x86_64/bin:/opt/AAA/bin:/opt/jdk1.6.0_45/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
MAIL=/var/mail/johnliu
PWD=/root
LANG=en_US.UTF-8
HOME=/home/johnliu
SUDO_COMMAND=/bin/bash
SHLVL=2
LOGNAME=johnliu
XDG_DATA_DIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop
LESSOPEN=| /usr/bin/lesspipe %s
DISPLAY=localhost:10.0
SUDO_GID=1000
LESSCLOSE=/usr/bin/lesspipe %s %s
_=/usr/bin/env
```
johnliu@Ubn1604G2:/root$ sudo env

```
TERM=xterm
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
PATH=/foo4:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin
LANG=en_US.UTF-8
HOME=/home/johnliu
DISPLAY=localhost:10.0
MAIL=/var/mail/root
LOGNAME=root
USER=root
USERNAME=root
SHELL=/bin/bash
SUDO_COMMAND=/usr/bin/env
SUDO_USER=johnliu
SUDO_UID=1000
SUDO_GID=1000
```
### 7. /etc/environment vs /etc/sudoers

johnliu@Ubn1604G2:/root$ vi /etc/environment

```
PATH="/foo2:/foo1:/foo:/home/johnliu/dev/cmake-3.11.4-Linux-x86_64/bin:/opt/AAA/bin:/opt/jdk1.6.0_45/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games"
```
johnliu@Ubn1604G2:/root$ sudo vi /etc/sudoers

```
#
# This file MUST be edited with the 'visudo' command as root.
#
# Please consider adding local content in /etc/sudoers.d/ instead of
# directly modifying this file.
#
# See the man page for details on how to write a sudoers file.
#
Defaults        env_reset
Defaults        mail_badpass
Defaults        secure_path="/foo4:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"

# Host alias specification

# User alias specification

# Cmnd alias specification

# User privilege specification
root    ALL=(ALL:ALL) ALL

# Members of the admin group may gain root privileges
%admin ALL=(ALL) ALL

# Allow members of group sudo to execute any command
%sudo   ALL=(ALL:ALL) ALL

# See sudoers(5) for more information on "#include" directives:

#includedir /etc/sudoers.d
```


Test1!
Test2!
Test3!1 2 a b c d e f g h i j 11 12
b1 b2 c1 c2
