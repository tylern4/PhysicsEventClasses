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

### Using gnu Parallel
```shell
parallel ./skim {} ::: /path/to/*.root
```

## Size reduction

| Original       	| Skimmed       	| Percent 	|
|----------------	|---------------	|---------	|
| 195MB          	| 26MB          	| ~87%    	|
| 605,338 Events 	| 37,225 Events 	| ~93.8%   	|
| 197MB          	| 58MB          	| ~70%      |
| 493,324 Events 	| 78,897 Events 	| ~84%      |
