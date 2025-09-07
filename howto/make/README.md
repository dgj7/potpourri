# makefiles
Make is a utility for running commands, usually for compiling software projects.

## Rules
`rules` consist of targets, prerequisites and commands.

```Make
targets: prerequisites
    command
    command
    command
```

_targets_ are filenames, to be created by the rule
_prerequisites_ are filenames, that must exist for a rule to be run
_commands_ start with a tab character, and are run if the rule's requirements are met.

## Usage
`make` looks for a file called `Makefile` by default; you can specify a different file with the `-f` or `--file` flags:

```Bash
make --file my-makefile
```

## Other Details
### default goal
Create a default goal using the default goal built-in variable.

```Make
.DEFAULT_GOAL := all
```


---
