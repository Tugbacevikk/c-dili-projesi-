# c-dili-projesi-
# Ozan Macerası – Metin Tabanlı RPG Oyunu (C)

Bu proje, C programlama dili kullanılarak geliştirilmiş **metin tabanlı bir rol yapma oyunudur (RPG)**.  
Oyuncu bir **Ozan** karakterini yönetir; kamp yapar, maceralara atılır, hayatta kalmaya çalışır ve seviye atlar.

---

## 🎯 Projenin Amacı

Bu projenin amacı:

- Yapı (`struct`) kullanımı
- Fonksiyonel programlama yaklaşımı
- Rastgelelik (`rand`)
- Karakter durumu yönetimi
- Menü tabanlı kullanıcı etkileşimi

gibi **C programlama dili konularını uygulamalı olarak pekiştirmektir.**

---

## 🧙‍♂️ Oyun Hikâyesi

Oyuncu bir ozanı canlandırır.  
Ozan:

- Kamp alanında dinlenebilir
- Han ve şifahaneye gidebilir
- Maceralara atılabilir
- Haydutlarla savaşabilir
- Komşulara yardım edebilir
- Hayatta kalmak için açlık, uyku ve hijyeni yönetmek zorundadır

Amaç **ölmeden seviye atlamak ve güçlenmektir.**

---

## 🧩 Karakter Özellikleri

Ozan karakterinin aşağıdaki özellikleri vardır:

- **Can**
- **Tokluk**
- **Uyku**
- **Hijyen**
- **Altın**
- **Deneyim**
- **Seviye**
- **Güç**
- **Çeviklik**
- **Karizma**
- **Toplayıcılık**
- **Dayanıklılık**

Tüm değerler belirli sınırlar içinde tutulur.

---

## 🗺️ Oyun Alanları ve Aktiviteler

### 🏕️ Kamp Alanı
- Şarkı söyleme
- Nehirde yıkanma
- Uyuma / kestirme
- Köy meydanına dönme

### 🍺 Han
- Yiyecek alma
- İçecek içme
- Enstrüman çalma

### 🏥 Şifahane
- Yaraları sardırma
- Merhem alma

### ⚔️ Macera
- Bitki toplama ve avlanma
- Kolay / Orta / Zor keşif
- Haydutlarla savaş veya kaçma

### 🏠 Komşu
- Yardım ederek altın kazanma
- Yiyecek satın alma

---

## 📈 Seviye Sistemi

- Her **100 deneyim puanı** → **1 seviye**
- Seviye atladıkça karakter güçlenir
- Yetersiz deneyimde seviye atlanamaz

---

## ☠️ Hayatta Kalma Mekaniği

Aşağıdaki durumlar can kaybına yol açar:

- Tokluk = 0 → Büyük can kaybı
- Uyku = 0 → Orta can kaybı
- Hijyen = 0 → Küçük can kaybı

Can **0’a düşerse oyun sona erer.**

---

## 🛠️ Derleme ve Çalıştırma

### Linux / macOS / WSL

```bash
gcc ozan.c -o ozan
./ozan
