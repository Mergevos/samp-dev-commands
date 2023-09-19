# open-test-mode

[![mergevos](https://img.shields.io/badge/mergevos-samp--dev--commands-2f2f2f.svg?style=for-the-badge)](https://github.com/Mergevos/samp-dev-commands)

<!--
Short description of your library, why it's useful, some examples, pictures or
videos. Link to your forum release thread too.

Remember: You can use "forumfmt" to convert this readme to forum BBCode!

What the sections below should be used for:

`## Installation`: Leave this section un-edited unless you have some specific
additional installation procedure.

`## Testing`: Whether your library is tested with a simple `main()` and `print`,
unit-tested, or demonstrated via prompting the player to connect, you should
include some basic information for users to try out your code in some way.

And finally, maintaining your version number`:

* Follow [Semantic Versioning](https://semver.org/)
* When you release a new version, update `VERSION` and `git tag` it
* Versioning is important for sampctl to use the version control features

Happy Pawning!
-->

## Installation

Simply install to your project:

```bash
sampctl package install Mergevos/samp-dev-commands
```

Include in your code and begin using the library:

```pawn
#include <dev-commands>
```

## Usage

<!--
Write your code documentation or examples here. If your library is documented in
the source code, direct users there. If not, list your API and describe it well
in this section. If your library is passive and has no API, simply omit this
section.
-->

Simply include it in your gamemode and that's it. You have all needed commands.

```pawn
CMD:xgoto(playerid, params[]) // goes to precise coords
CMD:vehicle(playerid, params[]) // spawns a vehicle
CMD:weapon(playerid, params[]) // gives a weapon to player or to a target
CMD:health(playerid, params[]) // sets health to a player or to a target
CMD:fixveh(playerid, params[]) // fix player vehicle
CMD:port(playerid, params[]) // ports a player to a target or target to the player
```

If you find anymore commands or have any more ideas, open pull request.

## Testing

<!--
Depending on whether your package is tested via in-game "demo tests" or
y_testing unit-tests, you should indicate to readers what to expect below here.
-->

To test, simply run the package:

```bash
sampctl package run
```
