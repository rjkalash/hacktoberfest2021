 A progrom that tells what is the location of the ISS(International Space Station) and how many people are there on it.
  Interesting...is it🖖🖖
  
      import requests
      import os

      width, height = os.get_terminal_size()
      print(os.get_terminal_size())
      while True:
          print('\n\n')
          print('*******************International Space Station Data*************************')
          print('\n')
          x = input('Press ENTER to view the current position of the ISS with the people currently on it:')
          print('\n')
          while True:
              positions = requests.get('http://api.open-notify.org/iss-now.json').json()
              peoples = requests.get("http://api.open-notify.org/astros.json").json()
              # print(response)
              print('\n')
              print('Timestamp:' + str(positions['timestamp']))
              print('latitude: ' + positions['iss_position']['latitude'])
              print('longitude: ' + positions['iss_position']['longitude'])
          # print(peoples)
          # print('\n')
          # print('People currently on the ISS:')
          # print('\n')
          # x = 0
          # for i in peoples['people']:
          #     x+=1
          #     print(str(x) + 'st person: ' + i['name'])
          #     # print()
          #
          # print('\n')
          # print('Hence at this time there are a total of ' + str(x) + ' people in the ISS.')
          # print('\n')
          # loop_varri = input('Do you want to continue(y/n):')
          # if loop_varri == 'y':
          #     continue
          # else:
          #     break





