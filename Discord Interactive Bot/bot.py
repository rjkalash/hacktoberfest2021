import discord 
import os
from keepalive import keep_alive
import requests
import json
import random

client=discord.Client()


roasts=['I tried to see things your way, but I couldn\'t get my head that far up my ass!','Best part about being me is, I\'m NOT you!','I never forget a face, but in your case I\'ll be glad to make an exception.','When the virus is over, I still want some of you to stay away from me.','Everyone is entitled to be stupid, but you abuse the privilege.','Oh dear! Looks like you fell out of the ugly tree and hit every branch on the way down!','I like long walks especially when they\'re taken by people like you.','The Village called and said they were looking for you. They\'re missing their idiot.','I obviously don\'t want to talk to you right now, so leave a message and I\'ll be sure to ignore it.','I\'m obviously doing something more important than you.','I\'m not here right now, because I\'m waiting for you to go offline.','You are as useless as \"ueue\" in \"queue\".','You must have been born on a highway, because thats where most accidents happen.','I heard that you are a lady killer.They take one look at you and die of shock.','If I throw a stick, will you leave?','If you were a vegetable, you would be a cabbitch.','Your father should have wiped you on the sheets.','If you ran like your mouth, you would be in good shape.','If I was a bird, I know who I\'d shit on.','If your brain was dynamite, there wouldn’t be enough to blow your hat off.','You\’re a gray sprinkle on a rainbow cupcake.','You are more disappointing than an unsalted pretzel.',' Light travels faster than sound, which is why you seemed bright until you spoke.','You\'re so annoying he makes his Happy Meal cry.','You have so many gaps in your teeth it looks like your tongue is in jail.','Your secrets are always safe with me. I never even listen when you tell me them.','I’ll never forget the first time we met. But I’ll keep trying.','Hold still. I’m trying to imagine you with a personality.','Your face makes onions cry.','Don’t be ashamed of who you are. That’s your parents’ job.','Your face is just fine, but we’ll have to put a bag over that personality.','You bring everyone so much joy… when you leave the room.','I thought of you today. It reminded me to take out the trash.']

greet=['hi','hello','wassup','yo']
funny=['lol','lmao','haha','hahaha','lmfao','oaml']
bruh=['bruh','wtf','yo wtf']
pog=['pog','pogchamp','poggo','poggers']


if "responding" in db.keys():
  db["responding"]=True

def get_joke():
  url = "https://dad-jokes.p.rapidapi.com/random/joke"
  headers = {
    'x-rapidapi-key': "807eae8320mshca22b424981f342p11cfffjsn84100a8edb36",
    'x-rapidapi-host': "dad-jokes.p.rapidapi.com"
    }
  response = requests.request("GET", url, headers=headers)
  json_data = json.loads(response.text)
  joke = "**"+json_data['body'][0]['setup'] +"**"+"\n\n"+"||"+ json_data['body'][0]['punchline']+"||"
  return(joke)


@client.event
async def on_ready():
  print('We have logged in as {0.user}'.format(client))

@client.event
async def on_raw_reaction_add(payload):
  message_id = payload.message_id
  if message_id == <enter_id>:
    guild_id=payload.guild_id
    guild=discord.utils.find(lambda g : g.id == guild_id,client.guilds)

    if payload.emoji.name == 'Popoga':
      role = discord.utils.get(guild.roles, name='fire')
    elif payload.emoji.name == 'sumnathgrill':
      role = discord.utils.get(guild.roles, name='furry')
    elif payload.emoji.name == 'ShrekO':
      role = discord.utils.get(guild.roles, name='batch1')
    elif payload.emoji.name == 'LinusW':
      role = discord.utils.get(guild.roles, name='batch2')
    else:
      role = discord.utils.get(guild.roles, name='payload.emoji.name')

    if role is not None:
      member = payload.member
      if member is not None:
        await member.add_roles(role)
        print("added.")
      else:
        print("Member doesn\'nt exist.")
    else:
      print("Role does\'nt exist.")
  
@client.event
async def on_raw_reaction_remove(payload):
  message_id = payload.message_id
  if message_id == <enter_id>:
    guild_id=payload.guild_id
    guild=discord.utils.find(lambda g : g.id == guild_id,client.guilds)

    if payload.emoji.name == 'Popoga':
      role = discord.utils.get(guild.roles, name='fire')
    elif payload.emoji.name == 'sumanthgrill':
      role = discord.utils.get(guild.roles, name='furry')
    elif payload.emoji.name == 'ShrekO':
      role = discord.utils.get(guild.roles, name='batch1')
    elif payload.emoji.name == 'LinusW':
      role = discord.utils.get(guild.roles, name='batch2')
    else:
      role = discord.utils.get(guild.roles, name='payload.emoji.name')

    if role is not None:
      member = discord.utils.find(lambda m : m.id == payload.user_id,guild.members)
      if member is not None:
        await member.remove_roles(role)
        print("removed.")
      else:
        print("Member doesn\'nt exist.")
    else:
      print("Role does\'nt exist.")


@client.event
async def on_message(message):
  if message.author == client.user:
    return
  
  msg=message.content

  if msg.startswith('>dadjoke'):
    dad_joke=get_joke()
    await message.channel.send(dad_joke)
  
  if any(word in msg for word in gay):
    await message.add_reaction("<enter_emoji_id>")
  if any(word in msg for word in funny):
    await message.add_reaction("<enter_emoji_id>")
  if any(word in msg for word in bruh):
    await message.add_reaction("<enter_emoji_id>")
  if msg.startswith('hehe bwoi'):
    await message.add_reaction("<enter_emoji_id>")
  if any(word in msg for word in pog):
    await message.add_reaction("<enter_emoji_id>")

  if any(word in msg for word in greet):
    await message.reply('Hey, sup!')
  if message.content.startswith('>what\'s your name'):
    await message.reply('I\'m Lemon, what about you?')
  if message.content.startswith('>Nice to meet you'):
    await message.reply('Likewise!')

  if message.content.startswith('>roast'):
    await message.channel.send(random.choice(roasts))

  if msg.startswith(">responding"):
    flag=msg.split(">responding",1)[1]

    if flag.lower() == "true":
      db["responding"]=True
      await message.channel.send("Responding is on")
    else:
      db["responding"]=False
      await message.channel.send("Responding is off")

# keep_alive()
client.run(os.getenv('TOKEN'))