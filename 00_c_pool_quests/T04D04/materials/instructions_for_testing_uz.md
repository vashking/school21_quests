# Test uchun ko‘rsatmalar. 

Dasturning to‘g‘ri ma‘lumot qaytarishidan tashqari avtotest siz tuzgan dastur kodini keyingi punktlar bo‘yicha tekshirib o‘tadi: 

* **Code style.** Siz yozgan chiroyli kod standartga qanchalik mos kelishini tekshirish uchun _clang-format_ utilitidan foydalanishingiz mumkin. 
  ```materials/linters``` papkasida ```.clang-format``` fayli bor, unda stil uchun kerakli sozlamalar mavjud. 
  Bu sozlamali fayl o‘zining ta’sirini o‘zi bilan bir katalogda bo‘lgan barcha fayllarga va shu katalog ichida joylashgan boshqa kataloglarga o‘tkazadi. 
  Bu sozlamarni o‘z fayllaringizda qo‘llash uchun ushbu faylni ```src``` katologiga ko‘chirib o‘kazing. \
  \
  Stilni tekshirish uchun keyingi buyruqdan foydalaning: \
  ```clang-format -n src/sourcefile_name.c```
  
  clang-format kerakli versiyasi: \
  **Linux** - 13.0.1
  
  Google Style: https://google.github.io/styleguide/cppguide.html
