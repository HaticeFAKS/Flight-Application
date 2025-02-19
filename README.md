# ✈️ Flight-Application

Bu proje, bir havayolu şirketinin uçuş ve bilet işlemlerini yönetmek için geliştirilmiş bir sistemdir. Uçuş ekleme, silme, güncelleme ve bilet satışı gibi işlemler içermektedir.

## 📌 Proje İçeriği

- **Uçuş Yönetimi:**
  - Yeni uçuş ekleme
  - Uçuş kaydı silme
  - Uçuş kalkış zamanını değiştirme
- **Bilet Satış Sistemi:**
  - Yolcular için bilet satın alma işlemleri
  - Koltuk kapasitesine göre fiyatlandırma
  - Satılan biletlerin kaydedilmesi

## 📂 Dosya Yapısı

- `main.c` - Havayolu bilet satış sisteminin ana kodları
- `bilet.txt` - Satılan bilet bilgileri (uçuş numarası, TC kimlik no, fiyat)
- `ucus.dat` - Uçuş bilgilerinin saklandığı dosya
- `rapor.docx` - Proje raporu (analiz, tasarım ve kullanım talimatları)
## 📥 Kurulum ve Çalıştırma

Projeyi GitHub üzerinden aşağıdaki komut ile klonlayabilirsiniz:
```bash
 git clone https://github.com/HaticeFAKS/Flight-Application.git
```

## 🚀 Kullanım Talimatları

1. Program çalıştırıldığında aşağıdaki seçenekler sunulacaktır:
   - **1:** Yeni bir uçuş ekleme
   - **2:** Bir uçuş kaydını silme
   - **3:** Uçuş kalkış zamanını değiştirme
   - **4:** Yeni bir uçuş için bilet satışı

2. Seçiminizi yaptıktan sonra sistem, gerekli bilgileri girmenizi isteyecektir.
3. Tüm işlemler başarıyla tamamlandıktan sonra uçuş ve bilet bilgileri güncellenir.

## ⚠️ Dikkat Edilmesi Gerekenler

- TC Kimlik numarası **11 haneli** olmalıdır.
- Kalkış ve varış noktaları aynı olamaz.
- Kalkış saati **00:00 - 23:59** arasında olmalıdır.
- Koltuk kapasitesi dolduğunda yeni bilet satılamaz.

## 📖 Detaylı Bilgi
Daha fazla bilgi için `rapor.docx` dosyasını inceleyebilirsiniz.

---

👨‍💻 Takım Arkadaşları: Handan Karakum-Melisa Yalçınkaya


