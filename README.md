# Latex-Note-Generator

This programs generate a folder with a main .tex file with some basic structure, a folder to store images and a folder to store other .tex sub files.

## Use

This program runs on the command line using [cxxopts](https://github.com/jarro2783/cxxopts). To avoid errors is recommended to use "" to specify the option value.

The options are:

- Autor: puts the name of the author on the TeX file, it is mandatory.

```shell
-a "Author" --author "Author"
```

- Path: path to generate the folder, if not specified will default to the folder were the program is located

```shell
-p "PATH" --path "PATH"
```

\*Subject: name of the subject of the work, it is mandatory.

```shell
-s "SUBJECT" --subject "SUBJECT"
```

\*Acronym: Acronym of the subject, gives name to the main file and the folder. If not specified will take the firs letter of every word in subject.

```shell
-c "ACRONYM" --acronym "ACRONYM"
```

## TODO

- Add the possibility to add other packages from the command line
