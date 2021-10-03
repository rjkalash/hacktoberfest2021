// dectruct obj
const {
  rl,
  question,
  tambah,
  perkalian,
  pengurangan,
  pembagian,
} = require("./count");

// main app async
const main = async () => {
  try {
    const menu = await question(
      "Menu \n 1. Oprasi tambah \n 2. Oprasi perkalian \n 3. Oprasi pembagian \n 4. Oprasi pengurangan \n\nPilih menu : "
    );
    const angka1 = await question("Masukan angka 1 : ");
    const angka2 = await question("Masukan angka 2 : ");
    if (menu == 1) {
      const hasil = await tambah(angka1, angka2);
      console.log(hasil);
    } else if (menu == 2) {
      const hasil = await perkalian(angka1, angka2);
      console.log(hasil);
    } else if (menu == 3) {
      const hasil = await pembagian(angka1, angka2);
      console.log(hasil);
    } else if (menu == 4) {
      const hasil = await pengurangan(angka1, angka2);
      console.log(hasil);
    }
    rl.close();
  } catch (error) {
    console.log("Error : ", error);
  }
};
main();
