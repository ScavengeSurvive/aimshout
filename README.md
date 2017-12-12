# aimshout

Aim-Shout provides players with a way to communicate easily in the midst of battle without taking their hand off the mouse.

Players can prepare a message and broadcast it nearby using the key-combination aim and look-behind which, by default, is left-mouse-button and middle-mouse-button - right next to each other!

## Usage

Simply add to your `pawn.json` and include:

```json
{
    "dependencies": ["ScavengeSurvive/aimshout"]
}
```

```pawn
#include <aimshout>
```

## Testing

To test, simply run the package:

```bash
sampctl package run
```

Then connect to `localhost:7777`.
