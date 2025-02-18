### **Wildcard Pattern Matching - Summary**  
Wildcard pattern matching allows flexible string searches using special symbols. It is commonly used in **file searching, database queries, shell scripting, and text processing**.  

#### **Common Wildcards and Their Meanings:**  

| Wildcard | Meaning | Example | Matches | Does Not Match |
|----------|---------|---------|----------|----------------|
| `*` | Matches **zero or more** characters | `a*c` | `ac`, `abc`, `aXYZc` | `ab`, `cb` |
| `?` | Matches **exactly one** character | `a?c` | `abc`, `axc` | `ac`, `aXYZc` |
| `[ ]` | Matches **one character** from a given set | `file[123].txt` | `file1.txt`, `file2.txt` | `file4.txt` |
| `[! ]` | Matches **one character NOT in the set** | `file[!3].txt` | `file1.txt`, `file2.txt` | `file3.txt` |
| `{ }` | Matches **one of multiple strings** | `hello.{jpg,png}` | `hello.jpg`, `hello.png` | `hello.txt` |
| `\` | Escapes a special character | `file\*name.txt` | `file*name.txt` | `filename.txt` |
