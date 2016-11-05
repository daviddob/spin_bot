from slacker import Slacker

slack = Slacker('xoxp-23584478294-23583487255-80722151107-ad2150f3a7')

# Send a message to #general channel
slack.chat.post_message('#silverman', 'Running api')

# Get users list
#response = slack.users.list()
#users = response.body['members']

# Upload a file
#slack.files.upload('hello.txt')
