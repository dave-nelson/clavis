Project: Wyse terminal keyboard 840358-01
=========================================

The Wyse 840358-01 is a 104 key terminal keyboard based on the Texas 
Instruments TI CF60137N 28-pin controller.  It features Cherry MX black 
keyswitches, double-shot keycaps (navy blue and yellow on grey), and an ANSI-style layout.


Matrix
------

The 840358 features a densely populated key matrix of 8 columns x 13 rows.  The 
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
    <td> Num 7 </td>
    <td> . &gt; </td>
    <td> K </td>
    <td> U </td>
    <td> 5 % </td>
    <td> \ | </td>
    <td> F10 </td>
    <td> Esc </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen">10</td>
    <td> Num + </td>
    <td> = + </td>
    <td> Enter </td>
    <td> Y </td>
    <td> Left Alt </td>
    <td> 2 @ </td>
    <td> ` ~ </td>
    <td> 1 ! </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 11 </td>
    <td> Num Enter </td>
    <td> , &lt; </td>
    <td> F12 </td>
    <td> O </td>
    <td> Num Lock </td>
    <td> Caps Lock </td>
    <td> Left Ctrl </td>
    <td> <em>(empty)</em> </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 12 </td>
    <td> Num . </td>
    <td> F11 </td>
    <td> / ? </td>
    <td> I </td>
    <td> ; : </td>
    <td> Right Shift </td>
    <td> <em>(empty)</em> </td>
    <td> Left Shift </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 13 </td>
    <td> Num 0 </td>
    <td> Num 9 </td>
    <td> Num - </td>
    <td> Num * </td>
    <td> ' " </td><!-- ' -->
    <td> Select </td>
    <td> Right Ctrl </td>
    <td> Space </td>
  </tr>


  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 14 </td>
    <td> Num / </td>
    <td> Z </td>
    <td> L </td>
    <td> - _ </td>
    <td> Right Alt </td>
    <td> ] } </td>
    <td> Scroll Lock </td>
    <td> [ { </td>  <!-- } -->
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 15 </td>
    <td> Num 2 </td>
    <td> M </td>
    <td> H </td>
    <td> P </td>
    <td> 4 $ </td>
    <td> Home </td>
    <td> F6 </td>
    <td> Right arrow </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 16 </td>
    <td> Num 1 </td>
    <td> B </td>
    <td> J </td>
    <td> T </td>
    <td> 3 # </td>
    <td> Insert </td>
    <td> F7 </td>
    <td> Back Space </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 17 </td>
    <td colspan="8" style="background: lightblue"> GND </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 24 </td>
    <td> Num 8 </td>
    <td> F9 </td>
    <td> A </td>
    <td> F8 </td>
    <td> 9 ( </td>
    <td> F1 </td>
    <td> Pause </td>
    <td> Tab </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 25 </td>
    <td> Num 6 </td>
    <td> C </td>
    <td> S </td>
    <td> Q </td>
    <td> 8 * </td>
    <td> Page Down </td>
    <td> F2 </td>
    <td> Print Screen </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 26 </td>
    <td> Num 5 </td>
    <td> X </td>
    <td> F </td>
    <td> E </td>
    <td> 7 &amp; </td>
    <td> End </td>
    <td> F3 </td>
    <td> Left arrow </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 27 </td>
    <td> Num 4 </td>
    <td> V </td>
    <td> D </td>
    <td> W </td>
    <td> 6 ^ </td>
    <td> Delete </td>
    <td> F4 </td>
    <td> Down arrow </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 28 </td>
    <td> Num 3 </td>
    <td> N </td>
    <td> G </td>
    <td> R </td>
    <td> 0 ) </td>
    <td> Page Up </td>
    <td> F5 </td>
    <td> Up arrow </td>
  </tr>

</table>

Note that the keys available represent a fairly standard ANSI 101 keyboard, 
with the addition of a "Select" key (upper right).


Implementation
--------------

For the Teensy USB implementation the following ports were used.

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

    <td> Num 7 </td>
    <td> Num . </td>
    <td> K </td>
    <td> U </td>
    <td> Num 5 </td>
    <td> Backslash/pipe </td>
    <td> F10 </td>
    <td> Esc </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 10<br/>D1 </td>

    <td> Num + </td>
    <td> = / + </td>
    <td> Enter </td>
    <td> Y </td>
    <td> Left Alt </td>
    <td> 2 / @ </td>
    <td> ` / ~ </td>
    <td> 1 / ! </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 11<br/>D2 </td>

    <td> Num Enter </td>
    <td> , / &lt; </td>
    <td> F12 </td>
    <td> O </td>
    <td> Num Lock </td>
    <td> Caps Lock </td>
    <td> Left Ctrl </td>
    <td> (unassigned) </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 12<br/>D3 </td>

    <td> Num . </td>
    <td> F11 </td>
    <td> / / ? </td>
    <td> I </td>
    <td> ; / : </td>
    <td> Right Shift </td>
    <td> (unassigned) </td>
    <td> Left Shift </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 13<br/>D4 </td>

    <td> Num 0 </td>
    <td> Num 9 </td>
    <td> Num - </td>
    <td> Num * </td>
    <td> ' / " </td>
    <td> Select </td>
    <td> Right Ctrl </td>
    <td> Space </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 14<br/>D5 </td>
    <td> Num / </td>
    <td> Z </td>
    <td> L </td>
    <td> - / _ </td>
    <td> Right Alt </td>
    <td> ] / } </td>
    <td> Scroll lock </td>
    <td> [ / { </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 15<br/>D7 </td>

    <td> Num 2 </td>
    <td> M </td>
    <td> H </td>
    <td> P </td>
    <td> 4 / $ </td>
    <td> Home </td>
    <td> F6 </td>
    <td> Right arrow </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 16<br/>F0 </td>

    <td> Num 1 </td>
    <td> B </td>
    <td> J </td>
    <td> T </td>
    <td> 3 </td>
    <td> Insert </td>
    <td> F7 </td>
    <td> Backspace </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 17 </td>
    <td colspan="8" style="background: lightblue"> GND </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 24<br/>F1 </td>

    <td> Num 8 </td>
    <td> F9 </td>
    <td> A </td>
    <td> F8 </td>
    <td> 9 / ( </td>
    <td> F1 </td>
    <td> Pause </td>
    <td> Tab </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 25<br/>F4 </td>

    <td> Num 6 </td>
    <td> C </td>
    <td> S </td>
    <td> Q </td>
    <td> 8 / * </td>
    <td> PgDn </td>
    <td> F2  </td>
    <td> Print Screen </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 26<br/>F5 </td>

    <td> Num 5 </td>
    <td> X </td>
    <td> F </td>
    <td> E </td>
    <td> 7 / &amp; </td>
    <td> End </td>
    <td> F3 </td>
    <td> Left arrow </td>
  </tr>

  <tr style="background: white">
    <td style="background: lightgreen"> 27<br/>F6 </td>
    <td> Num 4 </td>
    <td> V </td>
    <td> D </td>
    <td> W </td>
    <td> 6 </td>
    <td> Delete </td>
    <td> F4 </td>
    <td> Down arrow </td>
  </tr>

  <tr style="background: lightgrey">
    <td style="background: lightgreen"> 28<br/>F7 </td>

    <td> Num 3 </td>
    <td> N </td>
    <td> G </td>
    <td> R </td>
    <td> 0 / ) </td>
    <td> PgUp </td>
    <td> F5 </td>
    <td> Up arrow </td>
  </tr>

</table>

In addition, the following ports were used for LED indicators:

 * C6: Num Lock
 * C7: Caps Lock
 * E6: Scroll Lock

