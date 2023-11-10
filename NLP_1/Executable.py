from tkinter import *
from tkinter import filedialog,messagebox
from tkinter import Label
from googleapiclient.discovery import build
from pytube import Playlist
import datetime
import os
import isodate
import datetime
import pandas as pd
from tensorflow.keras.preprocessing.sequence import pad_sequences
from googleapiclient.discovery import build
from pytube import Playlist
from tqdm import tqdm
import json
import requests
import time
import pandas as pd
import re
import numpy as np
import pafy
from googleapiclient.discovery import build
import iso8601
import pickle
import keras
import datetime
from tkinter.filedialog import asksaveasfile

history_mirror=[]


def nlp_model(sentence,mod):
    with open('tokenizer.pickle', 'rb') as handle:
        tokenizer = pickle.load(handle)
    
    sequences = tokenizer.texts_to_sequences(sentence)
    padded = pad_sequences(sequences, maxlen=200, padding='post', truncating='post')
    
    if mod=="ann":
        ann = keras.models.load_model("ann.keras")
        pred = ann.predict(padded)
        return  (len(pred[(pred>=0.5)]),len(pred[(pred<0.5)]))
    
    else:
        bi_lstm = keras.models.load_model("bi_lstm_model.keras")
        pred = bi_lstm.predict(padded)
        return (len(pred[(pred>=0.5)]),len(pred[(pred<0.5)]))



def remove_html_tags(text):
    """Remove html tags from a string"""
    import re
    clean = re.compile('<.*?>')
    return re.sub(clean, '', text)


def get_comments(youtube_object, video_id, token):
  
  global all_comments
  totalReplyCount = 0
  token_reply = None
  
  if (token == ''):
    video_response=youtube_object.commentThreads().list(part='snippet',maxResults=100,videoId=video_id,order='relevance').execute()
  else:
    video_response=youtube_object.commentThreads().list(part='snippet',maxResults=100,videoId=video_id,order='relevance',pageToken=token).execute()


  for indx, item in enumerate(video_response['items']):
    all_comments.append(remove_html_tags(item['snippet']['topLevelComment']['snippet']['textDisplay']))

    totalReplyCount = item['snippet']['totalReplyCount']

  if "nextPageToken" in video_response:
    return get_comments(youtube_object, video_id, video_response['nextPageToken'])
  else:
    all_comments = [x for x in all_comments if len(x) > 0]
    return []


def main_cmnt(play_list_link):

  p = Playlist(play_list_link)
  global all_comments
  all_comments = []
  
  for url_input in tqdm(p):
    video_id_split = url_input.split('=')
    video_id=video_id_split[1]

    youtube_object = build('youtube', 'v3',developerKey=api_key)
    comments = get_comments(youtube_object,video_id,'')

  # Show results:
  df = pd.DataFrame(all_comments,columns=['Comments'])
  df = df.astype(str).apply(lambda x: x.str.encode('ascii', 'ignore').str.decode('ascii'))
  df['Comments'] = df['Comments'].apply(lambda x: re.split('<a href="https:\/\/.*', str(x))[0])
  all_comments = df['Comments'].to_list()
  print("All total comments obtained: "  + str(len(all_comments)))
  return all_comments



def get_upload_date(url_input):
    video_id_split =url_input.split('=')
    video_id=video_id_split[1]
    youtube = build('youtube', 'v3', developerKey=api_key)

    # Retrieve the video details using the video ID
    video_response = youtube.videos().list(
        part='snippet',
        id=video_id
    ).execute()
  
    # Extract the upload date from the response
    video_info = video_response['items'][0]['snippet']
    upload_date_iso = video_info['publishedAt']
    upload_date = iso8601.parse_date(upload_date_iso)
    
    return upload_date




def save():    
    try:
        path = filedialog.asksaveasfile(filetypes = (("Text files", "*.txt"), ("All files", "*.*"))).name
    
    except:
        return   
    history_mirror
    with open(path, 'w') as f:
      for line in history_mirror:
        f.write(line)
        f.write('\n')
        f.write('_________________________________________________________________________________')
        f.write('\n')


#____________________________________________________________________________________________________________________________________________________________________________________________________________________________
api_key = "AIzaSyDeP_lfp2l2sr9cEPKRi5M6CpwXDUMgQ2c"  
youtube = build("youtube", "v3", developerKey=api_key)

def convert_duration(duration):
    # Convert ISO 8601 duration format to a timedelta object
    duration = isodate.parse_duration(duration)
    return duration




