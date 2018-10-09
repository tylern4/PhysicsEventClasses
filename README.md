# Skim

## Build with Make

'''
make
'''

## Build with cmake

'''
mkdir build && cd build
cmake ..
make
'''

## Running skim

'''
./Skim /path/to/files/to/unskimmed.root
'''
Or using environment to set conditions
'''
GAPRT=2 ./Skim /path/to/files/to/unskimmed.root
'''

### Size reduction

| Original       	| Skimmed       	| Percent 	|
|----------------	|---------------	|---------	|
| 195MB          	| 26MB          	| ~13%    	|
| 605,338 Events 	| 37,225 Events 	| ~6.2%   	|
