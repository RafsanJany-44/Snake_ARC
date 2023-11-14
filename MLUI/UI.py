from tkinter import *
from tkinter import filedialog,messagebox
from tkinter import Label
from joblib import Parallel, delayed
import joblib
import pandas as pd
import sklearn
from sklearn.ensemble import _weight_boosting

def load_model(model_name):
    return joblib.load(model_name)



def model_call():
    
    data_path = playlist_url_entry.get()
    
    model = load_model("Ada.sav")
    X_test = pd.read_csv(data_path)
    y_pred = model.predict(X_test)
    
    sleep_stage_dict = {0:"Deep Sleep", 1:"Light Sleep"}
    
    total_views = 0
    total_likes = 0
    total_comments = 0
    total_duration = 0




    print('Total Viwes: ',total_views)
    print('Total Likes: ',total_likes)
    print('Total comments: ',total_comments)
    print('Total duration: ',total_duration)
    print("Data Path: ",data_path)
    #_________________________________________________________________________________________
    #________________________________________________________________________________________________
    
    playlist_info_entry.delete(0, END)
    playlist_info_entry.insert(0, sleep_stage_dict[y_pred[0]])
    views_entry.delete(0, END)
    views_entry.insert(0, total_views)
    likes_entry.delete(0, END)
    likes_entry.insert(0, total_likes)
    comments_entry.delete(0, END)
    comments_entry.insert(0, total_comments)
    duration_entry.delete(0, END)
    duration_entry.insert(0, str(total_duration))






root = Tk()
root.title("Sleep Stage Classification")
root.configure(bg="white")


# Label and Entry for Playlist URL
playlist_url_label = Label(root, text="Enter Playlist URL:")
playlist_url_label.grid(row=0, column=0, padx=5, pady=5, sticky="w")

playlist_url_entry = Entry(root, width=50)
playlist_url_entry.grid(row=1, column=0, padx=5, pady=5, sticky="w")

# Button to get playlist info
get_info_button = Button(root, text="Go", command=model_call, padx=5, pady=2)
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

pos_comments_entry = Entry(root, width=10, bg="green")
pos_comments_entry.grid(row=5, column=1, padx=5, pady=5, sticky="w")

neg_comments_label = Label(root, text="Total Negative Comments:")
neg_comments_label.grid(row=4, column=2, padx=5, pady=5, sticky="w")

neg_comments_entry = Entry(root, width=10, bg="red")
neg_comments_entry.grid(row=5, column=2, padx=5, pady=5, sticky="w")

benchmark_label = Label(root, text="Benchmark:")
benchmark_label.grid(row=6, column=1, pady=5, sticky="w")

benchmark_entry = Entry(root, width=10, bg="yellow")
benchmark_entry.grid(row=7, column=1, pady=5, sticky="w")
root.mainloop()

