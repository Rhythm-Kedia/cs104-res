### -1. `addprefix`
Adds a prefix to each word in a list.

**Syntax:**
```make
$(addprefix prefix, list)
```
**Example:**
```make
FILES = file1.c file2.c file3.c
PREFIXED = $(addprefix src/, $(FILES))

# Result: PREFIXED = src/file1.c src/file2.c src/file3.c
```

### 0. `notdir`
Removes directory components, keeping only the filenames.

**Syntax:**
```make
$(notdir names)
```
**Example:**
```make
FILES = src/main.c src/utils.c include/header.h
NAMES = $(notdir $(FILES))

# Result: NAMES = main.c utils.c header.h
```
Here are some more useful **Makefile functions** for string and filename manipulation:

---

### 1. **`addsuffix`**
Adds a suffix to each word in a list.

**Syntax:**
```make
$(addsuffix suffix, list)
```
**Example:**
```make
FILES = main utils config
EXTENDED = $(addsuffix .c, $(FILES))

# Result: EXTENDED = main.c utils.c config.c
```

---

### 2. **`basename`**
Removes the file extension from filenames.

**Syntax:**
```make
$(basename names)
```
**Example:**
```make
FILES = main.c utils.cpp header.h
BASE = $(basename $(FILES))

# Result: BASE = main utils header
```

---

### 3. **`dir`**
Extracts the directory part of a path.

**Syntax:**
```make
$(dir names)
```
**Example:**
```make
FILES = src/main.c include/header.h
DIRS = $(dir $(FILES))

# Result: DIRS = src/ include/
```

---

### 4. **`filter`**
Filters words in a list that match a pattern.

**Syntax:**
```make
$(filter pattern..., list)
```
**Example:**
```make
FILES = main.c utils.c script.py Makefile
CFILES = $(filter %.c, $(FILES))

# Result: CFILES = main.c utils.c
```

---

### 5. **`filter-out`**
Removes words that match a pattern.

**Syntax:**
```make
$(filter-out pattern..., list)
```
**Example:**
```make
FILES = main.c utils.c script.py Makefile
NONCFILES = $(filter-out %.c, $(FILES))

# Result: NONCFILES = script.py Makefile
```

---

### 6. **`findstring`**
Checks if a substring exists in a string.

**Syntax:**
```make
$(findstring find, in)
```
**Example:**
```make
TEXT = "hello world"
CHECK = $(findstring world, $(TEXT))

# Result: CHECK = world (non-empty means found)
```

---

### 7. **`foreach`**
Loops over a list and applies an operation.

**Syntax:**
```make
$(foreach var, list, expression)
```
**Example:**
```make
FILES = main.c utils.c
OBJECTS = $(foreach file, $(FILES), $(file:.c=.o))

# Result: OBJECTS = main.o utils.o
```

---

### 8. **`join`**
Joins two lists, pairing elements positionally.

**Syntax:**
```make
$(join list1, list2)
```
**Example:**
```make
LIST1 = a b c
LIST2 = 1 2 3
JOINED = $(join $(LIST1),$(LIST2))

# Result: JOINED = a1 b2 c3
```

---

### 9. **`patsubst`**
Pattern substitution in a list.

**Syntax:**
```make
$(patsubst pattern,replacement,text)
```
**Example:**
```make
FILES = main.c utils.c
OBJS = $(patsubst %.c,%.o,$(FILES))

# Result: OBJS = main.o utils.o
```

---

### 10. **`wildcard`**
Finds files matching a pattern.

**Syntax:**
```make
$(wildcard pattern)
```
**Example:**
```make
CFILES = $(wildcard *.c)

# Result: CFILES = (list of all .c files in the directory)
```

---
