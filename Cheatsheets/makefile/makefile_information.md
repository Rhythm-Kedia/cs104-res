## Useful information

Generic syntax:
```Makefile
target: dependencies
    actions
```

- The rule is triggered if the target file doesn't exist in the current directory or if one or more dependencies have been updated more recently than the target file. If you only modify the target file and not its dependencies, the rule isn't triggered as long as the target file still exists.
- If one dependence file is missing, the Makefile tries to find a rule whose target is this missing file. If it is found, that rule is triggered fisrt, and after the initial rule is triggered too.
- A rule without dependencies is only triggered if the target file doesn't exist anymore.
- If you pass no rule as an argument to the `make` command on terminal, it will trigger the very first rule. It is a convention to call the first rule `all:`.
- You may want to define targets that do not correspond to actual files. Instead, it perform actions such as cleaning up a build directory or running tests. These are called "phony" targets.
- You must use a tab to make the indentation, or it will prompt an error otherwise
- `*` searches your filesystem for matching filenames. [I suggest][example1] that you always wrap it in the `wildcard` function:
```Makefile
thing_wrong := *.o  # Don't do this! '*' will not get expanded
one: $(thing_wrong) # Fails, because $(thing_wrong) is the string "*.o"
two: *.o            # Don't do this! Stays as *.o if there are no files that match this pattern :(
```
```Makefile
thing_right := $(wildcard *.o) # that is right! You must always use $(wildcard )
three: $(thing_right)          # Works as you would expect!
four: $(wildcard *.o)          # Same as rule three
```
- When there are multiple targets in a rule, the commands will be run for each target. E.g.,
```Makefile
f1.o f2.o:
	echo $@
# Equivalent to:
# f1.o:
#	 echo f1.o
# f2.o:
#	 echo f2.o
```
- You can pass variables to `Makefile`, from the command line, e.g., `make FIRS_VAR=Myke SECOND_VAR=Joanne`.
- In Makefile, each line is considered a separate command, and they are executed in their own subshell. If you want to run multiple commands in the same subshell, you need to concatenate them using `;` or `&&`. You can use `\` to scape the break line and make things more organized:
```Makefile
target1:
	cd /path/to/A/path/to/B/ ; \ # first the cd command is run
	  lualatex main.tex          # then the lualatex is run
```
or
```Makefile
target2:
	command1 && \
	  command2    # command1 and command2 are run simultaneously
```
- [Makefile][Makefile whitespaces] is ridiculously stupid to work with varible's filenames that contains whitespace in it. It is useless to single or double quote the filename as Make ignores them in every situation. Moreover, all make functions use whitespace as delimiters, and disregard quote characters. So, as general rule, **you must not use filenames with whitespaces and you must not quote Make variables**, you can even get some weird workaround to handle whitespaces, but the solution is as stupid as Makefile itself:
```Makefile
NULL :=
S := $(NULL) $(NULL) # whitespace

path := /some/path here # this is meant to be "/some/path here"
xpath := $(subst $S,^,$(path)) # match whitespace, replace by ^, from $(path)

var := $(xpath) another_file.txt # now you can have "/some/path here" and another_file.txt
all:
        @echo $(words $(path)) # 2
	@echo $(words $(var)) # 2
	@echo $(var) # /some/path^here labas
	@echo $(subst ^,$S,$(var)) # /some/path here labas
```
- Some shell features such as prefix and suffix substitution (`${parameter/#foo/bar}` and `${parameter/%foo/bar}`) [are not supported] by `/bin/sh` (only in Makefile?), which is the default shell interpreter in Makefile. To use those features, you need to change the shell interpreter, i.e., `SHELL:=/bin/bash`.


## Static pattern rules

```Makefile
objects = foo.o bar.o all.o
all: $(objects)

# These files compile via implicit rules
# Syntax:
# targets ...: target-pattern: prereq-patterns ...
# Example:
foo.o: %.o: %.c
# foo.o sets the **stem** to "foo".
# It then replaces the '%' in prereq-patterns with that stem, yielding "foo.c"
# you can do all for all target files at once:
# foo.o bar.o all.o: %.o: %.c
# or simply
$(objects): %.o: %.c
# Either of these two forms are equivalent to these three commands:
# foo.o: foo.c
# bar.o: bar.c
# all.o: all.c

all.c:
	echo "int main() { return 0; }" > all.c

%.c:
	touch $@

clean:
	rm -f *.c *.o all
```
- The filter function can be used in static pattern rules to match the correct files.
```Makefile
obj_files = foo.result bar.o lose.o
src_files = foo.raw bar.c lose.c

all: $(obj_files)
# Note: PHONY is important here. Without it, implicit rules will try to build the executable "all", since the prereqs are ".o" files.
.PHONY: all 

# Ex 1: filter %.o files from $(obj_files), the dependency is %.c
$(filter %.o,$(obj_files)): %.o: %.c
	echo "Ex1. target: $@ prereq: $<"

# Ex 2: filter %.result files from $(obj_files), the dependency is %.raw
$(filter %.result,$(obj_files)): %.result: %.raw
	echo "Ex2. target: $@ prereq: $<" 

%.c %.raw:
	touch $@

clean:
	rm -f $(src_files
```
```Makefile
# % expands to the same stem
%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
```

## Main `.PHONY` targets:
- `all:` target
    - It is actually just a dummy rule
    - The `all` target has no command
    - It is actually just a dummy target whose dependencies are the targets from rules at the tip of the [dependency tree (DT)][DT_wb]. For instance, if a project has two files at the tip of the DT, `all` must have these two files. Otherwise, the Makefile will not be able to verify all the files at the end of the DT.
- `clean:` target
    - It is actually just a dummy rule
    - it does not have dependencies
    - It aims to remove intermediates file that was created through the process
    - It is never called unless you explicitly type `make clean`

[DT_wb]: https://youtu.be/GExnnTaBELk?t=2147
[@_wb]: https://opensource.com/article/18/8/what-how-makefile#:~:text=To%20suppress%20echoing%20the%20actual%20command%2C%20we%20need%20to%20start%20echo%20with%20%40
[Makefile example]: https://spin.atomicobject.com/2016/08/26/makefile-c-projects/
[example1]: https://makefiletutorial.com/
[Makefile whitespaces]: https://stackoverflow.com/a/56411000/13998346
[are not supported]: https://stackoverflow.com/questions/50649104/bin-sh-1-bad-substitution-makefile