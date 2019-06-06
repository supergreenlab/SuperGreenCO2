![SuperGreenLab](assets/sgl.png?raw=true "SuperGreenLab")

[![SuperGreenLab](assets/reddit-button.png?raw=true "SuperGreenLab")](https://www.reddit.com/r/SuperGreenLab)

# SuperGreenCO2 - DIY CO2 dispenser for growbox

This is a first test at building a DIY co2 dispenser based on [this kind of co2 kits](https://l.messenger.com/l.php?u=https%3A%2F%2Fwww.lamota.org%2Fen%2Fdisposable-co2-cilynder-kit%2F&h=AT2BRQmcIwBo06t2YK3KDxMq-x_IlHN7knh6b51aBKhjmJn5nTFIqT7sfM_TFskey0B-74DN4D2OyjYyFYhDZzREsxe0vggfoa9S42tNavWjBIypG5Zv8yi1jv0).
and [this co2 sensor](https://www.dfrobot.com/product-1565.html?search=co2)

I intentionnaly skip the actual building part, because this is an early test I made for this video:

[![Youtube play](assets/youtube-play.png?raw=true "Youtube play")](https://youtu.be/MLtzA9BGmUM)

# How to use

Once connected to the co2 controller wifi network called ![SSID](assets/wifi-ssid.png?raw=true "SSID"), you can access the control interface by going to this url:

```

http://192.168.1.3/fs/app.html

```

Once there, click the `settings` button, which will allow you to access all of the firmware's parameters.

Below is the list of the parameters you're interested in:

## Time scheduling

CO2 addition is useless when there is no light, there are 4 parameters to tell the controller when the lights are on.

### "Sunrise" hours:

`on_hour`: hour at which to start spreading co2, from 0 to 23, UTC, see note below
`on_min`: minutes

```

### "Sunset" hours:

`off_hour`: hour at which to stop spreading co2, from 0 to 23, UTC, see note below
`off_min`: minutes

```


#### UTC note

All those parameters are in UTC (24hr) format, which means you'll need to remove/add hours based on where you are on earth.
You can use this website to do the conversion: [thetimezoneconverter.com](https://www.thetimezoneconverter.com/), just select `UTC` on the right side, and your location on the left side.
Don't forget to select the small `24` below.

