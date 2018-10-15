#!/usr/bin/python3
from collections import defaultdict
from requests import get


def count_words(subreddit, word_list=[], after=None, counter={}):
    """ counts the number of occurrences of words in word_list """
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    try:
        res = get(url, headers={'User-agent': 'l33t'}, params={'after': after},
                  allow_redirects=False).json()
        after = res['data'].get('after')

        if counter == {}:
            counter = defaultdict(int)

        for item in res['data']['children']:
            words = item['data']['title'].lower().split()
            for i in words:
                if i.lower() in word_list:
                    counter[i.lower()] += 1
        if after is not None:
            count_words(subreddit, word_list, after, counter)
        else:
            [print('{}: {}'.format(v, counter[v]))
             for v in sorted(counter, key=counter.get, reverse=True)]
    except:
        pass
