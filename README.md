# CustomShortcuts

![](https://cdn.discordapp.com/attachments/928212231886356551/1048152132328628304/Icon128.png)

Custom Shortcuts is a plugin initially released to UE5 to allow designers to make their own editor shortcuts by executing blueprint editor code.

## Install notes

* Clone plugin in your project's Plugins/ folder. 
* Regenerate visual studio project.
* Build your project using Visual Studio or Rider.
* Enable the plugin in the Plugin tab 
![image](https://user-images.githubusercontent.com/16429096/205249083-f4d0e0e1-df1b-4a96-aa89-faa806f4a77e.png)

## How to

### Create a new shortcut

* Create a new EditorUtilityBlueprint 

<img src="https://user-images.githubusercontent.com/16429096/205249516-a37f73d0-0c8b-46d1-bc8d-8087cac78fad.png" height="350">

* Make it inherit from CustomShortcutObject class 

<img src="https://user-images.githubusercontent.com/16429096/205249634-7aae213d-5b6e-4e0e-9280-b9b4cfe2683f.png" height="350">

* Open it. In the details panel you can change the Input Chords of the input, as well as the name and description of it.

(In this example, I will show how to make a shortcut that doubles the size of an actor)

![image](https://user-images.githubusercontent.com/16429096/205250246-89b2b49f-dd83-45cf-9f0a-36182cabebfb.png)

* Override the OnShortcutExecuted event to implement the behaviour of your shortcut when executed.

(The transaction nodes are here to register our modifications in the Undo history, allowing the user to revert the changes https://docs.unrealengine.com/4.27/en-US/BlueprintAPI/Transactions/)

![image](https://user-images.githubusercontent.com/16429096/205250534-001dbd84-bda0-4b96-8e57-8f7549e38354.png)

![image](https://user-images.githubusercontent.com/16429096/205250841-20da0c37-52d5-4722-afc0-e6832a849ec6.png)

* (Optionnal) You can override the CanExecuteShortcut function to indicate wheter the shortcut can be executed or not

![image](https://user-images.githubusercontent.com/16429096/205251117-6e4f4bc2-92e3-4fd5-a261-d7a8bf62f8e9.png)

<img src="https://user-images.githubusercontent.com/16429096/205251017-0110750a-4809-4ecf-8a02-27b2ce5d9900.png" height="250">

## Register a shortcut

* Go in ProjectSettings > Plugins > Custom Shortcuts and add your class in the CustomShortcuts list

![image](https://user-images.githubusercontent.com/16429096/205250425-a71a592c-dc57-4b8e-92b7-d18b368737d0.png)

* If ever your shortcut is not well registered, you can use Tools > Refresh custom shortcuts. Restarting the engine should fix it too.

<img src="https://user-images.githubusercontent.com/16429096/205251208-25c9b262-abf2-401c-af36-965c2db5359f.png" height="350">

# Result

You shortcut is now registered in EditorSettings > Keyboard Shortcuts and can be executed by anyone!

![image](https://user-images.githubusercontent.com/16429096/205253493-4142fabf-e6de-4c16-b2a3-216925d8c0b2.png)

![UnrealEditor-Win64-DebugGame_iT2aNWl2ja](https://user-images.githubusercontent.com/16429096/205253993-db0a9265-d843-45f3-9bd8-ba8f95d5c51a.gif)
