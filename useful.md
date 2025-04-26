## Some useful functions:
### Counting word frequency in python
```python
def word_frequency(text: str, delimiter: str = " ") -> dict:
    """
    Returns a dictionary with word frequencies from the input text,
    split using the specified delimiter.
    If delimiter is an empty string, splits into individual characters.
    """
    freq = {}
    if delimiter == "": units = list(text)
    else: units = text.split(delimiter)
    for unit in units:
        bef = unit
        word = unit.strip().lower()
        if word:
            if word in freq: freq[word] += 1
            else: freq[word] = 1
    return freq
```
# AWK
## 🧼 `gsub(regex, replacement, target)`
**Global substitution** — replaces *all* matches of `regex` in `target` with `replacement`.

### ✅ Common Usages

| Task                          | Example                                                  | Notes                              |
|------------------------------|----------------------------------------------------------|------------------------------------|
| Replace all `;` with `,`     | `gsub(/;/, ",", $0)`                                     | Modifies the entire line           |
| Trim spaces in `$4`          | `gsub(/^[ \t\r]+|[ \t\r]+$/, "", $4)`                    | Cleans leading/trailing whitespace |
| Swap words using groups      | `gsub(/(foo)(bar)/, "\\2\\1", $0)`                       | Needs `gawk`, uses `\\1`, `\\2`    |
| Replace only in a variable   | `tmp = $2; gsub(/x/, "y", tmp)`                          | Leaves original `$2` unchanged     |
| Clean all fields dynamically | `for (i = 1; i <= NF; i++) gsub(/^\s+|\s+$/, "", $i)`    | Loop over all fields               |

> 📌 Only `gawk` supports backreferences like `\\1` in `gsub()`.

---

## 🔍 `match(string, regex [, array])`
Finds the **position** of `regex` match in `string`. If an optional array is given, stores **capturing groups**.

### ✅ Common Usages

| Task                                 | Example                                                     | Notes                                   |
|-------------------------------------|-------------------------------------------------------------|-----------------------------------------|
| Find "abc" in string                | `if (match($0, /abc/)) print "found"`                       | Returns starting position (1-based)     |
| Capture groups into array           | `match($0, /user ([0-9]+)/, arr)`                           | `arr[1]` has the captured number         |
| Extract and print matched value     | `print substr($0, RSTART, RLENGTH)`                         | Uses `RSTART` and `RLENGTH`             |
| Combine match + replace             | `if (match($1, /(abc)(def)/, arr)) print arr[2] arr[1]`     | Prints "defabc" from match              |

---

### 🔧 Built-in variables used with `match()`

- `RSTART` → starting index of the match (1-based)
- `RLENGTH` → length of the match

---

### 🧪 Example combining `match` and `gsub`

```awk
{
    # Clean trailing spaces in field 3
    gsub(/^[ \t\r]+|[ \t\r]+$/, "", $4)
    # If loginShell matches /bin/(.*), extract the shell name
    if (match($4, /\/bin\/(.*)/, m)) {
        print "Shell:", m[1]
    }
}
```
Certainly! Here’s an expanded version of the **`tr` command** table, including additional examples like removing carriage returns, handling different types of whitespace, and more:

| **Operation**                             | **Example Command**                                              | **Explanation**                                                |
|------------------------------------------|------------------------------------------------------------------|----------------------------------------------------------------|
| **Translate lowercase to uppercase**     | `echo "hello world"` | `tr 'a-z' 'A-Z'`                            | Converts all lowercase letters to uppercase.                   |
| **Translate uppercase to lowercase**     | `echo "HELLO WORLD"` | `tr 'A-Z' 'a-z'`                            | Converts all uppercase letters to lowercase.                   |
| **Delete characters**                    | `echo "hello123world"` | `tr -d '0-9'`                              | Removes all digits from the input string.                      |
| **Squeeze repeating characters**         | `echo "hello     world"` | `tr -s ' '`                               | Converts multiple spaces into a single space.                  |
| **Substitute characters in range**       | `echo "abc123xyz"` | `tr '0-9' '#'`                                | Replaces all digits with `#`.                                  |
| **Complement (exclude) characters**      | `echo "abc123xyz"` | `tr -cd '0-9'`                               | Deletes all characters except digits.                          |
| **Multiple character substitutions**     | `echo "abc"` | `tr 'a-b' 'x-y'`                                     | Converts `a` to `x` and `b` to `y`.                            |
| **Remove specific characters**           | `echo "hello world"` | `tr -d 'aeiou'`                              | Removes vowels from the string.                                |
| **Replace spaces with underscores**      | `echo "hello world"` | `tr ' ' '_'`                                  | Replaces spaces with underscores.                              |
| **Remove carriage returns (`\r`)**       | `echo "hello\rworld"` | `tr -d '\r'`                                | Removes carriage returns (commonly used in Windows files).     |
| **Remove newlines (`\n`)**                | `echo "hello\nworld"` | `tr -d '\n'`                                | Removes newlines from input.                                   |
| **Convert tabs to spaces**               | `echo -e "hello\tworld"` | `tr '\t' ' '`                             | Converts tabs (`\t`) to spaces.                                |
| **Remove leading and trailing whitespace**| `echo "    hello world    "` | `tr -s ' '`                           | Removes extra spaces at the beginning and end of the string.   |
| **Remove non-printable characters**      | `echo -e "hello\x01world"` | `tr -cd '\11\12\40-\176'`                | Removes non-printable characters (keeps printable ASCII).      |
| **Convert multiple spaces to a single space** | `echo "hello     world"` | `tr -s ' '`                               | Converts multiple consecutive spaces into a single one.        |
| **Remove all control characters**        | `echo -e "hello\x01world\x02"` | `tr -cd '\11\12\40-\176'`             | Removes control characters like `\x01`, `\x02`.                |
| **Swap pairs of characters**             | `echo "abc"` | `tr 'a-b' 'x-y'`                                     | Swap characters `a` to `x` and `b` to `y`.                    |
| **Convert uppercase to lowercase and vice versa** | `echo "HELLO world"` | `tr 'a-zA-Z' 'A-Za-z'`                   | Converts uppercase letters to lowercase and vice versa.       |

---

### 🔧 **Options**:

| **Option**  | **Description**                                              |
|-------------|--------------------------------------------------------------|
| `-d`        | **Delete** characters in `SET1`                              |
| `-s`        | **Squeeze** repeating characters into one                    |
| `-c`        | **Complement** the set, i.e., operate on characters not in `SET1` |
| `-t`        | **Truncate** the string to `SET1` (not commonly used)        |

---

### 🧠 **Explanation of Common Operations**:

- **Deleting Characters**:  
  You can remove characters by specifying them in `SET1` and using the `-d` option. This is useful for eliminating unwanted characters like spaces, digits, or special characters.
  
- **Squeezing Characters**:  
  The `-s` option reduces sequences of repeated characters (like multiple spaces) to a single occurrence. This is helpful for normalizing text formatting.

- **Complementing Characters**:  
  With the `-c` option, `tr` operates on all characters except those in `SET1`. For example, `tr -cd '0-9'` removes everything except digits.

- **Handling Control Characters**:  
  You can remove or filter out non-printable control characters using `tr -cd '\11\12\40-\176'` to preserve printable characters only.

---
