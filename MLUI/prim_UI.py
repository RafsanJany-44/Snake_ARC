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
    
    #data Reading
    X_test = pd.read_csv(data_path)
    
    #model calling
    model_gb = load_model("Grad.sav")
    
    
    #prediction
    gb_pred  = model_gb.predict(X_test)
    
    
    #sleep dictionary
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
    playlist_info_entry.insert(0, sleep_stage_dict[gb_pred[0]])



root = Tk()
root.title("Sleep Stage Classification Foe Single Model")
root.configure(bg="white")


# Label and Entry for Playlist URL
playlist_url_label = Label(root, text="Enter Data Path:")
playlist_url_label.grid(row=0, column=0, padx=5, pady=5, sticky="w")

playlist_url_entry = Entry(root, width=50)
playlist_url_entry.grid(row=1, column=0, padx=5, pady=5, sticky="w")

# Button to get playlist info
get_info_button = Button(root, text="Go", command=model_call, padx=5, pady=2)
get_info_button.grid(row=1, column=1, padx=5, pady=5, sticky="w")

# Labels and Entries for Playlist Info
playlist_info_label = Label(root, text="Predicted Sleep Stage:")
playlist_info_label.grid(row=2, column=0, padx=5, pady=5, sticky="w")

playlist_info_entry = Entry(root, width=50)
playlist_info_entry.grid(row=3, column=0, padx=5, pady=5, sticky="w")
root.mainloop()