def get_playlist_info():
    try:
        playlist_url = playlist_url_entry.get()
        print(playlist_url)
        playlist = Playlist(playlist_url)
        playlist_title = playlist.title
        
    except Exception as e:
        messagebox.showerror("Error", "Failed to retrieve playlist data. Make sure the URL is valid.")
        print(e)
        return
      
    
    print("Comment Collecting--->>>>")
    k = main_cmnt(playlist_url)
    total_comments = len(k)
    
    
    print("Model Prediction--->>>>")
    pos_neg = nlp_model(k,"a")

    total_views = 0
    total_likes = 0
    total_duration = 0

    print("Collecting Info--->>>>")
    for url in tqdm(playlist):
      video = pafy.new(url)
      total_views = total_views+int(video.viewcount)
      total_duration = total_duration+ int(video.length)
      if not video.likes is None:
        total_likes = total_likes+int(video.likes)
    
    convert_time = time.strftime("%H:%M:%S", time.gmtime(total_duration))
    print('Total Viwes: ',total_views)
    print('Total Likes: ',total_likes)
    print('Total duration: ',convert_time)
    print("All total comments obtained: ",total_comments)
    print("Total Positive Comments: ",pos_neg[0])
    
    print("Total Non-Positive Comments: ",pos_neg[1])
    upload_duration = (datetime.date.today()-get_upload_date(url).date()).days
    #Benchmarking 
    bench_mark = (total_likes/total_views) + (pos_neg[0]/total_comments) - ((1/(total_duration/3600)) + (1/(upload_duration/7)))
    
    print("Like Views Ratio: ", (total_likes/total_views))
    print("Positive Comment Percentage: ",(pos_neg[0]/total_comments))
    print("Video Duration Param(hour): ",1/(total_duration/3600))
    print("Upload Time Param(week): ", (1/(upload_duration/7)))
    print("The Final BenchMark: ",bench_mark)
    print("____________________________________________________________________________________________________________________")
    history_mirror.append("Title:"+playlist_title+"\nTotal Views: "+str(total_views)+"\nTotal Likes: "+str(total_likes)+"\nDuration: "+convert_time+"\nTotal Comment: "+str(total_comments)+"\nPositive Comments: "+str(pos_neg[0])+"\nBenchMark: "+str(round(bench_mark,2)*100)+"/100"+"\nLink: "+playlist_url)
    #_________________________________________________________________________________________
    #_________________________________________________________________________________________
    #UI connection
    playlist_info_entry.delete(0, END)
    playlist_info_entry.insert(0, playlist_title)
    views_entry.delete(0, END)
    views_entry.insert(0, total_views)
    likes_entry.delete(0, END)
    likes_entry.insert(0, total_likes)
    comments_entry.delete(0, END)
    comments_entry.insert(0, total_comments)
    duration_entry.delete(0, END)
    duration_entry.insert(0, convert_time)
    pos_comments_entry.delete(0, END)
    pos_comments_entry.insert(0, pos_neg[0])
    neg_comments_entry.delete(0, END)
    neg_comments_entry.insert(0, pos_neg[1])
    benchmark_entry.delete(0,END)
    benchmark_entry.insert(0, round(bench_mark,2)*100)


root = Tk()
root.title("YouTube Playlist Info Retrieval")
root.configure(bg="#EBD7FF")



# Label and Entry for Playlist URL
playlist_url_label = Label(root, text="Enter Playlist URL:")
playlist_url_label.grid(row=0, column=0, padx=5, pady=5, sticky="w")

playlist_url_entry = Entry(root, width=50)
playlist_url_entry.grid(row=1, column=0, padx=5, pady=5, sticky="w")

# Button to get playlist info
get_info_button = Button(root, text="Go", command=get_playlist_info, padx=5, pady=2, bg="#E4FF00")
get_info_button.grid(row=1, column=1, padx=5, pady=5, sticky="w")

# Labels and Entries for Playlist Info
playlist_info_label = Label(root, text="Playlist Title:")
playlist_info_label.grid(row=2, column=0, padx=5, pady=5, sticky="w")

playlist_info_entry = Entry(root, width=50)
playlist_info_entry.grid(row=3, column=0, padx=5, pady=5, sticky="w")

views_label = Label(root, text="Total Views:")
views_label.grid(row=2, column=1, padx=5, pady=5, sticky="w")

views_entry = Entry(root, width=10)
views_entry.grid(row=3, column=1, padx=5, pady=5, sticky="w")

likes_label = Label(root, text="Total Likes:")
likes_label.grid(row=2, column=2, padx=5, pady=5, sticky="w")

likes_entry = Entry(root, width=10)
likes_entry.grid(row=3, column=2, padx=5, pady=5, sticky="w")

comments_label = Label(root, text="Total Comments:")
comments_label.grid(row=4, column=0, padx=5, pady=5, sticky="w")

comments_entry = Entry(root, width=10)
comments_entry.grid(row=5, column=0, padx=5, pady=5, sticky="w")

duration_label = Label(root, text="Total Duration:")
duration_label.grid(row=2, column=3, padx=5, pady=5, sticky="w")

duration_entry = Entry(root, width=20)
duration_entry.grid(row=3, column=3, padx=5, pady=5, sticky="w")

pos_comments_label = Label(root, text="Total Positive Comments:")
pos_comments_label.grid(row=4, column=1, padx=5, pady=5, sticky="w")

pos_comments_entry = Entry(root, width=10, bg="light green")
pos_comments_entry.grid(row=5, column=1, padx=5, pady=5, sticky="w")

neg_comments_label = Label(root, text="Total NoN Positive Comments:")
neg_comments_label.grid(row=4, column=2, padx=5, pady=5, sticky="w")

neg_comments_entry = Entry(root, width=10, bg="light yellow")
neg_comments_entry.grid(row=5, column=2, padx=5, pady=5, sticky="w")

benchmark_label = Label(root, text="Benchmark (out of 100):")
benchmark_label.grid(row=6, column=1, pady=5, sticky="w")

benchmark_entry = Entry(root, width=10, bg="pink")
benchmark_entry.grid(row=7, column=1, pady=5, sticky="w")

save_pdf_info_button = Button(root, text="Save History", command= lambda : save(), padx=5, pady=2,bg="#D997FE")
save_pdf_info_button.grid(row=7, column=3, padx=5, pady=5, sticky="w")

root.mainloop()