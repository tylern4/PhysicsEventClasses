# Skim

## Build with Make

```shell
make
```

## Build with cmake

```shell
mkdir build && cd build
cmake ..
make
```

## Running skim

```shell
./Skim /path/to/files/to/unskimmed.root
```
Or using environment to set conditions
```shell
GAPRT=2 ./Skim /path/to/files/to/unskimmed.root
```

### Size reduction

| Original       	| Skimmed       	| Percent 	|
|----------------	|---------------	|---------	|
| 195MB          	| 26MB          	| ~13%    	|
| 605,338 Events 	| 37,225 Events 	| ~6.2%   	|
