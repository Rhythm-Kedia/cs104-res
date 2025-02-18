<table>
  <tr>
    <th>Syntax</th>
    <th>Description</th>
    <th>Example</th>
  </tr>
  <tr>
    <th colspan="3"><h2>Special characters</h2></th>
  </tr>
  <tr>
    <td><code>@</code></td>
    <td>Command prefix: suppress printing the command on the terminal.</td>
    <td><code>@rm -f *.out *.aux *.alg *.acr</code></td>
  </tr>
  <tr>
    <td><code>|</code></td>
    <td>dependency prefix: check whether the following dependencies exist, but do not trigger them. If they don't exist, however, it is triggered..</td>
    <td><code>compile: | default_preamble.tex</code></td>
  </tr>
  <tr>
    <td><code>-</code></td>
    <td>Command prefix: error will be printed but ignored, and make will continue to run</td>
    <td><code>-false</code></td>
  </tr>
  <tr>
    <td><code>%</code></td>
    <td>Serves as a variety of wildcard-like functionalities within Makefile, such as search-and-replace patterns, rule terget-dependency pattern, etc. To expand to system files (i.e., outside <code>Makefile</code>), use <code>*</code> with <code>wildcard</code> instead.</td>
    <td><code>dest/%.txt: src/%.txt</code></td>
  </tr>
  <tr>
    <th colspan="3"><h2>Usual variable names</h2></th>
  </tr>
  <tr>
    <td><code>CC</code></td>
    <td>Program for compiling C programs; default is <code>cc</code></td>
    <td></td>
  </tr>
  <tr>
    <td><code>CFLAGS</code></td>
    <td>Extra flags to give to the C compiler</td>
    <td></td>
  </tr>
  <tr>
    <td><code>CPPFLAGS</code></td>
    <td>Extra flags to give to the C preprocessor</td>
    <td></td>
  </tr>
  <tr>
    <td><code>CXX</code></td>
    <td>Program for compiling C++ programs; default is <code>g++</code></td>
    <td></td>
  </tr>
  <tr>
    <td><code>CXXFLAGS</code></td>
    <td>Extra flags to give to the C++ compiler</td>
    <td></td>
  </tr>
  <tr>
    <td><code>LDFLAGS</code></td>
    <td>Extra flags to give to compilers when they are supposed to invoke the linker</td>
    <td></td>
  </tr>
  <tr>
    <td><code>SRCS</code></td>
    <td>Source files (<code>.c</code>/<code>.cpp</code>).</td>
    <td></td>
  </tr>
  <tr>
    <td><code>OBJS</code></td>
    <td>Object files (<code>.o</code>).</td>
    <td></td>
  </tr>
  <tr>
    <td><code>EXEC</code></td>
    <td>Executable file name, that is, the final output.</td>
    <td></td>
  </tr>
  <tr>
    <td><code>SHELL</code></td>
    <td>Set the shell interpreter. Default is <code>/bin/sh</code></td>
    <td></td>
  </tr>
  <tr>
    <th colspan="3"><h2>Variable expansion</h2></th>
  </tr>
  <tr>
    <td><code>$(X)</code>, <code>${X}</code>, <code>$X</code></td>
    <td>Expand to the Makefile variable <code>VARIABLE</code>. If it is not found, return shell variable instead. <code>$(X)</code> is peferred, while <code>$X</code> is a bad practice as it only works single-character variables.</td>
    <td><code>echo $(SRCS)</code></td>
  </tr>
  <tr>
    <td><code>$(X:<ins>pattern</ins>=<ins>replace</ins>)</code></td>
    <td>Variable expansion with pattern substitution/replacement.</td>
    <td><code>OBJS = $(SRCS:.c=.o)</code></td>
  </tr>
  <tr>
    <td><code>$${FOO}</code></td>
    <td>Expand to the shell variable <code>FOO</code></td>
    <td><code>echo let me see it $${PWD}</code></td>
  </tr>
  <tr>
    <td><code>$@</code></td>
    <td>Expand to the target(s), that is, the left-hand side of the rule</td>
    <td></td>
  </tr>
  <tr>
    <td><code>$@</code></td>
    <td>Expand to all the targets, that is, the left-hand side of the rule.</td>
    <td></td>
  </tr>
  <tr>
    <td><code>$^</code></td>
    <td>Expand to the dependencies, that is, the right-hand side of the rule.</td>
    <td></td>
  </tr>
  <tr>
    <td><code>$<</code></td>
    <td>Expand to the first the dependency.</td>
    <td></td>
  </tr>
  <tr>
    <td><code>$?</code></td>
    <td>List of dependencies (prerequisites) that are newer than the target.</td>
    <td></td>
  </tr>
  <tr>
    <th colspan="3"><h2>Makefile functions</h2></th>
  </tr>
  <tr>
    <td><code>$(shell <ins>command</ins>)</code>, <code>$$(<ins>command</ins>)</code></td>
    <td>Shell command substitution. <code>$(shell <ins>command</ins>)</code> -> Parse time. <code>$$(<ins>command</ins>)</code> -> Runtime.</td>
    <td><code>echo $(shell ls) is that good?</code></td>
  </tr>
  <tr>
    <td><code>$(or <ins>element1</ins>, <ins>element2</ins>)</code></td>
    <td>Makefile or conditional. It is useful both for handling Makefile varables and <code>$(shell <ins>command</ins>)</code> commands.</td>
    <td><code>$(or $(shell { ls -1 lecture_*.tex | head -n 1; } 2> /dev/null), $(basename $(shell pwd)))</code>
    <br>
      <code>$(or $(MY_VARIABLE), default_value)</code>
    </td>
  </tr>
  <tr>
    <td><code>$(addprefix <ins>FOO</ins>,<ins>BAR</ins>)</code></td>
    <td>Prefix each word in a list with a specified prefix.</td>
    <td><code>$(addprefix $(BINDIR)/,$(BINARIES))</code></td>
  </tr>
  <tr>
    <td><code>$(addsuffix <ins>FOO</ins>,<ins>BAR</ins>)</code></td>
    <td>Suffix each word in a list with a specified prefix.</td>
    <td></td>
  </tr>
  <tr>
    <td><code>$(foreach <ins>DIR</ins>,<ins>$(DIRS)</ins>,<ins>someting</ins></code></td>
    <td>Iterate over <code><ins>$(DIRS)</ins></code> variable.</td>
    <td><code>CFILES=$(foreach DIR,$(SRCDIRS),$(wildcard $(DIR)/*.c))</code></td>
  </tr>
  <tr>
    <td><code>$(wildcard <ins>foo</ins>/*.<ins>bar</ins>)</code></td>
    <td>Uses the wildcard <code>*</code>. It searches your filesystem for matching filenames. You should always wrap it in the <code>wildcard</code> function.</td>
    <td><code>$(wildcard $(DIR)/*.c)</code></td>
  </tr>
  <tr>
    <td><code>$(patsubst <ins>match-it</ins>,<ins>replace-by-it</ins>,<ins>from-it</ins>)</code></td>
    <td>Pattern-based substitution.</td>
    <td><code>$(patsubst %.c,$(BUILDDIR)/%.o,$(notdir $(CFILES)))</code></td>
  </tr>
  <tr>
    <td><code>$(filter <ins>get-it</ins>,<ins>from-it</ins>)</code></td>
    <td>Filter function.</td>
    <td><code>$(filter %tip.o,$(OBJECTS))</code></td>
  </tr>
  <tr>
    <td><code>$(filter-out <ins>filter-it-out</ins>,<ins>from-it</ins>)</code></td>
    <td>Filter out function.</td>
    <td><code>$(filter-out %tip.o,$(OBJECTS))</code></td>
  </tr>
  <tr>
    <td><code>$(word <ins>extract-it</ins>,<ins>from-it</ins>)</code></td>
    <td>Extracts a specific word from a space-separated list of words.</td>
    <td></td>
  </tr>
  <tr>
    <td><code>$(wordlist <ins>start</ins>,<ins>,end</ins>,<ins>text</ins>)</code></td>
    <td>Extracts a range of words from a space-separated list of words.</td>
    <td></td>
  </tr>
  <tr>
    <td><code>$(words <ins>list</ins>)</code></td>
    <td>Counts the number of words in a list.</td>
    <td></td>
  </tr>
  <tr>
    <td><code>$(firstword <ins>list</ins>)</code></td>
    <td>Extracts the first word from a space-separated list of words.</td>
    <td></td>
  </tr>
  <tr>
    <td><code>$(lastword <ins>list</ins>)</code></td>
    <td>Extracts the last word from a space-separated list of words.</td>
    <td></td>
  </tr>
  <tr>
    <td><code>$(strip <ins>list</ins>)</code></td>
    <td>Removes leading and trailing whitespace characters from a string.</td>
    <td></td>
  </tr>
  <tr>
    <td><code>$(dir <ins>path</ins>)</code></td>
    <td>Extracts the directory portion from a path.</td>
    <td><code>$(dir src/foo.c hacks)</code> yields <code>src/ ./</code></td>
  </tr>
  <tr>
    <td><code>$(notdir <ins>path</ins>)</code></td>
    <td>Extracts the name portion from a path.</td>
    <td><code>$(notdir src/foo.c hacks lecture_3/figs/DLL_EL)</code> yields <code>foo.c hacks DLL_EL</code></td>
  </tr>
  <tr>
    <td><code>$(basename <ins>path</ins>)</code></td>
    <td>Extracts the file name without the extension from a path.</td>
    <td><code>$(basename src/foo.c src-1.0/bar hacks)</code> yields <code>src/foo src-1.0/bar hacks</code></td>
  </tr>
  <tr>
    <th colspan="3"><h2>Assignments</h2></th>
  </tr>
  <tr>
    <td><code>=</code></td>
    <td>Simple Variable Assignment (AKA lazy or deferred evaluation), that is, it is evaluated everytime the variable is encountered in the code.</td>
    <td><code>FOO = $(BAR)
BAR = hello
all:
  echo $(FOO) # prints "hello"</code>
</td>
  </tr>
  <tr>
    <td><code>:=</code></td>
    <td>Immediate Variable Assignment. Use it when you want the variable to be set to the value at the time of assignment, without being affected by any changes made later in the Makefile.</td>
    <td><code>FOO := $(BAR)
BAR = hello
all:
  echo $(FOO)# prints nothing</code>
</td>
  </tr>
  <tr>
    <td><code>?=</code></td>
    <td>Conditional assignment, that is, it assigns a value to a variable only if it does not have a value.</td>
    <td></td>
  </tr>
  <tr>
    <td><code>+=</code></td>
    <td>Appending.</td>
    <td></td>
  </tr>
</table>