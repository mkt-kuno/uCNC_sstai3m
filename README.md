# 簡易振動台ファームウェア
Anycubic i3 Mega の3Dプリンタとしての自我を失わせて、Y軸のみを使用した振動台として生きてもらうためのuCNCファームウェアです。  
なので詳細はこちらまで  
https://github.com/Paciente8159/uCNC  

## 説明
uCNCはgrblが基本なので、Gcodeの方言はgrblです。  
X軸しかありません。Y,Z軸は設定をナーフしてあります。  
ので通常のホームコマンドは使用できません。特殊コマンド、 $HX にてX軸のみをホーミングしてから加振を開始してください。  
速度は $600[mm/s]$ 、加速度は $10000[mm/s^2]$ 、移動上限 $200[mm]$ 程度を上限に制御してください。  
乗せるものの重さによっては、下方調整や、モータドライバ(A4988)のトルク調整が必要になってきます。  

モータードライバの冷やしやすさを優先して、Y-StepperをX軸として使用しています。紛らわしいですね。  
X_LIMIT は設定の簡単さを優先して、X_MIN (E5) を使用しています。こっちは順当ですね。  

制御用ソフトはCandleでも、bCNCでも、CNCjsでも自分にあったものを使用してください。  

Gcodeは自身で**確実かつ正しいものを作成することを強く推奨**します。  
が、それすら億劫なやつのために簡単な[Webアプリ](https://mkt-kuno.github.io/uCNC_simple_shaking_table_ai3m/)をおいておきますが、動作保証はしません。  
**デバッグすらしていません。** 覚悟の上で使用してください。  

## 初期設定
初期設定項目は以下の通りです。最低限のgrblの知識を知ったうえで使用してください。  
UNLOCKしてからじゃないと動かせないことくらいは、理解してから、ということです。  
```
uCNC firmware v1.13.0
$0=33.333 (Step pulse time, microseconds)
$2=0 (Step pulse invert, mask)
$3=1 (Step direction invert, mask)
$4=0 (Invert step enable pin, boolean)
$5=1 (Invert limit pins, boolean)
$6=0 (Invert probe pin, boolean)
$7=0
$10=1 (Status report options, mask)
$11=0.200 (Junction deviation, millimeters)
$12=0.002 (Arc tolerance, millimeters)
$13=0 (Report in inches, boolean)
$20=0 (Soft limits enable, boolean)
$21=1 (Hard limits enable, boolean)
$22=1 (Homing cycle enable, boolean)
$23=0 (Homing direction invert, mask)
$24=100.000 (Homing locate feed rate, mm/min)
$25=200.000 (Homing search seek rate, mm/min)
$26=100 (Homing switch debounce delay, milliseconds)
$27=2.000 (Homing switch pull-off distance, millimeters)
$30=1000 (Maximum spindle speed, RPM)
$31=0 (Minimum spindle speed, RPM)
$32=0 (Laser-mode enable, boolean)
$100=80.000 (X-axis travel resolution, step/mm)
$110=36000.000 (X-axis maximum rate, mm/min)
$120=10000.000 (X-axis acceleration, mm/sec^2)
$130=200.000 (X-axis maximum travel, millimeters)
```
## サンプルコード
Gcodeサンプル、三角振動です。正弦波が良ければ自分で作成してください。  
```gcode
$HX            ; ホーミング
G90            ; 絶対座標モード
G21            ; mm単位
G1 X100 F600   ; 基準位置へ
G4 P1          ; 1秒待機
; 設定
$110=36000     ; X軸最大速度 600 mm/s
$120=10000     ; X軸加速度 10000 mm/s^2

G91            ; 相対モードに変更（往復指令を簡略化）
; --- 1Hz振動（±10mm、10往復 = 10秒） ---
G1 X10  F1200
G1 X-10 F1200
G1 X10  F1200
G1 X-10 F1200
G1 X10  F1200
G1 X-10 F1200
G1 X10  F1200
G1 X-10 F1200
G1 X10  F1200
G1 X-10 F1200
; --- 終了 ---
G90
```
