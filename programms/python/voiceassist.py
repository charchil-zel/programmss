import speech_recognition as sr
import pyttsx3
import datetime
import wikipedia
import pywhatkit
listner = sr.Recognizer()
engine=pyttsx3.init()
voices=engine.getProperty('voices')
engine.setProperty('voices', voices[1].id)
def talk(text):
    engine.say(text);
    engine.runAndWait()

def talk_command():
    try:
        with sr.Microphone() as source:
            print("listening...")
            voice=listner.listen(source)
            command=listner.recognize_google(voice)
            command=command.lower()
            if 'churchill' in command: 

                command = command.replace('churchill','');
                
    except:
        pass
    return command;

def run_command():
    command= talk_command();

    if 'play' in command:
        song=command.replace('play','');
        talk('playing'+song);
        pywhatkit.playonyt(song);
    elif 'time' in command: 
        time=datetime.datetime.now().strftime('%H:%M %p')
        talk('Its'+ time)
    elif 'wikipedia' in command:
        person=command.replace('wikipedia','');
        info=wikipedia.summary(person)
        print(person)
        print(info)
        talk(info)

run_command();