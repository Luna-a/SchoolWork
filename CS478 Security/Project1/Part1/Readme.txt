How to use this program: 
 Use make command to compile and run program
  -To display frequency analysis of the ciphertext input 1 and press enter.
  -To decrypt the text using a key entered by user input 2 and press enter. Input the key making it so that that the first letter of the key represents "A", the second letter represents "B", and so on.
  -To make the program guess the cipher key and decrypt the text using it input 3 and press enter. At this point look through the plaintext displayed for words that can be made out. A message comes up asking if you want to modify the key, which will change the message. If the message doesn't make sense input "y". At this point the message and the key are displayed. Look through the message to find 2 letters you want to switch and input the new key with the letters switched. Repeat this until all of the message is clear. At this point when asked if you would like to modify the key input "n". A file will be created named "result.txt" which contains the key and the plaintext.

Algorithm I used to guess the key:
  I counted the frequency of all letters appearing in the ciphertext then tied the most frequently appearing letter to the first letter in the frequency distribution provided in the homework, then I tied the second most frequent letter to the second letter in the frequency distribution. I did this for all letters until I had my initial key guess. At this point the key guess is used on the ciphertext and the resulting message is shown to the user. The user then has to find words throughout the message and repeadetly modify the key by switching letters in the key until the message is completely clear.

Steps I took to decrypt the message:
  After running the program using input 3 the message shown had some visible words and some words that I could see what they were suppose to be. For example "THISIS", "SUCCEEF", and "SECURITP" appeared in the message. "THISIS" makes sense so I figured the letters t, h, i, and s were correct. I then modified the key so that "SUCCEEF" was now "SUCCEED" and then changed the key again so that "SECURITP" was now "SECURITY". I repeated this same method of modifying the key so that more words made sense until eventually I got to the key "MOLJVXKQACEHWUGNFTYIBSRZDP", which gave me the full decoded message.









