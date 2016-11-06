#!/usr/bin/python
import os
import time
import json
import time
import datetime

from slackclient import SlackClient
from pprint import pprint

BOT_NAME = 'revlis'

CHANNEL_ARRAY = []
CHANNEL_MAP = {}

SLACK_CLIENT = SlackClient('xoxb-100949172436-Mnko99U0sJryXKJ5NGhwrE1f')
BOT_ID = 'U2YTX52CU'
AT_BOT = "<@" + BOT_ID + ">"

CONFIG = 'config.json'

def get_channels(bot_id):
    channel_list = SLACK_CLIENT.api_call('channels.list')
    group_list = SLACK_CLIENT.api_call('groups.list')

    bot_channels = []

    #print(SLACK_CLIENT.api_call('channels.info', channel="C0VN9R41F"))

    for channel in channel_list['channels']:

        if not channel['is_archived']:
            channel_id = channel['id']

            channel_info = SLACK_CLIENT.api_call('channels.info', channel=channel_id)

            #print(channel_info)

            for member in channel_info['channel']['members']:
                if BOT_ID == member:
                    #print('found him! in ' + channel_info['channel']['name'])
                    bot_channels.append(channel_id)


    for group in group_list['groups']:

        if not group['is_archived']:
            group_id = group['id']
            group_info = SLACK_CLIENT.api_call('groups.info', channel=group_id)

            for member in group_info['group']['members']:
                if BOT_ID == member:
                    bot_channels.append(group_id)

    return bot_channels

def filter_all(message_stats):
    global CHANNEL_MAP

    if not 'user' in message_stats:
        return

    channel = message_stats['channel']
    ts = message_stats['ts']
    message = message_stats['text']
    user = message_stats['user']

    if channel in CHANNEL_MAP:
        gif_count, message_count, user_map = CHANNEL_MAP[channel]

        if '/giphy' in message:
            giphy_link = message_stats['attachments'][0]['image_url']
            os.system("wget " + giphy_link + " -O newest.gif")
        else:
            if message_count > 6:
                gif_count = 0
                message_count = 0
                CHANNEL_MAP[channel] = gif_count, message_count, user_map
            else:
                message_count += 1
                CHANNEL_MAP[channel] = gif_count, message_count, user_map
            if user in user_map:
                if user_map[user] == message:
                    #print('delete message at ts')
                    message_count -= 1
                    delete_message(channel, ts)
                else:
                    user_map[user] = message
            else:
                user_map[user] = message
                CHANNEL_MAP[channel] = gif_count, message_count, user_map
        #print(CHANNEL_MAP)
    else:
        CHANNEL_MAP[channel] = 0, 0, {}
        #print(CHANNEL_MAP)

def slack_commands_list(command, channel, user):
    global CHANNEL_ARRAY

    if command.startswith('sudo ') and is_sudoer(user):
        sudo_command = command.split(' ', 1)[1]

        if sudo_command.startswith('kick '):
            user = get_user_from_command(command)
            kick_user(channel, user)

        if sudo_command.startswith('upgrade '):
            user = get_user_from_command(command)
            add_sudoer(user)

    elif command.startswith('sudo') and not is_sudoer(user):
        SLACK_CLIENT.api_call("chat.postMessage", channel=channel, text="You don't have root!", username=BOT_NAME)
    elif command.startswith('refresh'):
        CHANNEL_ARRAY = get_channels(BOT_ID)
        SLACK_CLIENT.api_call("chat.postMessage", channel=channel, text="Channel list has been refreshed!", username=BOT_NAME)
    else:
        SLACK_CLIENT.api_call("chat.postMessage", channel=channel, text="No command found.", username=BOT_NAME)

def parse_slack_output(slack_rtm_output):
    """
        The Slack Real Time Messaging API is an events firehose.
        this parsing function returns None if there is no messages being sent,
        returns true, the chat message, the channel, and the user if the message
        was directed at the bot, and false with the rest of the return values if it
        is just a message.
    """
    output_list = slack_rtm_output
    if output_list and len(output_list) > 0:
        for output in output_list:
            if output and 'text' in output and AT_BOT in output['text']:
                # return true, and all data info after
               output['text'] = output['text'].split(AT_BOT)[1].strip().lower()
               return True, output

            if output and 'text' in output:
               # return false and all data info
               return False, output

    return None, None


if __name__ == "__main__":
    READ_WEBSOCKET_DELAY = 1 # 1 second delay between reading from firehose
    if SLACK_CLIENT.rtm_connect():
        print("Bananabot connected and running!")
        CHANNEL_ARRAY = get_channels(BOT_ID)
        print(_ARRAY)

        while True:

            at_bot, message_stats = parse_slack_output(SLACK_CLIENT.rtm_read())

            if at_bot != None and 'user' in message_stats:
                # print(message_stats)
                channel = message_stats['channel']
                command = message_stats['text']
                user = message_stats['user']
                ts = message_stats['ts']

                if at_bot:
                    slack_commands_list(command, channel, user)
                else:
                    if channel in CHANNEL_ARRAY:
                        filter_all(message_stats)
            else:
                None
            time.sleep(READ_WEBSOCKET_DELAY)
    else:
        print("Connection failed. Invalid Slack token or bot ID?")
