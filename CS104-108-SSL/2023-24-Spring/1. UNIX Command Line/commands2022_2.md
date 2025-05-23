# Lab 01 A2 Commands 
## ps: Show running processes
- only shell processes
    
    ```ps```
- all

    ```ps aux```

- The ps command also allows you to sort the output. For example, to sort the output based on the memory usage , you would use:
    
    ```bash
    ps aux --sort=-%mem
    
    #fg/bg  
    sleep 100  
    sleep 100 &  
    sleep 100  
    ctrl Z to suspend  
    jobs; jobs -l  
    bg; bg %id  
    jobs
    sleep 100  
    sleep 200  
    fg; fg %2  
    kill -9 pid  
    ```

# chmod
```bash
chmod g=r filename  
chmod a-x filename  
chmod -R o-w dirname  
```

# regex
### ensure you are in the right folder which has these files

```bash
grep "for" bigfile
grep -i "for" bigfile
grep -i "^for" bigfile
grep -i "for a" bigfile
grep -i "cried.$" bigfile
grep -i "h.s" bigfile
grep -i "t..t" bigfile
grep "cried|could" bigfile (not correct)
grep "cried\|could" bigfile (not correct)
grep -E "cried|could" bigfile

#quantifiers
grep -E "to*" bigfile
grep -E "to?" bigfile
grep -E "to+" bigfile
grep -E "to{1}" bigfile
grep -E "to{1,}" bigfile


#grouping
grep -E "(fear)?less" bigfile
grep -i "h[ia]s" bigfile
grep 'h[^i]s' bigfile (anyletter except i)
grep "[A-Z]" bigfile

#not just file search, can be used with other commands
ls -l | grep file

#grep, -v negation, -r recursive search, -w whole word, -n show line number, -c count, -B  5 5 lines before context, -A 5, 5 lines after context
grep -v "Wolf" bigfile
grep  "Wolf" bigfile
grep  -r "Wolf" *
grep -w "his" bigfile; grep  "his" bigfile
grep -A 2 "5" list
```

# find
### ensure you are in the right folder which has these files

```bash
find dir1/ -name "*.png"
find dir1/ -name file*
find . -type f -iname "a*"
find . -type d
find . -type f -size +1k
find . -type f -size +1k -size -10k
find dir2/ -mtime -10
find dir2/ -perm 644
```

# wc, -l, -w, -c etc

```bash
wc /proc/cpuinfo /proc/meminfo

```


# tr

```bash
echo 'abcdefgh' | tr 'abcd' 'pqrs'
echo 'abcdefgh' | tr 'a-d' 'p-s'
echo 'abcdefgh' | tr -d 'cde'
echo 'abcdddddddefgh' | tr -s 'd'
echo 'abcdddddddefgh' | tr -s 'd' '_' (replace d with _)
echo 'Happy' | tr 'a-z' 'A-Z'
echo "my phone is 123-456-7890" | tr -cd '0-9'
```

# cut
### ensure you are in the right folder which has these files

```bash
cut CS-104_2022-2_Students.csv -d ',' -f 1,3
cut CS-104_2022-2_Students.csv -d ',' -f -4
cut CS-104_2022-2_Students.csv -d ',' -f 1,3 --output-delimiter=" "
cut CS-104_2022-2_Students.csv -d ',' -f 1,2,3 --complement
echo "abcdefg" | cut -b 1,3,5
echo "abcdefg" | cut -b 1-4
```

# paste
### ensure you are in the right folder which has these files

```bash
paste fruits1 fruits2
paste -d '_' fruits1 fruits2
paste -d '_%' fruits1 fruits2 fruits1
paste -s fruits1 fruits2
```

# sort
### ensure you are in the right folder which has these files

```bash
sort fruits1
sort -r fruits1
sort -n list1
sort -nr list1
sort -t ',' -k8 CS-104_2022-2_Students.csv
```
# zip

```bash
zip -r archivename.zip dir1 dir2 file1 file1
zip -e  archivename.zip dir1
zip -s 1g -r archivename.zip dir1
unzip archivename.zip
unzip archivename.zip -d /path/to/directory
unzip -l archivename.zip
```

# apt
### rolldice is a command line app, that just prints dice roll no

```bash
sudo apt show games-cheese
sudo apt install rolldice
sudo apt remove rolldice
```

# command-sub

```bash
touch file-`date +%s`.tx
touch file-$(date +%s).tx

#redirection and pipe
bash commands.sh 1> out
bash commands.sh 2> out
cat out
bash commands.sh 2> /dev/null
bash commands.sh > out 2>&1
wc -l < out  
wc -l < out > lines
cat fruits1 >> fruits3
sort fruits3 | uniq -i
```