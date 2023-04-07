# polindrom-bulma
Yazdığım kodun amacı girilen bir kelimenin  okunuşunun baştan ve sondan  aynı olup olmadığını bulma yani polindrom kelime bulmadır.

Kodumu yazarken tek yönlü bağlı liste kullandım önce onun için struct içinde  veri ve sonraki elemanı tutan değişkenler tanımladım. Bunları main içinde bir head bilgisi ile çağırarak null değerine eşitledim sonra kullanıcıdan kelime alarak onun uzunluğunu hesapladım. Kelimenin uzunluğu kadar dönecek bir döngü tanımlayıp içinde yeni bir değişkenle kelimeyi listeye aktarıp değerleri ve sıraları tutmasını  sağladım. Bu döngüden çıkınca if içerisinde tanımlamış olduğum polindrom kontrolu yapan fonksiyona head bilgisini verdim doğru içe true dönerek polindrom olduğu kullanıcıya bildirildi eeğer faalse dönerse olmadığı bildirilir. Tanımladığım polindromu kontrol eden fonksiyonda önce  tekrar bir liste içerisine kelimemi aktarıp uzunluğunu hesapladım  bu işlem bittiğinde başka bir döngüde uzunluğun yarısı kadar döndürerek baştan ve somnda kelimenin harflerinin eşit olup olmadığını kontrol ettim ve değeri döndürdüm.

Kodun testini yaparken polindrom olduğunu bir kelime verilir ve çıkan sonuca göre kodun doğruluğu test edilebilir.
