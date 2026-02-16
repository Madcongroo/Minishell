## Minishell (miniHELL)

`minishell` is a small Unix shell written in C.
It reads a command line, tokenizes it (lexer), builds an AST (parser), and
executes it using processes, pipes and redirections—while also providing a set
of built-in commands.

This project is designed as a learning exercise: it focuses on how a shell works
internally (parsing, file descriptors, `fork/exec`, environment management,
signals), rather than on being a full-featured Bash replacement.

---

## Features

- Interactive prompt with command history (GNU Readline)
- Command execution via `PATH` lookup or absolute/relative paths
- Pipes: `cmd1 | cmd2`
- Redirections:
	- input: `< file`
	- output: `> file`
	- append: `>> file`
	- heredoc: `<< delimiter` (stored in `/tmp/heredoctmp`)
- Quotes handling (`'...'` and `"..."`) and basic variable expansion
	- `$VAR` and `$?` (last command exit status)
- Environment stored in a custom hashmap (used by `env`, `export`, expansions)
- Builtins:
	- `echo` (with `-n`)
	- `cd`
	- `pwd`
	- `env`
	- `export`
	- `unset`
	- `exit`

---

## Build & Run

### Requirements

- A C compiler (`cc`)
- GNU Readline development headers
	- Debian/Ubuntu: `sudo apt-get install libreadline-dev`
	- Arch: `sudo pacman -S readline`

### Compile

```bash
make
```

### Start the shell

```bash
./minishell
```

You should see the prompt:

```text
miniHELL> 
```

---

## Usage examples

```bash
miniHELL> echo Hello
miniHELL> pwd
miniHELL> ls -l | wc -l
miniHELL> echo test > out.txt
miniHELL> cat < out.txt
miniHELL> echo more >> out.txt
miniHELL> cat << EOF
> line 1
> line 2
> EOF
miniHELL> echo $HOME
miniHELL> echo $?
```

---

## How it works (high level)

The execution flow is intentionally split into clear stages:

1. **Read input**
	 - The main loop uses `readline()` to get a line and store it in history.

2. **Preprocess / validate**
	 - Trims spaces and rejects invalid syntax early (unclosed quotes, misplaced
		 operators, invalid redirections, unsupported symbols).
	 - Detects simple assignments like `KEY=value` and stores them in the
		 environment map.

3. **Lexing (tokenizing)**
	 - The lexer converts the string into tokens such as `WORD`, `PIPE`,
		 `REDIR_IN`, `REDIR_OUT`, `APPEND`, `HEREDOC`.
	 - It also performs variable expansion for `$VAR` and `$?`.

4. **Parsing (AST building)**
	 - Tokens are transformed into an AST with nodes like:
		 - `AST_CMD`  (a command with arguments)
		 - `AST_PIPE` (left and right subtrees)
		 - redirection list attached to command nodes

5. **Execution**
	 - **Pipes**: implemented with `pipe()`, `fork()`, `dup2()` and recursion.
	 - **Redirections**: each redirection opens a file and temporarily replaces
		 `STDIN`/`STDOUT` using `dup2()`, then restores them.
	 - **Builtins**: executed directly (no `execve`) when applicable.
	 - **External commands**: executed with `fork()` + `execve()`.
	 - Exit status is stored in the special variable `$?`.

6. **Signals**
	 - The shell handles `Ctrl-C` (SIGINT) and ignores `Ctrl-\` (SIGQUIT) in the
		 interactive prompt.
	 - Child processes use a dedicated signal setup.

---

## Project structure

- `src/lexer/` : preprocessing + lexer + variable expansion
- `src/parser/`: AST construction and syntax checks
- `src/exec/`  : command execution, pipes, redirections, heredoc
- `src/builtins/`: builtin implementations
- `src/env/` + `src/hashmap/`: environment representation and export sorting
- `src/signals/`: interactive and child signal handling
- `libft/`: custom utility library

---

## What you learn from this project

- How a shell turns raw text into actions (lexer → parser → executor)
- Process creation and program replacement (`fork`, `execve`, `waitpid`)
- Pipe and redirection mechanics (file descriptors, `dup2`, `open`, `close`)
- Signal handling in interactive programs vs child processes
- Environment and state management (including `$?` and `export` semantics)
- Defensive C programming (memory ownership, error paths, resource cleanup)

---

## Limitations (intentional)

This minishell implements a subset of Bash behavior.
In particular, it rejects or does not support:

- logical operators: `&&`, `||`
- separators and job control: `;`, `&`
- subshell/grouping: `(` `)`
- backslash escapes and backticks: `\\`, `` ` ``

If you want, tell me which features you want next (wildcards, `||/&&`,
parentheses, better heredoc behavior, etc.) and I can help you plan or
implement them.
