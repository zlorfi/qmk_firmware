# michi's Mac Layout

This layout was designed to work with a MacOs in mind. This layout implements the [German umlaut](https://en.wikipedia.org/wiki/Umlaut_(linguistics)) and switched positions for `Z` ad `Y`.

There are two different ways of using the German umlaut and can be switched by setting `UNICODE_ENABLE` to either `yes` or `no`. 
Setting this constant to `no` will send a combination of strings to generate the coresponding umlaut.
Switching this value to `yes` will send HEX-based unicodes to the system. Please note, that this solution will only work for MacOS and only by adding `System Preferences > Keyboard > Input Sources` and selecting `Unicode Hex Input`.