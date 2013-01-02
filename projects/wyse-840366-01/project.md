Project: Wyse terminal keyboard 840366-01
=========================================

The Wyse 840366-01 is a 104 key terminal keyboard based on the Texas 
Instruments TI CF60137N 28-pin controller.  It features Cherry MX black 
keyswitches, double-shot keycaps (navy blue and yellow on grey), and a large 
ISO-style Enter key.

Matrix
------

The 840366 features a densely populated key matrix of 8 columns x 13 rows.  The 
columns and rows below are labelled with CF60137N pin numbers.

<table style="background: grey; text-align: center">
  <colgroup>
    <col span="1" style="width: 10%;">
    <col span="1" style="width: 10%;">
    <col span="1" style="width: 10%;">
    <col span="1" style="width: 10%;">
    <col span="1" style="width: 10%;">
    <col span="1" style="width: 10%;">
    <col span="1" style="width: 10%;">
    <col span="1" style="width: 10%;">
    <col span="1" style="width: 10%;">
  </colgroup>

  <tr style="background:pink">
    <td style="background: grey"></td>
    <td>1</td>
    <td>2</td>
    <td>3</td>
    <td>4</td>
    <td>5</td>
    <td>6</td>
    <td>7</td>
    <td>8</td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen">9</td>
    <td> Num 0 </td>
    <td> Num 4 </td>
    <td> PF1 </td>
    <td> &lt;&gt; </td>
    <td> 8* </td>
    <td> Tab </td>
    <td> Return </td>
    <td> F1 </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen">10</td>
    <td> Num . </td>
    <td> Num 5 </td>
    <td> PF2 </td>
    <td> Z </td>
    <td> 9( </td>
    <td> R </td>
    <td> '” </td>
    <td> F2 </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 11 </td>
    <td> Up </td>
    <td> Num 6 </td>
    <td> PF3 </td>
    <td> C </td>
    <td> 0) </td>
    <td> W </td>
    <td> \| </td>
    <td> F3 </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 12 </td>
    <td> Down </td>
    <td> Num 1 </td>
    <td> PF4 </td>
    <td> X </td>
    <td> -_ </td>
    <td> E </td>
    <td> ;: </td>
    <td> F4 </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 13 </td>
    <td> Left </td>
    <td> Num 2 </td>
    <td> Num 7 </td>
    <td> V </td>
    <td> =+ </td>
    <td> Q </td>
    <td> Space </td>
    <td> F5 </td>
  </tr>


  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 14 </td>
    <td> F19 </td>
    <td> F18 </td>
    <td> F17 </td>
    <td> Do </td>
    <td> Help </td>
    <td> F14 </td>
    <td> F13 </td>
    <td> Compose </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 15 </td>
    <td> Right </td>
    <td> ]} </td>
    <td> [{ </td>
    <td> Backsp </td>
    <td> P </td>
    <td> Insert </td>
    <td> Ctrl </td>
    <td> F7 </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 16 </td>
    <td> L </td>
    <td> K </td>
    <td> J </td>
    <td> Shift </td>
    <td> H </td>
    <td> G </td>
    <td> F20 </td>
    <td> F6 </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 17 </td>
    <td colspan="8" style="background: lightblue"> GND </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 24 </td>
    <td> Find </td>
    <td> Num 3 </td>
    <td> Num 9 </td>
    <td> M </td>
    <td> 3# </td>
    <td> O </td>
    <td> D </td>
    <td> F12 </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 25 </td>
    <td> Num Enter </td>
    <td> Next </td>
    <td> Num 8 </td>
    <td> B </td>
    <td> 2@ </td>
    <td> I </td>
    <td> F </td>
    <td> F11 </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 26 </td>
    <td> Num , </td>
    <td> Num - </td>
    <td> Prev </td>
    <td> N </td>
    <td> 1! </td>
    <td> U </td>
    <td> S </td>
    <td> F10 </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 27 </td>
    <td> /? </td>
    <td> . </td>
    <td> , </td>
    <td> Select </td>
    <td> `~ </td>
    <td> Y </td>
    <td> A </td>
    <td> F9 </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 28 </td>
    <td> 7&amp; </td>
    <td> 6^ </td>
    <td> 5% </td>
    <td> 4$ </td>
    <td> Remove </td>
    <td> T </td>
    <td> Capslock </td>
    <td> F8 </td>
  </tr>

</table>

Note that some of the keys cannot be represented in a standard way via USB HID, 
since they rely on the presence (or absence) of a shift modifier.  An example 
is the "&lt;" key (shift to "&gt;"): these characters are implemented in USB as 
"," and "." resp. plus the SHIFT modifier.

Also note the absence of typical PC keyboard keys like Num Lock and Esc, and 
modifiers like Alt.


Implementation
--------------

For the Teensy USB implementation the following ports were used, and the 
meanings of certain keys were reinterpreted (as shown below) to make the 
keyboard more PC-compatible.

Changes are highlighted in bold.  Modifier keys are highlighted in yellow.

<table style="background: grey; text-align: center">
  <colgroup>
    <col span="1" style="width: 10%;">
    <col span="1" style="width: 10%;">
    <col span="1" style="width: 10%;">
    <col span="1" style="width: 10%;">
    <col span="1" style="width: 10%;">
    <col span="1" style="width: 10%;">
    <col span="1" style="width: 10%;">
    <col span="1" style="width: 10%;">
    <col span="1" style="width: 10%;">
  </colgroup>

  <tr style="background:pink">
    <td style="background: grey"></td>
    <td> 1<br/>B0 </td>
    <td> 2<br/>B1 </td>
    <td> 3<br/>B2 </td>
    <td> 4<br/>B3 </td>
    <td> 5<br/>B4 </td>
    <td> 6<br/>B5 </td>
    <td> 7<br/>B6 </td>
    <td> 8<br/>B7 </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 9<br/>D0 </td>

    <td> Num 0 </td>
    <td> Num 4 </td>
    <td> PF1<br/><strong>KEY_NUM_LOCK</strong> </td>
    <td> &lt;&gt;<br/><strong>(none)</strong> </td>
    <td> 8* </td>
    <td> Tab </td>
    <td> Return </td>
    <td> F1 </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 10<br/>D1 </td>

    <td> Num . </td>
    <td> Num 5 </td>
    <td> PF2<br/><strong>KEYPAD_SLASH</strong> </td>
    <td> Z </td>
    <td> 9( </td>
    <td> R </td>
    <td> '” </td>
    <td> F2 </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 11<br/>D2 </td>

    <td> Up </td>
    <td> Num 6 </td>
    <td> PF3<br/><strong>KEYPAD_ASTERIX</strong> </td>
    <td> C </td>
    <td> 0) </td>
    <td> W </td>
    <td> \| </td>
    <td> F3 </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 12<br/>D3 </td>

    <td> Down </td>
    <td> Num 1 </td>
    <td> PF4<br/><strong>KEYPAD_MINUS</strong> </td>
    <td> X </td>
    <td> -_ </td>
    <td> E </td>
    <td> ;: </td>
    <td> F4 </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 13<br/>D4 </td>

    <td> Left </td>
    <td> Num 2 </td>
    <td> Num 7 </td>
    <td> V </td>
    <td> =+ </td>
    <td> Q </td>
    <td> Space </td>
    <td> F5 </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 14<br/>D5 </td>
    <td> F19<br/><strong>KEY_SCROLL_LOCK</strong> </td>
    <td> F18<br/><strong>KEY_PRINTSCREEN</strong> </td>
    <td> F17 </td>
    <td> Do<br/><strong>KEY_ESC</strong> </td>
    <td style="background: yellow"> Help<br/><strong>KEY_RIGHT_GUI</strong> </td>
    <td> F14 </td>
    <td> F13 </td>
    <td style="background: yellow"> Compose<br/><strong>KEY_ALT</strong> </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 15<br/>D7 </td>

    <td> Right </td>
    <td> ]} </td>
    <td> [{ </td>
    <td> Backsp </td>
    <td> P </td>
    <td> Insert </td>
    <td style="background: yellow"> Ctrl </td>
    <td> F7 </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 16<br/>F0 </td>

    <td> L </td>
    <td> K </td>
    <td> J </td>
    <td style="background: yellow"> Shift </td>
    <td> H </td>
    <td> G </td>
    <td> F20<br/><strong>KEY_PAUSE</strong> </td>
    <td> F6 </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 17 </td>
    <td colspan="8" style="background: lightblue"> GND </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 24<br/>F1 </td>

    <td> Find<br/><strong>KEY_HOME</strong> </td>
    <td> Num 3 </td>
    <td> Num 9 </td>
    <td> M </td>
    <td> 3# </td>
    <td> O </td>
    <td> D </td>
    <td> F12 </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 25<br/>F4 </td>

    <td> Num Enter </td>
    <td> Next<br/><strong>KEY_PAGE_DOWN</strong> </td>
    <td> Num 8 </td>
    <td> B </td>
    <td> 2@ </td>
    <td> I </td>
    <td> F </td>
    <td> F11 </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 26<br/>F5 </td>

    <td> Num ,<br/><strong>KEYPAD_PLUS</strong> </td>
    <td> Num -<br/><strong>KEYPAD_PLUS</strong> </td>
    <td> Prev<br/><strong>KEY_PAGE_UP</strong> </td>
    <td> N </td>
    <td> 1! </td>
    <td> U </td>
    <td> S </td>
    <td> F10 </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 27<br/>F6 </td>
    <td> /? </td>
    <td> . </td>
    <td> , </td>
    <td> Select<br/><strong>KEY_END</strong> </td>
    <td> `~ </td>
    <td> Y </td>
    <td> A </td>
    <td> F9 </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 28<br/>F7 </td>

    <td> 7&amp; </td>
    <td> 6^ </td>
    <td> 5% </td>
    <td> 4$ </td>
    <td> Remove<br/><strong>KEY_DELETE</strong> </td>
    <td> T </td>
    <td> Capslock </td>
    <td> F8 </td>
  </tr>

</table>

