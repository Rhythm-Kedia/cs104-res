# Lab 01 A1 Commands 

```pwd``` and ```cd```; absolute vs relative paths; dir1, dir2, file1, file2 etc are used as reference. You need to interpret it carefully.

In some cases we assume these dir/files alreay created, in other cases you maybe creating them.

Note you have root access in the container, hence your home is /root

```bash
cd /
cd /root/
cd /home/
cd /home/labDirectory/
```

Assuming you are in /home when trying the commands. All below mean same. the first is relative, the latter is absolute path.

when trying below, if you entered a folder, you need to find a way to get back to /home to try the next command

Remember to use “Tab” for autofilling.
cd labDirectory ; cd /home/labdirectory/; cd ~/../home/labdirectory

#assume you are inside labDirectory. go to /home and then to /root Note ".." is parent directory, . is current directory. Use pwd to check where you are
cd .
cd ../
cd ../../
#change to home directory of the user
cd
#change back to previous working directory
cd -

## ls
try out below inside some folder


```bash
ls -a; ls -l; ll, ls -al
```
You can also pass multiple directories and files separated by space:

```bash
ls /etc /var /etc/passwd
```

Understand via web or man what these options mean, choose a relevant folder and checkout options -X, -S, -t, -R, Be sure the folder has many files (e.g. /etc/)

```bash
ls -lt
```

# mkdir
## absolute and relative

```bash
mkdir /tmp/test ; mkdir test/
## multiple folders; notice the multiple arguments?
mkdir dir1 dir2 dir3 ; ls
##recursively; try with and without -p
mkdir -p dir1/dir2
#complex command :-)
mkdir -p Music/{Jazz/Blues,Folk,Disco,Rock/{Gothic,Punk,Progressive},Classical/Baroque/Early}
##If you want to work with spaces in directory or file names, you need to escape them. But not recommended, go with _ or -
mkdir "dir 1"
mkdir 'dir 2'
mkdir dir\ 3
```

# echo
- redirection via ls also to create file

```bash
echo "This is a test"
echo "This is a test" > file1
ls > file2
```

# cat, print, file redirection

```bash
cat file1
cat file1 file2 file3
cat file*

cat file* > newfile
cat newfile
cat file* >> newfile
cat newfile

#numbering and delete extra lines
cat -n /etc/lsb-release
cat -s file1
```

# mv; reverse change
```bash
mv file1 dir1
mv dir1/file1 .
mv t* file dir3 dir2
# can copy to files also, overwrites in this case
mv file1 file2
```
# cp; renaming in new place

```bash
cp file1 dir1/
cp file1 dir1/file2
#By default, if the destination file exists, it is overwritten. The -n option tells cp not to overwrite an existing file.
##confirm before overwriting
cp -i file1 file2
## recursive copy, ensure you have files in dir1 and also in dir2
cp -R dir1 dir2
```

# rm; check out these options as well

```bash
rm file1
rm *.jpg
rm -d (same as rmdir; needs to be empty)
rm -r dir1
rm -i file*
```
# misc

```bash
man
clear
history
!415 (assumes there is a command at 415, which is executed)
!! (last command is executes)
history 5
du
du -sh

head file1
head -n 2 file1; head -2 file1
head -n 2 file1 file2
which ls

#tr is complicated, simple examples
echo 'abcdefg' | tr 'abc' 'xyz'
echo 'abcdefg' | tr -d 'abc'
echo 'abcdefg' | tr 'abc' 'xyz'
```