The seed round display looks great but is not easy to setup.



The Seeed library overview is at 

https://wiki.seeedstudio.com/seeedstudio_round_display_usage/#round-display-library-overview


Install these githubs by downloading the github as a zip and using library install zip

https://github.com/Seeed-Studio/Seeed_Arduino_RoundDisplay

and also the 

https://github.com/Seeed-Projects/SeeedStudio_TFT_eSPI


and in the library remove the original TFT_eSPI library if you had it.


also you need the include file called driver.h with this line

```
#define BOARD_SCREEN_COMBO 501 // Round Display for Seeed Studio XIAO （GC9A01)

```

then most of the examples from the libraries SeeedStudio_TFT_eSPI ```round display``` should work.

The code I have in this folder does work for me.







