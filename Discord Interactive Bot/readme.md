This was my try at creating a fun interactive discord bot. This bot can respond to basic grettings such as "Hi", "Hello", etc. This set be increased by linking a live api to this bot, though i left it out as most api's are paid. 
=======================================================

Here I'd like to bring your attention to a few things: 
=======================================================
1. The keep_alive function was used to ping the bot constantly to keep it running as the other method would require for me to host it which is paid for most part. 

2. The "Token variable used in the last function represents your own bot token which is provided by discord. Keep in mind to keep this token a secrect and not include it with .env files.

3. I will include the keep_alive() incase you require it, however if you choose to host it then comment out the keep_alive() function call at line:139 and from keepalive import keep_alive on line:3

4. This bot uses an API for "Dadjokes" which I thought would be a playful feature. You can invoke it by typing put >Dadjoke. And many other reaction features which require specific "Message_id". These id's can be found through hovering over the message and clicking on "id".
=======================================================

THANK YOU :)