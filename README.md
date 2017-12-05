# accel

Example C extension to do vector subtraction

## Requirements

- python 3.6

## Quickstart

```
git clone git@github.com:massover/accel.git
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
python setup.py build_ext --inplace
pytest
```

## Usage

```
import accel
accel.vector_sub([5, 4, 3, 2, 1], [1, 1, 1, 1, 1])
# [4, 3, 2, 1, 0]
```

## Compile

```
python setup.py build_ext --inplace
```