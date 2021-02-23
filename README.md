# led_ene
某専攻科で開発されているという謎のLEDキューブ  
その真相を解明すべく、われわれはAmazonの奥地に向かったのであった。  

## 各種メモ
- [EneLEDリファレンス](https://github.com/yoshiko-kulala/led_ene/blob/master/EneLED_reference.md)  
EneLEDクラスのリファレンス  
- [EneLED2リファレンス](https://github.com/yoshiko-kulala/led_ene/blob/master/EneLED2_reference.md)  
EneLED2クラスのリファレンス  
**最新版**  
- [リモコンデータ](https://github.com/yoshiko-kulala/led_ene/blob/master/remocon_sig.md)  
リモコンの信号を読んだ時のメモ  
- [ESPで遠隔化メモ](https://github.com/yoshiko-kulala/led_ene/blob/release/remote_memo.md)  
キューブとボタンの間を無線化しようずメモ  

## cube
LEDcubeを動かす前に配列から信号を出す練習(使い道なし)  

## cube2
点灯パターンを配列指定して送るやつ  
現在は何も光らない(20200126)  
LEDキューブ(2)の座標が記されている  
[![](http://img.youtube.com/vi/rc0n9DIIMOk/0.jpg)](http://www.youtube.com/watch?v=rc0n9DIIMOk "")  

## cube3
pikaという配列から光らせる  
光の壁が近づいてくる  
実は光らないLED見つけたりするデバッグ用  

## cube4
クラスにある程度の処理を突っ込んだけど色々未完成  
とりあえずデモっぽい動きするよ  
各段ごとの点灯は未実装  
[![](http://img.youtube.com/vi/iQ5e2esYOFQ/0.jpg)](http://www.youtube.com/watch?v=iQ5e2esYOFQ "")  

## cube5
リモコンで操作できるようにしようとした奴  
未完成、開発頓挫  

## cube6
新しくライブラリ書き直した  
各段ごとに出力を切り替えて別々に表示できるようになった  
それに合わせて入力用の配列も変化  
割り込みは500Hzになった  
[![](http://img.youtube.com/vi/GyUMiwEu_p8/0.jpg)](http://www.youtube.com/watch?v=GyUMiwEu_p8 "")  

## WS2812B
マイコン入りLEDテープのデモ

## freefall
LEDテープで自由落下+跳ね返りを作りたかった  
開発停止中  

## ir_remcon
リモコンの信号を読んで16進数で返してくれる子  

## remcon_test
リモコンの信号を読んで何のボタンが押されたか返してくれる子  
専攻科のSONYのTVリモコン  