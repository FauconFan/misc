# atpt

## usage

```
usage: atpt [FILE] [CMD]
```

atpt is a simple command that takes a file and a command and runs the command at each time the file is modified.

The file could be a folder too.

The command CMD can contain an '#' that is a marker. It will be replaced by FILE.

## install

```
cd ~
git clone https://github.com/FauconFan/atpt.git
cd atpt
make
sudo make install
```

## Examples

```
atpt script.py "python3 #"
atpt script.sh "sh #"
atpt test.c "gcc # && ./a.out"
atpt test.cpp "clang++ # && ./a.out"
atpt Test.java "javac # && java \$(echo # | sed 's/.java//')"
```
