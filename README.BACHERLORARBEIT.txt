Requirements
------------

See also: https://devguide.python.org/getting-started/setup-building/#wasi

  - WASI cross-compiler setup
  - Weval

Easiest way is to install the wasi devcontainer and manually install
the github release of weval.


Testing
-------

Do a clean build first:

  $ python3 Tools/wasm/wasi build --quiet

Simple test:

  $ ./test.sh

Get benchmark data:

  $ ./test.sh benchmark


Interesting files
-----------------

  - /Programs/python.c  - Main function
  - /Modules/main.c     - Most of the implementation
  - /test.sh            - Test script
  - /main*.py           - Test cases


Full checkout
-------------

available at: https://github.com/versteht-nur-bahnhof/cpython

(this takes a while to clone)
