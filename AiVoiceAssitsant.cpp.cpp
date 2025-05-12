#include <iostream>
#include <string>
#include <sapi.h>  // Windows Speech API
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "sapi.lib")

using namespace std;

// Text-to-speech function
void speak(const wstring& text) {
    ISpVoice* pVoice = nullptr;

    if (FAILED(::CoInitialize(nullptr))) return;

    HRESULT hr = CoCreateInstance(CLSID_SpVoice, nullptr, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice);
    if (SUCCEEDED(hr)) {
        pVoice->Speak(text.c_str(), SPF_IS_XML, nullptr);
        pVoice->Release();
    }

    ::CoUninitialize();
}

// Chatbot response logic
string getResponse(const string& input) {
    if (input == "hello") return "Hello Sunny!";
    else if (input == "what is your name") return "I am your voice assistant.";
    else if (input == "tell my full name") return "Your Name is Sunny Bhardwaj.";
    else if (input == "tell my fav singer name") return "Your Favorite Singer Name is Sidhu Moose Wala";
    else if (input == "open notepad") {
        system("start notepad");
        return "Opening Notepad.";
    }
    else if (input == "bye") return "Goodbye!";
    else return "Sorry, I didn't understand that.";
}

int main() {
    string input;
    cout << "Welcome to your C++ Voice Assistant (type 'exit' to quit)\n";

    while (true) {
        cout << "\nYou: ";
        getline(cin, input);

        if (input == "exit") break;

        string response = getResponse(input);
        wstring wideResponse(response.begin(), response.end());

        cout << "Assistant: " << response << endl;
        speak(wideResponse);
    }

    return 0;
}