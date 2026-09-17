# Ortholith

RP2040 を使った左右分割キーボード。7x4 の格子配列に、左右のロータリーエンコーダと
右手側トラックボール、RGB Matrix を載せています。

* Keyboard Maintainer: [mina-root](https://github.com/mina-root)
* Hardware Supported: Ortholith PCB v0 (RP2040 / Zero 互換)
* Hardware Availability: 即売会での限定頒布（4台）

## 仕様

| 項目 | 内容 |
|---|---|
| MCU | RP2040 |
| 配列 | 左右分割・格子配列 7列 x 4行（実装 49キー） |
| 分割通信 | シリアル（vendor / PIO） |
| エンコーダ | 左右に1個ずつ |
| ポインティングデバイス | PMW3360 トラックボール（右手側） |
| RGB | WS2812 / RGB Matrix（左25 + 右22 = 47 LED） |
| OLED | **非対応**（v0 基板にパターンはあるが搭載不可） |
| ブートローダ | rp2040（UF2） |

## ビルド

このディレクトリは **vial-qmk のツリーに配置して**ビルドします。
手順はリポジトリ直下の [README.md](../../README.md) を参照してください。

    make ortholith:vial

## キーマップ

キーマップは `vial` の1種類のみです。Vial アプリからGUIで変更できます。

## ブートローダへの入り方

以下のいずれかで UF2 書き込みモードに入ります。

* **物理リセットボタン**: PCB 裏のリセットボタンを素早く2回押す
* **キーコード**: キーマップ上の `QK_BOOT` を押す
* **Bootmagic reset**: マトリクス (0,0) のキーを押しながら USB を接続する

`RPI-RP2` という名前のドライブが現れたら、そこへ `.uf2` をコピーしてください。
