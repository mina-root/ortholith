# Ortholith

RP2040 を使った左右分割キーボード **Ortholith** のファームウェア（QMK / Vial 用キーボード定義）です。

* 7x4 格子配列・47キー+2エンコーダ
* 右手側に PMW3360 トラックボール(Keyballのトラックボール基板と互換)
* RGB Matrix 47 LED

> キーフリで頒布したv0 基板では **OLED は搭載できません。** 基板上にパターンとシルクがありますが、
> 設計時にピンアサインを逆にするとかいう大ポカをやらかしたので乗りません（悲しい……）
> ケースの該当箇所も塞いであります

## 組み立てる方へ

組み立て手順・同梱物・別途用意していただくものは **[BUILD.md（組み立てガイド）](BUILD.md)** にまとめてあります。

## 接続について

キーボードとPCの接続は左手側の奥側にあるTypeCポートを使用してください。
左右の接続は内側側面にあるコネクタを使用してください。ここでもTypeCケーブルを使用します。

**左右間の接続に使うコネクタを誤ってPCに接続しないようにしてください！** 

## ⚠ キー配列について

既定のキーマップは **QWERTY ではなく** ローマ字入力に最適化された
[大西配列](https://o24.works/layout/) を採用しています。

作者ミナモトの思想の関係でこうなっています。[QWERTY配列をやめろ](https://note.com/mina_root/n/nc55238c528ab)。
```
Q L U , .  │  F W R Y P
E I A O -  │  K T N S H
Z X C V ;  │  G D M J B
```

記号とIME切替キーの配置は、**OSのキーボード配列が日本語(JIS)** であることを想定。

QWERTY や US 配列で使いたい場合は、下記のとおり Vial から変更できます。

---

## キーマップを変えたいだけなら（ビルド不要）

**Vial対応のファームウェアを焼いてあるはずなのでVialで編集できます。**

一応手順を。
1. [Vial](https://get.vial.today/) をインストール
2. Ortholith を USB で接続
3. Vial を起動すると自動で認識されるので、GUI 上でキーマップを変更

変更は本体に保存されるので、ファームウェアを焼き直す必要はありません。

> Linux では hidraw へのアクセス権が必要です。Vial の
> [udev 設定](https://get.vial.today/manual/linux-udev.html) を入れてください。

書き込み済みのファームウェアだけ欲しい場合は
[Releases](https://github.com/mina-root/ortholith/releases) から `.uf2` を取得できます。

---

## 自分でビルドしたい？

このリポジトリには **キーボード定義だけ** が入っています。
ビルドには [vial-qmk](https://github.com/vial-kb/vial-qmk) のツリーが必要です。

### 事前に必要なもの

このキットを買うような人ならVial-QMKのビルドなんて慣れたもんだと思いますが一応。

`make git-submodule` が内部で `qmk` コマンドを呼ぶため、**qmk CLI が PATH に通っている必要があります。**
これが無いと `qmk: command not found` でビルド手順の途中で止まっちゃうかと

**Windows**: [QMK MSYS](https://msys.qmk.fm/) を入れれば、ツールチェーンも qmk CLI も同梱されています。
以降のコマンドは QMK MSYS のシェル上で実行してください。

**Linux (Fedora の例)**:

```bash
sudo dnf install arm-none-eabi-gcc-cs arm-none-eabi-newlib arm-none-eabi-binutils-cs
python3 -m venv ~/.venv/qmk && ~/.venv/qmk/bin/pip install qmk
export PATH="$HOME/.venv/qmk/bin:$PATH"    # qmk を PATH に通す
```

**macOS**: `brew install qmk/qmk/qmk` でツールチェーンごと入ります。

### ビルド手順

```bash
# 1. vial-qmk を取得し、動作確認済みのコミットに固定する
git clone https://github.com/vial-kb/vial-qmk.git
cd vial-qmk
git checkout dd43959ae5c08d8a28d38a1acf7b04e86b14a344
make git-submodule          # RP2040 には pico-sdk が必要。省略するとビルドに失敗します

# 2. このリポジトリのキーボード定義を配置する
git clone https://github.com/mina-root/ortholith.git /tmp/ortholith
cp -r /tmp/ortholith/keyboards/ortholith keyboards/

# 3. ビルド（vial-qmk 直下に ortholith_vial.uf2 ができる）
make ortholith:vial
```

書き込みまで一気にやる場合:

```bash
make ortholith:vial:flash
```

### 注意点

* **コミットの固定は省略しないでください。** vial-qmk / QMK に破壊的変更が入った場合、
  最新版では将来ビルドが通らなくなる可能性があります。上記のコミットは動作確認済みです。
* QMKの公式リポジトリにレイアウト定義がマージされてるわけではないので`qmk compile -kb ortholith` は使えません。vial-qmk はツリー内で `make` を使う方式です。
  `qmk_home` の設定を変更する必要もありません。
* Windows の場合は [QMK MSYS](https://msys.qmk.fm/) を入れて、その上で同じコマンドを実行してください。

### ビルド環境

| | |
|---|---|
| vial-qmk | `dd43959ae5c08d8a28d38a1acf7b04e86b14a344` (branch `vial`, 2026-07-26) |
| ツールチェーン | arm-none-eabi-gcc（QMK MSYS / `qmk setup` が導入するもの） |

---

## キーマップ

キーマップは `vial` の1種類です。レイヤー構成は以下のとおり。

| レイヤー | 用途 |
|---|---|
| `_BASE` | 通常入力。ホームロウ Mod 付き |
| `_LOWER` | 記号・テンキー |
| `_RAISE` | ファンクションキー・カーソル移動 |
| `_LAYER3` | マウスボタン・ホイール |

---

## 書き込み方

1. 以下のいずれかでブートローダに入る
   * PCB裏、ロータリーエンコーダ部の裏のリセットボタンを押しながら接続する
   * キーマップにブートローダモードにするキーがあればそれを押す
2. `RPI-RP2` ドライブが現れるので、`.uf2` をコピーする

左右それぞれに書き込んでください。

---

## ケースデータが欲しい？

X:@mina_VRChに連絡してくれればお渡し出来ます。
自分で3DプリントするなりJLCに発注するなりどうぞ。
一応CNCできるようにデータ作ってあります。
製造時に内Rが必要だがデータにない箇所がちょっとあると担当者に突っ込まれましたが小さいRを追加してやってもらえばいいです。

---

## ライセンス

GPL-2.0-or-later。詳細は [LICENSE](LICENSE) を参照してください。

このリポジトリに含まれるのは Ortholith 固有のキーボード定義のみです。
ビルドされるファームウェアは vial-qmk および QMK Firmware と組み合わさった結合著作物であり、
それらも GPL-2.0-or-later で配布されています。対応するソースコードは以下から取得できます。

* vial-qmk: https://github.com/vial-kb/vial-qmk （コミット `dd43959ae5c08d8a28d38a1acf7b04e86b14a344`）
* QMK Firmware: https://github.com/qmk/qmk_firmware

### 同梱のトラックボールケースについて

同梱のトラックボールケースは、[けぺお（kepeo）](https://www.thingiverse.com/kepeo/designs) さんの
「[Keyball 25mm Trackball Case Type C](https://www.thingiverse.com/thing:6719828)」を利用しています。
ライセンスは [CC BY 4.0](https://creativecommons.org/licenses/by/4.0/deed.ja) です。

**改変点**: M2ネジに合わせて、ネジ穴を少し大きくしています。
